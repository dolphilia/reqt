#include "QTabBarHandler.h"

QTabBarHandler::QTabBarHandler(QObject *parent)
    : QObject(parent)
    , currentChangedCallback(nullptr)
    , tabCloseRequestedCallback(nullptr) {
}

QTabBarHandler::~QTabBarHandler() {
}

void QTabBarHandler::setCurrentChangedCallback(QTabBar_CurrentChangedCallback callback) {
    currentChangedCallback = callback;
}

void QTabBarHandler::setTabCloseRequestedCallback(QTabBar_TabCloseRequestedCallback callback) {
    tabCloseRequestedCallback = callback;
}

void QTabBarHandler::onCurrentChanged(int index) const {
    if (currentChangedCallback) {
        currentChangedCallback(parent(), index);
    }
}

void QTabBarHandler::onTabCloseRequested(int index) const {
    if (tabCloseRequestedCallback) {
        tabCloseRequestedCallback(parent(), index);
    }
}
