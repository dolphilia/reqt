#include "QRadioButtonHandler.h"

QRadioButtonHandler::QRadioButtonHandler(QObject* parent)
    : QObject(parent)
    , toggledCallback(nullptr)
    , clickedCallback(nullptr)
    , pressedCallback(nullptr)
    , releasedCallback(nullptr) {
}

void QRadioButtonHandler::setToggledCallback(QRadioButton_ToggledCallback callback) {
    toggledCallback = callback;
}

void QRadioButtonHandler::setClickedCallback(QRadioButton_ClickedCallback callback) {
    clickedCallback = callback;
}

void QRadioButtonHandler::setPressedCallback(QRadioButton_PressedCallback callback) {
    pressedCallback = callback;
}

void QRadioButtonHandler::setReleasedCallback(QRadioButton_ReleasedCallback callback) {
    releasedCallback = callback;
}

void QRadioButtonHandler::onToggled(bool checked) const {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}

void QRadioButtonHandler::onClicked(bool checked) const {
    if (clickedCallback) {
        clickedCallback(parent(), checked);
    }
}

void QRadioButtonHandler::onPressed() const {
    if (pressedCallback) {
        pressedCallback(parent());
    }
}

void QRadioButtonHandler::onReleased() const {
    if (releasedCallback) {
        releasedCallback(parent());
    }
}
