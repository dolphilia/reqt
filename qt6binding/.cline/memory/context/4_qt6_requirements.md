# Qt6の要件

## 2.1 必須コンポーネント
```cmake
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
)
```

## 2.2 Qt機能の有効化
```cmake
set(CMAKE_AUTOMOC ON)  # メタオブジェクトコンパイラ
set(CMAKE_AUTORCC ON)  # リソースコンパイラ
set(CMAKE_AUTOUIC ON)  # UIコンパイラ
```

## 2.3 依存関係
- QtCore: 基本機能
- QtWidgets: GUIコンポーネント
- QtGui: グラフィックス機能
