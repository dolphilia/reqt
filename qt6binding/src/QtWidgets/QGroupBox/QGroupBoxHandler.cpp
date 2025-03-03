#include "QGroupBoxHandler.h"

GroupBoxHandler::GroupBoxHandler(QObject* parent)
    : QObject(parent)
    , toggledCallback(nullptr) {
}

void GroupBoxHandler::setToggledCallback(ToggledCallback callback) {
    toggledCallback = callback;
}

void GroupBoxHandler::onToggled(bool checked) const {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}
