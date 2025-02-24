#ifndef QMENUBAR_C_H
#define QMENUBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QMenuBar creation/deletion
void* QMenuBar_create(void* parent);
void QMenuBar_delete(void* menu_bar);

// Menu operations
void* QMenuBar_addMenu(void* menu_bar, const char* title);
void* QMenuBar_addMenu2(void* menu_bar, void* menu);
void QMenuBar_clear(void* menu_bar);

// Actions
void* QMenuBar_addAction(void* menu_bar, const char* text);
void QMenuBar_removeAction(void* menu_bar, void* action);
void* QMenuBar_addSeparator(void* menu_bar);

// Properties
void QMenuBar_setVisible(void* menu_bar, bool visible);
bool QMenuBar_isVisible(void* menu_bar);
void QMenuBar_setEnabled(void* menu_bar, bool enabled);
bool QMenuBar_isEnabled(void* menu_bar);
int QMenuBar_height(void* menu_bar);

// Native menu bar
void QMenuBar_setNativeMenuBar(void* menu_bar, bool native);
bool QMenuBar_isNativeMenuBar(void* menu_bar);

// Corner widgets
void QMenuBar_setCornerWidget(void* menu_bar, void* widget, int corner);
void* QMenuBar_cornerWidget(void* menu_bar, int corner);

// Action management
void QMenuBar_setActionEnabled(void* menu_bar, void* action, bool enabled);
bool QMenuBar_isActionEnabled(void* menu_bar, void* action);
void QMenuBar_setActionVisible(void* menu_bar, void* action, bool visible);
bool QMenuBar_isActionVisible(void* menu_bar, void* action);
void QMenuBar_setActionText(void* menu_bar, void* action, const char* text);
const char* QMenuBar_actionText(void* menu_bar, void* action);

// Signal handlers
typedef void (*QMenuBarTriggeredCallback)(void* action);
typedef void (*QMenuBarHoveredCallback)(void* action);

void QMenuBar_setTriggeredCallback(void* menu_bar, QMenuBarTriggeredCallback callback);
void QMenuBar_setHoveredCallback(void* menu_bar, QMenuBarHoveredCallback callback);

// Corner constants
#define QMENUBAR_CORNER_TOPLEFT 0
#define QMENUBAR_CORNER_TOPRIGHT 1

#ifdef __cplusplus
}
#endif

#endif // QMENUBAR_C_H
