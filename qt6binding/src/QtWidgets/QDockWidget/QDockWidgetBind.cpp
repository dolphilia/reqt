#include "QDockWidgetBind.h"
#include "QDockWidgetHandler.h"

QDockWidgetBind::QDockWidgetBind(const QString& title, QWidget* parent)
    : QDockWidget(title, parent)
    , handler(new DockWidgetHandler(this)) {
    connect(this, &QDockWidget::allowedAreasChanged, handler, &DockWidgetHandler::onAllowedAreasChanged);
    connect(this, &QDockWidget::dockLocationChanged, handler, &DockWidgetHandler::onDockLocationChanged);
    connect(this, &QDockWidget::featuresChanged, handler, &DockWidgetHandler::onFeaturesChanged);
    connect(this, &QDockWidget::topLevelChanged, handler, &DockWidgetHandler::onTopLevelChanged);
    connect(this, &QDockWidget::visibilityChanged, handler, &DockWidgetHandler::onVisibilityChanged);
}

QDockWidgetBind::~QDockWidgetBind() {
    delete handler;
}

void QDockWidgetBind::setAllowedAreasChangedCallback(AllowedAreasChangedCallback callback) const {
    handler->setAllowedAreasChangedCallback(callback);
}

void QDockWidgetBind::setDockLocationChangedCallback(DockLocationChangedCallback callback) const {
    handler->setDockLocationChangedCallback(callback);
}

void QDockWidgetBind::setFeaturesChangedCallback(FeaturesChangedCallback callback) const {
    handler->setFeaturesChangedCallback(callback);
}

void QDockWidgetBind::setTopLevelChangedCallback(TopLevelChangedCallback callback) const {
    handler->setTopLevelChangedCallback(callback);
}

void QDockWidgetBind::setVisibilityChangedCallback(VisibilityChangedCallback callback) const {
    handler->setVisibilityChangedCallback(callback);
}
