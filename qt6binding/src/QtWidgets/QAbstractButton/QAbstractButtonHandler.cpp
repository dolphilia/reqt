#include "QAbstractButtonHandler.h"

QAbstractButtonHandler::QAbstractButtonHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr)
    , toggledCallback(nullptr)
{
}

void QAbstractButtonHandler::setClickedCallback(ClickCallback callback) {
    clickedCallback = callback;
}

void QAbstractButtonHandler::setPressedCallback(PressCallback callback) {
    pressedCallback = callback;
}

void QAbstractButtonHandler::setReleasedCallback(ReleaseCallback callback) {
    releasedCallback = callback;
}

void QAbstractButtonHandler::setToggledCallback(ToggleCallback callback) {
    toggledCallback = callback;
}

void QAbstractButtonHandler::onClicked(bool checked) const {
    if (clickedCallback) {
        clickedCallback(parent(), checked);
    }
}

void QAbstractButtonHandler::onPressed() const {
    if (pressedCallback) {
        pressedCallback(parent());
    }
}

void QAbstractButtonHandler::onReleased() const {
    if (releasedCallback) {
        releasedCallback(parent());
    }
}

void QAbstractButtonHandler::onToggled(bool checked) const {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}