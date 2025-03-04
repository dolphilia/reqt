#include "QToolButtonHandler.h"

QToolButtonHandler::QToolButtonHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , toggledCallback(nullptr)
    , triggeredCallback(nullptr) {
}

void QToolButtonHandler::setClickedCallback(QToolButton_ClickedCallback callback) {
    clickedCallback = callback;
}

void QToolButtonHandler::setToggledCallback(QToolButton_ToggledCallback callback) {
    toggledCallback = callback;
}

void QToolButtonHandler::setTriggeredCallback(QToolButton_TriggeredCallback callback) {
    triggeredCallback = callback;
}

void QToolButtonHandler::onClicked() const {
    if (clickedCallback) {
        clickedCallback(parent());
    }
}

void QToolButtonHandler::onToggled(bool checked) const {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}

void QToolButtonHandler::onTriggered() const {
    if (triggeredCallback) {
        triggeredCallback(parent());
    }
}
