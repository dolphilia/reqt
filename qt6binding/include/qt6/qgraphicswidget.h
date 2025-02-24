#ifndef QGRAPHICSWIDGET_H
#define QGRAPHICSWIDGET_H

#ifdef __cplusplus
extern "C" {
#endif

void* QGraphicsWidget_create(void* parent);
void QGraphicsWidget_delete(void* widget);
void QGraphicsWidget_setGeometry(void* widget, double x, double y, double width, double height);
void QGraphicsWidget_getGeometry(void* widget, double* x, double* y, double* width, double* height);
void QGraphicsWidget_setLayout(void* widget, void* layout);
void* QGraphicsWidget_layout(void* widget);
void QGraphicsWidget_adjustSize(void* widget);
void QGraphicsWidget_resize(void* widget, double width, double height);
void QGraphicsWidget_setMinimumSize(void* widget, double width, double height);
void QGraphicsWidget_setMaximumSize(void* widget, double width, double height);
void QGraphicsWidget_setSizePolicy(void* widget, int horizontal, int vertical);
void QGraphicsWidget_setWindowFlags(void* widget, int flags);
int QGraphicsWidget_windowFlags(void* widget);
void QGraphicsWidget_setWindowTitle(void* widget, const char* title);
void QGraphicsWidget_setGeometryChangedCallback(void* widget, void (*callback)(void*, double, double, double, double));
void QGraphicsWidget_setLayoutChangedCallback(void* widget, void (*callback)(void*));

#ifdef __cplusplus
}
#endif

#endif // QGRAPHICSWIDGET_H
