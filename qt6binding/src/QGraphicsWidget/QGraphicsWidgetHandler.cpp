#include "QGraphicsWidgetHandler.h"
#include <QRectF>

QGraphicsWidgetHandler::QGraphicsWidgetHandler(QObject* parent)
    : QObject(parent)
    , widget(nullptr)
    , geometryChangedCallback(nullptr)
    , layoutChangedCallback(nullptr)
{
}

void QGraphicsWidgetHandler::setWidget(QGraphicsWidget* widget) {
    this->widget = widget;
    if (widget) {
        connect(widget, &QGraphicsWidget::geometryChanged, this, &QGraphicsWidgetHandler::onGeometryChanged);
        connect(widget, &QGraphicsWidget::layoutChanged, this, &QGraphicsWidgetHandler::onLayoutChanged);
    }
}

void QGraphicsWidgetHandler::setGeometryChangedCallback(GeometryChangedCallback callback) {
    geometryChangedCallback = callback;
}

void QGraphicsWidgetHandler::setLayoutChangedCallback(LayoutChangedCallback callback) {
    layoutChangedCallback = callback;
}

void QGraphicsWidgetHandler::onGeometryChanged() {
    if (geometryChangedCallback && widget) {
        QRectF rect = widget->geometry();
        geometryChangedCallback(widget, rect.x(), rect.y(), rect.width(), rect.height());
    }
}

void QGraphicsWidgetHandler::onLayoutChanged() {
    if (layoutChangedCallback && widget) {
        layoutChangedCallback(widget);
    }
}
