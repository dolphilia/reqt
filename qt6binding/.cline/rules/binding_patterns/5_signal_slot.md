# シグナル/スロット実装パターン

## 5.1 基本パターン
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

## 5.2 実装例
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

## 5.3 実装のポイント
1. シグナル定義
   - シグナルの引数型
   - シグナルの発行タイミング
   - シグナルの伝播

2. スロット実装
   - スロットの引数処理
   - スロットの実行コンテキスト
   - スロットのエラー処理

3. コールバック管理
   - コールバック関数の型定義
   - コールバックの登録/解除
   - コールバックの実行制御

4. スレッド考慮
   - シグナルの接続タイプ
   - スレッド間通信
   - 同期/非同期実行
