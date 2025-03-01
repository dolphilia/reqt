# デプロイメント

## 4.1 依存関係の収集
```cmake
# 1. 依存DLLの収集（Windows）
if(WIN32)
    include(DeployQt)
    windeployqt(${PROJECT_NAME}
        --no-compiler-runtime
        --no-translations
        --no-system-d3d-compiler
        $<TARGET_FILE:${PROJECT_NAME}>
    )
endif()

# 2. 依存ライブラリの収集（macOS）
if(APPLE)
    include(DeployQt)
    macdeployqt(${PROJECT_NAME}
        --no-plugins
        $<TARGET_FILE:${PROJECT_NAME}>
    )
endif()
```

## 4.2 パッケージング
```cmake
# 1. CPack設定
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Example")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Qt6 C bindings library")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT_NAME})

# 2. プラットフォーム固有のパッケージ
if(WIN32)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
else()
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "maintainer@example.com")
endif()

include(CPack)
```

## 4.3 デプロイメントパターン

### 1. 基本デプロイメント
```cmake
# 1. 実行ファイルのデプロイ
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)

# 2. 依存ライブラリのデプロイ
file(GLOB DEPS_LIBS
    "${Qt6_DIR}/bin/*.dll"
    "${Qt6_DIR}/lib/*.so*"
)
install(FILES ${DEPS_LIBS}
    DESTINATION lib
)

# 3. リソースのデプロイ
install(DIRECTORY resources
    DESTINATION share/${PROJECT_NAME}
)
```

### 2. プラットフォーム別デプロイメント
```cmake
# 1. Windows用デプロイメント
if(WIN32)
    # DLLのデプロイ
    install(FILES
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.dll
        DESTINATION bin
    )
    
    # レジストリ設定
    install(CODE "
        execute_process(
            COMMAND reg add \"HKLM\\Software\\${PROJECT_NAME}\"
        )
    ")
endif()

# 2. Linux用デプロイメント
if(UNIX AND NOT APPLE)
    # 共有ライブラリのデプロイ
    install(FILES
        ${CMAKE_BINARY_DIR}/lib${PROJECT_NAME}.so
        DESTINATION lib
    )
    
    # デスクトップエントリのデプロイ
    install(FILES
        ${PROJECT_NAME}.desktop
        DESTINATION share/applications
    )
endif()
```

## 4.4 デプロイメントスクリプト

### 1. 依存関係の解決
```cmake
# 1. 依存関係の検出
function(detect_dependencies TARGET_NAME)
    get_target_property(DEPS ${TARGET_NAME} LINK_LIBRARIES)
    foreach(DEP ${DEPS})
        if(TARGET ${DEP})
            get_target_property(DEP_TYPE ${DEP} TYPE)
            if(DEP_TYPE STREQUAL "SHARED_LIBRARY")
                # 依存ライブラリの処理
            endif()
        endif()
    endforeach()
endfunction()

# 2. 依存関係のコピー
function(copy_dependencies TARGET_NAME DEST_DIR)
    get_target_property(TARGET_LOCATION ${TARGET_NAME}
        LOCATION)
    get_filename_component(TARGET_DIR ${TARGET_LOCATION}
        DIRECTORY)
    file(GLOB DEPS
        "${TARGET_DIR}/*.dll"
        "${TARGET_DIR}/*.so*"
        "${TARGET_DIR}/*.dylib"
    )
    file(COPY ${DEPS} DESTINATION ${DEST_DIR})
endfunction()
```

### 2. パッケージ作成スクリプト
```cmake
# 1. アーカイブの作成
function(create_archive TARGET_NAME VERSION)
    set(ARCHIVE_NAME
        "${TARGET_NAME}-${VERSION}-${CMAKE_SYSTEM_NAME}")
    add_custom_target(dist
        COMMAND ${CMAKE_COMMAND} -E tar "czf"
            "${ARCHIVE_NAME}.tar.gz" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endfunction()

# 2. インストーラの作成
function(create_installer TARGET_NAME VERSION)
    if(WIN32)
