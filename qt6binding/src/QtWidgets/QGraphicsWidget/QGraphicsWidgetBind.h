#ifndef QGRAPHICSWIDGET_BIND_H
#define QGRAPHICSWIDGET_BIND_H

#include "QGraphicsWidgetHandler.h"
#include <QGraphicsWidget>

class QGraphicsWidgetBind : public QGraphicsWidget {
    Q_OBJECT
    typedef void (*GeometryChangedCallback)(void*, double, double, double, double);
    typedef void (*LayoutChangedCallback)(void*);
public:
    explicit QGraphicsWidgetBind(QGraphicsItem* parent = nullptr);
    ~QGraphicsWidgetBind() override;
    void setGeometryChangedCallback(GeometryChangedCallback callback) const;
    void setLayoutChangedCallback(LayoutChangedCallback callback) const;
private:
    GraphicsWidgetHandler* handler;
};

#endif // QGRAPHICSWIDGET_BIND_H
