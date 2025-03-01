# C APIの実装

## 4.1 基底クラスのAPI
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

## 4.2 派生クラスのAPI
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
