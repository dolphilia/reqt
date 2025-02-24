#include "QGraphicsViewHandler.h"

QGraphicsViewHandler::QGraphicsViewHandler(QObject* parent)
    : QObject(parent)
    , view(nullptr)
    , sceneRectChangedCallback(nullptr)
    , scaleChangedCallback(nullptr)
    , transformChangedCallback(nullptr)
{
}

void QGraphicsViewHandler::setView(QGraphicsView* view) {
    this->view = view;
    if (view && view->scene()) {
        connect(view->scene(), &QGraphicsScene::sceneRectChanged, this, &QGraphicsViewHandler::onSceneRectChanged);
    }
    // Note: Scale and transform changes are monitored through the view's transformations
}

void QGraphicsViewHandler::setSceneRectChangedCallback(SceneRectChangedCallback callback) {
    sceneRectChangedCallback = callback;
}

void QGraphicsViewHandler::setScaleChangedCallback(ScaleChangedCallback callback) {
    scaleChangedCallback = callback;
}

void QGraphicsViewHandler::setTransformChangedCallback(TransformChangedCallback callback) {
    transformChangedCallback = callback;
}

void QGraphicsViewHandler::onSceneRectChanged(const QRectF& rect) {
    if (sceneRectChangedCallback && view) {
        sceneRectChangedCallback(view, rect.x(), rect.y(), rect.width(), rect.height());
    }
}

void QGraphicsViewHandler::onScaleChanged(qreal sx, qreal sy) {
    if (scaleChangedCallback && view) {
        scaleChangedCallback(view, sx, sy);
    }
}

void QGraphicsViewHandler::onTransformChanged() {
    if (transformChangedCallback && view) {
        transformChangedCallback(view);
    }
}
