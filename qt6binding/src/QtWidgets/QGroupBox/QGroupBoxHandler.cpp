#include "QGroupBoxHandler.h"

QGroupBoxHandler::QGroupBoxHandler(QObject* parent)
    : QObject(parent)
    , toggledCallback(nullptr) {
}

void QGroupBoxHandler::setToggledCallback(QGroupBox_ToggledCallback callback) {
    toggledCallback = callback;
}

void QGroupBoxHandler::onToggled(bool checked) const {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}
