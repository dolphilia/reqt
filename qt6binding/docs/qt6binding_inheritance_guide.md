# Qt6バインディングにおける継承関係の実装ガイド

このドキュメントでは、Qt6のC++クラスの継承関係をC言語バインディングで適切に実装するための方法を説明します。Qtの多くのクラスは`QObject`を継承しており、継承したクラスは`QObject`の機能も使えますが、バインディングでは明示的に実装する必要があります。

## 目次

1. [継承関係の基本概念](#継承関係の基本概念)
2. [バインディングの3層構造](#バインディングの3層構造)
3. [QObjectの機能を継承先クラスに実装する方法](#qobjectの機能を継承先クラスに実装する方法)
4. [実装例：QWidgetにQObjectの機能を追加する](#実装例qwidgetにqobjectの機能を追加する)
5. [継承チェーンの実装](#継承チェーンの実装)
6. [シグナル・スロットの継承](#シグナルスロットの継承)
7. [ベストプラクティス](#ベストプラクティス)

## 継承関係の基本概念

Qtでは、多くのクラスが`QObject`を基底クラスとして継承しています。例えば：

```
QObject
  └── QWidget
       ├── QPushButton
       ├── QLabel
       └── QLineEdit
```

C++では継承によって基底クラスの機能を自動的に利用できますが、C言語バインディングでは明示的に実装する必要があります。

## バインディングの3層構造

Qt6バインディングは以下の3層構造で実装されています：

1. **Handlerクラス** - Qt側のクラスを扱うC++クラス
2. **Bindクラス** - C++とC言語の橋渡しをする静的メソッドを提供するクラス
3. **CAPI関数** - C言語から呼び出せる関数群

継承関係を実装する場合、これら3層すべてで適切に対応する必要があります。

## QObjectの機能を継承先クラスに実装する方法

### 1. Handlerクラスでの実装

継承先クラスのHandlerクラスで、QObjectHandlerの機能を実装します。

```cpp
// 例：QWidgetHandlerクラス
class QWidgetHandler : public QObjectHandler {
public:
    // QWidgetHandler固有のメソッド
    void resize(int w, int h);
    void move(int x, int y);
    // ...

    // QObjectHandlerのメソッドをオーバーライド（必要な場合）
    void setObjectName(const QString &name) override;
    // ...
};
```

### 2. Bindクラスでの実装

継承先クラスのBindクラスで、QObjectBindの機能を委譲または実装します。

```cpp
// 例：QWidgetBindクラス
class QWidgetBind {
public:
    // QWidgetBind固有のメソッド
    static void resize(void* widget, int w, int h);
    static void move(void* widget, int x, int y);
    // ...

    // QObjectBindの機能を委譲
    static void setObjectName(void* widget, const char* name) {
        QObjectBind::setObjectName(widget, name);
    }
    // ...
};
```

### 3. CAPI関数での実装

継承先クラスのCAPI関数で、QObjectのCAPI関数と同等の機能を提供します。

```c
// 例：QWidgetのCAPI関数
void QWidget_setObjectName(void* widget, const char* name) {
    QWidgetBind::setObjectName(widget, name);
}
// ...
```

## 実装例：QWidgetにQObjectの機能を追加する

以下に、QWidgetクラスにQObjectの機能を追加する具体的な実装例を示します。

### Handler層の実装

```cpp
// QWidgetHandler.h
#ifndef Q_WIDGET_HANDLER_H
#define Q_WIDGET_HANDLER_H

#include "../QObject/QObjectHandler.h"
#include <QWidget>

class QWidgetHandler : public QObjectHandler {
public:
    explicit QWidgetHandler(QWidget* widget = nullptr);
    virtual ~QWidgetHandler();

    // QWidgetの固有機能
    void resize(int w, int h);
    void move(int x, int y);
    // ...

    // QObjectHandlerの機能をオーバーライド（必要な場合）
    void setObjectName(const QString &name) override;
    // ...

    // QWidgetへのアクセス
    QWidget* widget() const;

private:
    QWidget* m_widget;
};

#endif // Q_WIDGET_HANDLER_H
```

```cpp
// QWidgetHandler.cpp
#include "QWidgetHandler.h"

QWidgetHandler::QWidgetHandler(QWidget* widget)
    : QObjectHandler(widget), m_widget(widget)
{
}

QWidgetHandler::~QWidgetHandler()
{
}

void QWidgetHandler::resize(int w, int h)
{
    if (m_widget) {
        m_widget->resize(w, h);
    }
}

void QWidgetHandler::move(int x, int y)
{
    if (m_widget) {
        m_widget->move(x, y);
    }
}

void QWidgetHandler::setObjectName(const QString &name)
{
    // 必要に応じてQWidgetに特化した実装を行う
    QObjectHandler::setObjectName(name);
}

QWidget* QWidgetHandler::widget() const
{
    return m_widget;
}
```

### Bind層の実装

```cpp
// QWidgetBind.h
#ifndef Q_WIDGET_BIND_H
#define Q_WIDGET_BIND_H

#include "QWidgetHandler.h"
#include "../QObject/QObjectBind.h"

class QWidgetBind {
public:
    // QWidgetの固有機能
    static void resize(void* widget, int w, int h);
    static void move(void* widget, int x, int y);
    // ...

    // QObjectの機能を委譲
    static void setObjectName(void* widget, const char* name);
    static char* objectName(void* widget);
    // ...

private:
    static QWidgetHandler* handler(void* widget);
};

#endif // Q_WIDGET_BIND_H
```

```cpp
// QWidgetBind.cpp
#include "QWidgetBind.h"
#include <QString>

void QWidgetBind::resize(void* widget, int w, int h)
{
    handler(widget)->resize(w, h);
}

void QWidgetBind::move(void* widget, int x, int y)
{
    handler(widget)->move(x, y);
}

void QWidgetBind::setObjectName(void* widget, const char* name)
{
    handler(widget)->setObjectName(QString::fromUtf8(name));
}

char* QWidgetBind::objectName(void* widget)
{
    QString name = handler(widget)->objectName();
    return qstrdup(name.toUtf8().constData());
}

QWidgetHandler* QWidgetBind::handler(void* widget)
{
    return static_cast<QWidgetHandler*>(widget);
}
```

### CAPI層の実装

```cpp
// QWidgetCAPI.cpp
#include "QWidgetBind.h"
#include "qwidget.h"

extern "C" {

void QWidget_resize(void* widget, int w, int h)
{
    QWidgetBind::resize(widget, w, h);
}

void QWidget_move(void* widget, int x, int y)
{
    QWidgetBind::move(widget, x, y);
}

// QObjectの機能
void QWidget_setObjectName(void* widget, const char* name)
{
    QWidgetBind::setObjectName(widget, name);
}

char* QWidget_objectName(void* widget)
{
    return QWidgetBind::objectName(widget);
}

// ...

}
```

```c
// qwidget.h (C言語ヘッダー)
#ifndef QT_QWIDGET_H
#define QT_QWIDGET_H

#include <stdbool.h>
#include "qobject.h" // QObjectの機能も使えることを示す

#ifdef __cplusplus
extern "C" {
#endif

// QWidgetの固有機能
void QWidget_resize(void* widget, int w, int h);
void QWidget_move(void* widget, int x, int y);
// ...

// QObjectから継承した機能
void QWidget_setObjectName(void* widget, const char* name);
char* QWidget_objectName(void* widget);
// ...

#ifdef __cplusplus
}
#endif

#endif // QT_QWIDGET_H
```

## 継承チェーンの実装

複数レベルの継承がある場合（例：QObject → QWidget → QPushButton）、各レベルで適切に機能を実装する必要があります。

1. 各レベルのHandlerクラスが前のレベルを継承
2. 各レベルのBindクラスが前のレベルの機能を委譲または実装
3. 各レベルのCAPI関数が前のレベルの機能を提供

## シグナル・スロットの継承

Qtのシグナル・スロットシステムも継承関係で適切に扱う必要があります。

1. 基底クラスのシグナルを継承先クラスでも利用できるようにする
2. 継承先クラス固有のシグナルを追加する
3. コールバック関数の設定メカニズムを各レベルで実装する

```cpp
// 例：QWidgetのシグナルコールバック設定
void QWidget_setDestroyedCallback(void* widget, void (*callback)(void*))
{
    // QObjectのDestroyedシグナルを利用
    QObject_setDestroyedCallback(widget, callback);
}

void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*))
{
    // QWidget固有のシグナル
    static_cast<BindQWidget*>(widget)->setCustomContextMenuRequestedCallback(
        reinterpret_cast<WidgetCustomContextMenuRequestedCallback>(callback)
    );
}
```

## ベストプラクティス

1. **一貫性を保つ** - 継承関係全体で命名規則や実装パターンを一貫させる
2. **重複を避ける** - 基底クラスの機能を再実装せず、委譲を活用する
3. **型安全性を確保** - キャストは慎重に行い、型の整合性を確保する
4. **メモリ管理に注意** - 特にC言語側に返す文字列などのリソース管理に注意
5. **ドキュメント化** - 継承関係や利用可能な機能を明確にドキュメント化する

以上のガイドラインに従うことで、Qtの継承関係をC言語バインディングで適切に実装できます。
