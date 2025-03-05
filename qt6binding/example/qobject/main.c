#include "qt6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// オブジェクト名変更コールバック
void onObjectNameChanged(void *obj, const char *name)
{
    printf("オブジェクト名変更: %s\n", name);
}

// 破棄コールバック
void onDestroyed(void *obj)
{
    printf("オブジェクト破棄\n");
}

// イベントコールバック
void onEvent(void *obj, void *event)
{
    printf("イベント受信\n");
}

// 子イベントコールバック
void onChildEvent(void *obj, void *event)
{
    printf("子イベント受信\n");
}

// カスタムイベントコールバック
void onCustomEvent(void *obj, void *event)
{
    printf("カスタムイベント受信\n");
}

// タイマーイベントコールバック
void onTimerEvent(void *obj, void *event)
{
    printf("タイマーイベント受信: オブジェクト=%s\n", QObject_objectName(obj));
}

// 接続通知コールバック
void onConnectNotify(void *obj, const void *signal)
{
    printf("シグナル接続通知\n");
}

// 切断通知コールバック
void onDisconnectNotify(void *obj, const void *signal)
{
    printf("シグナル切断通知\n");
}

// イベントフィルタコールバック
bool onEventFilter(void *obj, void *watched, void *event)
{
    printf("イベントフィルタ: 監視対象=%s\n", QObject_objectName(watched));
    // falseを返すとイベントは通常通り処理される
    return false;
}

int main(int argc, char *argv[])
{
    // Qt初期化
    void *app = QApplication_create(argc, argv);
    
    printf("=== QObjectの基本機能テスト ===\n\n");
    
    // QObjectの作成
    void *obj = QObject_create(NULL);
    printf("QObjectを作成しました\n");
    
    // コールバック設定
    QObject_setObjectNameChangedCallback(obj, onObjectNameChanged);
    QObject_setDestroyedCallback(obj, onDestroyed);
    QObject_setEventCallback(obj, onEvent);
    QObject_setChildEventCallback(obj, onChildEvent);
    QObject_setCustomEventCallback(obj, onCustomEvent);
    QObject_setTimerEventCallback(obj, onTimerEvent);
    QObject_setConnectNotifyCallback(obj, onConnectNotify);
    QObject_setDisconnectNotifyCallback(obj, onDisconnectNotify);
    
    // オブジェクト名設定
    QObject_setObjectName(obj, "TestObject");
    
    // オブジェクト名取得
    const char *name = QObject_objectName(obj);
    printf("オブジェクト名: %s\n", name);
    
    // 継承関係チェック
    bool inherits = QObject_inherits(obj, "QObject");
    printf("QObjectを継承していますか: %s\n", inherits ? "はい" : "いいえ");
    
    // ウィジェットタイプチェック
    bool isWidget = QObject_isWidgetType(obj);
    printf("ウィジェットタイプですか: %s\n", isWidget ? "はい" : "いいえ");
    
    // ウィンドウタイプチェック
    bool isWindow = QObject_isWindowType(obj);
    printf("ウィンドウタイプですか: %s\n", isWindow ? "はい" : "いいえ");
    
    printf("\n=== 親子関係のテスト ===\n\n");
    
    // 子オブジェクト作成
    void *child1 = QObject_create(obj);
    QObject_setObjectName(child1, "Child1");
    
    void *child2 = QObject_create(obj);
    QObject_setObjectName(child2, "Child2");
    
    // 孫オブジェクト作成
    void *grandchild = QObject_create(child1);
    QObject_setObjectName(grandchild, "GrandChild");
    
    // 親オブジェクト取得
    void *parent = QObject_parent(child1);
    if (parent) {
        printf("Child1の親オブジェクト: %s\n", QObject_objectName(parent));
    }
    
    // 子オブジェクト取得
    int childCount = 0;
    void **children = QObject_children(obj, &childCount);
    if (children) {
        printf("子オブジェクト数: %d\n", childCount);
        for (int i = 0; i < childCount; i++) {
            if (children[i]) {
                printf("  子オブジェクト %d: %s\n", i, QObject_objectName(children[i]));
            }
        }
        free(children);
    }
    
    // 子オブジェクト検索
    void *foundChild = QObject_findChild(obj, "Child1");
    if (foundChild) {
        printf("検索で見つかった子オブジェクト: %s\n", QObject_objectName(foundChild));
    }
    
    // 再帰的に子オブジェクト検索
    void *foundGrandchild = QObject_findChild(obj, "GrandChild");
    if (foundGrandchild) {
        printf("検索で見つかった孫オブジェクト: %s\n", QObject_objectName(foundGrandchild));
    }
    
    // 複数の子オブジェクト検索
    int foundCount = 0;
    void **foundChildren = QObject_findChildren(obj, "", &foundCount);
    if (foundChildren) {
        printf("検索で見つかった全ての子オブジェクト数: %d\n", foundCount);
        for (int i = 0; i < foundCount; i++) {
            if (foundChildren[i]) {
                printf("  見つかった子オブジェクト %d: %s\n", i, QObject_objectName(foundChildren[i]));
            }
        }
        free(foundChildren);
    }
    
    printf("\n=== シグナル/スロットのテスト ===\n\n");
    
    // シグナルブロック
    bool blocked = QObject_blockSignals(obj, true);
    printf("シグナルブロック前の状態: %s\n", blocked ? "ブロック中" : "ブロックなし");
    
    bool isBlocked = QObject_signalsBlocked(obj);
    printf("シグナルブロック状態: %s\n", isBlocked ? "ブロック中" : "ブロックなし");
    
    QObject_blockSignals(obj, false);
    
    printf("\n=== タイマー機能のテスト ===\n\n");
    
    // タイマー用のオブジェクト
    void *timerObj = QObject_create(NULL);
    QObject_setObjectName(timerObj, "TimerObject");
    
    // タイマーイベントのコールバック設定
    QObject_setTimerEventCallback(timerObj, onTimerEvent);
    
    // タイマー開始
    int timerId = QObject_startTimer(timerObj, 100, 0); // 0 = Qt::CoarseTimer
    printf("タイマー開始: ID=%d\n", timerId);
    
    // すぐにタイマーを停止（実際のアプリケーションではイベントループを使用）
    QObject_killTimer(timerObj, timerId);
    printf("タイマーを停止しました\n");
    
    printf("注意: 実際のアプリケーションでは、タイマーイベントを処理するために\n");
    printf("      イベントループを実行する必要があります。\n");
    
    printf("\n=== イベントフィルタのテスト ===\n\n");
    
    // イベントフィルタ設定
    void *filterObj = QObject_create(NULL);
    QObject_setObjectName(filterObj, "EventFilter");
    
    // イベントフィルタ設定
    QObject_installEventFilter(obj, filterObj);
    printf("イベントフィルタを設定しました\n");
    
    // イベントフィルタ削除
    QObject_removeEventFilter(obj, filterObj);
    printf("イベントフィルタを削除しました\n");
    
    printf("\n=== スレッドのテスト ===\n\n");
    
    // スレッド取得
    void *thread = QObject_thread(obj);
    printf("スレッドポインタ: %p\n", thread);
    
    // スレッド移動（実際には別スレッドを作成する必要があるため、ここではデモのみ）
    bool moved = QObject_moveToThread(obj, thread);
    printf("スレッド移動: %s\n", moved ? "成功" : "失敗");
    
    printf("\n=== オブジェクト情報のテスト ===\n\n");
    
    // オブジェクトツリー表示
    printf("オブジェクトツリー:\n");
    QObject_dumpObjectTree(obj);
    
    // オブジェクト情報表示
    printf("\nオブジェクト情報:\n");
    QObject_dumpObjectInfo(obj);
    
    printf("\n=== 動的プロパティのテスト ===\n\n");
    
    // 動的プロパティ名取得
    int propCount = 0;
    char **propNames = QObject_dynamicPropertyNames(obj, &propCount);
    if (propNames) {
        printf("動的プロパティ数: %d\n", propCount);
        for (int i = 0; i < propCount; i++) {
            if (propNames[i]) {
                printf("  プロパティ名 %d: %s\n", i, propNames[i]);
                free(propNames[i]);
            }
        }
        free(propNames);
    }
    
    printf("\n=== クリーンアップ ===\n\n");
    
    
    printf("\n=== クリーンアップ ===\n\n");
    
    // クリーンアップ
    QObject_delete(timerObj);
    QObject_delete(filterObj);
    QObject_delete(obj); // 子オブジェクトも自動的に削除される
    QApplication_delete(app);
    
    printf("テスト完了\n");
    
    return 0;
}
