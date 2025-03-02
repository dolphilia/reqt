#include "QStackedWidgetBind.h"

QStackedWidgetBind::QStackedWidgetBind(QWidget* parent)
    : QStackedWidget(parent)
    , handler(new QStackedWidgetHandler(this))
{
    handler->setStackedWidget(this);
}

QStackedWidgetBind::~QStackedWidgetBind() {
    delete handler;
}

void QStackedWidgetBind::setCurrentChangedCallback(void (*callback)(void*, int)) {
    handler->setCurrentChangedCallback(callback);
}

void QStackedWidgetBind::setWidgetRemovedCallback(void (*callback)(void*, int)) {
    handler->setWidgetRemovedCallback(callback);
}
