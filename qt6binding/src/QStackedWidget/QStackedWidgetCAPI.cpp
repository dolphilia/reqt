#include "QStackedWidgetBind.h"

extern "C" {

void* QStackedWidget_create(void* parent) {
    return new QStackedWidgetBind(static_cast<QWidget*>(parent));
}

void QStackedWidget_delete(void* stackedWidget) {
    delete static_cast<QStackedWidgetBind*>(stackedWidget);
}

int QStackedWidget_addWidget(void* stackedWidget, void* widget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->addWidget(static_cast<QWidget*>(widget));
}

int QStackedWidget_insertWidget(void* stackedWidget, int index, void* widget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->insertWidget(index, static_cast<QWidget*>(widget));
}

void QStackedWidget_removeWidget(void* stackedWidget, void* widget) {
    static_cast<QStackedWidgetBind*>(stackedWidget)->removeWidget(static_cast<QWidget*>(widget));
}

int QStackedWidget_count(void* stackedWidget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->count();
}

int QStackedWidget_currentIndex(void* stackedWidget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->currentIndex();
}

void* QStackedWidget_currentWidget(void* stackedWidget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->currentWidget();
}

void* QStackedWidget_widget(void* stackedWidget, int index) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->widget(index);
}

int QStackedWidget_indexOf(void* stackedWidget, void* widget) {
    return static_cast<QStackedWidgetBind*>(stackedWidget)->indexOf(static_cast<QWidget*>(widget));
}

void QStackedWidget_setCurrentIndex(void* stackedWidget, int index) {
    static_cast<QStackedWidgetBind*>(stackedWidget)->setCurrentIndex(index);
}

void QStackedWidget_setCurrentWidget(void* stackedWidget, void* widget) {
    static_cast<QStackedWidgetBind*>(stackedWidget)->setCurrentWidget(static_cast<QWidget*>(widget));
}

void QStackedWidget_setCurrentChangedCallback(void* stackedWidget, void (*callback)(void*, int)) {
    static_cast<QStackedWidgetBind*>(stackedWidget)->setCurrentChangedCallback(callback);
}

void QStackedWidget_setWidgetRemovedCallback(void* stackedWidget, void (*callback)(void*, int)) {
    static_cast<QStackedWidgetBind*>(stackedWidget)->setWidgetRemovedCallback(callback);
}

}
