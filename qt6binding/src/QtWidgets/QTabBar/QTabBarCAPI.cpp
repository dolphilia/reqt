#include "QTabBarBind.h"
#include <QString>

extern "C" {

typedef void (*QTabBar_CurrentChangedCallback)(void*, int);
typedef void (*QTabBar_TabCloseRequestedCallback)(void*, int);

void* QTabBar_create(void* parent) {
    return new QTabBarBind(static_cast<QWidget*>(parent));
}

void QTabBar_delete(void* tab_bar) {
    delete static_cast<QTabBarBind*>(tab_bar);
}

int QTabBar_addTab(void* tab_bar, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QTabBarBind*>(tab_bar)->addTab(qstr);
}

int QTabBar_insertTab(void* tab_bar, int index, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QTabBarBind*>(tab_bar)->insertTab(index, qstr);
}

void QTabBar_removeTab(void* tab_bar, int index) {
    static_cast<QTabBarBind*>(tab_bar)->removeTab(index);
}

void QTabBar_setCurrentIndex(void* tab_bar, int index) {
    static_cast<QTabBarBind*>(tab_bar)->setCurrentIndex(index);
}

int QTabBar_currentIndex(void* tab_bar) {
    return static_cast<QTabBarBind*>(tab_bar)->currentIndex();
}

int QTabBar_count(void* tab_bar) {
    return static_cast<QTabBarBind*>(tab_bar)->count();
}

const char* QTabBar_tabText(void* tab_bar, int index) {
    QString text = static_cast<QTabBarBind*>(tab_bar)->tabText(index);
    return qstrdup(text.toUtf8().constData());
}

void QTabBar_setTabText(void* tab_bar, int index, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTabBarBind*>(tab_bar)->setTabText(index, qstr);
}

void QTabBar_setTabsClosable(void* tab_bar, bool closable) {
    static_cast<QTabBarBind*>(tab_bar)->setTabsClosable(closable);
}

bool QTabBar_tabsClosable(void* tab_bar) {
    return static_cast<QTabBarBind*>(tab_bar)->tabsClosable();
}

void QTabBar_setTabEnabled(void* tab_bar, int index, bool enabled) {
    static_cast<QTabBarBind*>(tab_bar)->setTabEnabled(index, enabled);
}

bool QTabBar_isTabEnabled(void* tab_bar, int index) {
    return static_cast<QTabBarBind*>(tab_bar)->isTabEnabled(index);
}

void QTabBar_setTabToolTip(void* tab_bar, int index, const char* tooltip) {
    const QString qstr = QString::fromUtf8(tooltip);
    static_cast<QTabBarBind*>(tab_bar)->setTabToolTip(index, qstr);
}

void QTabBar_setCurrentChangedCallback(void* tab_bar, QTabBar_CurrentChangedCallback callback) {
    static_cast<QTabBarBind*>(tab_bar)->setCurrentChangedCallback(callback);
}

void QTabBar_setTabCloseRequestedCallback(void* tab_bar, QTabBar_TabCloseRequestedCallback callback) {
    static_cast<QTabBarBind*>(tab_bar)->setTabCloseRequestedCallback(callback);
}

}
