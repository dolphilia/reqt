# スレッド安全性

## 6.1 基本原則
- メインスレッドでのGUI操作
- スレッドセーフなリソース管理
- 排他制御の実装

## 6.2 実装方針
1. スレッド間通信の制御
   - シグナル/スロットを利用した安全な通信
   - イベントキューによるメッセージング
   - スレッド間の同期制御

2. リソースの適切なロック
   - ミューテックスによる保護
   - リードライトロック
   - アトミック操作

3. スレッドセーフなコールバック
   - メインスレッドでの実行保証
   - コールバックキューの管理
   - 再入可能な実装

4. デッドロック防止
   - ロック順序の一貫性
   - タイムアウトの設定
   - デッドロック検出機構

## 6.3 実装例
```cpp
// スレッドセーフなコールバック実行
void invoke_callback(void* obj, Callback cb) {
    if (QThread::currentThread() == qApp->thread()) {
        // メインスレッドなら直接実行
        cb(obj);
    } else {
        // 別スレッドならメインスレッドにポスト
        QMetaObject::invokeMethod(qApp, [=]() {
            cb(obj);
        }, Qt::QueuedConnection);
    }
}
