#ifndef QT_QTIMERBIND_H
#define QT_QTIMERBIND_H

#include "QTimerHandler.h"

// タイマーのコールバック関数の型定義（C言語側で使用）
typedef void (*QTimerCallback)(void *userData);

class QTimerBind {
public:
    // 作成・削除
    static void *create();
    static void delete_timer(void *timer);

    // タイマー操作
    static void start(void *timer, int msec);
    static void startSingleShot(void *timer, int msec);
    static void stop(void *timer);
    static bool isActive(void *timer);
    static int interval(void *timer);
    static void setInterval(void *timer, int msec);
    static int remainingTime(void *timer);
    static int timerId(void *timer);
    
    // 追加機能
    static bool isSingleShot(void *timer);
    static void setSingleShot(void *timer, bool singleShot);
    static int timerType(void *timer);
    static void setTimerType(void *timer, int type);
    static int id(void *timer);

    // コールバック設定
    static void setCallback(void *timer, QTimerCallback callback, void *userData);
    
    // 静的シングルショットタイマー
    static void singleShot(int msec, QTimerCallback callback, void *userData);

private:
    static QTimerHandler *handler(void *timer);
};

#endif // QT_QTIMERBIND_H
