#ifndef DOCKWIDGET_HANDLER_H
#define DOCKWIDGET_HANDLER_H

#include <QObject>
#include <QDockWidget>

class DockWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*AllowedAreasChangedCallback)(void*, int);
    typedef void (*DockLocationChangedCallback)(void*, int);
    typedef void (*FeaturesChangedCallback)(void*, int);
    typedef void (*TopLevelChangedCallback)(void*, bool);
    typedef void (*VisibilityChangedCallback)(void*, bool);
public:
    explicit DockWidgetHandler(QObject* parent = nullptr);
    void setAllowedAreasChangedCallback(AllowedAreasChangedCallback callback);
    void setDockLocationChangedCallback(DockLocationChangedCallback callback);
    void setFeaturesChangedCallback(FeaturesChangedCallback callback);
    void setTopLevelChangedCallback(TopLevelChangedCallback callback);
    void setVisibilityChangedCallback(VisibilityChangedCallback callback);
public slots:
    void onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) const;
    void onDockLocationChanged(Qt::DockWidgetArea area) const;
    void onFeaturesChanged(QDockWidget::DockWidgetFeatures features) const;
    void onTopLevelChanged(bool topLevel) const;
    void onVisibilityChanged(bool visible) const;
private:
    AllowedAreasChangedCallback allowedAreasChangedCallback;
    DockLocationChangedCallback dockLocationChangedCallback;
    FeaturesChangedCallback featuresChangedCallback;
    TopLevelChangedCallback topLevelChangedCallback;
    VisibilityChangedCallback visibilityChangedCallback;
};

#endif // DOCKWIDGET_HANDLER_H
