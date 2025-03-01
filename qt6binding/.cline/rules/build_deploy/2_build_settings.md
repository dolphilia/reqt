# ビルド設定

## 2.1 ターゲット設定
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

## 2.2 依存関係の設定
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

## 2.3 ビルド設定のパターン

### 1. ライブラリ設定
```cmake
# 1. 共有ライブラリ
add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
)

# 2. 静的ライブラリ
add_library(${PROJECT_NAME}_static STATIC
    ${SOURCES}
)

# 3. オブジェクトライブラリ
add_library(${PROJECT_NAME}_obj OBJECT
    ${SOURCES}
)
```

### 2. ターゲットプロパティ
```cmake
# 1. 出力名の設定
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "qt6binding"
    DEBUG_POSTFIX "d"
)

# 2. バージョン情報の設定
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# 3. エクスポート設定
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)
```

## 2.4 ビルドオプション

### 1. コンパイルオプション
```cmake
# 1. 警告レベル
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /WX
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Werror
    )
endif()

# 2. 最適化オプション
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Debug>:-O0 -g>
)
```

### 2. リンクオプション
```cmake
# 1. 基本設定
target_link_options(${PROJECT_NAME} PRIVATE
    $<$<PLATFORM_ID:Windows>:/SUBSYSTEM:WINDOWS>
)

# 2. RPATHの設定
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INSTALL_RPATH "@loader_path/../lib"
    )
elseif(UNIX)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INSTALL_RPATH "$ORIGIN/../lib"
    )
endif()
```

## 2.5 ビルド設定のガイドライン

### 1. ターゲット設定
- 適切なターゲット種別の選択
- ソースファイルの整理
- インクルードパスの管理
- 出力設定の最適化

### 2. 依存関係管理
- 必要なパッケージの検索
- 適切なリンク設定
- バージョン要件の指定
- 互換性の確保

### 3. コンパイル設定
- 警告レベルの設定
- 最適化オプションの選択
- デバッグ情報の制御
- プラットフォーム対応

### 4. リンク設定
- 共有/静的リンクの選択
- RPATHの適切な設定
- シンボルの可視性制御
- バージョン情報の管理
