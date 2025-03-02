#ifndef QGUIAPPLICATION_BIND_H
#define QGUIAPPLICATION_BIND_H

#include <QGuiApplication>
#include <QScreen>
#include <QWindow>
#include <QClipboard>
#include <QCursor>
#include <QFont>
#include <QIcon>
#include <QInputMethod>
#include <QPalette>
#include <QStyleHints>

class QGuiApplicationBind {
public:
    // プロパティ取得
    static const char* applicationDisplayName();
    static const char* desktopFileName();
    static int layoutDirection();
    static const char* platformName();
    static QScreen* primaryScreen();
    static bool quitOnLastWindowClosed();
    
    // プロパティ設定
    static void setApplicationDisplayName(const char* name);
    static void setDesktopFileName(const char* name);
    static void setLayoutDirection(int direction);
    static void setQuitOnLastWindowClosed(bool quit);
    static void setWindowIcon(const QIcon* icon);
    
    // インスタンスメソッド
    static double devicePixelRatio(QGuiApplication* app);
    static bool isSavingSession(QGuiApplication* app);
    static bool isSessionRestored(QGuiApplication* app);
    static const char* sessionId(QGuiApplication* app);
    static const char* sessionKey(QGuiApplication* app);
    static void setBadgeNumber(QGuiApplication* app, long long number);
    
    // 静的メソッド
    static QWindow** allWindows(int* count);
    static int applicationState();
    static void changeOverrideCursor(const QCursor* cursor);
    static QClipboard* clipboard();
    static bool desktopSettingsAware();
    static QObject* focusObject();
    static QWindow* focusWindow();
    static QFont* font();
    static int highDpiScaleFactorRoundingPolicy();
    static QInputMethod* inputMethod();
    static bool isLeftToRight();
    static bool isRightToLeft();
    static int keyboardModifiers();
    static QWindow* modalWindow();
    static int mouseButtons();
    static QCursor* overrideCursor();
    static QPalette* palette();
    static int queryKeyboardModifiers();
    static void restoreOverrideCursor();
    static QScreen* screenAt(int x, int y);
    static QScreen** screens(int* count);
    static void setDesktopSettingsAware(bool on);
    static void setFont(const QFont* font);
    static void setHighDpiScaleFactorRoundingPolicy(int policy);
    static void setOverrideCursor(const QCursor* cursor);
    static void setPalette(const QPalette* palette);
    static QStyleHints* styleHints();
    static void sync();
    static QWindow* topLevelAt(int x, int y);
    static QWindow** topLevelWindows(int* count);
    static QIcon* windowIcon();
};

#endif // QGUIAPPLICATION_BIND_H
