#ifndef QMENU_C_H
#define QMENU_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QMenu creation/deletion
void* QMenu_create(void* parent);
void* QMenu_createWithTitle(const char* title, void* parent);
void QMenu_delete(void* menu);

// Menu items
void* QMenu_addAction(void* menu, const char* text);
void* QMenu_addMenu(void* menu, void* submenu);
void* QMenu_addSeparator(void* menu);
void QMenu_removeAction(void* menu, void* action);
void QMenu_clear(void* menu);

// Properties
void QMenu_setTitle(void* menu, const char* title);
const char* QMenu_title(void* menu);
void QMenu_setIcon(void* menu, const char* iconPath);
void QMenu_setEnabled(void* menu, bool enabled);
bool QMenu_isEnabled(void* menu);
void QMenu_setVisible(void* menu, bool visible);
bool QMenu_isVisible(void* menu);

// Actions
void QMenu_setActionEnabled(void* menu, void* action, bool enabled);
bool QMenu_isActionEnabled(void* menu, void* action);
void QMenu_setActionVisible(void* menu, void* action, bool visible);
bool QMenu_isActionVisible(void* menu, void* action);
void QMenu_setActionText(void* menu, void* action, const char* text);
const char* QMenu_actionText(void* menu, void* action);
void QMenu_setActionIcon(void* menu, void* action, const char* iconPath);
void QMenu_setActionCheckable(void* menu, void* action, bool checkable);
bool QMenu_isActionCheckable(void* menu, void* action);
void QMenu_setActionChecked(void* menu, void* action, bool checked);
bool QMenu_isActionChecked(void* menu, void* action);

// Popup
void QMenu_popup(void* menu, int x, int y);
void QMenu_exec(void* menu);

// Signal handlers
typedef void (*QMenuAboutToShowCallback)();
typedef void (*QMenuAboutToHideCallback)();
typedef void (*QMenuTriggeredCallback)(void* action);
typedef void (*QMenuHoveredCallback)(void* action);

void QMenu_setAboutToShowCallback(void* menu, QMenuAboutToShowCallback callback);
void QMenu_setAboutToHideCallback(void* menu, QMenuAboutToHideCallback callback);
void QMenu_setTriggeredCallback(void* menu, QMenuTriggeredCallback callback);
void QMenu_setHoveredCallback(void* menu, QMenuHoveredCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QMENU_C_H
