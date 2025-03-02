#ifndef QGRAPHICSWIDGET_HANDLER_H
#define QGRAPHICSWIDGET_HANDLER_H

#include <QObject>
#include <QGraphicsWidget>

typedef void (*GeometryChangedCallback)(void*, double, double, double, double);
typedef void (*LayoutChangedCallback)(void*);

class QGraphicsWidgetHandler : public QObject {
    Q_OBJECT
public:
    explicit QGraphicsWidgetHandler(QObject* parent = nullptr);
    QGraphicsWidgetHandler(const QGraphicsWidgetHandler&) = delete;
    QGraphicsWidgetHandler& operator=(const QGraphicsWidgetHandler&) = delete;

    void setWidget(QGraphicsWidget* widget);
    void setGeometryChangedCallback(GeometryChangedCallback callback);
    void setLayoutChangedCallback(LayoutChangedCallback callback);

public slots:
    void onGeometryChanged();
    void onLayoutChanged();

private:
    QGraphicsWidget* widget;
    GeometryChangedCallback geometryChangedCallback;
    LayoutChangedCallback layoutChangedCallback;
};

#endif // QGRAPHICSWIDGET_HANDLER_H
