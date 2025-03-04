#ifndef QTOOLBAR_C_H
#define QTOOLBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QToolBar_create(void* parent);
void* QToolBar_create_with_title(const char* title, void* parent);
void QToolBar_delete(void* tool_bar);

// Actions
void* QToolBar_addAction(void* tool_bar, const char* text);
void* QToolBar_addAction_with_icon(void* tool_bar, const char* icon, const char* text);
void* QToolBar_addSeparator(void* tool_bar);
void* QToolBar_addWidget(void* tool_bar, void* widget);
void QToolBar_clear(void* tool_bar);
void* QToolBar_insertAction(void* tool_bar, void* before, void* action);
void* QToolBar_insertSeparator(void* tool_bar, void* before);
void* QToolBar_insertWidget(void* tool_bar, void* before, void* widget);
void QToolBar_removeAction(void* tool_bar, void* action);

// Properties
void QToolBar_setAllowedAreas(void* tool_bar, int areas);
int QToolBar_allowedAreas(void* tool_bar);
void QToolBar_setFloatable(void* tool_bar, bool floatable);
bool QToolBar_isFloatable(void* tool_bar);
void QToolBar_setMovable(void* tool_bar, bool movable);
bool QToolBar_isMovable(void* tool_bar);
void QToolBar_setOrientation(void* tool_bar, int orientation);
int QToolBar_orientation(void* tool_bar);
void QToolBar_setIconSize(void* tool_bar, int w, int h);
void QToolBar_setToolButtonStyle(void* tool_bar, int style);
int QToolBar_toolButtonStyle(void* tool_bar);

// Area constants
#define QTOOLBAR_AREA_LEFT 0x1
#define QTOOLBAR_AREA_RIGHT 0x2
#define QTOOLBAR_AREA_TOP 0x4
#define QTOOLBAR_AREA_BOTTOM 0x8
#define QTOOLBAR_AREA_ALL 0xF
#define QTOOLBAR_AREA_NONE 0x0

// Orientation constants
#define QTOOLBAR_HORIZONTAL 0x1
#define QTOOLBAR_VERTICAL 0x2

// Tool button style constants
#define QTOOLBAR_TOOLBUTTON_ICON_ONLY 0
#define QTOOLBAR_TOOLBUTTON_TEXT_ONLY 1
#define QTOOLBAR_TOOLBUTTON_TEXT_BESIDE_ICON 2
#define QTOOLBAR_TOOLBUTTON_TEXT_UNDER_ICON 3
#define QTOOLBAR_TOOLBUTTON_FOLLOW_STYLE 4

// Callbacks
typedef void (*QToolBar_ActionTriggeredCallback)(void*, void*);
typedef void (*QToolBar_MovableChangedCallback)(void*, bool);
typedef void (*QToolBar_OrientationChangedCallback)(void*, int);
typedef void (*QToolBar_TopLevelChangedCallback)(void*, bool);
typedef void (*QToolBar_VisibilityChangedCallback)(void*, bool);
typedef void (*QToolBar_AllowedAreasChangedCallback)(void*, int);

void QToolBar_setActionTriggeredCallback(void* tool_bar, QToolBar_ActionTriggeredCallback callback);
void QToolBar_setMovableChangedCallback(void* tool_bar, QToolBar_MovableChangedCallback callback);
void QToolBar_setOrientationChangedCallback(void* tool_bar, QToolBar_OrientationChangedCallback callback);
void QToolBar_setTopLevelChangedCallback(void* tool_bar, QToolBar_TopLevelChangedCallback callback);
void QToolBar_setVisibilityChangedCallback(void* tool_bar, QToolBar_VisibilityChangedCallback callback);
void QToolBar_setAllowedAreasChangedCallback(void* tool_bar, QToolBar_AllowedAreasChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTOOLBAR_C_H
