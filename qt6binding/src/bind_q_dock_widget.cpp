#include "bind_q_dock_widget.h"
#include "c_q_dock_widget.h"

QDockWidgetBind::QDockWidgetBind(const QString& title, QWidget* parent)
    : QDockWidget(title, parent)
    , handler(new DockWidgetHandler(this))
{
    connect(this, &QDockWidget::allowedAreasChanged, handler, &DockWidgetHandler::onAllowedAreasChanged);
    connect(this, &QDockWidget::dockLocationChanged, handler, &DockWidgetHandler::onDockLocationChanged);
    connect(this, &QDockWidget::featuresChanged, handler, &DockWidgetHandler::onFeaturesChanged);
    connect(this, &QDockWidget::topLevelChanged, handler, &DockWidgetHandler::onTopLevelChanged);
    connect(this, &QDockWidget::visibilityChanged, handler, &DockWidgetHandler::onVisibilityChanged);
    handler->setDockWidget(this);
}

QDockWidgetBind::~QDockWidgetBind() {
    delete handler;
}

void QDockWidgetBind::setAllowedAreasChangedCallback(void (*callback)(void*, int)) {
    handler->setAllowedAreasChangedCallback(callback);
}

void QDockWidgetBind::setDockLocationChangedCallback(void (*callback)(void*, int)) {
    handler->setDockLocationChangedCallback(callback);
}

void QDockWidgetBind::setFeaturesChangedCallback(void (*callback)(void*, int)) {
    handler->setFeaturesChangedCallback(callback);
}

void QDockWidgetBind::setTopLevelChangedCallback(void (*callback)(void*, bool)) {
    handler->setTopLevelChangedCallback(callback);
}

void QDockWidgetBind::setVisibilityChangedCallback(void (*callback)(void*, bool)) {
    handler->setVisibilityChangedCallback(callback);
}

extern "C" {

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

void QDockWidget_setAllowedAreasChangedCallback(void* dockWidget, QDockWidgetAllowedAreasChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setAllowedAreasChangedCallback(callback);
}

void QDockWidget_setDockLocationChangedCallback(void* dockWidget, QDockWidgetDockLocationChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setDockLocationChangedCallback(callback);
}

void QDockWidget_setFeaturesChangedCallback(void* dockWidget, QDockWidgetFeaturesChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setFeaturesChangedCallback(callback);
}

void QDockWidget_setTopLevelChangedCallback(void* dockWidget, QDockWidgetTopLevelChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setTopLevelChangedCallback(callback);
}

void QDockWidget_setVisibilityChangedCallback(void* dockWidget, QDockWidgetVisibilityChangedCallback callback) {
    static_cast<QDockWidgetBind*>(dockWidget)->setVisibilityChangedCallback(callback);
}

}
