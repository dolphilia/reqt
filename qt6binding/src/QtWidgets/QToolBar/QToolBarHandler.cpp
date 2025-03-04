#include "QToolBarHandler.h"

QToolBarHandler::QToolBarHandler(QObject* parent)
    : QObject(parent)
    , actionTriggeredCallback(nullptr)
    , movableChangedCallback(nullptr)
    , orientationChangedCallback(nullptr)
    , topLevelChangedCallback(nullptr)
    , visibilityChangedCallback(nullptr)
    , allowedAreasChangedCallback(nullptr) {
}

void QToolBarHandler::setActionTriggeredCallback(QToolBar_ActionTriggeredCallback callback) {
    actionTriggeredCallback = callback;
}

void QToolBarHandler::setMovableChangedCallback(QToolBar_MovableChangedCallback callback) {
    movableChangedCallback = callback;
}

void QToolBarHandler::setOrientationChangedCallback(QToolBar_OrientationChangedCallback callback) {
    orientationChangedCallback = callback;
}

void QToolBarHandler::setTopLevelChangedCallback(QToolBar_TopLevelChangedCallback callback) {
    topLevelChangedCallback = callback;
}

void QToolBarHandler::setVisibilityChangedCallback(QToolBar_VisibilityChangedCallback callback) {
    visibilityChangedCallback = callback;
}

void QToolBarHandler::setAllowedAreasChangedCallback(QToolBar_AllowedAreasChangedCallback callback) {
    allowedAreasChangedCallback = callback;
}

void QToolBarHandler::onActionTriggered(QAction* action) const {
    if (actionTriggeredCallback) {
        actionTriggeredCallback(parent(), action);
    }
}

void QToolBarHandler::onMovableChanged(bool movable) const {
    if (movableChangedCallback) {
        movableChangedCallback(parent(), movable);
    }
}

void QToolBarHandler::onOrientationChanged(int orientation) const {
    if (orientationChangedCallback) {
        orientationChangedCallback(parent(), orientation);
    }
}

void QToolBarHandler::onTopLevelChanged(bool topLevel) const {
    if (topLevelChangedCallback) {
        topLevelChangedCallback(parent(), topLevel);
    }
}

void QToolBarHandler::onVisibilityChanged(bool visible) const {
    if (visibilityChangedCallback) {
        visibilityChangedCallback(parent(), visible);
    }
}

void QToolBarHandler::onAllowedAreasChanged(int areas) const {
    if (allowedAreasChangedCallback) {
        allowedAreasChangedCallback(parent(), areas);
    }
}
