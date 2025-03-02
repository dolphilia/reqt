#include "QMdiSubWindowHandler.h"

MdiSubWindowHandler::MdiSubWindowHandler(QObject* parent)
    : QObject(parent)
    , subWindow(nullptr)
    , windowStateChangedCallback(nullptr)
    , aboutToActivateCallback(nullptr)
{
}

void MdiSubWindowHandler::setSubWindow(QMdiSubWindow* subWindow) {
    this->subWindow = subWindow;
    connect(subWindow, &QMdiSubWindow::windowStateChanged, this, &MdiSubWindowHandler::onWindowStateChanged);
    connect(subWindow, &QMdiSubWindow::aboutToActivate, this, &MdiSubWindowHandler::onAboutToActivate);
}

void MdiSubWindowHandler::setWindowStateChangedCallback(WindowStateChangedCallback callback) {
    windowStateChangedCallback = callback;
}

void MdiSubWindowHandler::setAboutToActivateCallback(AboutToActivateCallback callback) {
    aboutToActivateCallback = callback;
}

void MdiSubWindowHandler::onWindowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState) {
    if (windowStateChangedCallback && subWindow) {
        windowStateChangedCallback(subWindow, static_cast<int>(oldState), static_cast<int>(newState));
    }
}

void MdiSubWindowHandler::onAboutToActivate() {
    if (aboutToActivateCallback && subWindow) {
        aboutToActivateCallback(subWindow);
    }
}
