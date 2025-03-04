#include "QTabWidgetHandler.h"

QTabWidgetHandler::QTabWidgetHandler(QObject* parent)
    : QObject(parent)
    , currentChangedCallback(nullptr)
    , tabCloseRequestedCallback(nullptr) {
}

void QTabWidgetHandler::setCurrentChangedCallback(QTabWidget_CurrentChangedCallback callback) {
    currentChangedCallback = callback;
}

void QTabWidgetHandler::setTabCloseRequestedCallback(QTabWidget_TabCloseRequestedCallback callback) {
    tabCloseRequestedCallback = callback;
}

void QTabWidgetHandler::onCurrentChanged(int index) const {
    if (currentChangedCallback) {
        currentChangedCallback(parent(), index);
    }
}

void QTabWidgetHandler::onTabCloseRequested(int index) const {
    if (tabCloseRequestedCallback) {
        tabCloseRequestedCallback(parent(), index);
    }
}
