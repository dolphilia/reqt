# Qt6バインディング 実装パターン

## 1. バインディングクラスの実装パターン

### 1.1 基本構造
```cpp
// [QtClass]Bind.h
class Bind[QtClass] : public [QtClass] {
    Q_OBJECT  // シグナル/スロットを使用する場合

public:
    explicit Bind[QtClass]([QtClass] *parent = nullptr);
    ~Bind[QtClass]();

    // Qtメソッドのラッパー
    void someMethod();

    // Handlerの設定（必要な場合）
    void setHandler([QtClass]Handler *handler);
    [QtClass]Handler *handler() const;

private:
    [QtClass]Handler *m_handler;  // 必要な場合
};
```

### 1.2 実装例
```cpp
// QPushButtonBind.h
class BindQPushButton : public QPushButton {
    Q_OBJECT
public:
    explicit BindQPushButton(QWidget *parent = nullptr);
    ~BindQPushButton();

    void setHandler(QPushButtonHandler *handler);
    QPushButtonHandler *handler() const;

private:
    QPushButtonHandler *m_handler;
};
```

## 2. ハンドラクラスの実装パターン

### 2.1 基本構造
```cpp
// [QtClass]Handler.h
class [QtClass]Handler : public QObject {
    Q_OBJECT
public:
    explicit [QtClass]Handler(QObject *parent = nullptr);
    ~[QtClass]Handler();

    // コールバック設定メソッド
    void setSignalCallback([QtClass]SignalCallback callback);

public slots:
    void onSignal();  // シグナル受信用スロット

private:
    [QtClass]SignalCallback m_signalCallback;
};
```

### 2.2 実装例
```cpp
// QTextEditHandler.h
class TextEditHandler : public QObject {
    Q_OBJECT
public:
    explicit TextEditHandler(QObject *parent = nullptr);
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
```

## 3. C API実装パターン

### 3.1 基本構造
```cpp
// [QtClass]CAPI.cpp
extern "C" {
    // オブジェクト作成/削除
    void* [QtClass]_create(void* parent) {
        return new Bind[QtClass](reinterpret_cast<[QtClass]*>(parent));
    }

    void [QtClass]_delete(void* ptr) {
        delete static_cast<Bind[QtClass]*>(ptr);
    }

    // メソッド呼び出し
    void [QtClass]_someMethod(void* ptr) {
        static_cast<Bind[QtClass]*>(ptr)->someMethod();
    }

    // コールバック設定
    void [QtClass]_setSignalCallback(void* ptr, [QtClass]SignalCallback callback) {
        auto* obj = static_cast<Bind[QtClass]*>(ptr);
        [QtClass]Handler* handler = obj->handler();
        if (!handler) {
            handler = new [QtClass]Handler(obj);
            obj->setHandler(handler);
        }
        handler->setSignalCallback(callback);
    }
}
```

### 3.2 実装例
```cpp
// QTextEditCAPI.cpp
extern "C" {
    void* QTextEdit_create(void* parent) {
        return new BindQTextEdit(reinterpret_cast<QWidget*>(parent));
    }

    void QTextEdit_setText(void* text_edit, const char* text) {
        static_cast<BindQTextEdit*>(text_edit)->setText(
            QString::fromUtf8(text)
        );
    }

    void QTextEdit_setTextChangedCallback(
        void* text_edit,
        void (*callback)()
    ) {
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

## 4. 継承関係の実装パターン

### 4.1 基本パターン
```cpp
// 基底クラス
class BindQWidget : public QWidget {
    Q_OBJECT
public:
    // 共通機能
};

// 派生クラス
class BindQPushButton : public QPushButton {
    Q_OBJECT
public:
    // 追加機能
};
```

### 4.2 実装例
```cpp
// QAbstractButtonBind.h → QPushButtonBind.h
class BindQAbstractButton : public QAbstractButton {
    Q_OBJECT
public:
    void setClickCallback(void (*callback)());
protected:
    QAbstractButtonHandler *m_handler;
};

class BindQPushButton : public QPushButton {
    Q_OBJECT
public:
    // QPushButton固有の機能
    using BindQAbstractButton::setClickCallback;
};
```

## 5. シグナル/スロット実装パターン

### 5.1 基本パターン
```cpp
// ハンドラでシグナルを受信
class Handler : public QObject {
    Q_OBJECT
public:
    void setCallback(void (*callback)());

public slots:
    void onSignal() {
        if (m_callback) m_callback();
    }

private:
    void (*m_callback)();
};

// バインディングクラスでシグナルを接続
class Binding : public QObject {
    Q_OBJECT
public:
    void setupConnections() {
        connect(this, SIGNAL(signal()),
                m_handler, SLOT(onSignal()));
    }
};
```

### 5.2 実装例
```cpp
// QPushButtonHandler
void QPushButtonHandler::setClickCallback(void (*callback)()) {
    m_clickCallback = callback;
}

void QPushButtonHandler::onClick() {
    if (m_clickCallback) m_clickCallback();
}

// QPushButtonBind
BindQPushButton::BindQPushButton(QWidget *parent)
    : QPushButton(parent)
{
    connect(this, SIGNAL(clicked()),
            m_handler, SLOT(onClick()));
}
```

## 6. エラー処理パターン

### 6.1 NULLチェックパターン
```cpp
void* ptr = [QtClass]_create(parent);
if (!ptr) {
    // エラー処理
    return NULL;
}
```

### 6.2 例外処理パターン
```cpp
extern "C" void* [QtClass]_someOperation(void* ptr) {
    try {
        auto* obj = static_cast<Bind[QtClass]*>(ptr);
        return obj->someOperation();
    } catch (const std::exception& e) {
        // エラー状態に変換
        return NULL;
    }
}
```

## 7. メモリ管理パターン

### 7.1 リソース確保パターン
```cpp
// 1. 単一リソース
void* obj = [QtClass]_create(NULL);
if (!obj) return NULL;
// 使用
[QtClass]_delete(obj);

// 2. 複数リソース
void* obj1 = [QtClass1]_create(NULL);
if (!obj1) return NULL;

void* obj2 = [QtClass2]_create(obj1);
if (!obj2) {
    [QtClass1]_delete(obj1);
    return NULL;
}
```

### 7.2 文字列管理パターン
```cpp
// 文字列の取得
const char* str = [QtClass]_getText(ptr);
// 使用
// 注: 次のAPI呼び出しまで有効

// 文字列の設定
[QtClass]_setText(ptr, "text");
// 注: 内部でコピーを作成
```

## 8. テストパターン

### 8.1 基本テストパターン
```c
void test_widget_creation() {
    void* widget = QWidget_create(NULL);
    assert(widget != NULL);
    QWidget_delete(widget);
}
```

### 8.2 コールバックテストパターン
```c
static bool callback_called = false;

void test_callback(void* ptr) {
    callback_called = true;
}

void test_signal_emission() {
    void* button = QPushButton_create(NULL);
    QPushButton_setClickCallback(button, test_callback);
    
    // シグナルのエミュレート
    QPushButton_click(button);
    
    assert(callback_called);
    QPushButton_delete(button);
}
