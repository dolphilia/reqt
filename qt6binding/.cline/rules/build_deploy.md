# ビルドとデプロイメントガイドライン

## 1. CMake設定

### 1.1 基本設定
```cmake
# 1. プロジェクト設定
cmake_minimum_required(VERSION 3.16)
project(qt6binding VERSION 1.0.0 LANGUAGES CXX)

# 2. コンパイラ設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3. ビルドタイプ設定
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# 4. コンパイラフラグ
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
```

### 1.2 Qt6の設定
```cmake
# 1. Qt6の検索
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
)

# 2. 自動MOC設定
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 3. Qt6のリンク設定
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
```

## 2. プラットフォーム固有の設定

### 2.1 Windows設定
```cmake
if(WIN32)
    # 1. DLLエクスポート設定
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    
    # 2. Windows固有の定義
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )
    
    # 3. リンカーフラグ
    set(CMAKE_SHARED_LINKER_FLAGS 
        "${CMAKE_SHARED_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
endif()
```

### 2.2 macOS設定
```cmake
if(APPLE)
    # 1. RPATHの設定
    set(CMAKE_MACOSX_RPATH ON)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INSTALL_RPATH "@loader_path/../lib"
    )
    
    # 2. フレームワーク設定
    set_target_properties(${PROJECT_NAME} PROPERTIES
        FRAMEWORK TRUE
        FRAMEWORK_VERSION A
        MACOSX_FRAMEWORK_IDENTIFIER com.example.qt6binding
    )
    
    # 3. デプロイメントターゲット
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")
endif()
```

### 2.3 Linux設定
```cmake
if(UNIX AND NOT APPLE)
    # 1. RPATH設定
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INSTALL_RPATH "$ORIGIN/../lib"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
    
    # 2. 共有ライブラリのバージョン
    set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )
    
    # 3. インストールディレクトリ
    include(GNUInstallDirs)
endif()
```

## 3. ビルド設定

### 3.1 ターゲット設定
```cmake
# 1. ソースファイルの収集
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.h"
)

# 2. ライブラリターゲットの定義
add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
    ${MOC_HEADERS}
)

# 3. インクルードディレクトリ
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
```

### 3.2 依存関係の設定
```cmake
# 1. パッケージの検索
find_package(Threads REQUIRED)

# 2. 依存関係のリンク
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Threads::Threads
)

# 3. コンパイル定義
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        QT_NO_KEYWORDS
        $<$<CONFIG:Debug>:QT_DEBUG>
        $<$<CONFIG:Release>:QT_NO_DEBUG>
)
```

## 4. インストール設定

### 4.1 ファイルのインストール
```cmake
# 1. ヘッダーのインストール
install(FILES
    ${PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

# 2. ライブラリのインストール
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FRAMEWORK DESTINATION Library/Frameworks
)

# 3. CMake設定ファイルのインストール
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)
```

### 4.2 パッケージ設定
```cmake
# 1. バージョンファイルの生成
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# 2. 設定ファイルの生成
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

# 3. パッケージファイルのインストール
install(FILES
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)
```

## 5. デプロイメント

### 5.1 依存関係の収集
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

### 5.2 パッケージング
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

## 6. テスト設定

### 6.1 テストの有効化
```cmake
# 1. テストの設定
enable_testing()
add_subdirectory(tests)

# 2. テストターゲットの定義
add_executable(${PROJECT_NAME}_test
    ${TEST_SOURCES}
)

# 3. テストの依存関係
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
        ${PROJECT_NAME}
        Qt6::Test
)
```

### 6.2 テストの実行
```cmake
# 1. テストケースの追加
add_test(NAME ${PROJECT_NAME}_test
         COMMAND ${PROJECT_NAME}_test)

# 2. テスト環境の設定
set_tests_properties(${PROJECT_NAME}_test
    PROPERTIES
        ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)

# 3. カバレッジの設定
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME}_test
        PRIVATE
            --coverage
    )
    target_link_options(${PROJECT_NAME}_test
        PRIVATE
            --coverage
    )
endif()
