# ビルド設定

## 3.1 CMake設定
```cmake
# プロジェクト設定
cmake_minimum_required(VERSION 3.16)
project(qt6binding)

# C++標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ライブラリ設定
add_library(qt6binding SHARED
    ${SOURCES}
    ${MOC_HEADERS}
)

# インクルードディレクトリ
target_include_directories(qt6binding PUBLIC
    include
    include/qt6
    src
)

# リンク設定
target_link_libraries(qt6binding PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
```

## 3.2 ディレクトリ構造
```
qt6binding/
├── src/              # ソースコード
├── include/          # 公開ヘッダー
├── example/          # サンプルコード
└── build/            # ビルド出力
```

## 3.3 出力ファイル
- Windows: qt6binding.dll
- Linux: libqt6binding.so
- macOS: libqt6binding.dylib
