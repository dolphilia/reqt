#include "QTabWidgetBind.h"
#include <QString>

extern "C" {

void* QTabWidget_create(void* parent) {
    return new QTabWidgetBind(static_cast<QWidget*>(parent));
}

void QTabWidget_delete(void* tab_widget) {
    delete static_cast<QTabWidgetBind*>(tab_widget);
}

int QTabWidget_addTab(void* tab_widget, void* page, const char* label) {
    const QString qstr = QString::fromUtf8(label);
    return static_cast<QTabWidgetBind*>(tab_widget)->addTab(
        static_cast<QWidget*>(page),
        qstr
    );
}

int QTabWidget_insertTab(void* tab_widget, int index, void* page, const char* label) {
    const QString qstr = QString::fromUtf8(label);
    return static_cast<QTabWidgetBind*>(tab_widget)->insertTab(
        index,
        static_cast<QWidget*>(page),
        qstr
    );
}

void QTabWidget_removeTab(void* tab_widget, int index) {
    static_cast<QTabWidgetBind*>(tab_widget)->removeTab(index);
}

int QTabWidget_currentIndex(void* tab_widget) {
    return static_cast<QTabWidgetBind*>(tab_widget)->currentIndex();
}

void QTabWidget_setCurrentIndex(void* tab_widget, int index) {
    static_cast<QTabWidgetBind*>(tab_widget)->setCurrentIndex(index);
}

int QTabWidget_count(void* tab_widget) {
    return static_cast<QTabWidgetBind*>(tab_widget)->count();
}

void* QTabWidget_currentWidget(void* tab_widget) {
    return static_cast<QTabWidgetBind*>(tab_widget)->currentWidget();
}

void QTabWidget_setCurrentWidget(void* tab_widget, void* widget) {
    static_cast<QTabWidgetBind*>(tab_widget)->setCurrentWidget(static_cast<QWidget*>(widget));
}

void QTabWidget_setTabText(void* tab_widget, int index, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTabWidgetBind*>(tab_widget)->setTabText(index, qstr);
}

const char* QTabWidget_tabText(void* tab_widget, int index) {
    const QString qstr = static_cast<QTabWidgetBind*>(tab_widget)->tabText(index);
    return qstrdup(qstr.toUtf8().constData());
}

void QTabWidget_setTabToolTip(void* tab_widget, int index, const char* tip) {
    const QString qstr = QString::fromUtf8(tip);
    static_cast<QTabWidgetBind*>(tab_widget)->setTabToolTip(index, qstr);
}

void QTabWidget_setTabEnabled(void* tab_widget, int index, bool enabled) {
    static_cast<QTabWidgetBind*>(tab_widget)->setTabEnabled(index, enabled);
}

bool QTabWidget_isTabEnabled(void* tab_widget, int index) {
    return static_cast<QTabWidgetBind*>(tab_widget)->isTabEnabled(index);
}

void QTabWidget_setTabsClosable(void* tab_widget, bool closable) {
    static_cast<QTabWidgetBind*>(tab_widget)->setTabsClosable(closable);
}

bool QTabWidget_tabsClosable(void* tab_widget) {
    return static_cast<QTabWidgetBind*>(tab_widget)->tabsClosable();
}

void QTabWidget_setMovable(void* tab_widget, bool movable) {
    static_cast<QTabWidgetBind*>(tab_widget)->setMovable(movable);
}

bool QTabWidget_isMovable(void* tab_widget) {
    return static_cast<QTabWidgetBind*>(tab_widget)->isMovable();
}

void QTabWidget_setTabPosition(void* tab_widget, int position) {
    static_cast<QTabWidgetBind*>(tab_widget)->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
}

int QTabWidget_tabPosition(void* tab_widget) {
    return static_cast<int>(static_cast<QTabWidgetBind*>(tab_widget)->tabPosition());
}

typedef void (*QTabWidget_CurrentChangedCallback)(void*, int);
typedef void (*QTabWidget_TabCloseRequestedCallback)(void*, int);

void QTabWidget_setCurrentChangedCallback(void* tab_widget, QTabWidget_CurrentChangedCallback callback) {
    static_cast<QTabWidgetBind*>(tab_widget)->setCurrentChangedCallback(callback);
}

void QTabWidget_setTabCloseRequestedCallback(void* tab_widget, QTabWidget_TabCloseRequestedCallback callback) {
    static_cast<QTabWidgetBind*>(tab_widget)->setTabCloseRequestedCallback(callback);
}

}
