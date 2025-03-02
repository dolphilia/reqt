# バインディング作成のガイドライン

## 1. バインディングクラスとそのヘッダー作成用資料

このドキュメントは、Qt6の既存クラスを直接継承し、Cバインディング用のラッパー機能やハンドラ管理機能を付加するバインディングクラスの作成方法について説明します。

### 1.1 基本構造

バインディングクラスは元のQtクラスを直接継承し、必要に応じてQ_OBJECTマクロを使用してシグナル/スロット機能を実装します。また、ハンドラクラスへの委譲機能を持たせる場合は、専用のメンバ変数とsetter/getterを実装します。

```cpp
// Bind[QtClass].h
#ifndef BIND_##[QTCLASS]_H
#define BIND_##[QTCLASS]_H

#include <[QtClass].h>               // 元のQtクラスのヘッダー
#include "[QtClass]Handler.h"        // 必要に応じてハンドラクラスのヘッダー

class Bind[QtClass] : public [QtClass] {
    Q_OBJECT  // シグナル/スロット利用時に必要

public:
    explicit Bind[QtClass]([QtClass]* parent = nullptr);
    ~Bind[QtClass]();

    // Qtの機能をラップするメソッド
    void someMethod();

    // ハンドラの設定と取得（必要な場合）
    void setHandler([QtClass]Handler* handler);
    [QtClass]Handler* handler() const;

private:
    [QtClass]Handler* m_handler;  // ハンドラクラスのインスタンスを保持
};

#endif // BIND_##[QTCLASS]_H
```

### 1.2 実装例

以下は、`QPushButton`のバインディングクラスの実装例です。

```cpp
// BindQPushButton.h
#ifndef BIND_QPUSHBUTTON_H
#define BIND_QPUSHBUTTON_H

#include <QPushButton>
#include "QPushButtonHandler.h"

class BindQPushButton : public QPushButton {
    Q_OBJECT

public:
    explicit BindQPushButton(QWidget* parent = nullptr);
    ~BindQPushButton();

    void setHandler(QPushButtonHandler* handler);
    QPushButtonHandler* handler() const;

private:
    QPushButtonHandler* m_handler;
};

#endif // BIND_QPUSHBUTTON_H
```

### 1.3 実装のポイント

- **継承関係**  
  - 対象のQtクラスを直接継承する。  
  - Q_OBJECTマクロを必要に応じて使用し、シグナル／スロットを有効にする。  
  - 複数継承は避ける。

- **メンバ構成**  
  - コンストラクタ／デストラクタでリソースを適切に管理する。  
  - Qtメソッドのラッパーとして、必要な機能を追加実装する。  
  - ハンドラ管理用のsetter/getterとプライベートメンバを実装する。

- **命名規則**  
  - クラス名は「Bind[QtClass]」とする。  
  - メソッド名はQtの規約に沿った名称を採用する。  
  - メンバ変数は「m_」で始める。

---

## 2. ハンドラクラスとそのヘッダー作成用資料

このドキュメントは、Qt6のシグナル／スロット機構をCバインディング側に提供するためのハンドラクラスの実装およびヘッダー作成方法を説明します。

### 2.1 基本構造

ハンドラクラスは、QObjectを継承し、コールバック関数ポインタをメンバ変数として管理します。シグナル受信用のスロットを実装し、Qtからの通知をC API側のコールバックへ伝達します。

```cpp
// [QtClass]Handler.h
#ifndef [QTCLASS]_HANDLER_H
#define [QTCLASS]_HANDLER_H

#include <QObject>

typedef void (*[QtClass]SignalCallback)();

class [QtClass]Handler : public QObject {
    Q_OBJECT
public:
    explicit [QtClass]Handler(QObject* parent = nullptr);
    ~[QtClass]Handler();

    // コールバック設定メソッド
    void setSignalCallback([QtClass]SignalCallback callback);

public slots:
    // シグナル受信用スロット
    void onSignal();

private:
    [QtClass]SignalCallback m_signalCallback;
};

#endif // [QTCLASS]_HANDLER_H
```

### 2.2 実装例

以下は、`QTextEdit`用のハンドラクラスの実装例です。

```cpp
// QTextEditHandler.h
#ifndef QTEXTEDIT_HANDLER_H
#define QTEXTEDIT_HANDLER_H

#include <QObject>

class TextEditHandler : public QObject {
    Q_OBJECT
public:
    explicit TextEditHandler(QObject* parent = nullptr);
    ~TextEditHandler();

    void setTextChangedCallback(void (*callback)());
    void setCursorPositionChangedCallback(void (*callback)());

public slots:
    void onTextChanged();
    void onCursorPositionChanged();

private:
    void (*m_textChangedCallback)();
    void (*m_cursorPositionChangedCallback)();
};

#endif // QTEXTEDIT_HANDLER_H
```

### 2.3 実装のポイント

- **基本構成**  
  - `QObject`を継承し、Q_OBJECTマクロを必ず使用する。  
  - コールバック関数ポインタをメンバ変数として保持し、NULLチェックを行う。

- **シグナル受信用スロット**  
  - Qtシグナルを受信して、対応するコールバックを実行する。  
  - 複数のシグナルに対応する場合、各スロットを個別に実装する。

- **スレッド安全性とメモリ管理**  
  - コールバックの安全な呼び出しと、親オブジェクトによる自動削除を利用する。  
  - リソースのクリーンアップや、例外発生時の適切な処理を行う。

---

## 3. C APIとその公開ヘッダー作成用資料

このドキュメントは、Qt6のバインディングクラスをC言語から利用可能にするためのC APIおよび公開ヘッダーの作成方法を説明します。

### 3.1 基本構造

C APIは、C++側で実装されたバインディングクラスのインスタンス生成、メソッド呼び出し、コールバック設定などをC言語のインターフェースとして公開します。extern "C" ブロック内に実装することで、名前修飾を抑制します。

#### 公開ヘッダー例

```cpp
// [QtClass]CAPI.h
#ifndef [QTCLASS]_CAPI_H
#define [QTCLASS]_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

// オブジェクト作成／削除
void* [QtClass]_create(void* parent);
void  [QtClass]_delete(void* ptr);

// メソッド呼び出し
void [QtClass]_someMethod(void* ptr);

// コールバック設定
void [QtClass]_setSignalCallback(void* ptr, [QtClass]SignalCallback callback);

#ifdef __cplusplus
}
#endif

#endif // [QTCLASS]_CAPI_H
```

### 3.2 実装例

以下は、`QTextEdit`用のC API実装例です。

```cpp
// QTextEditCAPI.cpp
#include "QTextEditCAPI.h"
#include "BindQTextEdit.h"
#include "TextEditHandler.h"
#include <QString>

extern "C" {

void* QTextEdit_create(void* parent) {
    return new BindQTextEdit(reinterpret_cast<QWidget*>(parent));
}

void QTextEdit_delete(void* ptr) {
    delete static_cast<BindQTextEdit*>(ptr);
}

void QTextEdit_setText(void* text_edit, const char* text) {
    static_cast<BindQTextEdit*>(text_edit)->setText(QString::fromUtf8(text));
}

void QTextEdit_setTextChangedCallback(void* text_edit, void (*callback)()) {
    auto* edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new TextEditHandler(edit);
        edit->setTextEditHandler(handler);
    }
    handler->setTextChangedCallback(callback);
}

}
```

### 3.3 実装のポイント

- **関数命名規則**  
  - クラス名とメソッド名をアンダースコアで区切る。  
  - 動詞で始まる命名（create, delete, setなど）を採用し、get/setプレフィックスを明示的に使用する。

- **型変換とエラーチェック**  
  - `void*`を適切なバインディングクラス型にキャストする。  
  - NULLポインタや不正な引数に対するチェックを実装する。

- **メモリ管理**  
  - オブジェクトの生成と解放を明確にし、リソースリークを防止する。  
  - 内部で生成された一時オブジェクトや親子関係の管理を徹底する。