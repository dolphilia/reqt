#ifndef QT_QTIMER_H
#define QT_QTIMER_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// タイマーのコールバック関数の型定義
typedef void (*QTimer_Callback)(void *userData);

// 作成・削除
void *QTimer_create();
void QTimer_delete(void *timer);

// タイマー操作
void QTimer_start(void *timer, int msec);
void QTimer_startSingleShot(void *timer, int msec);
void QTimer_stop(void *timer);
bool QTimer_isActive(void *timer);
int QTimer_interval(void *timer);
void QTimer_setInterval(void *timer, int msec);
int QTimer_remainingTime(void *timer);
int QTimer_timerId(void *timer);

// 追加機能
bool QTimer_isSingleShot(void *timer);
void QTimer_setSingleShot(void *timer, bool singleShot);
int QTimer_timerType(void *timer);
void QTimer_setTimerType(void *timer, int type);
int QTimer_id(void *timer);

// コールバック設定
typedef void (*QTimer_TimeoutCallback)(void*);
void QTimer_setTimeoutCallback(void* timer, QTimer_TimeoutCallback callback);

// 静的メソッド
void QTimer_singleShot(int msec, QTimer_Callback callback, void *userData);

#ifdef __cplusplus
}
#endif

#endif // QT_QTIMER_H
