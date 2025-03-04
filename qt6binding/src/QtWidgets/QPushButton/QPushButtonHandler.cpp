#include "QPushButtonHandler.h"

QButtonClickHandler::QButtonClickHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr) {
}

void QButtonClickHandler::setClickedCallback(QPushButton_ClickedCallback callback) {
    clickedCallback = callback;
}

void QButtonClickHandler::setPressedCallback(QPushButton_PressedCallback callback) {
    pressedCallback = callback;
}

void QButtonClickHandler::setReleasedCallback(QPushButton_ReleasedCallback callback) {
    releasedCallback = callback;
}

void QButtonClickHandler::onClicked() const {
    if (clickedCallback) {
        clickedCallback(parent());
    }
}

void QButtonClickHandler::onPressed() const {
    if (pressedCallback) {
        pressedCallback(parent());
    }
}

void QButtonClickHandler::onReleased() const {
    if (releasedCallback) {
        releasedCallback(parent());
    }
}
