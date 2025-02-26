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
    // イベントタイプの表示はここでは簡易的に実装
    printf("イベント受信\n");
}

int main(int argc, char *argv[])
{
    // Qt初期化
    void *app = QApplication_create(argc, argv);
    
    // QObjectの作成
    void *obj = QObject_create(NULL);
    printf("QObjectを作成しました\n");
    
    // コールバック設定
    QObject_setObjectNameChangedCallback(obj, onObjectNameChanged);
    QObject_setDestroyedCallback(obj, onDestroyed);
    QObject_setEventCallback(obj, onEvent);
    
    // オブジェクト名設定
    QObject_setObjectName(obj, "TestObject");
    
    // オブジェクト名取得
    char *name = QObject_objectName(obj);
    printf("オブジェクト名: %s\n", name);
    free(name);
    
    // クラス名取得
    char *className = QObject_className(obj);
    printf("クラス名: %s\n", className);
    free(className);
    
    // プロパティ設定/取得はスキップ
    printf("プロパティ操作はスキップします\n");
    
    // 動的プロパティ名取得
    int count = 0;
    char **propNames = QObject_dynamicPropertyNames(obj, &count);
    if (propNames) {
        printf("動的プロパティ数: %d\n", count);
        for (int i = 0; i < count; i++) {
            if (propNames[i]) {
                printf("  プロパティ名 %d: %s\n", i, propNames[i]);
                free(propNames[i]);
            }
        }
        free(propNames);
    }
    
    // シグナルブロック
    bool blocked = QObject_blockSignals(obj, true);
    printf("シグナルブロック前の状態: %s\n", blocked ? "ブロック中" : "ブロックなし");
    
    bool isBlocked = QObject_signalsBlocked(obj);
    printf("シグナルブロック状態: %s\n", isBlocked ? "ブロック中" : "ブロックなし");
    
    QObject_blockSignals(obj, false);
    
    // 継承関係チェック
    bool inherits = QObject_inherits(obj, "QObject");
    printf("QObjectを継承していますか: %s\n", inherits ? "はい" : "いいえ");
    
    // ウィジェットタイプチェック
    bool isWidget = QObject_isWidgetType(obj);
    printf("ウィジェットタイプですか: %s\n", isWidget ? "はい" : "いいえ");
    
    // ウィンドウタイプチェック
    bool isWindow = QObject_isWindowType(obj);
    printf("ウィンドウタイプですか: %s\n", isWindow ? "はい" : "いいえ");
    
    // 子オブジェクト作成
    void *child1 = QObject_create(obj);
    QObject_setObjectName(child1, "Child1");
    
    void *child2 = QObject_create(obj);
    QObject_setObjectName(child2, "Child2");
    
    // 子オブジェクト取得
    int childCount = 0;
    void **children = QObject_children(obj, &childCount);
    if (children) {
        printf("子オブジェクト数: %d\n", childCount);
        for (int i = 0; i < childCount; i++) {
            if (children[i]) {
                char *childName = QObject_objectName(children[i]);
                if (childName) {
                    printf("  子オブジェクト %d: %s\n", i, childName);
                    free(childName);
                }
            }
        }
        free(children);
    }
    
    // オブジェクトツリー表示
    printf("\nオブジェクトツリー:\n");
    QObject_dumpObjectTree(obj);
    
    // オブジェクト情報表示
    printf("\nオブジェクト情報:\n");
    QObject_dumpObjectInfo(obj);
    
    // タイマー開始（実際には使用例としてだけで、コールバックは設定していません）
    int timerId = QObject_startTimer(obj, 1000, 0); // 0 = Qt::CoarseTimer
    printf("タイマーID: %d\n", timerId);
    
    // タイマー停止
    QObject_killTimer(obj, timerId);
    
    // スレッド取得
    void *thread = QObject_thread(obj);
    printf("スレッドポインタ: %p\n", thread);
    
    // クリーンアップ
    QObject_delete(child1);
    QObject_delete(child2);
    QObject_delete(obj);
    QApplication_delete(app);
    
    return 0;
}
