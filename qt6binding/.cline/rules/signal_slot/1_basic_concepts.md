# シグナル・スロットの基本概念

## 1.1 シグナル/スロットの対応
```cpp
// C++側のシグナル/スロット
class QButtonBind : public QPushButton {
    Q_OBJECT
signals:
    void clicked(bool checked = false);
public slots:
    void onClicked(bool checked);
};

// C側のコールバック
typedef void (*ButtonCallback)(void* sender, bool checked);
```

## 1.2 コールバック管理
```cpp
// 1. コールバック保持
class CallbackHolder {
    std::unordered_map<std::string, void*> callbacks;
public:
    void setCallback(const std::string& signal, void* callback) {
        callbacks[signal] = callback;
    }
    
    void* getCallback(const std::string& signal) {
        auto it = callbacks.find(signal);
        return (it != callbacks.end()) ? it->second : nullptr;
    }
};

// 2. コールバックディスパッチ
void dispatch_callback(void* sender, const char* signal, void* data) {
    auto* holder = get_callback_holder(sender);
    if (auto callback = holder->getCallback(signal)) {
        reinterpret_cast<void (*)(void*, void*)>(callback)(sender, data);
    }
}
```

## 1.3 シグナル/スロットの基本パターン

### 1. シグナルの定義
```cpp
// 1. 基本的なシグナル
signals:
    void valueChanged(int value);
    void stateChanged(bool state);
    void textChanged(const QString& text);

// 2. パラメータなしのシグナル
signals:
    void clicked();
    void pressed();
    void released();

// 3. 複数パラメータのシグナル
signals:
    void itemSelected(int row, int column);
    void rangeChanged(int min, int max);
    void dataChanged(const QModelIndex& topLeft,
                    const QModelIndex& bottomRight);
```

### 2. スロットの定義
```cpp
// 1. パブリックスロット
public slots:
    void setValue(int value);
    void setText(const QString& text);
    void setEnabled(bool enabled);

// 2. プロテクテッドスロット
protected slots:
    void updateDisplay();
    void handleError(const QString& message);

// 3. プライベートスロット
private slots:
    void cleanup();
    void initialize();
```

## 1.4 シグナル/スロットの接続パターン

### 1. 直接接続
```cpp
// 1. 基本的な接続
connect(sender, SIGNAL(valueChanged(int)),
        receiver, SLOT(handleValue(int)));

// 2. 新しい構文での接続
connect(sender, &Sender::valueChanged,
        receiver, &Receiver::handleValue);

// 3. ラムダ式での接続
connect(sender, &Sender::valueChanged,
        [](int value) {
            // 値の処理
        });
```

### 2. キューイング接続
```cpp
// 1. キューイング接続の指定
connect(sender, &Sender::valueChanged,
        receiver, &Receiver::handleValue,
        Qt::QueuedConnection);

// 2. 自動接続タイプの選択
connect(sender, &Sender::valueChanged,
        receiver, &Receiver::handleValue,
        Qt::AutoConnection);
```

## 1.5 シグナル/スロットのガイドライン

### 1. シグナルの設計
- 意味のある名前を使用
- 必要な情報のみを送信
- 適切なパラメータ型を選択
- ドキュメントを提供

### 2. スロットの設計
- 単一責任の原則に従う
- エラー処理を含める
- パフォーマンスを考慮
- 再入可能性を確保

### 3. 接続の管理
- 適切な接続タイプを選択
- メモリリークを防止
- 循環参照を避ける
- デバッグ情報を提供

### 4. エラー処理
- シグナル発行の失敗を処理
- スロット実行の失敗を処理
- 接続エラーを検出
- リソースのクリーンアップ
