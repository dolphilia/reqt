#include "QMainWindowHandler.h"

MainWindowHandler::MainWindowHandler(QObject* parent)
    : QObject(parent)
    , titleCallback(nullptr) {
}

void MainWindowHandler::setWindowTitleCallback(WindowTitleChangedCallback callback) {
    titleCallback = callback;
}

void MainWindowHandler::onWindowTitleChanged(const QString& title) const {
    if (titleCallback) {
        titleCallback(parent(), title.toUtf8().constData());
    }
}
