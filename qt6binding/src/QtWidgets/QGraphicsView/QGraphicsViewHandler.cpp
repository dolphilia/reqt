#include "QGraphicsViewHandler.h"

GraphicsViewHandler::GraphicsViewHandler(QObject* parent)
    : QObject(parent)
    , sceneRectChangedCallback(nullptr)
    , scaleChangedCallback(nullptr)
    , transformChangedCallback(nullptr) {
}

void GraphicsViewHandler::setSceneRectChangedCallback(SceneRectChangedCallback callback) {
    sceneRectChangedCallback = callback;
}

void GraphicsViewHandler::setScaleChangedCallback(ScaleChangedCallback callback) {
    scaleChangedCallback = callback;
}

void GraphicsViewHandler::setTransformChangedCallback(TransformChangedCallback callback) {
    transformChangedCallback = callback;
}

void GraphicsViewHandler::onSceneRectChanged(const QRectF& rect) const {
    if (sceneRectChangedCallback) {
        sceneRectChangedCallback(parent(), rect.x(), rect.y(), rect.width(), rect.height());
    }
}

void GraphicsViewHandler::onScaleChanged(qreal sx, qreal sy) const {
    if (scaleChangedCallback) {
        scaleChangedCallback(parent(), sx, sy);
    }
}

void GraphicsViewHandler::onTransformChanged() const {
    if (transformChangedCallback) {
        transformChangedCallback(parent());
    }
}
