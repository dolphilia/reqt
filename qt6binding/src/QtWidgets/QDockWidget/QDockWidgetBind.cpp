#include "QDockWidgetBind.h"
#include "QDockWidgetHandler.h"

QDockWidgetBind::QDockWidgetBind(const QString& title, QWidget* parent)
    : QDockWidget(title, parent)
    , handler(new QDockWidgetHandler(this)) {
    connect(this, &QDockWidget::allowedAreasChanged, handler, &QDockWidgetHandler::onAllowedAreasChanged);
    connect(this, &QDockWidget::dockLocationChanged, handler, &QDockWidgetHandler::onDockLocationChanged);
    connect(this, &QDockWidget::featuresChanged, handler, &QDockWidgetHandler::onFeaturesChanged);
    connect(this, &QDockWidget::topLevelChanged, handler, &QDockWidgetHandler::onTopLevelChanged);
    connect(this, &QDockWidget::visibilityChanged, handler, &QDockWidgetHandler::onVisibilityChanged);
}

QDockWidgetBind::~QDockWidgetBind() {
    delete handler;
}

void QDockWidgetBind::setAllowedAreasChangedCallback(QDockWidget_AllowedAreasChangedCallback callback) const {
    handler->setAllowedAreasChangedCallback(callback);
}

void QDockWidgetBind::setDockLocationChangedCallback(QDockWidget_DockLocationChangedCallback callback) const {
    handler->setDockLocationChangedCallback(callback);
}

void QDockWidgetBind::setFeaturesChangedCallback(QDockWidget_FeaturesChangedCallback callback) const {
    handler->setFeaturesChangedCallback(callback);
}

void QDockWidgetBind::setTopLevelChangedCallback(QDockWidget_TopLevelChangedCallback callback) const {
    handler->setTopLevelChangedCallback(callback);
}

void QDockWidgetBind::setVisibilityChangedCallback(QDockWidget_VisibilityChangedCallback callback) const {
    handler->setVisibilityChangedCallback(callback);
}
