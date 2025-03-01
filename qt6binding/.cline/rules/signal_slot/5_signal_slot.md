# シグナル/スロット処理

## 5.1 コールバック定義
```c
// 1. コールバック関数型
typedef void (*ButtonClickCallback)(void* button);

// 2. コールバック設定
void QPushButton_setClickCallback(
    void* button,
    ButtonClickCallback callback
);
```

## 5.2 イベント処理フロー
1. Qt シグナル発生
2. Handler クラスがシグナルを受信
3. 登録されたコールバックを呼び出し
4. C言語側で処理を実行

## 5.3 実装例
```cpp
// C++側（Handler）
class QPushButtonHandler : public QObject {
    Q_OBJECT
public:
    void setClickCallback(ButtonClickCallback cb) {
        m_callback = cb;
    }

public slots:
    void onClick() {
        if (m_callback) {
            m_callback(m_button);
        }
    }

private:
    ButtonClickCallback m_callback;
    QPushButton* m_button;
};

// C側（使用例）
void onButtonClick(void* button) {
    // クリック時の処理
}

void setup() {
    void* button = QPushButton_create(NULL);
    QPushButton_setClickCallback(button, onButtonClick);
}
