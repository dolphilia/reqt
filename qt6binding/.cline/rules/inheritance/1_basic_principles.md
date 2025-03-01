# 基本原則

## 1.1 継承階層の設計
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

## 1.2 継承チェーン
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
