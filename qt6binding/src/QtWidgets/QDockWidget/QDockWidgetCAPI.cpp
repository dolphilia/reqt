#include "QDockWidgetBind.h"
#include "qdockwidget.h"

extern "C" {

typedef void (*AllowedAreasChangedCallback)(void*, int);
typedef void (*DockLocationChangedCallback)(void*, int);
typedef void (*FeaturesChangedCallback)(void*, int);
typedef void (*TopLevelChangedCallback)(void*, bool);
typedef void (*VisibilityChangedCallback)(void*, bool);

void* QDockWidget_create(const char* title, void* parent) {
    return new QDockWidgetBind(QString::fromUtf8(title), static_cast<QWidget*>(parent));
}

void QDockWidget_delete(void* dockWidget) {
    delete static_cast<QDockWidgetBind*>(dockWidget);
}

void QDockWidget_setWidget(void* dockWidget, void* widget) {
    static_cast<QDockWidgetBind*>(dockWidget)->setWidget(static_cast<QWidget*>(widget));
}

void* QDockWidget_widget(void* dockWidget) {
    return static_cast<QDockWidgetBind*>(dockWidget)->widget();
}

void QDockWidget_setTitleBarWidget(void* dockWidget, void* widget) {
    static_cast<QDockWidgetBind*>(dockWidget)->setTitleBarWidget(static_cast<QWidget*>(widget));
}

void* QDockWidget_titleBarWidget(void* dockWidget) {
    return static_cast<QDockWidgetBind*>(dockWidget)->titleBarWidget();
}

void QDockWidget_setFeatures(void* dockWidget, int features) {
    static_cast<QDockWidgetBind*>(dockWidget)->setFeatures(
        static_cast<QDockWidget::DockWidgetFeatures>(features));
}

int QDockWidget_features(void* dockWidget) {
    return static_cast<int>(static_cast<QDockWidgetBind*>(dockWidget)->features());
}

void QDockWidget_setFloating(void* dockWidget, bool floating) {
    static_cast<QDockWidgetBind*>(dockWidget)->setFloating(floating);
}

bool QDockWidget_isFloating(void* dockWidget) {
    return static_cast<QDockWidgetBind*>(dockWidget)->isFloating();
}

void QDockWidget_setAllowedAreas(void* dockWidget, int areas) {
    static_cast<QDockWidgetBind*>(dockWidget)->setAllowedAreas(
        static_cast<Qt::DockWidgetAreas>(areas));
}

int QDockWidget_allowedAreas(void* dockWidget) {
    return static_cast<int>(static_cast<QDockWidgetBind*>(dockWidget)->allowedAreas());
}

void QDockWidget_setAllowedAreasChangedCallback(void* dockWidget, AllowedAreasChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setAllowedAreasChangedCallback(callback);
}

void QDockWidget_setDockLocationChangedCallback(void* dockWidget, DockLocationChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setDockLocationChangedCallback(callback);
}

void QDockWidget_setFeaturesChangedCallback(void* dockWidget, FeaturesChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setFeaturesChangedCallback(callback);
}

void QDockWidget_setTopLevelChangedCallback(void* dockWidget, TopLevelChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setTopLevelChangedCallback(callback);
}

void QDockWidget_setVisibilityChangedCallback(void* dockWidget, VisibilityChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setVisibilityChangedCallback(callback);
}

}
