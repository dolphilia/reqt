# バインディングクラスの実装パターン

## 1.1 基本構造
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

## 1.2 実装例
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

## 1.3 実装のポイント
1. 継承関係
   - 対象のQtクラスを直接継承
   - 必要に応じてQ_OBJECTマクロを使用
   - 複数継承は避ける

2. メンバ構成
   - コンストラクタ/デストラクタ
   - ラッパーメソッド
   - ハンドラ管理
   - プライベートメンバ

3. 命名規則
   - クラス名は「Bind[QtClass]」
   - メソッド名はQt準拠
   - メンバ変数は「m_」プレフィックス
