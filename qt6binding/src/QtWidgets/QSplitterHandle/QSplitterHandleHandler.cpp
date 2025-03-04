#include "QSplitterHandleHandler.h"

QSplitterHandleHandler::QSplitterHandleHandler(QObject* parent)
    : QObject(parent)
    , movedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr) {
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
