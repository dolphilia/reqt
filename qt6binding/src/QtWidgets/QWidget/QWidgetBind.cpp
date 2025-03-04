#include "QWidgetBind.h"
#include "QWidgetHandler.h"

QWidgetBind::QWidgetBind(QWidget *parent)
    : QWidget(parent)
    , handler(new QWidgetHandler(this)) {
    // シグナルとスロットの接続
    connect(this, &QWidget::customContextMenuRequested, handler, &QWidgetHandler::onCustomContextMenuRequested);
    connect(this, &QWidget::windowIconChanged, handler, &QWidgetHandler::onWindowIconChanged);
    connect(this, &QWidget::windowTitleChanged, handler, &QWidgetHandler::onWindowTitleChanged);
}

QWidgetBind::~QWidgetBind() {
    delete handler;
}

// Signal callbacks
void QWidgetBind::setCustomContextMenuRequestedCallback(QWidget_CustomContextMenuRequestedCallback callback) const {
    handler->setCustomContextMenuRequestedCallback(callback);
}

void QWidgetBind::setWindowIconChangedCallback(QWidget_WindowIconChangedCallback callback) const {
    handler->setWindowIconChangedCallback(callback);
}

void QWidgetBind::setWindowTitleChangedCallback(QWidget_WindowTitleChangedCallback callback) const {
    handler->setWindowTitleChangedCallback(callback);
}
