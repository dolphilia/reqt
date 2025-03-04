#include "QPushButtonHandler.h"

ButtonClickHandler::ButtonClickHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr) {
}

void ButtonClickHandler::setClickedCallback(ClickedCallback callback) {
    clickedCallback = callback;
}

void ButtonClickHandler::setPressedCallback(PressedCallback callback) {
    pressedCallback = callback;
}

void ButtonClickHandler::setReleasedCallback(ReleasedCallback callback) {
    releasedCallback = callback;
}

void ButtonClickHandler::onClicked() const {
    if (clickedCallback) {
        clickedCallback(parent());
    }
}

void ButtonClickHandler::onPressed() const {
    if (pressedCallback) {
        pressedCallback(parent());
    }
}

void ButtonClickHandler::onReleased() const {
    if (releasedCallback) {
        releasedCallback(parent());
    }
}
