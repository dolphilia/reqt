#ifndef QGUIAPPLICATION_C_H
#define QGUIAPPLICATION_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// レイアウト方向
#define QT_LEFTTORIGHT 0
#define QT_RIGHTTOLEFT 1
#define QT_LAYOUTDIRECTION_AUTO 2

// アプリケーション状態
#define QT_APPLICATIONSTATE_ACTIVE 1
#define QT_APPLICATIONSTATE_INACTIVE 2
#define QT_APPLICATIONSTATE_HIDDEN 4
#define QT_APPLICATIONSTATE_SUSPENDED 8

// ハイDPIスケールファクタ丸め方針
#define QT_HIGHDPISCALEFACTORROUNDINGPOLICY_ROUND 0
#define QT_HIGHDPISCALEFACTORROUNDINGPOLICY_ROUNDPREFERFLOOR 1
#define QT_HIGHDPISCALEFACTORROUNDINGPOLICY_FLOOR 2
#define QT_HIGHDPISCALEFACTORROUNDINGPOLICY_CEIL 3
#define QT_HIGHDPISCALEFACTORROUNDINGPOLICY_PASSTHROUGH 4

// キーボード修飾キー
#define QT_KEYBOARDMODIFIER_NONE 0x00000000
#define QT_KEYBOARDMODIFIER_SHIFT 0x02000000
#define QT_KEYBOARDMODIFIER_CONTROL 0x04000000
#define QT_KEYBOARDMODIFIER_ALT 0x08000000
#define QT_KEYBOARDMODIFIER_META 0x10000000
#define QT_KEYBOARDMODIFIER_KEYPAD 0x20000000
#define QT_KEYBOARDMODIFIER_GROUPSWITCH 0x40000000

// マウスボタン
#define QT_MOUSEBUTTON_NONE 0x00000000
#define QT_MOUSEBUTTON_LEFT 0x00000001
#define QT_MOUSEBUTTON_RIGHT 0x00000002
#define QT_MOUSEBUTTON_MIDDLE 0x00000004
#define QT_MOUSEBUTTON_BACK 0x00000008
#define QT_MOUSEBUTTON_FORWARD 0x00000010
#define QT_MOUSEBUTTON_TASK 0x00000020
#define QT_MOUSEBUTTON_EXTRA1 0x00000040
#define QT_MOUSEBUTTON_EXTRA2 0x00000080
#define QT_MOUSEBUTTON_EXTRA3 0x00000100
#define QT_MOUSEBUTTON_EXTRA4 0x00000200
#define QT_MOUSEBUTTON_EXTRA5 0x00000400
#define QT_MOUSEBUTTON_EXTRA6 0x00000800
#define QT_MOUSEBUTTON_EXTRA7 0x00001000
#define QT_MOUSEBUTTON_EXTRA8 0x00002000
#define QT_MOUSEBUTTON_EXTRA9 0x00004000
#define QT_MOUSEBUTTON_EXTRA10 0x00008000
#define QT_MOUSEBUTTON_EXTRA11 0x00010000
#define QT_MOUSEBUTTON_EXTRA12 0x00020000
#define QT_MOUSEBUTTON_EXTRA13 0x00040000
#define QT_MOUSEBUTTON_EXTRA14 0x00080000
#define QT_MOUSEBUTTON_EXTRA15 0x00100000
#define QT_MOUSEBUTTON_EXTRA16 0x00200000
#define QT_MOUSEBUTTON_EXTRA17 0x00400000
#define QT_MOUSEBUTTON_EXTRA18 0x00800000
#define QT_MOUSEBUTTON_EXTRA19 0x01000000
#define QT_MOUSEBUTTON_EXTRA20 0x02000000
#define QT_MOUSEBUTTON_EXTRA21 0x04000000
#define QT_MOUSEBUTTON_EXTRA22 0x08000000
#define QT_MOUSEBUTTON_EXTRA23 0x10000000
#define QT_MOUSEBUTTON_EXTRA24 0x20000000
#define QT_MOUSEBUTTON_ALLBUTTONS 0xffffffff

// プロパティ取得
const char* QGuiApplication_applicationDisplayName();
const char* QGuiApplication_desktopFileName();
int QGuiApplication_layoutDirection();
const char* QGuiApplication_platformName();
void* QGuiApplication_primaryScreen();
bool QGuiApplication_quitOnLastWindowClosed();

// プロパティ設定
void QGuiApplication_setApplicationDisplayName(const char* name);
void QGuiApplication_setDesktopFileName(const char* name);
void QGuiApplication_setLayoutDirection(int direction);
void QGuiApplication_setQuitOnLastWindowClosed(bool quit);
void QGuiApplication_setWindowIcon(void* icon);

// インスタンスメソッド
double QGuiApplication_devicePixelRatio(void* app);
bool QGuiApplication_isSavingSession(void* app);
bool QGuiApplication_isSessionRestored(void* app);
const char* QGuiApplication_sessionId(void* app);
const char* QGuiApplication_sessionKey(void* app);
void QGuiApplication_setBadgeNumber(void* app, long long number);

// 静的メソッド
void** QGuiApplication_allWindows(int* count);
int QGuiApplication_applicationState();
void QGuiApplication_changeOverrideCursor(void* cursor);
void* QGuiApplication_clipboard();
bool QGuiApplication_desktopSettingsAware();
void* QGuiApplication_focusObject();
void* QGuiApplication_focusWindow();
void* QGuiApplication_font();
int QGuiApplication_highDpiScaleFactorRoundingPolicy();
void* QGuiApplication_inputMethod();
bool QGuiApplication_isLeftToRight();
bool QGuiApplication_isRightToLeft();
int QGuiApplication_keyboardModifiers();
void* QGuiApplication_modalWindow();
int QGuiApplication_mouseButtons();
void* QGuiApplication_overrideCursor();
void* QGuiApplication_palette();
int QGuiApplication_queryKeyboardModifiers();
void QGuiApplication_restoreOverrideCursor();
void* QGuiApplication_screenAt(int x, int y);
void** QGuiApplication_screens(int* count);
void QGuiApplication_setDesktopSettingsAware(bool on);
void QGuiApplication_setFont(void* font);
void QGuiApplication_setHighDpiScaleFactorRoundingPolicy(int policy);
void QGuiApplication_setOverrideCursor(void* cursor);
void QGuiApplication_setPalette(void* palette);
void* QGuiApplication_styleHints();
void QGuiApplication_sync();
void* QGuiApplication_topLevelAt(int x, int y);
void** QGuiApplication_topLevelWindows(int* count);
void* QGuiApplication_windowIcon();

#ifdef __cplusplus
}
#endif

#endif // QGUIAPPLICATION_C_H
