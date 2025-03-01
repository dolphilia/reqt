# コーディングスタイル

## 1. ファイル構造
```cpp
// ヘッダーファイル
#ifndef BIND_Q_[CLASSNAME]_H
#define BIND_Q_[CLASSNAME]_H

#include <[QtHeader]>
#include "[ClassHandler].h"  // 必要な場合

// クラス定義
class Bind[ClassName] : public [ClassName] {
    Q_OBJECT  // 必要な場合
public:
    // コンストラクタ
    // パブリックメソッド
protected:
    // 保護メンバ
private:
    // プライベートメンバ
};

#endif
```

## 2. 命名規則

### 2.1 クラス名
```cpp
class BindQWidget;      // バインディングクラス
class QWidgetHandler;   // ハンドラクラス
```

### 2.2 メソッド名
```cpp
void QWidget_create();  // コンストラクタ
void QWidget_delete();  // デストラクタ
void QWidget_show();    // アクション
```

### 2.3 変数名
```cpp
m_handler;              // メンバ変数
callback;               // コールバック関数
parentWidget;           // ローカル変数
```

## 3. コメント
```cpp
/**
 * @brief クラスの説明
 * @details 詳細な説明
 */
class SomeClass {
    /**
     * @brief メソッドの説明
     * @param param パラメータの説明
     * @return 戻り値の説明
     * @throws 例外の説明
     */
    ReturnType someMethod(ParamType param);
};
```

## 4. インデントとフォーマット

### 4.1 インデント
- スペース4文字を使用
- タブ文字は使用しない
- 継続行は8スペース

### 4.2 ブレース
```cpp
if (condition) {
    // 処理
} else {
    // 処理
}

while (condition) {
    // 処理
}

class ClassName {
public:
    // メンバ
private:
    // メンバ
};
```

### 4.3 スペース
```cpp
// 演算子の前後
a = b + c;
if (a < b) {
}

// カンマの後
function(a, b, c);

// ポインタ/参照の*と&
int* ptr;
int& ref;
```

## 5. ファイル編成

### 5.1 ヘッダファイル
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

### 5.2 実装ファイル
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

## 6. コード構造

### 6.1 クラス構造
```cpp
class ClassName {
public:
    // 1. コンストラクタ/デストラクタ
    // 2. パブリックメソッド
    // 3. パブリックスロット
    // 4. シグナル
protected:
    // 5. 保護メソッド
    // 6. 保護メンバ
private:
    // 7. プライベートメソッド
    // 8. プライベートメンバ
};
```

### 6.2 メソッド構造
```cpp
ReturnType ClassName::methodName(ParamType param) {
    // 1. 引数の検証
    if (!param) {
        return error;
    }

    // 2. 前処理
    prepare();

    // 3. メイン処理
    ReturnType result = process(param);

    // 4. 後処理
    cleanup();

    // 5. 結果返却
    return result;
}
```

## 7. 制約と規約

### 7.1 禁止事項
- グローバル変数の使用
- using namespace の使用
- 複数の継承（特別な場合を除く）
- マジックナンバーの使用

### 7.2 推奨事項
- const の積極的な使用
- スマートポインタの使用
- 早期リターン
- 小さな関数
