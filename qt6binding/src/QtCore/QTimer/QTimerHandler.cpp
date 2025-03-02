#include "QTimerHandler.h"

QTimerHandler::QTimerHandler()
    : QObject(nullptr), m_callback(nullptr), m_userData(nullptr)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &QTimerHandler::handleTimeout);
}

QTimerHandler::~QTimerHandler()
{
    // QTimerはQObjectの子なので、自動的に削除される
}

QTimer *QTimerHandler::timer() const
{
    return m_timer;
}

void QTimerHandler::start(int msec)
{
    if (msec > 0) {
        m_timer->setInterval(msec);
    }
    m_timer->start();
}

void QTimerHandler::startSingleShot(int msec)
{
    m_timer->setSingleShot(true);
    m_timer->setInterval(msec);
    m_timer->start();
}

void QTimerHandler::stop()
{
    m_timer->stop();
}

bool QTimerHandler::isActive() const
{
    return m_timer->isActive();
}

int QTimerHandler::interval() const
{
    return m_timer->interval();
}

void QTimerHandler::setInterval(int msec)
{
    m_timer->setInterval(msec);
}

int QTimerHandler::remainingTime() const
{
    return m_timer->remainingTime();
}

int QTimerHandler::timerId() const
{
    return m_timer->timerId();
}

bool QTimerHandler::isSingleShot() const
{
    return m_timer->isSingleShot();
}

void QTimerHandler::setSingleShot(bool singleShot)
{
    m_timer->setSingleShot(singleShot);
}

int QTimerHandler::timerType() const
{
    return static_cast<int>(m_timer->timerType());
}

void QTimerHandler::setTimerType(int type)
{
    m_timer->setTimerType(static_cast<Qt::TimerType>(type));
}

int QTimerHandler::id() const
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
    return static_cast<int>(m_timer->id());
#else
    return m_timer->timerId();
#endif
}

void QTimerHandler::setCallback(QTimerCallback callback, void *userData)
{
    m_callback = callback;
    m_userData = userData;
}

void QTimerHandler::handleTimeout()
{
    if (m_callback) {
        m_callback(m_userData);
    }
}
