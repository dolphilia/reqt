#include "handler_mdi_sub_window.h"

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

void MdiSubWindowHandler::setWindowStateChangedCallback(void (*callback)(void*, int, int)) {
    windowStateChangedCallback = callback;
}

void MdiSubWindowHandler::setAboutToActivateCallback(void (*callback)(void*)) {
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
