#include "QApplicationBind.h"
#include <QString>
#include <QWidget>
#include <QStyle>
#include <QFont>
#include <QPalette>
#include <QPoint>

QApplication* QApplicationBind::create(int argc, char* argv[]) {
    static int s_argc = argc;
    static char** s_argv = argv;
    static QApplication* app = nullptr;
    
    if (!app) {
        app = new QApplication(s_argc, s_argv);
    }
    return app;
}

void QApplicationBind::destroy(QApplication* app) {
    if (app) {
        delete app;
    }
}

int QApplicationBind::exec(QApplication* app) {
    if (app) {
        return app->exec();
    }
    return -1;
}

void QApplicationBind::processEvents(QApplication* app) {
    if (app) {
        app->processEvents();
    }
}

// プロパティ取得
bool QApplicationBind::autoSipEnabled(QApplication* app) {
    if (app) {
        return app->autoSipEnabled();
    }
    return false;
}

int QApplicationBind::cursorFlashTime(QApplication* app) {
    if (app) {
        return QApplication::cursorFlashTime();
    }
    return 0;
}

int QApplicationBind::doubleClickInterval(QApplication* app) {
    if (app) {
        return QApplication::doubleClickInterval();
    }
    return 0;
}

int QApplicationBind::keyboardInputInterval(QApplication* app) {
    if (app) {
        return QApplication::keyboardInputInterval();
    }
    return 0;
}

int QApplicationBind::startDragDistance(QApplication* app) {
    if (app) {
        return QApplication::startDragDistance();
    }
    return 0;
}

int QApplicationBind::startDragTime(QApplication* app) {
    if (app) {
        return QApplication::startDragTime();
    }
    return 0;
}

const char* QApplicationBind::styleSheet(QApplication* app) {
    if (app) {
        static QString styleSheetStr;
        styleSheetStr = app->styleSheet();
        return styleSheetStr.toUtf8().constData();
    }
    return "";
}

int QApplicationBind::wheelScrollLines(QApplication* app) {
    if (app) {
        return QApplication::wheelScrollLines();
    }
    return 0;
}

// プロパティ設定
void QApplicationBind::setAutoSipEnabled(QApplication* app, bool enabled) {
    if (app) {
        app->setAutoSipEnabled(enabled);
    }
}

void QApplicationBind::setCursorFlashTime(QApplication* app, int time) {
    if (app) {
        QApplication::setCursorFlashTime(time);
    }
}

void QApplicationBind::setDoubleClickInterval(QApplication* app, int interval) {
    if (app) {
        QApplication::setDoubleClickInterval(interval);
    }
}

void QApplicationBind::setKeyboardInputInterval(QApplication* app, int interval) {
    if (app) {
        QApplication::setKeyboardInputInterval(interval);
    }
}

void QApplicationBind::setStartDragDistance(QApplication* app, int distance) {
    if (app) {
        QApplication::setStartDragDistance(distance);
    }
}

void QApplicationBind::setStartDragTime(QApplication* app, int time) {
    if (app) {
        QApplication::setStartDragTime(time);
    }
}

void QApplicationBind::setStyleSheet(QApplication* app, const char* sheet) {
    if (app) {
        app->setStyleSheet(QString::fromUtf8(sheet));
    }
}

void QApplicationBind::setWheelScrollLines(QApplication* app, int lines) {
    if (app) {
        QApplication::setWheelScrollLines(lines);
    }
}

// アクション
void QApplicationBind::aboutQt(QApplication* app) {
    if (app) {
        app->aboutQt();
    }
}

void QApplicationBind::closeAllWindows(QApplication* app) {
    if (app) {
        app->closeAllWindows();
    }
}

void QApplicationBind::beep(QApplication* app) {
    if (app) {
        QApplication::beep();
    }
}

void QApplicationBind::alert(QApplication* app, void* widget, int msec) {
    if (app && widget) {
        QApplication::alert(static_cast<QWidget*>(widget), msec);
    }
}

// ウィジェット関連
void* QApplicationBind::activeModalWidget(QApplication* app) {
    if (app) {
        return QApplication::activeModalWidget();
    }
    return nullptr;
}

void* QApplicationBind::activePopupWidget(QApplication* app) {
    if (app) {
        return QApplication::activePopupWidget();
    }
    return nullptr;
}

void* QApplicationBind::activeWindow(QApplication* app) {
    if (app) {
        return QApplication::activeWindow();
    }
    return nullptr;
}

void* QApplicationBind::focusWidget(QApplication* app) {
    if (app) {
        return QApplication::focusWidget();
    }
    return nullptr;
}

void* QApplicationBind::widgetAt(QApplication* app, int x, int y) {
    if (app) {
        return QApplication::widgetAt(x, y);
    }
    return nullptr;
}

void* QApplicationBind::topLevelAt(QApplication* app, int x, int y) {
    if (app) {
        return QApplication::topLevelAt(x, y);
    }
    return nullptr;
}

// スタイル関連
void* QApplicationBind::style(QApplication* app) {
    if (app) {
        return QApplication::style();
    }
    return nullptr;
}

void QApplicationBind::setStyle(QApplication* app, void* style) {
    if (app && style) {
        QApplication::setStyle(static_cast<QStyle*>(style));
    }
}

void* QApplicationBind::setStyleByName(QApplication* app, const char* styleName) {
    if (app && styleName) {
        return QApplication::setStyle(QString::fromUtf8(styleName));
    }
    return nullptr;
}

// フォント・パレット関連
void QApplicationBind::font(QApplication* app, void* result) {
    if (app && result) {
        *static_cast<QFont*>(result) = QApplication::font();
    }
}

void QApplicationBind::fontForWidget(QApplication* app, void* widget, void* result) {
    if (app && widget && result) {
        *static_cast<QFont*>(result) = QApplication::font(static_cast<QWidget*>(widget));
    }
}

void QApplicationBind::fontForClass(QApplication* app, const char* className, void* result) {
    if (app && className && result) {
        *static_cast<QFont*>(result) = QApplication::font(className);
    }
}

void QApplicationBind::palette(QApplication* app, void* result) {
    if (app && result) {
        *static_cast<QPalette*>(result) = QApplication::palette();
    }
}

void QApplicationBind::paletteForWidget(QApplication* app, void* widget, void* result) {
    if (app && widget && result) {
        *static_cast<QPalette*>(result) = QApplication::palette(static_cast<QWidget*>(widget));
    }
}

void QApplicationBind::paletteForClass(QApplication* app, const char* className, void* result) {
    if (app && className && result) {
        *static_cast<QPalette*>(result) = QApplication::palette(className);
    }
}

void QApplicationBind::setFont(QApplication* app, void* font, const char* className) {
    if (app && font) {
        QApplication::setFont(*static_cast<QFont*>(font), className);
    }
}

void QApplicationBind::setPalette(QApplication* app, void* palette, const char* className) {
    if (app && palette) {
        QApplication::setPalette(*static_cast<QPalette*>(palette), className);
    }
}

// エフェクト関連
bool QApplicationBind::isEffectEnabled(QApplication* app, int effect) {
    if (app) {
        return QApplication::isEffectEnabled(static_cast<Qt::UIEffect>(effect));
    }
    return false;
}

void QApplicationBind::setEffectEnabled(QApplication* app, int effect, bool enable) {
    if (app) {
        QApplication::setEffectEnabled(static_cast<Qt::UIEffect>(effect), enable);
    }
}
