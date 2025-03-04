#include "QGraphicsWidgetBind.h"
#include "QGraphicsWidgetHandler.h"

QGraphicsWidgetBind::QGraphicsWidgetBind(QGraphicsItem* parent)
    : QGraphicsWidget(parent)
    , handler(new QGraphicsWidgetHandler(this)) {
    connect(this, &QGraphicsWidget::geometryChanged, handler, &QGraphicsWidgetHandler::onGeometryChanged);
    connect(this, &QGraphicsWidget::layoutChanged, handler, &QGraphicsWidgetHandler::onLayoutChanged);
}

QGraphicsWidgetBind::~QGraphicsWidgetBind() {
    delete handler;
}

void QGraphicsWidgetBind::setGeometryChangedCallback(QGraphicsWidget_GeometryChangedCallback callback) const {
    handler->setGeometryChangedCallback(callback);
}

void QGraphicsWidgetBind::setLayoutChangedCallback(QGraphicsWidget_LayoutChangedCallback callback) const {
    handler->setLayoutChangedCallback(callback);
}
