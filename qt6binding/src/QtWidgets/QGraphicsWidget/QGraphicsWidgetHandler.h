#ifndef GRAPHICSWIDGET_HANDLER_H
#define GRAPHICSWIDGET_HANDLER_H

#include <QObject>
#include <QGraphicsWidget>

class QGraphicsWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*QGraphicsWidget_GeometryChangedCallback)(void*, double, double, double, double);
    typedef void (*QGraphicsWidget_LayoutChangedCallback)(void*);
public:
    explicit QGraphicsWidgetHandler(QObject* parent = nullptr);
    void setGeometryChangedCallback(QGraphicsWidget_GeometryChangedCallback callback);
    void setLayoutChangedCallback(QGraphicsWidget_LayoutChangedCallback callback);
public slots:
    void onGeometryChanged();
    void onLayoutChanged();
private:
    QGraphicsWidget_GeometryChangedCallback geometryChangedCallback;
    QGraphicsWidget_LayoutChangedCallback layoutChangedCallback;
};

#endif // GRAPHICSWIDGET_HANDLER_H
