#include "QObjectBind.h"
#include "QObjectHandler.h"

QObjectBind::QObjectBind(QObject* parent)
    : QObject(parent)
    , handler(new QObjectHandler(this)) {
    connect(this, &QObject::destroyed, handler, &QObjectHandler::onDestroyed);
    connect(this, &QObject::objectNameChanged, handler, &QObjectHandler::onObjectNameChanged);
    connect(this, &QObject::event, handler, &QObjectHandler::onEvent);
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

// Reimplemented Protected Functions

void QObjectBind::childEvent(QChildEvent *event) {
    QObject::childEvent(event);
    handler->onChildEvent(event);
}

void QObjectBind::connectNotify(const QMetaMethod &signal) {
    QObject::connectNotify(signal);
    handler->onConnectNotify(signal);
}

void QObjectBind::customEvent(QEvent *event) {
    QObject::customEvent(event);
    handler->onCustomEvent(event);
}

void QObjectBind::disconnectNotify(const QMetaMethod &signal) {
    QObject::disconnectNotify(signal);
    handler->onDisconnectNotify(signal);
}

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

void QObjectBind::timerEvent(QTimerEvent *event) {
    QObject::timerEvent(event);
    handler->onTimerEvent(event);
}
