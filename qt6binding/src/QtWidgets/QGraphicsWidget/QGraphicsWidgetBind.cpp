#include "QGraphicsWidgetBind.h"
#include "QGraphicsWidgetHandler.h"

QGraphicsWidgetBind::QGraphicsWidgetBind(QGraphicsItem* parent)
    : QGraphicsWidget(parent)
    , handler(new GraphicsWidgetHandler(this)) {
    connect(this, &QGraphicsWidget::geometryChanged, handler, &GraphicsWidgetHandler::onGeometryChanged);
    connect(this, &QGraphicsWidget::layoutChanged, handler, &GraphicsWidgetHandler::onLayoutChanged);
}

QGraphicsWidgetBind::~QGraphicsWidgetBind() {
    delete handler;
}

void QGraphicsWidgetBind::setGeometryChangedCallback(GeometryChangedCallback callback) const {
    handler->setGeometryChangedCallback(callback);
}

void QGraphicsWidgetBind::setLayoutChangedCallback(LayoutChangedCallback callback) const {
    handler->setLayoutChangedCallback(callback);
}
