#include "QAbstractButtonHandler.h"

QAbstractButtonHandler::QAbstractButtonHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr)
    , toggledCallback(nullptr)
{
}

void QAbstractButtonHandler::setClickedCallback(QAbstractButton_ClickedCallback callback) {
    clickedCallback = callback;
}

void QAbstractButtonHandler::setPressedCallback(QAbstractButton_PressedCallback callback) {
    pressedCallback = callback;
}

void QAbstractButtonHandler::setReleasedCallback(QAbstractButton_ReleasedCallback callback) {
    releasedCallback = callback;
}

void QAbstractButtonHandler::setToggledCallback(QAbstractButton_ToggledCallback callback) {
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