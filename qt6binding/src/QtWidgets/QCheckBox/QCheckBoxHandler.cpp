#include "QCheckBoxHandler.h"

CheckBoxHandler::CheckBoxHandler(QObject* parent)
    : QObject(parent)
    , stateCallback(nullptr)
    , toggleCallback(nullptr)
    , clickedCallback(nullptr) {
}

void CheckBoxHandler::setStateChangedCallback(StateCallback callback) {
    stateCallback = callback;
}

void CheckBoxHandler::setToggledCallback(ToggleCallback callback) {
    toggleCallback = callback;
}

void CheckBoxHandler::setClickedCallback(ClickCallback callback) {
    clickedCallback = callback;
}

void CheckBoxHandler::onStateChanged(int state) const {
    if (stateCallback) {
        stateCallback(parent(), state);
    }
}

void CheckBoxHandler::onToggled(bool checked) const {
    if (toggleCallback) {
        toggleCallback(parent(), checked);
    }
}

void CheckBoxHandler::onClicked(bool checked) const {
    if (clickedCallback) {
        clickedCallback(parent(), checked);
    }
}