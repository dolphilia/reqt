#include "QGraphicsViewBind.h"

QGraphicsViewBind::QGraphicsViewBind(QWidget* parent)
    : QGraphicsView(parent)
    , handler(new QGraphicsViewHandler(this))
{
    handler->setView(this);
}

QGraphicsViewBind::QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent)
    , handler(new QGraphicsViewHandler(this))
{
    handler->setView(this);
}

QGraphicsViewBind::~QGraphicsViewBind() {
    delete handler;
}

void QGraphicsViewBind::setSceneRectChangedCallback(void (*callback)(void*, double, double, double, double)) {
    handler->setSceneRectChangedCallback(callback);
}

void QGraphicsViewBind::setScaleChangedCallback(void (*callback)(void*, double, double)) {
    handler->setScaleChangedCallback(callback);
}

void QGraphicsViewBind::setTransformChangedCallback(void (*callback)(void*)) {
    handler->setTransformChangedCallback(callback);
}
