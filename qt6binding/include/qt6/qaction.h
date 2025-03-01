#ifndef QT6_QACTION_H
#define QT6_QACTION_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Enums
enum QActionEventType {
    QAction_EventTrigger,
    QAction_EventHover
};

enum QActionMenuRole {
    QAction_NoRole,
    QAction_TextHeuristicRole,
    QAction_ApplicationSpecificRole,
    QAction_AboutQtRole,
    QAction_AboutRole,
    QAction_PreferencesRole,
    QAction_QuitRole
};

enum QActionPriority {
    QAction_LowPriority,
    QAction_NormalPriority,
    QAction_HighPriority
};

// コンストラクタ/デストラクタ
void* QAction_create(void* parent);
void* QAction_createWithText(const char* text, void* parent);
void* QAction_createWithIconAndText(void* icon, const char* text, void* parent);
void QAction_delete(void* action);

// プロパティ
void* QAction_actionGroup(void* action);
void QAction_activate(void* action, enum QActionEventType event);
void* QAction_associatedObjects(void* action);
bool QAction_autoRepeat(void* action);
void* QAction_data(void* action);
void* QAction_font(void* action);
void* QAction_icon(void* action);
const char* QAction_iconText(void* action);
bool QAction_isCheckable(void* action);
bool QAction_isChecked(void* action);
bool QAction_isEnabled(void* action);
bool QAction_isIconVisibleInMenu(void* action);
bool QAction_isSeparator(void* action);
bool QAction_isShortcutVisibleInContextMenu(void* action);
bool QAction_isVisible(void* action);
void* QAction_menu(void* action);
enum QActionMenuRole QAction_menuRole(void* action);
enum QActionPriority QAction_priority(void* action);

// セッター
void QAction_setActionGroup(void* action, void* group);
void QAction_setAutoRepeat(void* action, bool repeat);
void QAction_setCheckable(void* action, bool checkable);
void QAction_setData(void* action, void* data);
void QAction_setFont(void* action, void* font);
void QAction_setIcon(void* action, void* icon);
void QAction_setIconText(void* action, const char* text);
void QAction_setIconVisibleInMenu(void* action, bool visible);
void QAction_setMenu(void* action, void* menu);
void QAction_setMenuRole(void* action, enum QActionMenuRole role);
void QAction_setPriority(void* action, enum QActionPriority priority);
void QAction_setSeparator(void* action, bool separator);
void QAction_setShortcut(void* action, void* shortcut);
void QAction_setShortcutContext(void* action, int context);
void QAction_setShortcutVisibleInContextMenu(void* action, bool show);
void QAction_setStatusTip(void* action, const char* tip);
void QAction_setText(void* action, const char* text);
void QAction_setToolTip(void* action, const char* tip);
void QAction_setWhatsThis(void* action, const char* text);

// ゲッター
void* QAction_shortcut(void* action);
int QAction_shortcutContext(void* action);
bool QAction_showStatusText(void* action, void* object);
const char* QAction_statusTip(void* action);
const char* QAction_text(void* action);
const char* QAction_toolTip(void* action);
const char* QAction_whatsThis(void* action);

// スロット
void QAction_hover(void* action);
void QAction_resetEnabled(void* action);
void QAction_setChecked(void* action, bool checked);
void QAction_setDisabled(void* action, bool disabled);
void QAction_setEnabled(void* action, bool enabled);
void QAction_setVisible(void* action, bool visible);
void QAction_toggle(void* action);
void QAction_trigger(void* action);

// コールバック関数の型定義
typedef void (*QActionChangedCallback)(void* action);
typedef void (*QActionCheckableChangedCallback)(void* action, bool checkable);
typedef void (*QActionEnabledChangedCallback)(void* action, bool enabled);
typedef void (*QActionHoveredCallback)(void* action);
typedef void (*QActionToggledCallback)(void* action, bool checked);
typedef void (*QActionTriggeredCallback)(void* action, bool checked);
typedef void (*QActionVisibleChangedCallback)(void* action);

// コールバック設定関数
void QAction_setChangedCallback(void* action, QActionChangedCallback callback);
void QAction_setCheckableChangedCallback(void* action, QActionCheckableChangedCallback callback);
void QAction_setEnabledChangedCallback(void* action, QActionEnabledChangedCallback callback);
void QAction_setHoveredCallback(void* action, QActionHoveredCallback callback);
void QAction_setToggledCallback(void* action, QActionToggledCallback callback);
void QAction_setTriggeredCallback(void* action, QActionTriggeredCallback callback);
void QAction_setVisibleChangedCallback(void* action, QActionVisibleChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QT6_QACTION_H
