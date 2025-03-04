#include "QTabWidgetBind.h"
#include "QTabWidgetHandler.h"

QTabWidgetBind::QTabWidgetBind(QWidget* parent)
    : QTabWidget(parent)
    , handler(new QTabWidgetHandler(this)) {
    connect(this, &QTabWidget::currentChanged, handler, &QTabWidgetHandler::onCurrentChanged);
    connect(this, &QTabWidget::tabCloseRequested, handler, &QTabWidgetHandler::onTabCloseRequested);
}

QTabWidgetBind::~QTabWidgetBind() {
    delete handler;
}

void QTabWidgetBind::setCurrentChangedCallback(QTabWidget_CurrentChangedCallback callback) const {
    handler->setCurrentChangedCallback(callback);
}

void QTabWidgetBind::setTabCloseRequestedCallback(QTabWidget_TabCloseRequestedCallback callback) const {
    handler->setTabCloseRequestedCallback(callback);
}
