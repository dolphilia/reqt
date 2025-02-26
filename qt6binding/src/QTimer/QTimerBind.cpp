#include "QTimerBind.h"

void *QTimerBind::create()
{
    return new QTimerHandler();
}

void QTimerBind::delete_timer(void *timer)
{
    delete handler(timer);
}

void QTimerBind::start(void *timer, int msec)
{
    handler(timer)->start(msec);
}

void QTimerBind::startSingleShot(void *timer, int msec)
{
    handler(timer)->startSingleShot(msec);
}

void QTimerBind::stop(void *timer)
{
    handler(timer)->stop();
}

bool QTimerBind::isActive(void *timer)
{
    return handler(timer)->isActive();
}

int QTimerBind::interval(void *timer)
{
    return handler(timer)->interval();
}

void QTimerBind::setInterval(void *timer, int msec)
{
    handler(timer)->setInterval(msec);
}

int QTimerBind::remainingTime(void *timer)
{
    return handler(timer)->remainingTime();
}

int QTimerBind::timerId(void *timer)
{
    return handler(timer)->timerId();
}

bool QTimerBind::isSingleShot(void *timer)
{
    return handler(timer)->isSingleShot();
}

void QTimerBind::setSingleShot(void *timer, bool singleShot)
{
    handler(timer)->setSingleShot(singleShot);
}

int QTimerBind::timerType(void *timer)
{
    return handler(timer)->timerType();
}

void QTimerBind::setTimerType(void *timer, int type)
{
    handler(timer)->setTimerType(type);
}

int QTimerBind::id(void *timer)
{
    return handler(timer)->id();
}

void QTimerBind::setCallback(void *timer, QTimerCallback callback, void *userData)
{
    handler(timer)->setCallback(callback, userData);
}

QTimerHandler *QTimerBind::handler(void *timer)
{
    return static_cast<QTimerHandler *>(timer);
}

// 静的シングルショットタイマーの実装
void QTimerBind::singleShot(int msec, QTimerCallback callback, void *userData)
{
    // 一時的なタイマーハンドラを作成
    QTimerHandler *handler = new QTimerHandler();
    handler->setCallback(callback, userData);
    
    // タイマー終了時に自身を削除するためのラムダ関数を接続
    QObject::connect(handler->timer(), &QTimer::timeout, [handler]() {
        delete handler;
    });
    
    // シングルショットタイマーを開始
    handler->startSingleShot(msec);
}
