#include "QGraphicsWidgetHandler.h"
#include <QRectF>

QGraphicsWidgetHandler::QGraphicsWidgetHandler(QObject* parent)
    : QObject(parent)
    , geometryChangedCallback(nullptr)
    , layoutChangedCallback(nullptr) {
}

void QGraphicsWidgetHandler::setGeometryChangedCallback(QGraphicsWidget_GeometryChangedCallback callback) {
    geometryChangedCallback = callback;
}

void QGraphicsWidgetHandler::setLayoutChangedCallback(QGraphicsWidget_LayoutChangedCallback callback) {
    layoutChangedCallback = callback;
}

void QGraphicsWidgetHandler::onGeometryChanged() {
    if (geometryChangedCallback) {
        QGraphicsWidget* widget = qobject_cast<QGraphicsWidget*>(parent());
        if (widget) {
            QRectF rect = widget->geometry();
            geometryChangedCallback(parent(), rect.x(), rect.y(), rect.width(), rect.height());
        }
    }
}

void QGraphicsWidgetHandler::onLayoutChanged() {
    if (layoutChangedCallback) {
        layoutChangedCallback(parent());
    }
}
