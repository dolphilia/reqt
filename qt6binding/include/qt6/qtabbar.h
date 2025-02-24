#ifndef QTABBAR_C_H
#define QTABBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QTabBar
typedef void (*QTabBarCurrentChangedCallback)(int index);
typedef void (*QTabBarTabCloseRequestedCallback)(int index);

void* QTabBar_create(void* parent);
void QTabBar_delete(void* tab_bar);
int QTabBar_addTab(void* tab_bar, const char* text);
int QTabBar_insertTab(void* tab_bar, int index, const char* text);
void QTabBar_removeTab(void* tab_bar, int index);
void QTabBar_setCurrentIndex(void* tab_bar, int index);
int QTabBar_currentIndex(void* tab_bar);
int QTabBar_count(void* tab_bar);
const char* QTabBar_tabText(void* tab_bar, int index);
void QTabBar_setTabText(void* tab_bar, int index, const char* text);
void QTabBar_setTabsClosable(void* tab_bar, bool closable);
bool QTabBar_tabsClosable(void* tab_bar);
void QTabBar_setTabEnabled(void* tab_bar, int index, bool enabled);
bool QTabBar_isTabEnabled(void* tab_bar, int index);
void QTabBar_setTabToolTip(void* tab_bar, int index, const char* tooltip);
void QTabBar_setCurrentChangedCallback(void* tab_bar, QTabBarCurrentChangedCallback callback);
void QTabBar_setTabCloseRequestedCallback(void* tab_bar, QTabBarTabCloseRequestedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTABBAR_C_H
