#include "QGraphicsWidgetHandler.h"
#include <QRectF>

GraphicsWidgetHandler::GraphicsWidgetHandler(QObject* parent)
    : QObject(parent)
    , geometryChangedCallback(nullptr)
    , layoutChangedCallback(nullptr) {
}

void GraphicsWidgetHandler::setGeometryChangedCallback(GeometryChangedCallback callback) {
    geometryChangedCallback = callback;
}

void GraphicsWidgetHandler::setLayoutChangedCallback(LayoutChangedCallback callback) {
    layoutChangedCallback = callback;
}

void GraphicsWidgetHandler::onGeometryChanged() {
    if (geometryChangedCallback) {
        QGraphicsWidget* widget = qobject_cast<QGraphicsWidget*>(parent());
        if (widget) {
            QRectF rect = widget->geometry();
            geometryChangedCallback(parent(), rect.x(), rect.y(), rect.width(), rect.height());
        }
    }
}

void GraphicsWidgetHandler::onLayoutChanged() {
    if (layoutChangedCallback) {
        layoutChangedCallback(parent());
    }
}
