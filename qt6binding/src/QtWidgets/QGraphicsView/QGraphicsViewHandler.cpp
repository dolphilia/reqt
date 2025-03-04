#include "QGraphicsViewHandler.h"

QGraphicsViewHandler::QGraphicsViewHandler(QObject* parent)
    : QObject(parent)
    , sceneRectChangedCallback(nullptr)
    , scaleChangedCallback(nullptr)
    , transformChangedCallback(nullptr) {
}

void QGraphicsViewHandler::setSceneRectChangedCallback(QGraphicsView_SceneRectChangedCallback callback) {
    sceneRectChangedCallback = callback;
}

void QGraphicsViewHandler::setScaleChangedCallback(QGraphicsView_ScaleChangedCallback callback) {
    scaleChangedCallback = callback;
}

void QGraphicsViewHandler::setTransformChangedCallback(QGraphicsView_TransformChangedCallback callback) {
    transformChangedCallback = callback;
}

void QGraphicsViewHandler::onSceneRectChanged(const QRectF& rect) const {
    if (sceneRectChangedCallback) {
        sceneRectChangedCallback(parent(), rect.x(), rect.y(), rect.width(), rect.height());
    }
}

void QGraphicsViewHandler::onScaleChanged(qreal sx, qreal sy) const {
    if (scaleChangedCallback) {
        scaleChangedCallback(parent(), sx, sy);
    }
}

void QGraphicsViewHandler::onTransformChanged() const {
    if (transformChangedCallback) {
        transformChangedCallback(parent());
    }
}
