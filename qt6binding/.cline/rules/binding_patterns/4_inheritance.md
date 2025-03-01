# 継承関係の実装パターン

## 4.1 基本パターン
```cpp
// 基底クラス
class BindQWidget : public QWidget {
    Q_OBJECT
public:
    // 共通機能
    void setEnabled(bool enabled);
    bool isEnabled() const;
    // ...
protected:
    // 派生クラスで使用する機能
    QWidgetHandler* handler() const;
private:
    QWidgetHandler* m_handler;
};

// 派生クラス
class BindQPushButton : public QPushButton {
    Q_OBJECT
public:
    // 追加機能
    void setText(const QString& text);
    QString text() const;
    // ...
};
```

## 4.2 実装例
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

## 4.3 実装のポイント
1. 継承階層の設計
   - 共通機能の抽出
   - インターフェースの一貫性
   - 適切な抽象化レベル

2. メソッドの継承
   - 基底クラスのメソッド再利用
   - 仮想関数のオーバーライド
   - using宣言の活用

3. メンバ変数の管理
   - protected メンバの利用
   - private メンバのカプセル化
   - 継承先での拡張

4. シグナル/スロットの継承
   - 基底クラスのシグナル再利用
   - 新しいシグナルの追加
   - コールバック管理の継承
