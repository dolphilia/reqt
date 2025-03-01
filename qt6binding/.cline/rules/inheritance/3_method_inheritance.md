# メソッドの継承

## 3.1 仮想関数の実装
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

## 3.2 シグナル/スロットの継承
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
