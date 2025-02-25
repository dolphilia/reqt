#include "QStackedWidgetHandler.h"

QStackedWidgetHandler::QStackedWidgetHandler(QObject* parent)
    : QObject(parent)
    , stackedWidget(nullptr)
    , currentChangedCallback(nullptr)
    , widgetRemovedCallback(nullptr)
{
}

void QStackedWidgetHandler::setStackedWidget(QStackedWidget* stackedWidget) {
    if (this->stackedWidget) {
        disconnect(this->stackedWidget, &QStackedWidget::currentChanged, this, &QStackedWidgetHandler::onCurrentChanged);
        disconnect(this->stackedWidget, &QStackedWidget::widgetRemoved, this, &QStackedWidgetHandler::onWidgetRemoved);
    }
    
    this->stackedWidget = stackedWidget;
    
    if (stackedWidget) {
        connect(stackedWidget, &QStackedWidget::currentChanged, this, &QStackedWidgetHandler::onCurrentChanged);
        connect(stackedWidget, &QStackedWidget::widgetRemoved, this, &QStackedWidgetHandler::onWidgetRemoved);
    }
}

void QStackedWidgetHandler::setCurrentChangedCallback(StackedWidgetCurrentChangedCallback callback) {
    currentChangedCallback = callback;
}

void QStackedWidgetHandler::setWidgetRemovedCallback(StackedWidgetWidgetRemovedCallback callback) {
    widgetRemovedCallback = callback;
}

void QStackedWidgetHandler::onCurrentChanged(int index) {
    if (currentChangedCallback && stackedWidget) {
        currentChangedCallback(stackedWidget, index);
    }
}

void QStackedWidgetHandler::onWidgetRemoved(int index) {
    if (widgetRemovedCallback && stackedWidget) {
        widgetRemovedCallback(stackedWidget, index);
    }
}
