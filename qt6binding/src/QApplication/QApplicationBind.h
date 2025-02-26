#ifndef QAPPLICATION_BIND_H
#define QAPPLICATION_BIND_H

#include <QApplication>

class QApplicationBind {
public:
    // 基本操作
    static QApplication* create(int argc, char* argv[]);
    static void destroy(QApplication* app);
    static int exec(QApplication* app);
    static void processEvents(QApplication* app);
    
    // プロパティ取得
    static bool autoSipEnabled(QApplication* app);
    static int cursorFlashTime(QApplication* app);
    static int doubleClickInterval(QApplication* app);
    static int keyboardInputInterval(QApplication* app);
    static int startDragDistance(QApplication* app);
    static int startDragTime(QApplication* app);
    static const char* styleSheet(QApplication* app);
    static int wheelScrollLines(QApplication* app);
    
    // プロパティ設定
    static void setAutoSipEnabled(QApplication* app, bool enabled);
    static void setCursorFlashTime(QApplication* app, int time);
    static void setDoubleClickInterval(QApplication* app, int interval);
    static void setKeyboardInputInterval(QApplication* app, int interval);
    static void setStartDragDistance(QApplication* app, int distance);
    static void setStartDragTime(QApplication* app, int time);
    static void setStyleSheet(QApplication* app, const char* sheet);
    static void setWheelScrollLines(QApplication* app, int lines);
    
    // アクション
    static void aboutQt(QApplication* app);
    static void closeAllWindows(QApplication* app);
    static void beep(QApplication* app);
    static void alert(QApplication* app, void* widget, int msec);
    
    // ウィジェット関連
    static void* activeModalWidget(QApplication* app);
    static void* activePopupWidget(QApplication* app);
    static void* activeWindow(QApplication* app);
    static void* focusWidget(QApplication* app);
    static void* widgetAt(QApplication* app, int x, int y);
    static void* topLevelAt(QApplication* app, int x, int y);
    
    // スタイル関連
    static void* style(QApplication* app);
    static void setStyle(QApplication* app, void* style);
    static void* setStyleByName(QApplication* app, const char* styleName);
    
    // フォント・パレット関連
    static void font(QApplication* app, void* result);
    static void fontForWidget(QApplication* app, void* widget, void* result);
    static void fontForClass(QApplication* app, const char* className, void* result);
    static void palette(QApplication* app, void* result);
    static void paletteForWidget(QApplication* app, void* widget, void* result);
    static void paletteForClass(QApplication* app, const char* className, void* result);
    static void setFont(QApplication* app, void* font, const char* className);
    static void setPalette(QApplication* app, void* palette, const char* className);
    
    // エフェクト関連
    static bool isEffectEnabled(QApplication* app, int effect);
    static void setEffectEnabled(QApplication* app, int effect, bool enable);
};

#endif // QAPPLICATION_BIND_H
