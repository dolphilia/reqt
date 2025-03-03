#include "QDockWidgetHandler.h"

DockWidgetHandler::DockWidgetHandler(QObject* parent)
    : QObject(parent)
    , allowedAreasChangedCallback(nullptr)
    , dockLocationChangedCallback(nullptr)
    , featuresChangedCallback(nullptr)
    , topLevelChangedCallback(nullptr)
    , visibilityChangedCallback(nullptr) {
}

void DockWidgetHandler::setAllowedAreasChangedCallback(AllowedAreasChangedCallback callback) {
    allowedAreasChangedCallback = callback;
}

void DockWidgetHandler::setDockLocationChangedCallback(DockLocationChangedCallback callback) {
    dockLocationChangedCallback = callback;
}

void DockWidgetHandler::setFeaturesChangedCallback(FeaturesChangedCallback callback) {
    featuresChangedCallback = callback;
}

void DockWidgetHandler::setTopLevelChangedCallback(TopLevelChangedCallback callback) {
    topLevelChangedCallback = callback;
}

void DockWidgetHandler::setVisibilityChangedCallback(VisibilityChangedCallback callback) {
    visibilityChangedCallback = callback;
}

void DockWidgetHandler::onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) const {
    if (allowedAreasChangedCallback) {
        allowedAreasChangedCallback(parent(), static_cast<int>(allowedAreas));
    }
}

void DockWidgetHandler::onDockLocationChanged(Qt::DockWidgetArea area) const {
    if (dockLocationChangedCallback) {
        dockLocationChangedCallback(parent(), static_cast<int>(area));
    }
}

void DockWidgetHandler::onFeaturesChanged(QDockWidget::DockWidgetFeatures features) const {
    if (featuresChangedCallback) {
        featuresChangedCallback(parent(), static_cast<int>(features));
    }
}

void DockWidgetHandler::onTopLevelChanged(bool topLevel) const {
    if (topLevelChangedCallback) {
        topLevelChangedCallback(parent(), topLevel);
    }
}

void DockWidgetHandler::onVisibilityChanged(bool visible) const {
    if (visibilityChangedCallback) {
        visibilityChangedCallback(parent(), visible);
    }
}
