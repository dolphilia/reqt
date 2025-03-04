#include "QTabBarBind.h"
#include "QTabBarHandler.h"

QTabBarBind::QTabBarBind(QWidget *parent)
    : QTabBar(parent)
    , handler(new QTabBarHandler(this)) {
    connect(this, &QTabBar::currentChanged, handler, &QTabBarHandler::onCurrentChanged);
    connect(this, &QTabBar::tabCloseRequested, handler, &QTabBarHandler::onTabCloseRequested);
}

QTabBarBind::~QTabBarBind() {
    delete handler;
}

void QTabBarBind::setCurrentChangedCallback(QTabBar_CurrentChangedCallback callback) const {
    handler->setCurrentChangedCallback(callback);
}

void QTabBarBind::setTabCloseRequestedCallback(QTabBar_TabCloseRequestedCallback callback) const {
    handler->setTabCloseRequestedCallback(callback);
}
