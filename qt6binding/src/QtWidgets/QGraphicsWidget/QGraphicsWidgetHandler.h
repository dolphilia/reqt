#ifndef GRAPHICSWIDGET_HANDLER_H
#define GRAPHICSWIDGET_HANDLER_H

#include <QObject>
#include <QGraphicsWidget>

class GraphicsWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*GeometryChangedCallback)(void*, double, double, double, double);
    typedef void (*LayoutChangedCallback)(void*);
public:
    explicit GraphicsWidgetHandler(QObject* parent = nullptr);
    void setGeometryChangedCallback(GeometryChangedCallback callback);
    void setLayoutChangedCallback(LayoutChangedCallback callback);
public slots:
    void onGeometryChanged();
    void onLayoutChanged();
private:
    GeometryChangedCallback geometryChangedCallback;
    LayoutChangedCallback layoutChangedCallback;
};

#endif // GRAPHICSWIDGET_HANDLER_H
