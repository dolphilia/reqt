#ifndef QGRAPHICSVIEW_HANDLER_H
#define QGRAPHICSVIEW_HANDLER_H

#include <QObject>
#include <QGraphicsView>

typedef void (*SceneRectChangedCallback)(void*, double, double, double, double);
typedef void (*ScaleChangedCallback)(void*, double, double);
typedef void (*TransformChangedCallback)(void*);

class QGraphicsViewHandler : public QObject {
    Q_OBJECT
public:
    explicit QGraphicsViewHandler(QObject* parent = nullptr);
    QGraphicsViewHandler(const QGraphicsViewHandler&) = delete;
    QGraphicsViewHandler& operator=(const QGraphicsViewHandler&) = delete;

    void setView(QGraphicsView* view);
    void setSceneRectChangedCallback(SceneRectChangedCallback callback);
    void setScaleChangedCallback(ScaleChangedCallback callback);
    void setTransformChangedCallback(TransformChangedCallback callback);

public slots:
    void onSceneRectChanged(const QRectF& rect);
    void onScaleChanged(qreal sx, qreal sy);
    void onTransformChanged();

private:
    QGraphicsView* view;
    SceneRectChangedCallback sceneRectChangedCallback;
    ScaleChangedCallback scaleChangedCallback;
    TransformChangedCallback transformChangedCallback;
};

#endif // QGRAPHICSVIEW_HANDLER_H
