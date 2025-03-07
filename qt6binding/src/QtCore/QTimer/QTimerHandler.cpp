#include "QTimerHandler.h"

QTimerHandler::QTimerHandler(QObject* parent)
    : QObject(parent)
    , timeoutCallback(nullptr) {
}

void QTimerHandler::setTimeoutCallback(QTimer_TimeoutCallback callback) {
    timeoutCallback = callback;
}

void QTimerHandler::onTimeout() const {
    if (timeoutCallback) {
        timeoutCallback(parent());
    }
}
