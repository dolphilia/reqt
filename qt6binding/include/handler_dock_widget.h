#ifndef DOCKWIDGET_HANDLER_H
#define DOCKWIDGET_HANDLER_H

#include <QObject>
#include <QDockWidget>

class DockWidgetHandler : public QObject {
    Q_OBJECT
public:
    explicit DockWidgetHandler(QObject* parent = nullptr);
    void setDockWidget(QDockWidget* dockWidget);
    void setAllowedAreasChangedCallback(void (*callback)(void*, int));
    void setDockLocationChangedCallback(void (*callback)(void*, int));
    void setFeaturesChangedCallback(void (*callback)(void*, int));
    void setTopLevelChangedCallback(void (*callback)(void*, bool));
    void setVisibilityChangedCallback(void (*callback)(void*, bool));

public slots:
    void onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas);
    void onDockLocationChanged(Qt::DockWidgetArea area);
    void onFeaturesChanged(QDockWidget::DockWidgetFeatures features);
    void onTopLevelChanged(bool topLevel);
    void onVisibilityChanged(bool visible);

private:
    QDockWidget* dockWidget;
    void (*allowedAreasChangedCallback)(void*, int);
    void (*dockLocationChangedCallback)(void*, int);
    void (*featuresChangedCallback)(void*, int);
    void (*topLevelChangedCallback)(void*, bool);
    void (*visibilityChangedCallback)(void*, bool);
};

#endif // DOCKWIDGET_HANDLER_H
