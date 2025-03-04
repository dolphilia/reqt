#ifndef QGRAPHICSWIDGET_BIND_H
#define QGRAPHICSWIDGET_BIND_H

#include "QGraphicsWidgetHandler.h"
#include <QGraphicsWidget>

class QGraphicsWidgetBind : public QGraphicsWidget {
    Q_OBJECT
    typedef void (*QGraphicsWidget_GeometryChangedCallback)(void*, double, double, double, double);
    typedef void (*QGraphicsWidget_LayoutChangedCallback)(void*);
public:
    explicit QGraphicsWidgetBind(QGraphicsItem* parent = nullptr);
    ~QGraphicsWidgetBind() override;
    void setGeometryChangedCallback(QGraphicsWidget_GeometryChangedCallback callback) const;
    void setLayoutChangedCallback(QGraphicsWidget_LayoutChangedCallback callback) const;
private:
    QGraphicsWidgetHandler* handler;
};

#endif // QGRAPHICSWIDGET_BIND_H
