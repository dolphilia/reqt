#ifndef QGRAPHICSWIDGET_BIND_H
#define QGRAPHICSWIDGET_BIND_H

#include <QGraphicsWidget>
#include "QGraphicsWidgetHandler.h"

class QGraphicsWidgetBind : public QGraphicsWidget {
    Q_OBJECT

public:
    explicit QGraphicsWidgetBind(QGraphicsItem* parent = nullptr);
    ~QGraphicsWidgetBind() override;

    void setGeometryChangedCallback(void (*callback)(void*, double, double, double, double));
    void setLayoutChangedCallback(void (*callback)(void*));

private:
    QGraphicsWidgetHandler* handler;
};

#endif // QGRAPHICSWIDGET_BIND_H
