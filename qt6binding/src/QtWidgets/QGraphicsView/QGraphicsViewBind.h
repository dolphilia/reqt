#ifndef QGRAPHICSVIEW_BIND_H
#define QGRAPHICSVIEW_BIND_H

#include <QGraphicsView>
#include "QGraphicsViewHandler.h"

class QGraphicsViewBind : public QGraphicsView {
    Q_OBJECT
    typedef void (*QGraphicsView_SceneRectChangedCallback)(void*, double, double, double, double);
    typedef void (*QGraphicsView_ScaleChangedCallback)(void*, double, double);
    typedef void (*QGraphicsView_TransformChangedCallback)(void*);
public:
    explicit QGraphicsViewBind(QWidget* parent = nullptr);
    explicit QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent = nullptr);
    ~QGraphicsViewBind() override;

    void setSceneRectChangedCallback(QGraphicsView_SceneRectChangedCallback callback) const;
    void setScaleChangedCallback(QGraphicsView_ScaleChangedCallback callback) const;
    void setTransformChangedCallback(QGraphicsView_TransformChangedCallback callback) const;

private:
    QGraphicsViewHandler* handler;
};

#endif // QGRAPHICSVIEW_BIND_H
