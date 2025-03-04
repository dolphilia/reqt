#include "QMdiSubWindowHandler.h"

QMdiSubWindowHandler::QMdiSubWindowHandler(QObject* parent)
    : QObject(parent)
    , windowStateChangedCallback(nullptr)
    , aboutToActivateCallback(nullptr) {
}

void QMdiSubWindowHandler::setWindowStateChangedCallback(QMdiSubWindow_WindowStateChangedCallback callback) {
    windowStateChangedCallback = callback;
}

void QMdiSubWindowHandler::setAboutToActivateCallback(QMdiSubWindow_AboutToActivateCallback callback) {
    aboutToActivateCallback = callback;
}

void QMdiSubWindowHandler::onWindowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState) const {
    if (windowStateChangedCallback) {
        windowStateChangedCallback(parent(), static_cast<int>(oldState), static_cast<int>(newState));
    }
}

void QMdiSubWindowHandler::onAboutToActivate() const {
    if (aboutToActivateCallback) {
        aboutToActivateCallback(parent());
    }
}
