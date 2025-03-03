#include "QGraphicsViewBind.h"
#include "qgraphicsview.h"
#include <QGraphicsScene>
#include <QRectF>
#include <QTransform>

extern "C" {

void* QGraphicsView_create(void* parent) {
    return new QGraphicsViewBind(static_cast<QWidget*>(parent));
}

void* QGraphicsView_createWithScene(void* scene, void* parent) {
    return new QGraphicsViewBind(static_cast<QGraphicsScene*>(scene), static_cast<QWidget*>(parent));
}

void QGraphicsView_delete(void* view) {
    delete static_cast<QGraphicsViewBind*>(view);
}

void QGraphicsView_setScene(void* view, void* scene) {
    static_cast<QGraphicsViewBind*>(view)->setScene(static_cast<QGraphicsScene*>(scene));
}

void* QGraphicsView_scene(void* view) {
    return static_cast<QGraphicsViewBind*>(view)->scene();
}

void QGraphicsView_setSceneRect(void* view, double x, double y, double width, double height) {
    static_cast<QGraphicsViewBind*>(view)->setSceneRect(x, y, width, height);
}

void QGraphicsView_sceneRect(void* view, double* x, double* y, double* width, double* height) {
    QRectF rect = static_cast<QGraphicsViewBind*>(view)->sceneRect();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QGraphicsView_setHorizontalScrollBarPolicy(void* view, int policy) {
    static_cast<QGraphicsViewBind*>(view)->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

void QGraphicsView_setVerticalScrollBarPolicy(void* view, int policy) {
    static_cast<QGraphicsViewBind*>(view)->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

void QGraphicsView_scale(void* view, double sx, double sy) {
    static_cast<QGraphicsViewBind*>(view)->scale(sx, sy);
}

void QGraphicsView_rotate(void* view, double angle) {
    static_cast<QGraphicsViewBind*>(view)->rotate(angle);
}

void QGraphicsView_translate(void* view, double dx, double dy) {
    static_cast<QGraphicsViewBind*>(view)->translate(dx, dy);
}

void QGraphicsView_resetTransform(void* view) {
    static_cast<QGraphicsViewBind*>(view)->resetTransform();
}

void QGraphicsView_centerOn(void* view, double x, double y) {
    static_cast<QGraphicsViewBind*>(view)->centerOn(QPointF(x, y));
}

void QGraphicsView_ensureVisible(void* view, double x, double y, double width, double height) {
    static_cast<QGraphicsViewBind*>(view)->ensureVisible(QRectF(x, y, width, height));
}

void QGraphicsView_fitInView(void* view, double x, double y, double width, double height) {
    static_cast<QGraphicsViewBind*>(view)->fitInView(QRectF(x, y, width, height));
}

void QGraphicsView_setRenderHint(void* view, int hint, bool enabled) {
    static_cast<QGraphicsViewBind*>(view)->setRenderHint(static_cast<QPainter::RenderHint>(hint), enabled);
}

void QGraphicsView_setDragMode(void* view, int mode) {
    static_cast<QGraphicsViewBind*>(view)->setDragMode(static_cast<QGraphicsView::DragMode>(mode));
}

typedef void (*SceneRectChangedCallback)(void*, double, double, double, double);
typedef void (*ScaleChangedCallback)(void*, double, double);
typedef void (*TransformChangedCallback)(void*);

void QGraphicsView_setSceneRectChangedCallback(void* view, SceneRectChangedCallback callback) {
    static_cast<QGraphicsViewBind*>(view)->setSceneRectChangedCallback(callback);
}

void QGraphicsView_setScaleChangedCallback(void* view, ScaleChangedCallback callback) {
    static_cast<QGraphicsViewBind*>(view)->setScaleChangedCallback(callback);
}

void QGraphicsView_setTransformChangedCallback(void* view, TransformChangedCallback callback) {
    static_cast<QGraphicsViewBind*>(view)->setTransformChangedCallback(callback);
}

}
