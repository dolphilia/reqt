#ifndef GRAPHICSVIEW_HANDLER_H
#define GRAPHICSVIEW_HANDLER_H

#include <QObject>
#include <QGraphicsView>

class GraphicsViewHandler : public QObject {
    Q_OBJECT
    typedef void (*SceneRectChangedCallback)(void*, double, double, double, double);
    typedef void (*ScaleChangedCallback)(void*, double, double);
    typedef void (*TransformChangedCallback)(void*);
public:
    explicit GraphicsViewHandler(QObject* parent = nullptr);
    GraphicsViewHandler(const GraphicsViewHandler&) = delete;
    GraphicsViewHandler& operator=(const GraphicsViewHandler&) = delete;

    void setSceneRectChangedCallback(SceneRectChangedCallback callback);
    void setScaleChangedCallback(ScaleChangedCallback callback);
    void setTransformChangedCallback(TransformChangedCallback callback);

public slots:
    void onSceneRectChanged(const QRectF& rect) const;
    void onScaleChanged(qreal sx, qreal sy) const;
    void onTransformChanged() const;

private:
    SceneRectChangedCallback sceneRectChangedCallback;
    ScaleChangedCallback scaleChangedCallback;
    TransformChangedCallback transformChangedCallback;
};

#endif // GRAPHICSVIEW_HANDLER_H
