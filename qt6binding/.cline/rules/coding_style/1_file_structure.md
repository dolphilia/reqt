# ファイル構造

## 1.1 ヘッダーファイル
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

## 1.2 実装ファイル
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

## 1.3 C APIファイル
```cpp
// QWidgetCAPI.cpp
#include "QWidgetBind.h"
#include "qwidget.h"

extern "C" {
    void* QWidget_create(void* parent) {
        return new BindQWidget(static_cast<QWidget*>(parent));
    }

    void QWidget_delete(void* widget) {
        delete static_cast<BindQWidget*>(widget);
    }

    // その他のAPI関数
}
