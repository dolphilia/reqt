#include "QGraphicsWidgetBind.h"

QGraphicsWidgetBind::QGraphicsWidgetBind(QGraphicsItem* parent)
    : QGraphicsWidget(parent)
    , handler(new QGraphicsWidgetHandler(this))
{
    handler->setWidget(this);
}

QGraphicsWidgetBind::~QGraphicsWidgetBind() {
    delete handler;
}

void QGraphicsWidgetBind::setGeometryChangedCallback(void (*callback)(void*, double, double, double, double)) {
    handler->setGeometryChangedCallback(callback);
}

void QGraphicsWidgetBind::setLayoutChangedCallback(void (*callback)(void*)) {
    handler->setLayoutChangedCallback(callback);
}
