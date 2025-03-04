#include "QMainWindowHandler.h"

QMainWindowHandler::QMainWindowHandler(QObject* parent)
    : QObject(parent)
    , titleCallback(nullptr) {
}

void QMainWindowHandler::setWindowTitleCallback(QMainWindow_WindowTitleChangedCallback callback) {
    titleCallback = callback;
}

void QMainWindowHandler::onWindowTitleChanged(const QString& title) const {
    if (titleCallback) {
        titleCallback(parent(), title.toUtf8().constData());
    }
}
