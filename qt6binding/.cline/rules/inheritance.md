# 継承関係実装ガイドライン

## 1. 基本原則

### 1.1 継承階層の設計
```cpp
// 1. 基底クラスインターフェース
class BindQObject {
public:
    virtual ~BindQObject() = default;
    virtual void* handle() const = 0;
    virtual void setParent(void* parent) = 0;
    virtual const char* className() const = 0;
};

// 2. 基本実装
class BindQWidget : public QWidget, public BindQObject {
public:
    void* handle() const override { return (void*)this; }
    void setParent(void* parent) override {
        QWidget::setParent(static_cast<QWidget*>(parent));
    }
    const char* className() const override {
        return "QWidget";
    }
};
```

### 1.2 継承チェーン
```cpp
// 1. 継承チェーンの定義
class BindQAbstractButton : public QAbstractButton,
                          public BindQWidget {
public:
    using QAbstractButton::QAbstractButton;
    const char* className() const override {
        return "QAbstractButton";
    }
};

class BindQPushButton : public QPushButton,
                       public BindQAbstractButton {
public:
    using QPushButton::QPushButton;
    const char* className() const override {
        return "QPushButton";
    }
};
```

## 2. 型変換と検証

### 2.1 ダウンキャスト
```cpp
// 1. 安全なダウンキャスト
template<typename T>
T* safe_cast(void* ptr) {
    if (!ptr) return nullptr;
    
    auto* obj = static_cast<BindQObject*>(ptr);
    if (auto* cast = dynamic_cast<T*>(obj)) {
        return cast;
    }
    return nullptr;
}

// 2. 型チェック
bool is_type(void* ptr, const char* type) {
    if (!ptr) return false;
    
    auto* obj = static_cast<BindQObject*>(ptr);
    return strcmp(obj->className(), type) == 0;
}
```

### 2.2 型情報の管理
```cpp
// 1. 型情報レジストリ
class TypeRegistry {
    static std::unordered_map<std::string,
                             std::vector<std::string>> inheritance_map;
public:
    static void registerInheritance(const std::string& derived,
                                  const std::string& base) {
        inheritance_map[derived].push_back(base);
    }
    
    static bool isSubclassOf(const std::string& derived,
                            const std::string& base) {
        auto it = inheritance_map.find(derived);
        if (it == inheritance_map.end()) return false;
        
        const auto& bases = it->second;
        return std::find(bases.begin(), bases.end(),
                        base) != bases.end();
    }
};

// 2. 型情報の登録
void register_types() {
    TypeRegistry::registerInheritance("QPushButton",
                                    "QAbstractButton");
    TypeRegistry::registerInheritance("QAbstractButton",
                                    "QWidget");
    TypeRegistry::registerInheritance("QWidget",
                                    "QObject");
}
```

## 3. メソッドの継承

### 3.1 仮想関数の実装
```cpp
// 1. 純粋仮想関数
class BindQAbstractButton : public QAbstractButton {
protected:
    void paintEvent(QPaintEvent* event) override {
        // デフォルトの実装
        QStylePainter painter(this);
        QStyleOptionButton option;
        initStyleOption(&option);
        painter.drawControl(QStyle::CE_PushButton, option);
    }
};

// 2. 仮想関数のオーバーライド
class BindQPushButton : public QPushButton {
protected:
    bool event(QEvent* event) override {
        // カスタムイベント処理
        if (event->type() == QEvent::Type::User) {
            handleCustomEvent(event);
            return true;
        }
        return QPushButton::event(event);
    }
};
```

### 3.2 シグナル/スロットの継承
```cpp
// 1. 基底クラスのシグナル
class BindQAbstractButton : public QAbstractButton {
    Q_OBJECT
signals:
    void clicked(bool checked = false);
    void pressed();
    void released();
};

// 2. 派生クラスでのシグナル処理
class BindQPushButton : public QPushButton {
    Q_OBJECT
private slots:
    void onClicked(bool checked) {
        // 基底クラスのシグナルを処理
        if (m_clickCallback) {
            m_clickCallback(this, checked);
        }
    }
};
```

## 4. C APIの実装

### 4.1 基底クラスのAPI
```c
// 1. 共通関数
void* QObject_create() {
    return new BindQObject();
}

void QObject_delete(void* obj) {
    delete static_cast<BindQObject*>(obj);
}

void QObject_setParent(void* obj, void* parent) {
    auto* object = static_cast<BindQObject*>(obj);
    object->setParent(parent);
}

// 2. 型チェック関数
bool QObject_isWidget(void* obj) {
    return dynamic_cast<QWidget*>(
        static_cast<BindQObject*>(obj)) != nullptr;
}
```

### 4.2 派生クラスのAPI
```c
// 1. 特殊化された関数
void* QPushButton_create(void* parent) {
    auto* button = new BindQPushButton(
        static_cast<QWidget*>(parent));
    button->setParent(parent);
    return button;
}

void QPushButton_setText(void* button, const char* text) {
    if (auto* btn = safe_cast<BindQPushButton>(button)) {
        btn->setText(QString::fromUtf8(text));
    }
}

// 2. 継承されたメソッドのラッパー
void QPushButton_show(void* button) {
    // QWidgetから継承したshow()の呼び出し
    if (auto* btn = safe_cast<BindQPushButton>(button)) {
        btn->show();
    }
}
```

## 5. メモリ管理

### 5.1 所有権の管理
```cpp
// 1. 親子関係の管理
void set_parent_ownership(void* child, void* parent) {
    if (auto* c = safe_cast<BindQObject>(child)) {
        c->setParent(parent);
    }
}

// 2. 自動削除の管理
class AutoDeleteHandler : public QObject {
public:
    explicit AutoDeleteHandler(QObject* target)
        : m_target(target) {
        target->setParent(this);
    }
    
    ~AutoDeleteHandler() {
        delete m_target;
    }

private:
    QObject* m_target;
};
```

### 5.2 リソースの解放
```cpp
// 1. 階層的な解放
void delete_widget_hierarchy(void* widget) {
    if (auto* w = safe_cast<BindQWidget>(widget)) {
        // 子ウィジェットは自動的に削除される
        delete w;
    }
}

// 2. 参照カウントの管理
class RefCountedWidget : public BindQWidget {
    std::atomic<int> ref_count{1};
public:
    void addRef() {
        ref_count.fetch_add(1, std::memory_order_relaxed);
    }
    
    void release() {
        if (ref_count.fetch_sub(1,
            std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }
};
```

## 6. デバッグサポート

### 6.1 継承関係の検証
```cpp
// 1. 継承チェーン検証
class InheritanceValidator {
public:
    static bool validateChain(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        std::vector<std::string> chain;
        
        while (base) {
            chain.push_back(base->className());
            base = dynamic_cast<BindQObject*>(
                base->parent());
        }
        
        return validateChainIntegrity(chain);
    }

private:
    static bool validateChainIntegrity(
        const std::vector<std::string>& chain) {
        for (size_t i = 0; i < chain.size() - 1; ++i) {
            if (!TypeRegistry::isSubclassOf(
                chain[i], chain[i + 1])) {
                return false;
            }
        }
        return true;
    }
};

// 2. メモリレイアウト検証
class LayoutValidator {
public:
    static bool validateLayout(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        
        // QObjectオフセットの検証
        auto* qobj = dynamic_cast<QObject*>(base);
        if (!qobj) return false;
        
        // QWidgetオフセットの検証
        if (auto* widget = dynamic_cast<QWidget*>(base)) {
            if (static_cast<void*>(qobj) !=
                static_cast<void*>(widget)) {
                return false;
            }
        }
        
        return true;
    }
};
```

### 6.2 継承関係のトレース
```cpp
// 1. 継承チェーンの出力
void dump_inheritance_chain(void* obj) {
    auto* base = static_cast<BindQObject*>(obj);
    std::vector<std::string> chain;
    
    while (base) {
        chain.push_back(base->className());
        base = dynamic_cast<BindQObject*>(
            base->parent());
    }
    
    qDebug() << "Inheritance chain:";
    for (const auto& type : chain) {
        qDebug() << " -" << type.c_str();
    }
}

// 2. 仮想関数テーブルの検証
class VTableValidator {
public:
    static bool validateVTable(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        
        // 仮想関数の呼び出しテスト
        bool handle_valid = base->handle() != nullptr;
        bool classname_valid = base->className() != nullptr;
        
        // 派生クラス固有の仮想関数テスト
        if (auto* widget = dynamic_cast<QWidget*>(base)) {
            bool event_valid = widget->event(nullptr) == false;
            return handle_valid && classname_valid &&
                   event_valid;
        }
        
        return handle_valid && classname_valid;
    }
};
```

## 7. 継承メソッドの実装パターン

### 7.1 基本原則
```markdown
1. 継承の扱い
   - Qt6クラスの多くはQObjectやQWidgetなどを継承している
   - C言語では継承を直接表現できない
   - 継承元のメソッドもバインディングに含める必要がある

2. コード効率化
   - すべてのメソッドを再実装せず、継承元の関数を活用
   - 既存のバインディング関数をラップして再利用
   - 重複コードを最小限に抑える
```

### 7.2 実装パターン
```c
// 1. 継承元の関数を直接利用
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    // QWidgetの関数を再利用
    QWidget_setStyleSheet(button, styleSheet);
}

// 2. 型変換を含む実装
void QDialog_setLayout(void* dialog, void* layout) {
    // QWidgetのメソッドを利用
    QWidget_setLayout(dialog, layout);
}

// 3. 追加処理が必要な場合
void QMainWindow_setMenuBar(void* window, void* menuBar) {
    // 型チェックと追加処理
    if (!is_type(window, "QMainWindow")) return;
    QWidget_setParent(menuBar, window);  // 継承元の処理
    // QMainWindow固有の処理
    static_cast<QMainWindow*>(window)->setMenuBar(
        static_cast<QMenuBar*>(menuBar));
}
```

### 7.3 実装例
```cpp
// 1. スタイルシートの設定
// QWidget（基底クラス）の実装
void QWidget_setStyleSheet(void* widget, const char* styleSheet) {
    if (auto* w = safe_cast<QWidget>(widget)) {
        w->setStyleSheet(QString::fromUtf8(styleSheet));
    }
}

// QPushButton（派生クラス）の実装
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    // 基底クラスの関数を再利用
    QWidget_setStyleSheet(button, styleSheet);
}

// 2. イベントハンドリング
// QWidget（基底クラス）の実装
void QWidget_show(void* widget) {
    if (auto* w = safe_cast<QWidget>(widget)) {
        w->show();
    }
}

// QDialog（派生クラス）の実装
void QDialog_show(void* dialog) {
    // 基底クラスの関数を再利用
    QWidget_show(dialog);
}
```

### 7.4 実装の選択基準
```markdown
1. 直接再利用
   - 継承元の実装で十分な場合
   - 追加の処理が不要な場合
   - 型変換のみが必要な場合

2. ラッパー実装
   - 追加の検証が必要な場合
   - エラー処理を追加する場合
   - パラメータの変換が必要な場合

3. 完全な再実装
   - 派生クラス固有の処理が必要な場合
   - 継承元の動作を変更する場合
   - パフォーマンスの最適化が必要な場合
```

### 7.5 実装のガイドライン
```markdown
1. 基本方針
   - 可能な限り継承元の関数を再利用
   - 重複コードを避ける
   - 保守性を重視

2. 実装手順
   - 継承元の機能を確認
   - 必要な追加処理を特定
   - 適切な実装パターンを選択

3. 注意点
   - 型の安全性を確保
   - エラー処理を適切に実装
   - パフォーマンスを考慮
```

### 7.6 ドキュメント例
```c
/**
 * @brief スタイルシートを設定
 * 
 * この関数は QWidget::setStyleSheet() の機能を利用します。
 * QPushButtonはQWidgetを継承しているため、QWidget_setStyleSheet
 * を再利用することで実装を簡素化しています。
 *
 * @param button QPushButtonのポインタ
 * @param styleSheet 設定するスタイルシート
 * 
 * @note この実装はQWidgetの機能を直接利用するため、
 * QPushButton固有の追加処理は行いません。
 */
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    QWidget_setStyleSheet(button, styleSheet);
}
