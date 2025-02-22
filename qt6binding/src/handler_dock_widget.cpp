#include "handler_dock_widget.h"

DockWidgetHandler::DockWidgetHandler(QObject* parent)
    : QObject(parent)
    , dockWidget(nullptr)
    , allowedAreasChangedCallback(nullptr)
    , dockLocationChangedCallback(nullptr)
    , featuresChangedCallback(nullptr)
    , topLevelChangedCallback(nullptr)
    , visibilityChangedCallback(nullptr)
{
}

void DockWidgetHandler::setDockWidget(QDockWidget* dockWidget) {
    this->dockWidget = dockWidget;
    connect(dockWidget, &QDockWidget::allowedAreasChanged, this, &DockWidgetHandler::onAllowedAreasChanged);
    connect(dockWidget, &QDockWidget::dockLocationChanged, this, &DockWidgetHandler::onDockLocationChanged);
    connect(dockWidget, &QDockWidget::featuresChanged, this, &DockWidgetHandler::onFeaturesChanged);
    connect(dockWidget, &QDockWidget::topLevelChanged, this, &DockWidgetHandler::onTopLevelChanged);
    connect(dockWidget, &QDockWidget::visibilityChanged, this, &DockWidgetHandler::onVisibilityChanged);
}

void DockWidgetHandler::setAllowedAreasChangedCallback(void (*callback)(void*, int)) {
    allowedAreasChangedCallback = callback;
}

void DockWidgetHandler::setDockLocationChangedCallback(void (*callback)(void*, int)) {
    dockLocationChangedCallback = callback;
}

void DockWidgetHandler::setFeaturesChangedCallback(void (*callback)(void*, int)) {
    featuresChangedCallback = callback;
}

void DockWidgetHandler::setTopLevelChangedCallback(void (*callback)(void*, bool)) {
    topLevelChangedCallback = callback;
}

void DockWidgetHandler::setVisibilityChangedCallback(void (*callback)(void*, bool)) {
    visibilityChangedCallback = callback;
}

void DockWidgetHandler::onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) {
    if (allowedAreasChangedCallback && dockWidget) {
        allowedAreasChangedCallback(dockWidget, static_cast<int>(allowedAreas));
    }
}

void DockWidgetHandler::onDockLocationChanged(Qt::DockWidgetArea area) {
    if (dockLocationChangedCallback && dockWidget) {
        dockLocationChangedCallback(dockWidget, static_cast<int>(area));
    }
}

void DockWidgetHandler::onFeaturesChanged(QDockWidget::DockWidgetFeatures features) {
    if (featuresChangedCallback && dockWidget) {
        featuresChangedCallback(dockWidget, static_cast<int>(features));
    }
}

void DockWidgetHandler::onTopLevelChanged(bool topLevel) {
    if (topLevelChangedCallback && dockWidget) {
        topLevelChangedCallback(dockWidget, topLevel);
    }
}

void DockWidgetHandler::onVisibilityChanged(bool visible) {
    if (visibilityChangedCallback && dockWidget) {
        visibilityChangedCallback(dockWidget, visible);
    }
}
