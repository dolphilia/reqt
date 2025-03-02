#include "QApplicationBind.h"
#include "qapplication.h"

extern "C" {

// 基本操作
void* QApplication_create(int argc, char* argv[]) {
    return QApplicationBind::create(argc, argv);
}

void QApplication_delete(void* app) {
    QApplicationBind::destroy(static_cast<QApplication*>(app));
}

int QApplication_exec(void* app) {
    return QApplicationBind::exec(static_cast<QApplication*>(app));
}

void QApplication_processEvents(void* app) {
    QApplicationBind::processEvents(static_cast<QApplication*>(app));
}

// プロパティ取得
bool QApplication_autoSipEnabled(void* app) {
    return QApplicationBind::autoSipEnabled(static_cast<QApplication*>(app));
}

int QApplication_cursorFlashTime(void* app) {
    return QApplicationBind::cursorFlashTime(static_cast<QApplication*>(app));
}

int QApplication_doubleClickInterval(void* app) {
    return QApplicationBind::doubleClickInterval(static_cast<QApplication*>(app));
}

int QApplication_keyboardInputInterval(void* app) {
    return QApplicationBind::keyboardInputInterval(static_cast<QApplication*>(app));
}

int QApplication_startDragDistance(void* app) {
    return QApplicationBind::startDragDistance(static_cast<QApplication*>(app));
}

int QApplication_startDragTime(void* app) {
    return QApplicationBind::startDragTime(static_cast<QApplication*>(app));
}

const char* QApplication_styleSheet(void* app) {
    return QApplicationBind::styleSheet(static_cast<QApplication*>(app));
}

int QApplication_wheelScrollLines(void* app) {
    return QApplicationBind::wheelScrollLines(static_cast<QApplication*>(app));
}

// プロパティ設定
void QApplication_setAutoSipEnabled(void* app, bool enabled) {
    QApplicationBind::setAutoSipEnabled(static_cast<QApplication*>(app), enabled);
}

void QApplication_setCursorFlashTime(void* app, int time) {
    QApplicationBind::setCursorFlashTime(static_cast<QApplication*>(app), time);
}

void QApplication_setDoubleClickInterval(void* app, int interval) {
    QApplicationBind::setDoubleClickInterval(static_cast<QApplication*>(app), interval);
}

void QApplication_setKeyboardInputInterval(void* app, int interval) {
    QApplicationBind::setKeyboardInputInterval(static_cast<QApplication*>(app), interval);
}

void QApplication_setStartDragDistance(void* app, int distance) {
    QApplicationBind::setStartDragDistance(static_cast<QApplication*>(app), distance);
}

void QApplication_setStartDragTime(void* app, int time) {
    QApplicationBind::setStartDragTime(static_cast<QApplication*>(app), time);
}

void QApplication_setStyleSheet(void* app, const char* sheet) {
    QApplicationBind::setStyleSheet(static_cast<QApplication*>(app), sheet);
}

void QApplication_setWheelScrollLines(void* app, int lines) {
    QApplicationBind::setWheelScrollLines(static_cast<QApplication*>(app), lines);
}

// アクション
void QApplication_aboutQt(void* app) {
    QApplicationBind::aboutQt(static_cast<QApplication*>(app));
}

void QApplication_closeAllWindows(void* app) {
    QApplicationBind::closeAllWindows(static_cast<QApplication*>(app));
}

void QApplication_beep(void* app) {
    QApplicationBind::beep(static_cast<QApplication*>(app));
}

void QApplication_alert(void* app, void* widget, int msec) {
    QApplicationBind::alert(static_cast<QApplication*>(app), widget, msec);
}

// ウィジェット関連
void* QApplication_activeModalWidget(void* app) {
    return QApplicationBind::activeModalWidget(static_cast<QApplication*>(app));
}

void* QApplication_activePopupWidget(void* app) {
    return QApplicationBind::activePopupWidget(static_cast<QApplication*>(app));
}

void* QApplication_activeWindow(void* app) {
    return QApplicationBind::activeWindow(static_cast<QApplication*>(app));
}

void* QApplication_focusWidget(void* app) {
    return QApplicationBind::focusWidget(static_cast<QApplication*>(app));
}

void* QApplication_widgetAt(void* app, int x, int y) {
    return QApplicationBind::widgetAt(static_cast<QApplication*>(app), x, y);
}

void* QApplication_topLevelAt(void* app, int x, int y) {
    return QApplicationBind::topLevelAt(static_cast<QApplication*>(app), x, y);
}

// スタイル関連
void* QApplication_style(void* app) {
    return QApplicationBind::style(static_cast<QApplication*>(app));
}

void QApplication_setStyle(void* app, void* style) {
    QApplicationBind::setStyle(static_cast<QApplication*>(app), style);
}

void* QApplication_setStyleByName(void* app, const char* styleName) {
    return QApplicationBind::setStyleByName(static_cast<QApplication*>(app), styleName);
}

// フォント・パレット関連
void QApplication_font(void* app, void* result) {
    QApplicationBind::font(static_cast<QApplication*>(app), result);
}

void QApplication_fontForWidget(void* app, void* widget, void* result) {
    QApplicationBind::fontForWidget(static_cast<QApplication*>(app), widget, result);
}

void QApplication_fontForClass(void* app, const char* className, void* result) {
    QApplicationBind::fontForClass(static_cast<QApplication*>(app), className, result);
}

void QApplication_palette(void* app, void* result) {
    QApplicationBind::palette(static_cast<QApplication*>(app), result);
}

void QApplication_paletteForWidget(void* app, void* widget, void* result) {
    QApplicationBind::paletteForWidget(static_cast<QApplication*>(app), widget, result);
}

void QApplication_paletteForClass(void* app, const char* className, void* result) {
    QApplicationBind::paletteForClass(static_cast<QApplication*>(app), className, result);
}

void QApplication_setFont(void* app, void* font, const char* className) {
    QApplicationBind::setFont(static_cast<QApplication*>(app), font, className);
}

void QApplication_setPalette(void* app, void* palette, const char* className) {
    QApplicationBind::setPalette(static_cast<QApplication*>(app), palette, className);
}

// エフェクト関連
bool QApplication_isEffectEnabled(void* app, int effect) {
    return QApplicationBind::isEffectEnabled(static_cast<QApplication*>(app), effect);
}

void QApplication_setEffectEnabled(void* app, int effect, bool enable) {
    QApplicationBind::setEffectEnabled(static_cast<QApplication*>(app), effect, enable);
}

}
