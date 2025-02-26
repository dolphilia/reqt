#ifndef QAPPLICATION_C_H
#define QAPPLICATION_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 基本操作
void* QApplication_create(int argc, char* argv[]);
void QApplication_delete(void* app);
int QApplication_exec(void* app);
void QApplication_processEvents(void* app);

// プロパティ取得
bool QApplication_autoSipEnabled(void* app);
int QApplication_cursorFlashTime(void* app);
int QApplication_doubleClickInterval(void* app);
int QApplication_keyboardInputInterval(void* app);
int QApplication_startDragDistance(void* app);
int QApplication_startDragTime(void* app);
const char* QApplication_styleSheet(void* app);
int QApplication_wheelScrollLines(void* app);

// プロパティ設定
void QApplication_setAutoSipEnabled(void* app, bool enabled);
void QApplication_setCursorFlashTime(void* app, int time);
void QApplication_setDoubleClickInterval(void* app, int interval);
void QApplication_setKeyboardInputInterval(void* app, int interval);
void QApplication_setStartDragDistance(void* app, int distance);
void QApplication_setStartDragTime(void* app, int time);
void QApplication_setStyleSheet(void* app, const char* sheet);
void QApplication_setWheelScrollLines(void* app, int lines);

// アクション
void QApplication_aboutQt(void* app);
void QApplication_closeAllWindows(void* app);
void QApplication_beep(void* app);
void QApplication_alert(void* app, void* widget, int msec);

// ウィジェット関連
void* QApplication_activeModalWidget(void* app);
void* QApplication_activePopupWidget(void* app);
void* QApplication_activeWindow(void* app);
void* QApplication_focusWidget(void* app);
void* QApplication_widgetAt(void* app, int x, int y);
void* QApplication_topLevelAt(void* app, int x, int y);

// スタイル関連
void* QApplication_style(void* app);
void QApplication_setStyle(void* app, void* style);
void* QApplication_setStyleByName(void* app, const char* styleName);

// フォント・パレット関連
void QApplication_font(void* app, void* result);
void QApplication_fontForWidget(void* app, void* widget, void* result);
void QApplication_fontForClass(void* app, const char* className, void* result);
void QApplication_palette(void* app, void* result);
void QApplication_paletteForWidget(void* app, void* widget, void* result);
void QApplication_paletteForClass(void* app, const char* className, void* result);
void QApplication_setFont(void* app, void* font, const char* className);
void QApplication_setPalette(void* app, void* palette, const char* className);

// エフェクト関連
bool QApplication_isEffectEnabled(void* app, int effect);
void QApplication_setEffectEnabled(void* app, int effect, bool enable);

#ifdef __cplusplus
}
#endif

#endif // QAPPLICATION_C_H
