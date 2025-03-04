#include "QGraphicsViewBind.h"

QGraphicsViewBind::QGraphicsViewBind(QWidget* parent)
    : QGraphicsView(parent)
    , handler(new QGraphicsViewHandler(this)) {
    if (scene()) {
        connect(scene(), &QGraphicsScene::sceneRectChanged, handler, &QGraphicsViewHandler::onSceneRectChanged);
    }
}

QGraphicsViewBind::QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent)
    , handler(new QGraphicsViewHandler(this)) {
    if (scene) {
        connect(scene, &QGraphicsScene::sceneRectChanged, handler, &QGraphicsViewHandler::onSceneRectChanged);
    }
}

QGraphicsViewBind::~QGraphicsViewBind() {
    delete handler;
}

void QGraphicsViewBind::setSceneRectChangedCallback(QGraphicsView_SceneRectChangedCallback callback) const {
    handler->setSceneRectChangedCallback(callback);
}

void QGraphicsViewBind::setScaleChangedCallback(QGraphicsView_ScaleChangedCallback callback) const {
    handler->setScaleChangedCallback(callback);
}

void QGraphicsViewBind::setTransformChangedCallback(QGraphicsView_TransformChangedCallback callback) const {
    handler->setTransformChangedCallback(callback);
}
