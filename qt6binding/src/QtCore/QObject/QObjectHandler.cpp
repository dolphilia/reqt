#include "QObjectHandler.h"

QObjectHandler::QObjectHandler(QObject* parent)
    : QObject(parent)
    , destroyedCallback(nullptr)
    , objectNameChangedCallback(nullptr)
    , eventCallback(nullptr)
    , childEventCallback(nullptr)
    , connectNotifyCallback(nullptr)
    , customEventCallback(nullptr)
    , disconnectNotifyCallback(nullptr)
    , timerEventCallback(nullptr) {
}
// set Callback

void QObjectHandler::setDestroyedCallback(QObject_DestroyedCallback callback) {
    destroyedCallback = callback;
}

void QObjectHandler::setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) {
    objectNameChangedCallback = callback;
}

void QObjectHandler::setEventCallback(QObject_EventCallback callback) {
    eventCallback = callback;
}

void QObjectHandler::setChildEventCallback(QObject_ChildEventCallback callback) {
    childEventCallback = callback;
}

void QObjectHandler::setConnectNotifyCallback(QObject_ConnectNotifyCallback callback) {
    connectNotifyCallback = callback;
}

void QObjectHandler::setCustomEventCallback(QObject_CustomEventCallback callback) {
    customEventCallback = callback;
}

void QObjectHandler::setDisconnectNotifyCallback(QObject_DisconnectNotifyCallback callback) {
    disconnectNotifyCallback = callback;
}

void QObjectHandler::setTimerEventCallback(QObject_TimerEventCallback callback) {
    timerEventCallback = callback;
}

// onXXXX

void QObjectHandler::onDestroyed() const {
    if (destroyedCallback) {
        destroyedCallback(const_cast<QObjectHandler*>(this));
    }
}

void QObjectHandler::onObjectNameChanged(const QString& objectName) const {
    if (objectNameChangedCallback) {
        objectNameChangedCallback(const_cast<QObjectHandler*>(this), &objectName);
    }
}

void QObjectHandler::onEvent(QEvent* event) const {
    if (eventCallback) {
        eventCallback(const_cast<QObjectHandler*>(this), event);
    }
}

void QObjectHandler::onChildEvent(QChildEvent* event) const {
    if (childEventCallback) {
        childEventCallback(const_cast<QObjectHandler*>(this), event);
    }
}

void QObjectHandler::onConnectNotify(const QMetaMethod& signal) const {
    if (connectNotifyCallback) {
        connectNotifyCallback(const_cast<QObjectHandler*>(this), &signal);
    }
}

void QObjectHandler::onCustomEvent(QEvent* event) const {
    if (customEventCallback) {
        customEventCallback(const_cast<QObjectHandler*>(this), event);
    }
}

void QObjectHandler::onDisconnectNotify(const QMetaMethod& signal) const {
    if (disconnectNotifyCallback) {
        disconnectNotifyCallback(const_cast<QObjectHandler*>(this), &signal);
    }
}

void QObjectHandler::onTimerEvent(QTimerEvent* event) const {
    if (timerEventCallback) {
        timerEventCallback(const_cast<QObjectHandler*>(this), event);
    }
}
