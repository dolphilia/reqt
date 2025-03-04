#ifndef GRAPHICSVIEW_HANDLER_H
#define GRAPHICSVIEW_HANDLER_H

#include <QObject>
#include <QGraphicsView>

class QGraphicsViewHandler : public QObject {
    Q_OBJECT
    typedef void (*QGraphicsView_SceneRectChangedCallback)(void*, double, double, double, double);
    typedef void (*QGraphicsView_ScaleChangedCallback)(void*, double, double);
    typedef void (*QGraphicsView_TransformChangedCallback)(void*);
public:
    explicit QGraphicsViewHandler(QObject* parent = nullptr);
    QGraphicsViewHandler(const QGraphicsViewHandler&) = delete;
    QGraphicsViewHandler& operator=(const QGraphicsViewHandler&) = delete;

    void setSceneRectChangedCallback(QGraphicsView_SceneRectChangedCallback callback);
    void setScaleChangedCallback(QGraphicsView_ScaleChangedCallback callback);
    void setTransformChangedCallback(QGraphicsView_TransformChangedCallback callback);

public slots:
    void onSceneRectChanged(const QRectF& rect) const;
    void onScaleChanged(qreal sx, qreal sy) const;
    void onTransformChanged() const;

private:
    QGraphicsView_SceneRectChangedCallback sceneRectChangedCallback;
    QGraphicsView_ScaleChangedCallback scaleChangedCallback;
    QGraphicsView_TransformChangedCallback transformChangedCallback;
};

#endif // GRAPHICSVIEW_HANDLER_H
