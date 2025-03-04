#include "QStackedWidgetHandler.h"

QStackedWidgetHandler::QStackedWidgetHandler(QObject* parent)
    : QObject(parent)
    , currentChangedCallback(nullptr)
    , widgetRemovedCallback(nullptr) {
}

void QStackedWidgetHandler::setCurrentChangedCallback(QStackedWidget_CurrentChangedCallback callback) {
    currentChangedCallback = callback;
}

void QStackedWidgetHandler::setWidgetRemovedCallback(QStackedWidget_WidgetRemovedCallback callback) {
    widgetRemovedCallback = callback;
}

void QStackedWidgetHandler::onCurrentChanged(int index) const {
    if (currentChangedCallback) {
        currentChangedCallback(parent(), index);
    }
}

void QStackedWidgetHandler::onWidgetRemoved(int index) const {
    if (widgetRemovedCallback) {
        widgetRemovedCallback(parent(), index);
    }
}
