#ifndef QAPPLICATION_C_H
#define QAPPLICATION_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 基本操作
void* QApplication_create(int argc, char* argv[]);
void QApplication_delete(void* app);
int QApplication_exec();
void QApplication_processEvents();

// プロパティ取得
bool QApplication_autoSipEnabled(void* app);
int QApplication_cursorFlashTime();
int QApplication_doubleClickInterval();
int QApplication_keyboardInputInterval();
int QApplication_startDragDistance();
int QApplication_startDragTime();
const char* QApplication_styleSheet(void* app);
int QApplication_wheelScrollLines();

// プロパティ設定
void QApplication_setAutoSipEnabled(void* app, bool enabled);
void QApplication_setCursorFlashTime(int time);
void QApplication_setDoubleClickInterval(int interval);
void QApplication_setKeyboardInputInterval(int interval);
void QApplication_setStartDragDistance(int distance);
void QApplication_setStartDragTime(int time);
void QApplication_setStyleSheet(void* app, const char* sheet);
void QApplication_setWheelScrollLines(int lines);

// アクション
void QApplication_aboutQt();
void QApplication_closeAllWindows();
void QApplication_beep();
void QApplication_alert(void* widget, int msec);

// ウィジェット関連
void* QApplication_activeModalWidget();
void* QApplication_activePopupWidget();
void* QApplication_activeWindow();
void* QApplication_focusWidget();
void* QApplication_widgetAt(int x, int y);
void* QApplication_topLevelAt(int x, int y);

// スタイル関連
void* QApplication_style();
void QApplication_setStyle(void* style);
void* QApplication_setStyleByName(const char* styleName);

// フォント・パレット関連
void QApplication_font(void* result);
void QApplication_fontForWidget(void* widget, void* result);
void QApplication_fontForClass(const char* className, void* result);
void QApplication_palette(void* result);
void QApplication_paletteForWidget(void* widget, void* result);
void QApplication_paletteForClass(const char* className, void* result);
void QApplication_setFont(void* font, const char* className);
void QApplication_setPalette(void* palette, const char* className);

// エフェクト関連
bool QApplication_isEffectEnabled(int effect);
void QApplication_setEffectEnabled(int effect, bool enable);

#ifdef __cplusplus
}
#endif

#endif // QAPPLICATION_C_H
