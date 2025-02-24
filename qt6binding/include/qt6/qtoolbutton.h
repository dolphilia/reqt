#ifndef QTOOLBUTTON_C_H
#define QTOOLBUTTON_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QToolButton_create(void* parent);
void QToolButton_delete(void* tool_button);

// Properties
void QToolButton_setText(void* tool_button, const char* text);
const char* QToolButton_text(void* tool_button);
void QToolButton_setIcon(void* tool_button, const char* icon_path);
void QToolButton_setIconSize(void* tool_button, int w, int h);
void QToolButton_setToolButtonStyle(void* tool_button, int style);
int QToolButton_toolButtonStyle(void* tool_button);
void QToolButton_setAutoRaise(void* tool_button, bool enable);
bool QToolButton_autoRaise(void* tool_button);
void QToolButton_setCheckable(void* tool_button, bool checkable);
bool QToolButton_isCheckable(void* tool_button);
void QToolButton_setPopupMode(void* tool_button, int mode);
int QToolButton_popupMode(void* tool_button);
void QToolButton_setArrowType(void* tool_button, int type);
int QToolButton_arrowType(void* tool_button);
void QToolButton_setMenu(void* tool_button, void* menu);
void* QToolButton_menu(void* tool_button);
void QToolButton_setDefaultAction(void* tool_button, void* action);
void* QToolButton_defaultAction(void* tool_button);

// Tool button style constants
#define QTOOLBUTTON_STYLE_ICON_ONLY 0
#define QTOOLBUTTON_STYLE_TEXT_ONLY 1
#define QTOOLBUTTON_STYLE_TEXT_BESIDE_ICON 2
#define QTOOLBUTTON_STYLE_TEXT_UNDER_ICON 3
#define QTOOLBUTTON_STYLE_FOLLOW_STYLE 4

// Popup mode constants
#define QTOOLBUTTON_POPUP_DELAY 0
#define QTOOLBUTTON_POPUP_MENU_BUTTON 1
#define QTOOLBUTTON_POPUP_INSTANT 2

// Arrow type constants
#define QTOOLBUTTON_ARROW_NONE 0
#define QTOOLBUTTON_ARROW_UP 1
#define QTOOLBUTTON_ARROW_DOWN 2
#define QTOOLBUTTON_ARROW_LEFT 3
#define QTOOLBUTTON_ARROW_RIGHT 4

// Callbacks
typedef void (*QToolButtonClickedCallback)();
typedef void (*QToolButtonToggledCallback)(bool checked);
typedef void (*QToolButtonTriggeredCallback)();

void QToolButton_setClickedCallback(void* tool_button, QToolButtonClickedCallback callback);
void QToolButton_setToggledCallback(void* tool_button, QToolButtonToggledCallback callback);
void QToolButton_setTriggeredCallback(void* tool_button, QToolButtonTriggeredCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTOOLBUTTON_C_H
