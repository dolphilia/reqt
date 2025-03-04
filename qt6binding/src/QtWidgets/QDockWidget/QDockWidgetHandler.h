#ifndef DOCKWIDGET_HANDLER_H
#define DOCKWIDGET_HANDLER_H

#include <QObject>
#include <QDockWidget>

class QDockWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*QDockWidget_AllowedAreasChangedCallback)(void*, int);
    typedef void (*QDockWidget_DockLocationChangedCallback)(void*, int);
    typedef void (*QDockWidget_FeaturesChangedCallback)(void*, int);
    typedef void (*QDockWidget_TopLevelChangedCallback)(void*, bool);
    typedef void (*QDockWidget_VisibilityChangedCallback)(void*, bool);
public:
    explicit QDockWidgetHandler(QObject* parent = nullptr);
    void setAllowedAreasChangedCallback(QDockWidget_AllowedAreasChangedCallback callback);
    void setDockLocationChangedCallback(QDockWidget_DockLocationChangedCallback callback);
    void setFeaturesChangedCallback(QDockWidget_FeaturesChangedCallback callback);
    void setTopLevelChangedCallback(QDockWidget_TopLevelChangedCallback callback);
    void setVisibilityChangedCallback(QDockWidget_VisibilityChangedCallback callback);
public slots:
    void onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) const;
    void onDockLocationChanged(Qt::DockWidgetArea area) const;
    void onFeaturesChanged(QDockWidget::DockWidgetFeatures features) const;
    void onTopLevelChanged(bool topLevel) const;
    void onVisibilityChanged(bool visible) const;
private:
    QDockWidget_AllowedAreasChangedCallback allowedAreasChangedCallback;
    QDockWidget_DockLocationChangedCallback dockLocationChangedCallback;
    QDockWidget_FeaturesChangedCallback featuresChangedCallback;
    QDockWidget_TopLevelChangedCallback topLevelChangedCallback;
    QDockWidget_VisibilityChangedCallback visibilityChangedCallback;
};

#endif // DOCKWIDGET_HANDLER_H
