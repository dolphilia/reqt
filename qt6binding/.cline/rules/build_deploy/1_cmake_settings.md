# CMake設定

## 1.1 基本設定
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

## 1.2 Qt6の設定
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

## 1.3 プラットフォーム固有の設定

### 1. Windows設定
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

### 2. macOS設定
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

### 3. Linux設定
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

## 1.4 CMakeガイドライン

### 1. プロジェクト設定
- 適切なバージョン要件
- 必要な言語の指定
- プロジェクト情報の設定
- ビルドタイプの設定

### 2. コンパイラ設定
- C++標準の指定
- 警告レベルの設定
- 最適化レベルの設定
- デバッグ情報の設定

### 3. Qt6設定
- 必要なコンポーネントの指定
- 自動ツールの設定
- リンク設定の最適化
- 依存関係の管理

### 4. プラットフォーム対応
- プラットフォーム固有の設定
- 互換性の確保
- パス設定の適切な管理
- インストール設定の調整
