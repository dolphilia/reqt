#include "QWidgetHandler.h"

QWidgetHandler::QWidgetHandler(QObject* parent)
    : QObject(parent)
    , customContextMenuRequestedCallback(nullptr)
    , windowIconChangedCallback(nullptr)
    , windowTitleChangedCallback(nullptr) {
}

void QWidgetHandler::setCustomContextMenuRequestedCallback(QWidget_CustomContextMenuRequestedCallback callback) {
    customContextMenuRequestedCallback = callback;
}

void QWidgetHandler::setWindowIconChangedCallback(QWidget_WindowIconChangedCallback callback) {
    windowIconChangedCallback = callback;
}

void QWidgetHandler::setWindowTitleChangedCallback(QWidget_WindowTitleChangedCallback callback) {
    windowTitleChangedCallback = callback;
}

void QWidgetHandler::onCustomContextMenuRequested(const QPoint &pos) const {
    if (customContextMenuRequestedCallback) {
        customContextMenuRequestedCallback(parent(), &pos);
    }
}

void QWidgetHandler::onWindowIconChanged(const QIcon &icon) const {
    if (windowIconChangedCallback) {
        windowIconChangedCallback(parent(), &icon);
    }
}

void QWidgetHandler::onWindowTitleChanged(const QString &title) const {
    if (windowTitleChangedCallback) {
        windowTitleChangedCallback(parent(), &title);
    }
}
