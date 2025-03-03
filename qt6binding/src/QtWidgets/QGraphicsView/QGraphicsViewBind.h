#ifndef QGRAPHICSVIEW_BIND_H
#define QGRAPHICSVIEW_BIND_H

#include <QGraphicsView>
#include "QGraphicsViewHandler.h"

class QGraphicsViewBind : public QGraphicsView {
    Q_OBJECT
    typedef void (*SceneRectChangedCallback)(void*, double, double, double, double);
    typedef void (*ScaleChangedCallback)(void*, double, double);
    typedef void (*TransformChangedCallback)(void*);
public:
    explicit QGraphicsViewBind(QWidget* parent = nullptr);
    explicit QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent = nullptr);
    ~QGraphicsViewBind() override;

    void setSceneRectChangedCallback(SceneRectChangedCallback callback) const;
    void setScaleChangedCallback(ScaleChangedCallback callback) const;
    void setTransformChangedCallback(TransformChangedCallback callback) const;

private:
    GraphicsViewHandler* handler;
};

#endif // QGRAPHICSVIEW_BIND_H
