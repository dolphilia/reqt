#ifndef QGRAPHICSVIEW_H
#define QGRAPHICSVIEW_H

#ifdef __cplusplus
extern "C" {
#endif

void* QGraphicsView_create(void* parent);
void* QGraphicsView_createWithScene(void* scene, void* parent);
void QGraphicsView_delete(void* view);
void QGraphicsView_setScene(void* view, void* scene);
void* QGraphicsView_scene(void* view);
void QGraphicsView_setSceneRect(void* view, double x, double y, double width, double height);
void QGraphicsView_sceneRect(void* view, double* x, double* y, double* width, double* height);
void QGraphicsView_setHorizontalScrollBarPolicy(void* view, int policy);
void QGraphicsView_setVerticalScrollBarPolicy(void* view, int policy);
void QGraphicsView_scale(void* view, double sx, double sy);
void QGraphicsView_rotate(void* view, double angle);
void QGraphicsView_translate(void* view, double dx, double dy);
void QGraphicsView_resetTransform(void* view);
void QGraphicsView_centerOn(void* view, double x, double y);
void QGraphicsView_ensureVisible(void* view, double x, double y, double width, double height);
void QGraphicsView_fitInView(void* view, double x, double y, double width, double height);
void QGraphicsView_setRenderHint(void* view, int hint, bool enabled);
void QGraphicsView_setDragMode(void* view, int mode);
void QGraphicsView_setSceneRectChangedCallback(void* view, void (*callback)(void*, double, double, double, double));
void QGraphicsView_setScaleChangedCallback(void* view, void (*callback)(void*, double, double));
void QGraphicsView_setTransformChangedCallback(void* view, void (*callback)(void*));

#ifdef __cplusplus
}
#endif

#endif // QGRAPHICSVIEW_H
