#include "QGraphicsWidgetBind.h"
#include <QSizePolicy>
#include <QGraphicsLayout>
#include "qgraphicswidget.h"

extern "C" {

void* QGraphicsWidget_create(void* parent) {
    return new QGraphicsWidgetBind(static_cast<QGraphicsItem*>(parent));
}

void QGraphicsWidget_delete(void* widget) {
    delete static_cast<QGraphicsWidgetBind*>(widget);
}

void QGraphicsWidget_setGeometry(void* widget, double x, double y, double width, double height) {
    static_cast<QGraphicsWidgetBind*>(widget)->setGeometry(x, y, width, height);
}

void QGraphicsWidget_getGeometry(void* widget, double* x, double* y, double* width, double* height) {
    QRectF rect = static_cast<QGraphicsWidgetBind*>(widget)->geometry();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QGraphicsWidget_setLayout(void* widget, void* layout) {
    static_cast<QGraphicsWidgetBind*>(widget)->setLayout(static_cast<QGraphicsLayout*>(layout));
}

void* QGraphicsWidget_layout(void* widget) {
    return static_cast<QGraphicsWidgetBind*>(widget)->layout();
}

void QGraphicsWidget_adjustSize(void* widget) {
    static_cast<QGraphicsWidgetBind*>(widget)->adjustSize();
}

void QGraphicsWidget_resize(void* widget, double width, double height) {
    static_cast<QGraphicsWidgetBind*>(widget)->resize(width, height);
}

void QGraphicsWidget_setMinimumSize(void* widget, double width, double height) {
    static_cast<QGraphicsWidgetBind*>(widget)->setMinimumSize(width, height);
}

void QGraphicsWidget_setMaximumSize(void* widget, double width, double height) {
    static_cast<QGraphicsWidgetBind*>(widget)->setMaximumSize(width, height);
}

void QGraphicsWidget_setSizePolicy(void* widget, int horizontal, int vertical) {
    static_cast<QGraphicsWidgetBind*>(widget)->setSizePolicy(
        static_cast<QSizePolicy::Policy>(horizontal),
        static_cast<QSizePolicy::Policy>(vertical)
    );
}

void QGraphicsWidget_setWindowFlags(void* widget, int flags) {
    static_cast<QGraphicsWidgetBind*>(widget)->setWindowFlags(static_cast<Qt::WindowFlags>(flags));
}

int QGraphicsWidget_windowFlags(void* widget) {
    return static_cast<int>(static_cast<QGraphicsWidgetBind*>(widget)->windowFlags());
}

void QGraphicsWidget_setWindowTitle(void* widget, const char* title) {
    static_cast<QGraphicsWidgetBind*>(widget)->setWindowTitle(QString::fromUtf8(title));
}

typedef void (*GeometryChangedCallback)(void*, double, double, double, double);
typedef void (*LayoutChangedCallback)(void*);

void QGraphicsWidget_setGeometryChangedCallback(void* widget, GeometryChangedCallback callback) {
    static_cast<QGraphicsWidgetBind*>(widget)->setGeometryChangedCallback(callback);
}

void QGraphicsWidget_setLayoutChangedCallback(void* widget, LayoutChangedCallback callback) {
    static_cast<QGraphicsWidgetBind*>(widget)->setLayoutChangedCallback(callback);
}

}
