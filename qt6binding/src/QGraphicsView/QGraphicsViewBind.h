#ifndef QGRAPHICSVIEW_BIND_H
#define QGRAPHICSVIEW_BIND_H

#include <QGraphicsView>
#include "QGraphicsViewHandler.h"

class QGraphicsViewBind : public QGraphicsView {
    Q_OBJECT

public:
    explicit QGraphicsViewBind(QWidget* parent = nullptr);
    explicit QGraphicsViewBind(QGraphicsScene* scene, QWidget* parent = nullptr);
    ~QGraphicsViewBind() override;

    void setSceneRectChangedCallback(void (*callback)(void*, double, double, double, double));
    void setScaleChangedCallback(void (*callback)(void*, double, double));
    void setTransformChangedCallback(void (*callback)(void*));

private:
    QGraphicsViewHandler* handler;
};

#endif // QGRAPHICSVIEW_BIND_H
