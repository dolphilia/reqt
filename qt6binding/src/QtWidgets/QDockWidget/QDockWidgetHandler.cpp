#include "QDockWidgetHandler.h"

QDockWidgetHandler::QDockWidgetHandler(QObject* parent)
    : QObject(parent)
    , allowedAreasChangedCallback(nullptr)
    , dockLocationChangedCallback(nullptr)
    , featuresChangedCallback(nullptr)
    , topLevelChangedCallback(nullptr)
    , visibilityChangedCallback(nullptr) {
}

void QDockWidgetHandler::setAllowedAreasChangedCallback(QDockWidget_AllowedAreasChangedCallback callback) {
    allowedAreasChangedCallback = callback;
}

void QDockWidgetHandler::setDockLocationChangedCallback(QDockWidget_DockLocationChangedCallback callback) {
    dockLocationChangedCallback = callback;
}

void QDockWidgetHandler::setFeaturesChangedCallback(QDockWidget_FeaturesChangedCallback callback) {
    featuresChangedCallback = callback;
}

void QDockWidgetHandler::setTopLevelChangedCallback(QDockWidget_TopLevelChangedCallback callback) {
    topLevelChangedCallback = callback;
}

void QDockWidgetHandler::setVisibilityChangedCallback(QDockWidget_VisibilityChangedCallback callback) {
    visibilityChangedCallback = callback;
}

void QDockWidgetHandler::onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) const {
    if (allowedAreasChangedCallback) {
        allowedAreasChangedCallback(parent(), static_cast<int>(allowedAreas));
    }
}

void QDockWidgetHandler::onDockLocationChanged(Qt::DockWidgetArea area) const {
    if (dockLocationChangedCallback) {
        dockLocationChangedCallback(parent(), static_cast<int>(area));
    }
}

void QDockWidgetHandler::onFeaturesChanged(QDockWidget::DockWidgetFeatures features) const {
    if (featuresChangedCallback) {
        featuresChangedCallback(parent(), static_cast<int>(features));
    }
}

void QDockWidgetHandler::onTopLevelChanged(bool topLevel) const {
    if (topLevelChangedCallback) {
        topLevelChangedCallback(parent(), topLevel);
    }
}

void QDockWidgetHandler::onVisibilityChanged(bool visible) const {
    if (visibilityChangedCallback) {
        visibilityChangedCallback(parent(), visible);
    }
}
