#include "QTimerBind.h"
#include "../../include/qt6/qtimer.h"
#include <QTimer>

// 作成・削除
void *QTimer_create()
{
    return QTimerBind::create();
}

void QTimer_delete(void *timer)
{
    QTimerBind::delete_timer(timer);
}

// タイマー操作
void QTimer_start(void *timer, int msec)
{
    QTimerBind::start(timer, msec);
}

void QTimer_startSingleShot(void *timer, int msec)
{
    QTimerBind::startSingleShot(timer, msec);
}

void QTimer_stop(void *timer)
{
    QTimerBind::stop(timer);
}

bool QTimer_isActive(void *timer)
{
    return QTimerBind::isActive(timer);
}

int QTimer_interval(void *timer)
{
    return QTimerBind::interval(timer);
}

void QTimer_setInterval(void *timer, int msec)
{
    QTimerBind::setInterval(timer, msec);
}

int QTimer_remainingTime(void *timer)
{
    return QTimerBind::remainingTime(timer);
}

int QTimer_timerId(void *timer)
{
    return QTimerBind::timerId(timer);
}

// 追加機能
bool QTimer_isSingleShot(void *timer)
{
    return QTimerBind::isSingleShot(timer);
}

void QTimer_setSingleShot(void *timer, bool singleShot)
{
    QTimerBind::setSingleShot(timer, singleShot);
}

int QTimer_timerType(void *timer)
{
    return QTimerBind::timerType(timer);
}

void QTimer_setTimerType(void *timer, int type)
{
    QTimerBind::setTimerType(timer, type);
}

int QTimer_id(void *timer)
{
    return QTimerBind::id(timer);
}

// コールバック設定
void QTimer_setCallback(void *timer, QTimer_Callback callback, void *userData)
{
    QTimerBind::setCallback(timer, callback, userData);
}

// 静的メソッド
// シングルショットタイマーのためのグローバル変数
static QTimer *g_singleShotTimer = nullptr;
static QTimer_Callback g_singleShotCallback = nullptr;
static void *g_singleShotUserData = nullptr;

// シングルショットタイマーのコールバック
static void singleShotHandler()
{
    if (g_singleShotCallback) {
        g_singleShotCallback(g_singleShotUserData);
    }
    
    // タイマーを削除
    if (g_singleShotTimer) {
        delete g_singleShotTimer;
        g_singleShotTimer = nullptr;
    }
}

void QTimer_singleShot(int msec, QTimer_Callback callback, void *userData)
{
    // 前のタイマーがあれば削除
    if (g_singleShotTimer) {
        delete g_singleShotTimer;
    }
    
    // 新しいタイマーを作成
    g_singleShotTimer = new QTimer();
    g_singleShotTimer->setSingleShot(true);
    g_singleShotCallback = callback;
    g_singleShotUserData = userData;
    
    // タイマーを接続して開始
    QObject::connect(g_singleShotTimer, &QTimer::timeout, singleShotHandler);
    g_singleShotTimer->start(msec);
}
