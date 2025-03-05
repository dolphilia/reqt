#include "QObjectBind.h"
#include "QObjectHandler.h"

QObjectBind::QObjectBind(QObject* parent)
    : QObject(parent)
    , handler(new QObjectHandler(this)) {
    connect(this, &QObject::destroyed, handler, &QObjectHandler::onDestroyed);
    connect(this, &QObject::objectNameChanged, handler, &QObjectHandler::onObjectNameChanged);
}

QObjectBind::~QObjectBind() {
    delete handler;
}

void QObjectBind::setDestroyedCallback(QObject_DestroyedCallback callback) const {
    handler->setDestroyedCallback(callback);
}

void QObjectBind::setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) const {
    handler->setObjectNameChangedCallback(callback);
}

void QObjectBind::setEventCallback(QObject_EventCallback callback) const {
    handler->setEventCallback(callback);
}

void QObjectBind::setChildEventCallback(QObject_ChildEventCallback callback) const {
    handler->setChildEventCallback(callback);
}

void QObjectBind::setConnectNotifyCallback(QObject_ConnectNotifyCallback callback) const {
    handler->setConnectNotifyCallback(callback);
}

void QObjectBind::setCustomEventCallback(QObject_CustomEventCallback callback) const {
    handler->setCustomEventCallback(callback);
}

void QObjectBind::setDisconnectNotifyCallback(QObject_DisconnectNotifyCallback callback) const {
    handler->setDisconnectNotifyCallback(callback);
}

void QObjectBind::setTimerEventCallback(QObject_TimerEventCallback callback) const {
    handler->setTimerEventCallback(callback);
}

// Protected Functions made public

bool QObjectBind::isSignalConnected(const QMetaMethod &signal) const {
    return QObject::isSignalConnected(signal);
}

int QObjectBind::receivers(const char *signal) const {
    return QObject::receivers(signal);
}

QObject *QObjectBind::sender() const {
    return QObject::sender();
}

int QObjectBind::senderSignalIndex() const {
    return QObject::senderSignalIndex();
}

// Reimplemented Protected Functions

bool QObjectBind::event(QEvent *e) {
    if (handler && handler->hasEventCallback()) {
        handler->onEvent(e);
    }
    return QObject::event(e);
}

void QObjectBind::childEvent(QChildEvent *event) {
    QObject::childEvent(event);
    if (handler && handler->hasChildEventCallback()) {
        handler->onChildEvent(event);
    }
}

void QObjectBind::connectNotify(const QMetaMethod &signal) {
    QObject::connectNotify(signal);
    if (handler && handler->hasConnectNotifyCallback()) {
        handler->onConnectNotify(signal);
    }
}

void QObjectBind::customEvent(QEvent *event) {
    QObject::customEvent(event);
    if (handler && handler->hasCustomEventCallback()) {
        handler->onCustomEvent(event);
    }
}

void QObjectBind::disconnectNotify(const QMetaMethod &signal) {
    QObject::disconnectNotify(signal);
    if (handler && handler->hasDisconnectNotifyCallback()) {
        handler->onDisconnectNotify(signal);
    }
}

void QObjectBind::timerEvent(QTimerEvent *event) {
    QObject::timerEvent(event);
    if (handler && handler->hasTimerEventCallback()) {
        handler->onTimerEvent(event);
    }
}
