#include "QSplitterHandleHandler.h"

QSplitterHandleHandler::QSplitterHandleHandler(QObject* parent)
    : QObject(parent)
    , movedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr)
    , eventCallback(nullptr)
    , paintCallback(nullptr)
    , resizeCallback(nullptr) {
}

void QSplitterHandleHandler::setMovedCallback(QSplitterHandle_MovedCallback callback) {
    movedCallback = callback;
}

void QSplitterHandleHandler::setPressedCallback(QSplitterHandle_PressedCallback callback) {
    pressedCallback = callback;
}

void QSplitterHandleHandler::setReleasedCallback(QSplitterHandle_ReleasedCallback callback) {
    releasedCallback = callback;
}

void QSplitterHandleHandler::setEventCallback(QSplitterHandle_EventCallback callback) {
    eventCallback = callback;
}

void QSplitterHandleHandler::setPaintCallback(QSplitterHandle_PaintCallback callback) {
    paintCallback = callback;
}

void QSplitterHandleHandler::setResizeCallback(QSplitterHandle_ResizeCallback callback) {
    resizeCallback = callback;
}

void QSplitterHandleHandler::onMoved() const {
    if (movedCallback) {
        movedCallback(parent());
    }
}

void QSplitterHandleHandler::onPressed() const {
    if (pressedCallback) {
        pressedCallback(parent());
    }
}

void QSplitterHandleHandler::onReleased() const {
    if (releasedCallback) {
        releasedCallback(parent());
    }
}

bool QSplitterHandleHandler::onEvent(QEvent* event) const {
    if (eventCallback) {
        return eventCallback(parent(), event);
    }
    return false;
}

void QSplitterHandleHandler::onPaint() const {
    if (paintCallback) {
        paintCallback(parent());
    }
}

void QSplitterHandleHandler::onResize(QResizeEvent* event) const {
    if (resizeCallback) {
        resizeCallback(parent(), event);
    }
}
