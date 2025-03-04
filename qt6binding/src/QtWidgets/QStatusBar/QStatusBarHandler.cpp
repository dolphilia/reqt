#include "QStatusBarHandler.h"

QStatusBarHandler::QStatusBarHandler(QObject* parent)
    : QObject(parent)
    , messageChangedCallback(nullptr) {
}

void QStatusBarHandler::setMessageChangedCallback(QStatusBar_MessageChangedCallback callback) {
    messageChangedCallback = callback;
}

void QStatusBarHandler::onMessageChanged(const QString& message) const {
    if (messageChangedCallback) {
        messageChangedCallback(parent(), message.toUtf8().constData());
    }
}
