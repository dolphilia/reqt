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
