#include "QActionHandler.h"

QActionHandler::QActionHandler(QObject* parent)
    : QObject(parent)
    , changedCallback(nullptr)
    , checkableChangedCallback(nullptr)
    , enabledChangedCallback(nullptr)
    , hoveredCallback(nullptr)
    , toggledCallback(nullptr)
    , triggeredCallback(nullptr)
    , visibleChangedCallback(nullptr)
{
}

void QActionHandler::setChangedCallback(QActionChangedCallback callback) {
    changedCallback = callback;
}

void QActionHandler::setCheckableChangedCallback(QActionCheckableChangedCallback callback) {
    checkableChangedCallback = callback;
}

void QActionHandler::setEnabledChangedCallback(QActionEnabledChangedCallback callback) {
    enabledChangedCallback = callback;
}

void QActionHandler::setHoveredCallback(QActionHoveredCallback callback) {
    hoveredCallback = callback;
}

void QActionHandler::setToggledCallback(QActionToggledCallback callback) {
    toggledCallback = callback;
}

void QActionHandler::setTriggeredCallback(QActionTriggeredCallback callback) {
    triggeredCallback = callback;
}

void QActionHandler::setVisibleChangedCallback(QActionVisibleChangedCallback callback) {
    visibleChangedCallback = callback;
}

void QActionHandler::onChanged() {
    if (changedCallback) {
        changedCallback(parent());
    }
}

void QActionHandler::onCheckableChanged(bool checkable) {
    if (checkableChangedCallback) {
        checkableChangedCallback(parent(), checkable);
    }
}

void QActionHandler::onEnabledChanged(bool enabled) {
    if (enabledChangedCallback) {
        enabledChangedCallback(parent(), enabled);
    }
}

void QActionHandler::onHovered() {
    if (hoveredCallback) {
        hoveredCallback(parent());
    }
}

void QActionHandler::onToggled(bool checked) {
    if (toggledCallback) {
        toggledCallback(parent(), checked);
    }
}

void QActionHandler::onTriggered(bool checked) {
    if (triggeredCallback) {
        triggeredCallback(parent(), checked);
    }
}

void QActionHandler::onVisibleChanged() {
    if (visibleChangedCallback) {
        visibleChangedCallback(parent());
    }
}
