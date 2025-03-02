#include "QGuiApplicationBind.h"

extern "C" {

// プロパティ取得
const char* QGuiApplication_applicationDisplayName() {
    return QGuiApplicationBind::applicationDisplayName();
}

const char* QGuiApplication_desktopFileName() {
    return QGuiApplicationBind::desktopFileName();
}

int QGuiApplication_layoutDirection() {
    return QGuiApplicationBind::layoutDirection();
}

const char* QGuiApplication_platformName() {
    return QGuiApplicationBind::platformName();
}

void* QGuiApplication_primaryScreen() {
    return QGuiApplicationBind::primaryScreen();
}

bool QGuiApplication_quitOnLastWindowClosed() {
    return QGuiApplicationBind::quitOnLastWindowClosed();
}

// プロパティ設定
void QGuiApplication_setApplicationDisplayName(const char* name) {
    QGuiApplicationBind::setApplicationDisplayName(name);
}

void QGuiApplication_setDesktopFileName(const char* name) {
    QGuiApplicationBind::setDesktopFileName(name);
}

void QGuiApplication_setLayoutDirection(int direction) {
    QGuiApplicationBind::setLayoutDirection(direction);
}

void QGuiApplication_setQuitOnLastWindowClosed(bool quit) {
    QGuiApplicationBind::setQuitOnLastWindowClosed(quit);
}

void QGuiApplication_setWindowIcon(void* icon) {
    QGuiApplicationBind::setWindowIcon(static_cast<QIcon*>(icon));
}

// インスタンスメソッド
double QGuiApplication_devicePixelRatio(void* app) {
    return QGuiApplicationBind::devicePixelRatio(static_cast<QGuiApplication*>(app));
}

bool QGuiApplication_isSavingSession(void* app) {
    return QGuiApplicationBind::isSavingSession(static_cast<QGuiApplication*>(app));
}

bool QGuiApplication_isSessionRestored(void* app) {
    return QGuiApplicationBind::isSessionRestored(static_cast<QGuiApplication*>(app));
}

const char* QGuiApplication_sessionId(void* app) {
    return QGuiApplicationBind::sessionId(static_cast<QGuiApplication*>(app));
}

const char* QGuiApplication_sessionKey(void* app) {
    return QGuiApplicationBind::sessionKey(static_cast<QGuiApplication*>(app));
}

void QGuiApplication_setBadgeNumber(void* app, long long number) {
    QGuiApplicationBind::setBadgeNumber(static_cast<QGuiApplication*>(app), number);
}

// 静的メソッド
void** QGuiApplication_allWindows(int* count) {
    return reinterpret_cast<void**>(QGuiApplicationBind::allWindows(count));
}

int QGuiApplication_applicationState() {
    return QGuiApplicationBind::applicationState();
}

void QGuiApplication_changeOverrideCursor(void* cursor) {
    QGuiApplicationBind::changeOverrideCursor(static_cast<QCursor*>(cursor));
}

void* QGuiApplication_clipboard() {
    return QGuiApplicationBind::clipboard();
}

bool QGuiApplication_desktopSettingsAware() {
    return QGuiApplicationBind::desktopSettingsAware();
}

void* QGuiApplication_focusObject() {
    return QGuiApplicationBind::focusObject();
}

void* QGuiApplication_focusWindow() {
    return QGuiApplicationBind::focusWindow();
}

void* QGuiApplication_font() {
    return QGuiApplicationBind::font();
}

int QGuiApplication_highDpiScaleFactorRoundingPolicy() {
    return QGuiApplicationBind::highDpiScaleFactorRoundingPolicy();
}

void* QGuiApplication_inputMethod() {
    return QGuiApplicationBind::inputMethod();
}

bool QGuiApplication_isLeftToRight() {
    return QGuiApplicationBind::isLeftToRight();
}

bool QGuiApplication_isRightToLeft() {
    return QGuiApplicationBind::isRightToLeft();
}

int QGuiApplication_keyboardModifiers() {
    return QGuiApplicationBind::keyboardModifiers();
}

void* QGuiApplication_modalWindow() {
    return QGuiApplicationBind::modalWindow();
}

int QGuiApplication_mouseButtons() {
    return QGuiApplicationBind::mouseButtons();
}

void* QGuiApplication_overrideCursor() {
    return QGuiApplicationBind::overrideCursor();
}

void* QGuiApplication_palette() {
    return QGuiApplicationBind::palette();
}

int QGuiApplication_queryKeyboardModifiers() {
    return QGuiApplicationBind::queryKeyboardModifiers();
}

void QGuiApplication_restoreOverrideCursor() {
    QGuiApplicationBind::restoreOverrideCursor();
}

void* QGuiApplication_screenAt(int x, int y) {
    return QGuiApplicationBind::screenAt(x, y);
}

void** QGuiApplication_screens(int* count) {
    return reinterpret_cast<void**>(QGuiApplicationBind::screens(count));
}

void QGuiApplication_setDesktopSettingsAware(bool on) {
    QGuiApplicationBind::setDesktopSettingsAware(on);
}

void QGuiApplication_setFont(void* font) {
    QGuiApplicationBind::setFont(static_cast<QFont*>(font));
}

void QGuiApplication_setHighDpiScaleFactorRoundingPolicy(int policy) {
    QGuiApplicationBind::setHighDpiScaleFactorRoundingPolicy(policy);
}

void QGuiApplication_setOverrideCursor(void* cursor) {
    QGuiApplicationBind::setOverrideCursor(static_cast<QCursor*>(cursor));
}

void QGuiApplication_setPalette(void* palette) {
    QGuiApplicationBind::setPalette(static_cast<QPalette*>(palette));
}

void* QGuiApplication_styleHints() {
    return QGuiApplicationBind::styleHints();
}

void QGuiApplication_sync() {
    QGuiApplicationBind::sync();
}

void* QGuiApplication_topLevelAt(int x, int y) {
    return QGuiApplicationBind::topLevelAt(x, y);
}

void** QGuiApplication_topLevelWindows(int* count) {
    return reinterpret_cast<void**>(QGuiApplicationBind::topLevelWindows(count));
}

void* QGuiApplication_windowIcon() {
    return QGuiApplicationBind::windowIcon();
}

}
