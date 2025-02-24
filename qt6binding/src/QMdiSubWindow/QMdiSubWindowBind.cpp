#include "QMdiSubWindowBind.h"
#include "qmdisubwindow.h"

QMdiSubWindowBind::QMdiSubWindowBind(QWidget* parent)
    : QMdiSubWindow(parent)
    , handler(new MdiSubWindowHandler(this))
{
    connect(this, &QMdiSubWindow::windowStateChanged, handler, &MdiSubWindowHandler::onWindowStateChanged);
    connect(this, &QMdiSubWindow::aboutToActivate, handler, &MdiSubWindowHandler::onAboutToActivate);
    handler->setSubWindow(this);
}

QMdiSubWindowBind::~QMdiSubWindowBind() {
    delete handler;
}

void QMdiSubWindowBind::setWindowStateChangedCallback(void (*callback)(void*, int, int)) {
    handler->setWindowStateChangedCallback(callback);
}

void QMdiSubWindowBind::setAboutToActivateCallback(void (*callback)(void*)) {
    handler->setAboutToActivateCallback(callback);
}
