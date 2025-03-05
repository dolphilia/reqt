#include "QObjectHandler.h"

QObjectHandler::QObjectHandler(QObject* parent)
    : QObject(parent)
    , destroyedCallback(nullptr)
    , objectNameChangedCallback(nullptr)
    , eventCallback(nullptr) {
}

void QObjectHandler::setDestroyedCallback(QObject_DestroyedCallback callback) {
    destroyedCallback = callback;
}

void QObjectHandler::setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) {
    objectNameChangedCallback = callback;
}

void QObjectHandler::setEventCallback(QObject_EventCallback callback) {
    eventCallback = callback;
}

void QObjectHandler::onDestroyed() const {
    if (destroyedCallback) {
        destroyedCallback(parent());
    }
}

void QObjectHandler::onObjectNameChanged(const QString& objectName) const {
    if (objectNameChangedCallback) {
        objectNameChangedCallback(parent(), &objectName);
    }
}

void QObjectHandler::onEvent(QEvent* event) const {
    if (eventCallback) {
        eventCallback(parent(), event);
    }
}
