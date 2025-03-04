#include "QToolBarBind.h"
#include "QToolBarHandler.h"

QToolBarBind::QToolBarBind(QWidget* parent)
    : QToolBar(parent)
    , handler(new QToolBarHandler(this)) {
    connect(this, &QToolBar::actionTriggered, handler, &QToolBarHandler::onActionTriggered);
    connect(this, &QToolBar::movableChanged, handler, &QToolBarHandler::onMovableChanged);
    connect(this, &QToolBar::orientationChanged, handler, &QToolBarHandler::onOrientationChanged);
    connect(this, &QToolBar::topLevelChanged, handler, &QToolBarHandler::onTopLevelChanged);
    connect(this, &QToolBar::visibilityChanged, handler, &QToolBarHandler::onVisibilityChanged);
    connect(this, &QToolBar::allowedAreasChanged, handler, &QToolBarHandler::onAllowedAreasChanged);
}

QToolBarBind::QToolBarBind(const QString& title, QWidget* parent)
    : QToolBar(title, parent)
    , handler(new QToolBarHandler(this)) {
    connect(this, &QToolBar::actionTriggered, handler, &QToolBarHandler::onActionTriggered);
    connect(this, &QToolBar::movableChanged, handler, &QToolBarHandler::onMovableChanged);
    connect(this, &QToolBar::orientationChanged, handler, &QToolBarHandler::onOrientationChanged);
    connect(this, &QToolBar::topLevelChanged, handler, &QToolBarHandler::onTopLevelChanged);
    connect(this, &QToolBar::visibilityChanged, handler, &QToolBarHandler::onVisibilityChanged);
    connect(this, &QToolBar::allowedAreasChanged, handler, &QToolBarHandler::onAllowedAreasChanged);
}

QToolBarBind::~QToolBarBind() {
    delete handler;
}

void QToolBarBind::setActionTriggeredCallback(QToolBar_ActionTriggeredCallback callback) const {
    handler->setActionTriggeredCallback(callback);
}

void QToolBarBind::setMovableChangedCallback(QToolBar_MovableChangedCallback callback) const {
    handler->setMovableChangedCallback(callback);
}

void QToolBarBind::setOrientationChangedCallback(QToolBar_OrientationChangedCallback callback) const {
    handler->setOrientationChangedCallback(callback);
}

void QToolBarBind::setTopLevelChangedCallback(QToolBar_TopLevelChangedCallback callback) const {
    handler->setTopLevelChangedCallback(callback);
}

void QToolBarBind::setVisibilityChangedCallback(QToolBar_VisibilityChangedCallback callback) const {
    handler->setVisibilityChangedCallback(callback);
}

void QToolBarBind::setAllowedAreasChangedCallback(QToolBar_AllowedAreasChangedCallback callback) const {
    handler->setAllowedAreasChangedCallback(callback);
}
