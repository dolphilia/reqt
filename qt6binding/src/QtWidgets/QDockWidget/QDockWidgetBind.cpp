#include "QDockWidgetBind.h"
#include "qdockwidget.h"

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