#include "QCheckBoxHandler.h"

CheckBoxHandler::CheckBoxHandler(QObject* parent)
    : QObject(parent)
    , stateCallback(nullptr)
    , toggleCallback(nullptr)
{
}

void CheckBoxHandler::setStateChangedCallback(void (*callback)(void*, int)) {
    stateCallback = callback;
}

void CheckBoxHandler::setToggledCallback(void (*callback)(void*, bool)) {
    toggleCallback = callback;
}

void CheckBoxHandler::onStateChanged(int state) {
    if (stateCallback) {
        stateCallback(parent(), state);
    }
}

void CheckBoxHandler::onToggled(bool checked) {
    if (toggleCallback) {
        toggleCallback(parent(), checked);
    }
}
