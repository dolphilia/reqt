#include "QCheckBoxHandler.h"

QCheckBoxHandler::QCheckBoxHandler(QObject* parent)
    : QObject(parent)
    , stateCallback(nullptr)
    , toggleCallback(nullptr)
    , clickedCallback(nullptr) {
}

void QCheckBoxHandler::setStateChangedCallback(QCheckBox_StateChangedCallback callback) {
    stateCallback = callback;
}

void QCheckBoxHandler::setToggledCallback(QCheckBox_ToggledCallback callback) {
    toggleCallback = callback;
}

void QCheckBoxHandler::setClickedCallback(QCheckBox_ClickedCallback callback) {
    clickedCallback = callback;
}

void QCheckBoxHandler::onStateChanged(int state) const {
    if (stateCallback) {
        stateCallback(parent(), state);
    }
}

void QCheckBoxHandler::onToggled(bool checked) const {
    if (toggleCallback) {
        toggleCallback(parent(), checked);
    }
}

void QCheckBoxHandler::onClicked(bool checked) const {
    if (clickedCallback) {
        clickedCallback(parent(), checked);
    }
}