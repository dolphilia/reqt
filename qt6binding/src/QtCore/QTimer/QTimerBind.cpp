#include "QTimerBind.h"
#include "QTimerHandler.h"

QTimerBind::QTimerBind(QObject* parent)
    : QTimer(parent)
    , handler(new QTimerHandler(this)) {
    connect(this, &QTimer::timeout, handler, &QTimerHandler::onTimeout);
}

QTimerBind::~QTimerBind() {
    delete handler;
}

void QTimerBind::setTimeoutCallback(QTimer_TimeoutCallback callback) const {
    handler->setTimeoutCallback(callback);
}
