#include <qt6.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// タイマーのコールバック関数
void timerCallback(void *userData) {
    int *count = (int *)userData;
    (*count)++;
    printf("タイマーイベント発生: %d回目\n", *count);
}

// シングルショットタイマーのコールバック関数
void singleShotCallback(void *userData) {
    printf("シングルショットタイマーイベント発生: %s\n", (char *)userData);
}

int main(int argc, char *argv[]) {
    // Qtアプリケーションの初期化
    void *app = QApplication_create(argc, argv);
    
    printf("QTimerのテスト\n");
    printf("==============\n\n");
    
    // 通常のタイマーのテスト
    printf("1. 通常のタイマー (500ms間隔):\n");
    void *timer = QTimer_create();
    int count = 0;
    
    // コールバックの設定
    QTimer_setCallback(timer, timerCallback, &count);
    
    // タイマーの開始 (500ms間隔)
    QTimer_setInterval(timer, 500);
    QTimer_start(timer, 0);
    
    printf("タイマー開始...\n");
    printf("タイマーID: %d\n", QTimer_timerId(timer));
    printf("タイマー間隔: %dms\n", QTimer_interval(timer));
    printf("タイマーアクティブ: %s\n\n", QTimer_isActive(timer) ? "はい" : "いいえ");
    
    // 3秒間待機 (約6回のタイマーイベントが発生するはず)
    QApplication_processEvents();
    sleep(3);
    QApplication_processEvents();
    
    // タイマーの停止
    QTimer_stop(timer);
    printf("\nタイマー停止\n");
    printf("タイマーアクティブ: %s\n\n", QTimer_isActive(timer) ? "はい" : "いいえ");
    
    // シングルショットタイマーのテスト
    printf("2. シングルショットタイマー (1000ms):\n");
    
    // インスタンスを使用したシングルショットタイマー
    void *singleTimer = QTimer_create();
    QTimer_setCallback(singleTimer, singleShotCallback, "インスタンスを使用");
    QTimer_startSingleShot(singleTimer, 1000);
    
    printf("シングルショットタイマー開始...\n");
    
    // 静的メソッドを使用したシングルショットタイマー
    char *message = "静的メソッドを使用";
    QTimer_singleShot(2000, singleShotCallback, message);
    
    printf("静的シングルショットタイマー開始...\n\n");
    
    // 3秒間待機 (両方のシングルショットタイマーが発火するはず)
    QApplication_processEvents();
    sleep(3);
    QApplication_processEvents();
    
    // クリーンアップ
    QTimer_delete(timer);
    QTimer_delete(singleTimer);
    
    // アプリケーションの終了
    QApplication_delete(app);
    
    return 0;
}
