#include "QMainWindowBind.h"
#include "QMainWindowHandler.h"

QMainWindowBind::QMainWindowBind(QWidget* parent)
    : QMainWindow(parent)
    , handler(new QMainWindowHandler(this)) {
    connect(this, &QMainWindow::windowTitleChanged, handler, &QMainWindowHandler::onWindowTitleChanged);
}

QMainWindowBind::~QMainWindowBind() {
    delete handler;
}

void QMainWindowBind::setWindowTitleChangedCallback(QMainWindow_WindowTitleChangedCallback callback) const {
    handler->setWindowTitleCallback(callback);
}
