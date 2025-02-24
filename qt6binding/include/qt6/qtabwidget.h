#ifndef QTABWIDGET_C_H
#define QTABWIDGET_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QTabWidget
void* QTabWidget_create(void* parent);
void QTabWidget_delete(void* tab_widget);

// Tab management
int QTabWidget_addTab(void* tab_widget, void* page, const char* label);
int QTabWidget_insertTab(void* tab_widget, int index, void* page, const char* label);
void QTabWidget_removeTab(void* tab_widget, int index);
int QTabWidget_currentIndex(void* tab_widget);
void QTabWidget_setCurrentIndex(void* tab_widget, int index);
int QTabWidget_count(void* tab_widget);
void* QTabWidget_currentWidget(void* tab_widget);
void QTabWidget_setCurrentWidget(void* tab_widget, void* widget);

// Tab configuration
void QTabWidget_setTabText(void* tab_widget, int index, const char* text);
const char* QTabWidget_tabText(void* tab_widget, int index);
void QTabWidget_setTabToolTip(void* tab_widget, int index, const char* tip);
void QTabWidget_setTabEnabled(void* tab_widget, int index, bool enabled);
bool QTabWidget_isTabEnabled(void* tab_widget, int index);

// Widget properties
void QTabWidget_setTabsClosable(void* tab_widget, bool closable);
bool QTabWidget_tabsClosable(void* tab_widget);
void QTabWidget_setMovable(void* tab_widget, bool movable);
bool QTabWidget_isMovable(void* tab_widget);
void QTabWidget_setTabPosition(void* tab_widget, int position);
int QTabWidget_tabPosition(void* tab_widget);

// Signal handlers
typedef void (*QTabWidgetCurrentChangedCallback)(int index);
typedef void (*QTabWidgetTabCloseRequestedCallback)(int index);
void QTabWidget_setCurrentChangedCallback(void* tab_widget, QTabWidgetCurrentChangedCallback callback);
void QTabWidget_setTabCloseRequestedCallback(void* tab_widget, QTabWidgetTabCloseRequestedCallback callback);

// Tab position constants
#define QTABWIDGET_NORTH 0
#define QTABWIDGET_SOUTH 1
#define QTABWIDGET_WEST 2
#define QTABWIDGET_EAST 3

#ifdef __cplusplus
}
#endif

#endif // QTABWIDGET_C_H
