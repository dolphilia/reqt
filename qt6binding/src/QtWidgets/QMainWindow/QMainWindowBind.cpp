#include "QMainWindowBind.h"
#include "QMainWindowHandler.h"

QMainWindowBind::QMainWindowBind(QWidget* parent)
    : QMainWindow(parent)
    , handler(new MainWindowHandler(this)) {
    connect(this, &QMainWindow::windowTitleChanged, handler, &MainWindowHandler::onWindowTitleChanged);
}

QMainWindowBind::~QMainWindowBind() {
    delete handler;
}

void QMainWindowBind::setWindowTitleChangedCallback(WindowTitleChangedCallback callback) const {
    handler->setWindowTitleCallback(callback);
}
