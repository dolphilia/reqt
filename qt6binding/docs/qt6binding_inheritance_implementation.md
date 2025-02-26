# Qt6バインディングにおける継承関係の実装手順

このドキュメントでは、Qt6バインディングで新しいクラスを追加する際に、継承関係を適切に実装するための具体的な手順を説明します。

## 目次

1. [実装の概要](#実装の概要)
2. [実装手順](#実装手順)
3. [具体的な実装例](#具体的な実装例)
4. [継承チェーンの実装例](#継承チェーンの実装例)
5. [トラブルシューティング](#トラブルシューティング)

## 実装の概要

Qt6バインディングでは、Qtの継承関係を以下の3層構造で実装します：

1. **Handler層** - Qt側のクラスを扱うC++クラス
2. **Bind層** - C++とC言語の橋渡しをする静的メソッドを提供するクラス
3. **CAPI層** - C言語から呼び出せる関数群

継承関係を実装する場合、これら3層すべてで適切に対応する必要があります。

## 実装手順

新しいQtクラスのバインディングを作成し、継承関係を適切に実装するための手順は以下の通りです：

### 1. 継承関係の把握

まず、実装するクラスの継承関係を把握します。例えば、`QPushButton`は`QAbstractButton`を継承し、`QAbstractButton`は`QWidget`を継承し、`QWidget`は`QObject`を継承しています。

### 2. Handler層の実装

1. **Handlerクラスの作成**：
   - 基底クラスのHandlerを継承したHandlerクラスを作成します
   - 例：`QPushButtonHandler`は`QAbstractButtonHandler`を継承

   ```cpp
   // QPushButtonHandler.h
   #ifndef Q_PUSH_BUTTON_HANDLER_H
   #define Q_PUSH_BUTTON_HANDLER_H

   #include "../QAbstractButton/QAbstractButtonHandler.h"
   #include <QPushButton>

   class QPushButtonHandler : public QAbstractButtonHandler {
   public:
       explicit QPushButtonHandler(QPushButton* button = nullptr);
       virtual ~QPushButtonHandler();

       // QPushButtonの固有機能
       void setFlat(bool flat);
       bool isFlat() const;
       // ...

       // QPushButtonへのアクセス
       QPushButton* pushButton() const;
   };

   #endif // Q_PUSH_BUTTON_HANDLER_H
   ```

2. **Handlerクラスの実装**：
   - 基底クラスのコンストラクタを呼び出し、適切に初期化します
   - クラス固有のメソッドを実装します

   ```cpp
   // QPushButtonHandler.cpp
   #include "QPushButtonHandler.h"

   QPushButtonHandler::QPushButtonHandler(QPushButton* button)
       : QAbstractButtonHandler(button)
   {
   }

   QPushButtonHandler::~QPushButtonHandler()
   {
   }

   void QPushButtonHandler::setFlat(bool flat)
   {
       if (pushButton()) {
           pushButton()->setFlat(flat);
       }
   }

   bool QPushButtonHandler::isFlat() const
   {
       return pushButton() ? pushButton()->isFlat() : false;
   }

   QPushButton* QPushButtonHandler::pushButton() const
   {
       return qobject_cast<QPushButton*>(widget());
   }
   ```

### 3. Bind層の実装

1. **Bindクラスの作成**：
   - クラス固有のメソッドと基底クラスへの委譲メソッドを定義します

   ```cpp
   // QPushButtonBind.h
   #ifndef Q_PUSH_BUTTON_BIND_H
   #define Q_PUSH_BUTTON_BIND_H

   #include "QPushButtonHandler.h"
   #include "../QAbstractButton/QAbstractButtonBind.h"

   class QPushButtonBind {
   public:
       // 作成・削除
       static QPushButton* create(QWidget* parent = nullptr);
       static void destroy(QPushButton* button);

       // QPushButton固有の機能
       static void setFlat(void* button, bool flat);
       static bool isFlat(void* button);
       // ...

       // QAbstractButtonの機能を委譲
       static void setText(void* button, const char* text) {
           QAbstractButtonBind::setText(button, text);
       }
       // ...

       // QWidgetの機能を委譲
       static void resize(void* button, int w, int h) {
           QWidgetBind::resize(button, w, h);
       }
       // ...

       // QObjectの機能を委譲
       static void setObjectName(void* button, const char* name) {
           QObjectBind::setObjectName(button, name);
       }
       // ...
   };

   #endif // Q_PUSH_BUTTON_BIND_H
   ```

2. **Bindクラスの実装**：
   - クラス固有のメソッドを実装します
   - 基底クラスへの委譲メソッドはインライン実装が多いです

   ```cpp
   // QPushButtonBind.cpp
   #include "QPushButtonBind.h"

   QPushButton* QPushButtonBind::create(QWidget* parent)
   {
       return new QPushButton(parent);
   }

   void QPushButtonBind::destroy(QPushButton* button)
   {
       delete button;
   }

   void QPushButtonBind::setFlat(void* button, bool flat)
   {
       if (button) {
           static_cast<QPushButtonHandler*>(button)->setFlat(flat);
       }
   }

   bool QPushButtonBind::isFlat(void* button)
   {
       if (button) {
           return static_cast<QPushButtonHandler*>(button)->isFlat();
       }
       return false;
   }
   ```

### 4. CAPI層の実装

1. **C言語ヘッダーの作成**：
   - C言語から呼び出せる関数を宣言します
   - 基底クラスのヘッダーをインクルードして継承関係を示します

   ```c
   // qpushbutton.h
   #ifndef QT_QPUSHBUTTON_H
   #define QT_QPUSHBUTTON_H

   #include <stdbool.h>
   #include "qabstractbutton.h" // 基底クラスのヘッダー

   #ifdef __cplusplus
   extern "C" {
   #endif

   // 作成・削除
   void* QPushButton_create(void* parent);
   void QPushButton_delete(void* button);

   // QPushButton固有の機能
   void QPushButton_setFlat(void* button, bool flat);
   bool QPushButton_isFlat(void* button);
   // ...

   // QAbstractButtonから継承した機能
   void QPushButton_setText(void* button, const char* text);
   // ...

   // QWidgetから継承した機能
   void QPushButton_resize(void* button, int w, int h);
   // ...

   // QObjectから継承した機能
   void QPushButton_setObjectName(void* button, const char* name);
   // ...

   #ifdef __cplusplus
   }
   #endif

   #endif // QT_QPUSHBUTTON_H
   ```

2. **CAPI関数の実装**：
   - Bindクラスのメソッドを呼び出す関数を実装します

   ```cpp
   // QPushButtonCAPI.cpp
   #include "QPushButtonBind.h"
   #include "qpushbutton.h"

   extern "C" {

   void* QPushButton_create(void* parent)
   {
       return QPushButtonBind::create(static_cast<QWidget*>(parent));
   }

   void QPushButton_delete(void* button)
   {
       QPushButtonBind::destroy(static_cast<QPushButton*>(button));
   }

   void QPushButton_setFlat(void* button, bool flat)
   {
       QPushButtonBind::setFlat(button, flat);
   }

   bool QPushButton_isFlat(void* button)
   {
       return QPushButtonBind::isFlat(button);
   }

   // QAbstractButtonから継承した機能
   void QPushButton_setText(void* button, const char* text)
   {
       QPushButtonBind::setText(button, text);
   }

   // QWidgetから継承した機能
   void QPushButton_resize(void* button, int w, int h)
   {
       QPushButtonBind::resize(button, w, h);
   }

   // QObjectから継承した機能
   void QPushButton_setObjectName(void* button, const char* name)
   {
       QPushButtonBind::setObjectName(button, name);
   }

   // ...

   }
   ```

## 具体的な実装例

以下に、QObjectの機能をQWidgetに継承させる具体的な実装例を示します。

### Handler層

```cpp
// QWidgetHandler.h
class QWidgetHandler : public QObjectHandler {
public:
    explicit QWidgetHandler(QWidget* widget = nullptr);
    // ...

    // QObjectHandlerのメソッドを必要に応じてオーバーライド
    void setObjectName(const QString &name) override;
    // ...
};

// QWidgetHandler.cpp
QWidgetHandler::QWidgetHandler(QWidget* widget)
    : QObjectHandler(widget), m_widget(widget)
{
}

void QWidgetHandler::setObjectName(const QString &name)
{
    // 必要に応じてQWidget固有の処理を追加
    QObjectHandler::setObjectName(name);
}
```

### Bind層

```cpp
// QWidgetBind.h
class QWidgetBind {
public:
    // QWidget固有のメソッド
    static void resize(void* widget, int w, int h);
    // ...

    // QObjectの機能を委譲
    static void setObjectName(void* widget, const char* name) {
        QObjectBind::setObjectName(widget, name);
    }
    // ...
};

// QWidgetBind.cpp
void QWidgetBind::resize(void* widget, int w, int h)
{
    if (widget) {
        static_cast<QWidgetHandler*>(widget)->resize(w, h);
    }
}
```

### CAPI層

```cpp
// QWidgetCAPI.cpp
extern "C" {

void QWidget_resize(void* widget, int w, int h)
{
    QWidgetBind::resize(widget, w, h);
}

// QObjectから継承した機能
void QWidget_setObjectName(void* widget, const char* name)
{
    QWidgetBind::setObjectName(widget, name);
}

// ...

}
```

## 継承チェーンの実装例

複数レベルの継承がある場合（例：QObject → QWidget → QPushButton）、各レベルで適切に機能を実装します。

```
QObject
  ↓
QWidget
  ↓
QAbstractButton
  ↓
QPushButton
```

この場合、QPushButtonのバインディングでは：

1. QPushButtonHandlerはQAbstractButtonHandlerを継承
2. QPushButtonBindはQAbstractButtonBindの機能を委譲
3. QPushButtonのCAPI関数はQAbstractButtonの機能も提供

同様に、QAbstractButtonのバインディングでは：

1. QAbstractButtonHandlerはQWidgetHandlerを継承
2. QAbstractButtonBindはQWidgetBindの機能を委譲
3. QAbstractButtonのCAPI関数はQWidgetの機能も提供

## トラブルシューティング

### 継承関係の問題

**問題**: 基底クラスの機能が継承先クラスで利用できない

**解決策**:
1. 継承関係が正しく実装されているか確認する
2. 基底クラスのHandlerが正しく初期化されているか確認する
3. 委譲メソッドが正しく実装されているか確認する

### キャストの問題

**問題**: キャストエラーが発生する

**解決策**:
1. 適切な型キャストを使用する（static_cast, dynamic_cast, qobject_cast）
2. ポインタの型が正しいか確認する
3. nullポインタチェックを追加する

### メモリリークの問題

**問題**: メモリリークが発生する

**解決策**:
1. 文字列などのリソースの所有権を明確にする
2. 必要に応じてスマートポインタを使用する
3. デストラクタで適切にリソースを解放する
