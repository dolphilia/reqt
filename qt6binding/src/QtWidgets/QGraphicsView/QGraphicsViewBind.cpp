#include "QGraphicsViewBind.h"

QGraphicsViewBind::QGraphicsViewBind(QWidget* parent)
    : QGraphicsView(parent)
    , handler(new GraphicsViewHandler(this)) {
    if (scene()) {
        connect(scene(), &QGraphicsScene::sceneRectChanged, handler, &GraphicsViewHandler::onSceneRectChanged);
    }
}

QGraphicsViewBind::QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent)
    , handler(new GraphicsViewHandler(this)) {
    if (scene) {
        connect(scene, &QGraphicsScene::sceneRectChanged, handler, &GraphicsViewHandler::onSceneRectChanged);
    }
}

QGraphicsViewBind::~QGraphicsViewBind() {
    delete handler;
}

void QGraphicsViewBind::setSceneRectChangedCallback(SceneRectChangedCallback callback) const {
    handler->setSceneRectChangedCallback(callback);
}

void QGraphicsViewBind::setScaleChangedCallback(ScaleChangedCallback callback) const {
    handler->setScaleChangedCallback(callback);
}

void QGraphicsViewBind::setTransformChangedCallback(TransformChangedCallback callback) const {
    handler->setTransformChangedCallback(callback);
}
