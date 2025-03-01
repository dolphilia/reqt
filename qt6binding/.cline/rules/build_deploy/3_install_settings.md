# インストール設定

## 3.1 ファイルのインストール
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

## 3.2 パッケージ設定
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

## 3.3 インストール設定のパターン

### 1. 基本インストール
```cmake
# 1. 実行ファイルのインストール
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# 2. ライブラリのインストール
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# 3. ヘッダーのインストール
install(FILES ${HEADERS}
    DESTINATION include/${PROJECT_NAME}
)
```

### 2. コンポーネント別インストール
```cmake
# 1. コンポーネントの定義
install(TARGETS ${PROJECT_NAME}
    RUNTIME
        COMPONENT Runtime
        DESTINATION bin
    LIBRARY
        COMPONENT Development
        DESTINATION lib
    ARCHIVE
        COMPONENT Development
        DESTINATION lib
)

# 2. ヘッダーのインストール
install(FILES ${HEADERS}
    COMPONENT Development
    DESTINATION include/${PROJECT_NAME}
)

# 3. ドキュメントのインストール
install(FILES ${DOC_FILES}
    COMPONENT Documentation
    DESTINATION share/doc/${PROJECT_NAME}
)
```

## 3.4 インストールスクリプト

### 1. インストール後のスクリプト
```cmake
# 1. キャッシュの更新
install(CODE "
    execute_process(
        COMMAND ldconfig
    )
")

# 2. シンボリックリンクの作成
install(CODE "
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_INSTALL_PREFIX}/lib/lib${PROJECT_NAME}.so
            ${CMAKE_INSTALL_PREFIX}/lib/lib${PROJECT_NAME}.so.${PROJECT_VERSION}
    )
")
```

### 2. プラットフォーム固有のスクリプト
```cmake
# 1. Windows用スクリプト
if(WIN32)
    install(CODE "
        execute_process(
            COMMAND regsvr32 /s \${CMAKE_INSTALL_PREFIX}/bin/${PROJECT_NAME}.dll
        )
    ")
endif()

# 2. Linux用スクリプト
if(UNIX AND NOT APPLE)
    install(CODE "
        execute_process(
            COMMAND ldconfig
        )
    ")
endif()
```

## 3.5 インストール設定のガイドライン

### 1. ファイル構成
- 適切なディレクトリ構造
- ファイルの分類と整理
- パーミッションの設定
- バージョン管理

### 2. パッケージング
- 依存関係の管理
- バージョン互換性
- コンポーネントの分割
- 設定ファイルの提供

### 3. プラットフォーム対応
- パスの適切な設定
- プラットフォーム固有の処理
- インストール先の調整
- 環境変数の設定

### 4. インストール後の処理
- キャッシュの更新
- シンボリックリンクの作成
- 権限の設定
- 環境の設定
