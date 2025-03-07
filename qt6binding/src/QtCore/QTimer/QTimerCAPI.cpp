#include "QTimerBind.h"

extern "C" {

void* QTimer_create() {
    return new QTimerBind();
}

void QTimer_delete(void* timer) {
    delete static_cast<QTimerBind*>(timer);
}

void QTimer_start(void* timer, int msec) {
    QTimerBind* qtimer = static_cast<QTimerBind*>(timer);
    qtimer->setInterval(msec);
    qtimer->start();
}

void QTimer_startSingleShot(void* timer, int msec) {
    QTimerBind* qtimer = static_cast<QTimerBind*>(timer);
    qtimer->setSingleShot(true);
    qtimer->setInterval(msec);
    qtimer->start();
}

void QTimer_stop(void* timer) {
    static_cast<QTimerBind*>(timer)->stop();
}

bool QTimer_isActive(void* timer) {
    return static_cast<QTimerBind*>(timer)->isActive();
}

int QTimer_interval(void* timer) {
    return static_cast<QTimerBind*>(timer)->interval();
}

void QTimer_setInterval(void* timer, int msec) {
    static_cast<QTimerBind*>(timer)->setInterval(msec);
}

int QTimer_remainingTime(void* timer) {
    return static_cast<QTimerBind*>(timer)->remainingTime();
}

int QTimer_timerId(void* timer) {
    return static_cast<QTimerBind*>(timer)->timerId();
}

bool QTimer_isSingleShot(void* timer) {
    return static_cast<QTimerBind*>(timer)->isSingleShot();
}

void QTimer_setSingleShot(void* timer, bool singleShot) {
    static_cast<QTimerBind*>(timer)->setSingleShot(singleShot);
}

int QTimer_timerType(void* timer) {
    return static_cast<int>(static_cast<QTimerBind*>(timer)->timerType());
}

void QTimer_setTimerType(void* timer, int type) {
    static_cast<QTimerBind*>(timer)->setTimerType(static_cast<Qt::TimerType>(type));
}

typedef void (*QTimer_TimeoutCallback)(void*);

void QTimer_setTimeoutCallback(void* timer, QTimer_TimeoutCallback callback) {
    static_cast<QTimerBind*>(timer)->setTimeoutCallback(callback);
}

// 静的シングルショットタイマー
void QTimer_singleShot(int msec, QTimer_TimeoutCallback callback, void* userData) {
    QTimerBind* timer = new QTimerBind();
    timer->setTimeoutCallback(callback);
    QObject::connect(timer, &QTimer::timeout, timer, [timer, userData]() {
        timer->setTimeoutCallback(nullptr);
        timer->deleteLater();
    });
    timer->setSingleShot(true);
    timer->start(msec);
}

}
