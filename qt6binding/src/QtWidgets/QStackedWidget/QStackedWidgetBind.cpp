#include "QStackedWidgetBind.h"
#include "QStackedWidgetHandler.h"

QStackedWidgetBind::QStackedWidgetBind(QWidget* parent)
    : QStackedWidget(parent)
    , handler(new QStackedWidgetHandler(this)) {
    connect(this, &QStackedWidget::currentChanged, handler, &QStackedWidgetHandler::onCurrentChanged);
    connect(this, &QStackedWidget::widgetRemoved, handler, &QStackedWidgetHandler::onWidgetRemoved);
}

QStackedWidgetBind::~QStackedWidgetBind() {
    delete handler;
}

void QStackedWidgetBind::setCurrentChangedCallback(QStackedWidget_CurrentChangedCallback callback) const {
    handler->setCurrentChangedCallback(callback);
}

void QStackedWidgetBind::setWidgetRemovedCallback(QStackedWidget_WidgetRemovedCallback callback) const {
    handler->setWidgetRemovedCallback(callback);
}
