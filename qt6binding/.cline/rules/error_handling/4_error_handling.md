# エラー処理方針

## 4.1 エラー検出
```c
// 1. NULLチェック
void* widget = QWidget_create(NULL);
if (!widget) {
    // エラー処理
}

// 2. 戻り値チェック
int result = QWidget_someOperation(widget);
if (result < 0) {
    // エラー処理
}
```

## 4.2 エラー通知
1. エラーコードの返却
2. エラーメッセージの設定
3. コールバックによる通知
4. ログ出力

## 4.3 例外処理
```cpp
// C++側
try {
    // Qt操作
} catch (const std::exception& e) {
    // エラー状態に変換
    return NULL;  // または エラーコード
}

// C側
if (error_occurred) {
    // クリーンアップと回復処理
}
