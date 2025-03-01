# C APIインターフェース

## 3.1 コールバック設定
```c
// 1. シグナルコールバックの設定
void Widget_setCallback(void* widget, const char* signal,
                       void (*callback)(void*, void*)) {
    auto* handler = get_handler(widget);
    handler->setCallback(signal, reinterpret_cast<void*>(callback));
}

// 2. イベントフィルタの設定
void Widget_setEventFilter(void* widget,
                         bool (*filter)(void*, void*)) {
    auto* handler = get_handler(widget);
    handler->setEventFilter(filter);
}
```

## 3.2 シグナル発行
```c
// 1. 手動シグナル発行
void Button_click(void* button) {
    auto* btn = static_cast<QAbstractButton*>(button);
    btn->click();
}

// 2. カスタムシグナル発行
void Widget_emitCustomSignal(void* widget, const char* signal,
                           void* data) {
    auto* handler = get_handler(widget);
    handler->emitSignal(signal, data);
}
```

## 3.3 C API実装パターン

### 1. コールバック設定関数
```c
// 1. 単一パラメータのコールバック
void Button_setClickedCallback(void* button,
                             void (*callback)(void*)) {
    auto* handler = get_handler(button);
    handler->setClickedCallback(callback);
}

// 2. 複数パラメータのコールバック
void Widget_setPositionChangedCallback(
    void* widget,
    void (*callback)(void*, int, int)) {
    auto* handler = get_handler(widget);
    handler->setPositionChangedCallback(callback);
}

// 3. カスタムデータ付きコールバック
void Widget_setCallbackWithData(
    void* widget,
    void (*callback)(void*, void*),
    void* user_data) {
    auto* handler = get_handler(widget);
    handler->setCallbackWithData(callback, user_data);
}
```

### 2. シグナル発行関数
```c
// 1. 基本的なシグナル発行
void Widget_emitSignal(void* widget, const char* signal) {
    auto* handler = get_handler(widget);
    handler->emitSignal(signal);
}

// 2. パラメータ付きシグナル発行
void Widget_emitSignalWithInt(void* widget,
                             const char* signal,
                             int value) {
    auto* handler = get_handler(widget);
    handler->emitSignalWithInt(signal, value);
}

// 3. 複合データのシグナル発行
void Widget_emitSignalWithStruct(
    void* widget,
    const char* signal,
    const DataStruct* data) {
    auto* handler = get_handler(widget);
    handler->emitSignalWithStruct(signal, data);
}
```

## 3.4 C API使用例

### 1. コールバックの使用
```c
// 1. コールバック関数の定義
void on_button_clicked(void* button) {
    printf("Button clicked: %p\n", button);
}

// 2. コールバックの設定
void setup_button(void* button) {
    Button_setClickedCallback(button, on_button_clicked);
}

// 3. 複数パラメータのコールバック
void on_position_changed(void* widget, int x, int y) {
    printf("Position changed: %d, %d\n", x, y);
}

void setup_widget(void* widget) {
    Widget_setPositionChangedCallback(widget,
                                    on_position_changed);
}
```

### 2. シグナル発行の使用
```c
// 1. 基本的なシグナル発行
void trigger_button(void* button) {
    Button_click(button);  // クリックシグナルを発行
}

// 2. カスタムシグナルの発行
void trigger_custom_signal(void* widget) {
    DataStruct data = {1, "test"};
    Widget_emitSignalWithStruct(widget, "customSignal", &data);
}
```

## 3.5 C APIのガイドライン

### 1. コールバック設計
- 型安全性の確保
- エラー処理の追加
- リソース管理の考慮
- デバッグ情報の提供

### 2. シグナル発行
- パラメータの検証
- エラー状態の伝播
- スレッド安全性の確保
- パフォーマンスの最適化

### 3. メモリ管理
- リソースリークの防止
- 所有権の明確化
- クリーンアップの保証
- 循環参照の防止

### 4. エラー処理
- NULLポインタのチェック
- 型変換の検証
- エラー状態の通知
- リカバリ処理の実装
