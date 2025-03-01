# ファイル編成

## 5.1 ヘッダファイル
```cpp
// 1. システムヘッダ
#include <vector>
#include <string>

// 2. Qtヘッダ
#include <QWidget>
#include <QObject>

// 3. プロジェクトヘッダ
#include "QWidgetHandler.h"
#include "BindQWidget.h"
```

## 5.2 実装ファイル
```cpp
// 1. 対応するヘッダ
#include "BindQWidget.h"

// 2. その他のヘッダ
#include <algorithm>
#include "QWidgetHandler.h"

// 3. 実装
BindQWidget::BindQWidget() {
    // 実装
}
```

## 5.3 ディレクトリ構造
```
qt6binding/
├── src/              # ソースコード
│   ├── QWidget/
│   │   ├── QWidgetBind.h
│   │   ├── QWidgetBind.cpp
│   │   ├── QWidgetHandler.h
│   │   ├── QWidgetHandler.cpp
│   │   └── QWidgetCAPI.cpp
│   └── ...
├── include/          # 公開ヘッダー
│   └── qt6/
│       ├── qwidget.h
│       └── ...
├── example/          # サンプルコード
│   └── qwidget/
│       ├── CMakeLists.txt
│       └── main.c
└── build/            # ビルド出力
```

## 5.4 ファイル命名規則

### ヘッダファイル
- バインディングクラス: `[QtClass]Bind.h`
- ハンドラクラス: `[QtClass]Handler.h`
- C API: `q[class].h` (小文字)

### ソースファイル
- バインディングクラス: `[QtClass]Bind.cpp`
- ハンドラクラス: `[QtClass]Handler.cpp`
- C API: `[QtClass]CAPI.cpp`

### サンプルコード
- ディレクトリ: `q[class]` (小文字)
- メインファイル: `main.c`
- ビルド設定: `CMakeLists.txt`

## 5.5 ファイル内の順序

### ヘッダファイル
1. インクルードガード
2. インクルード文
3. 名前空間（必要な場合）
4. クラス宣言
   - public
   - protected
   - private
5. インライン関数の実装

### ソースファイル
1. インクルード文
2. 名前空間（必要な場合）
3. static関数/変数
4. クラスメソッドの実装
   - コンストラクタ/デストラクタ
   - public メソッド
   - protected メソッド
   - private メソッド
5. グローバル関数
