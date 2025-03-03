#include "qapplication.h"
#include <QFont>
#include <QPalette>
#include <QApplication>

extern "C" {

// Static Methods

// 基本操作

int QApplication_exec() {
    return QApplication::exec();
}

void QApplication_processEvents() {
    QApplication::processEvents();
}

// プロパティ取得
int QApplication_cursorFlashTime() {
    return QApplication::cursorFlashTime();
}

int QApplication_doubleClickInterval() {
    return QApplication::doubleClickInterval();
}

int QApplication_keyboardInputInterval() {
    return QApplication::keyboardInputInterval();
}

int QApplication_startDragDistance() {
    return QApplication::startDragDistance();
}

int QApplication_startDragTime() {
    return QApplication::startDragTime();
}

int QApplication_wheelScrollLines() {
    return QApplication::wheelScrollLines();
}

// プロパティ設定
void QApplication_setCursorFlashTime(int time) {
    QApplication::setCursorFlashTime(time);
}

void QApplication_setDoubleClickInterval(int interval) {
    QApplication::setDoubleClickInterval(interval);
}

void QApplication_setKeyboardInputInterval(int interval) {
    QApplication::setKeyboardInputInterval(interval);
}

void QApplication_setStartDragDistance(int distance) {
    QApplication::setStartDragDistance(distance);
}

void QApplication_setStartDragTime(int time) {
    QApplication::setStartDragTime(time);
}

void QApplication_setWheelScrollLines(int lines) {
    QApplication::setWheelScrollLines(lines);
}

// アクション
void QApplication_aboutQt() {
    QApplication::aboutQt();
}

void QApplication_closeAllWindows() {
    QApplication::closeAllWindows();
}

void QApplication_beep() {
    QApplication::beep();
}

void QApplication_alert(void* widget, int msec) {
    QApplication::alert(static_cast<QWidget*>(widget), msec);
}

// ウィジェット関連
void* QApplication_activeModalWidget() {
    return QApplication::activeModalWidget();
}

void* QApplication_activePopupWidget() {
    return QApplication::activePopupWidget();
}

void* QApplication_activeWindow() {
    return QApplication::activeWindow();
}

void* QApplication_focusWidget() {
    return QApplication::focusWidget();
}

void* QApplication_widgetAt(int x, int y) {
    return QApplication::widgetAt(x, y);
}

void* QApplication_topLevelAt(int x, int y) {
    return QApplication::topLevelAt(x, y);
}

// スタイル関連
void* QApplication_style() {
    return QApplication::style();
}

void QApplication_setStyle(void* style) {
    QApplication::setStyle(static_cast<QStyle *>(style));
}

void* QApplication_setStyleByName(const char* styleName) {
    return QApplication::setStyle(styleName);
}

// フォント・パレット関連
void QApplication_font(void* result) {
    *static_cast<QFont*>(result) = QApplication::font();
}

void QApplication_fontForWidget(void* widget, void* result) {
    *static_cast<QFont*>(result) = QApplication::font(static_cast<QWidget*>(widget));
}

void QApplication_fontForClass(const char* className, void* result) {
    *static_cast<QFont*>(result) = QApplication::font(className);
}

void QApplication_palette(void* result) {
    *static_cast<QPalette*>(result) = QApplication::palette();
}

void QApplication_paletteForWidget(void* widget, void* result) {
    *static_cast<QPalette*>(result) = QApplication::palette(static_cast<QWidget*>(widget));
}

void QApplication_paletteForClass(const char* className, void* result) {
    *static_cast<QPalette*>(result) = QApplication::palette(className);
}

void QApplication_setFont(void* font, const char* className) {
    QApplication::setFont(*static_cast<QFont*>(font), className);
}

void QApplication_setPalette(void* palette, const char* className) {
    QApplication::setPalette(*static_cast<QPalette*>(palette), className);
}

// エフェクト関連
bool QApplication_isEffectEnabled(int effect) {
    return QApplication::isEffectEnabled(static_cast<Qt::UIEffect>(effect));
}

void QApplication_setEffectEnabled(int effect, bool enable) {
    QApplication::setEffectEnabled(static_cast<Qt::UIEffect>(effect), enable);
}

// Methods

// 基本操作
void* QApplication_create(int argc, char* argv[]) {
    return new QApplication(argc, argv);
}

void QApplication_delete(void* app) {
    delete static_cast<QApplication*>(app);
}

// プロパティ取得
bool QApplication_autoSipEnabled(void* app) {
    return static_cast<QApplication*>(app)->autoSipEnabled();
}

const char* QApplication_styleSheet(void* app) {
    const QString qstr = static_cast<QApplication*>(app)->styleSheet();
    return qstr.toUtf8().constData();
}

// プロパティ設定
void QApplication_setAutoSipEnabled(void* app, bool enabled) {
    static_cast<QApplication*>(app)->setAutoSipEnabled(enabled);
}

void QApplication_setStyleSheet(void* app, const char* sheet) {
    static_cast<QApplication*>(app)->setStyleSheet(sheet);
}



}
