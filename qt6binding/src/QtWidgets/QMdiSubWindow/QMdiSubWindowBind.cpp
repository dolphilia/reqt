#include "QMdiSubWindowBind.h"
#include "QMdiSubWindowHandler.h"

QMdiSubWindowBind::QMdiSubWindowBind(QWidget* parent)
    : QMdiSubWindow(parent)
    , handler(new QMdiSubWindowHandler(this)) {
    connect(this, &QMdiSubWindow::windowStateChanged, handler, &QMdiSubWindowHandler::onWindowStateChanged);
    connect(this, &QMdiSubWindow::aboutToActivate, handler, &QMdiSubWindowHandler::onAboutToActivate);
}

QMdiSubWindowBind::~QMdiSubWindowBind() {
    delete handler;
}

void QMdiSubWindowBind::setWindowStateChangedCallback(QMdiSubWindow_WindowStateChangedCallback callback) const {
    handler->setWindowStateChangedCallback(callback);
}

void QMdiSubWindowBind::setAboutToActivateCallback(QMdiSubWindow_AboutToActivateCallback callback) const {
    handler->setAboutToActivateCallback(callback);
}
