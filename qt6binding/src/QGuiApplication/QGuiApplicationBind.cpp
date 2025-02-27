#include "QGuiApplicationBind.h"

const char* QGuiApplicationBind::applicationDisplayName() {
    static QString name;
    name = QGuiApplication::applicationDisplayName();
    return name.toUtf8().constData();
}

const char* QGuiApplicationBind::desktopFileName() {
    static QString name;
    name = QGuiApplication::desktopFileName();
    return name.toUtf8().constData();
}

int QGuiApplicationBind::layoutDirection() {
    return static_cast<int>(QGuiApplication::layoutDirection());
}

const char* QGuiApplicationBind::platformName() {
    static QString name;
    name = QGuiApplication::platformName();
    return name.toUtf8().constData();
}

QScreen* QGuiApplicationBind::primaryScreen() {
    return QGuiApplication::primaryScreen();
}

bool QGuiApplicationBind::quitOnLastWindowClosed() {
    return QGuiApplication::quitOnLastWindowClosed();
}

void QGuiApplicationBind::setApplicationDisplayName(const char* name) {
    if (name) {
        QGuiApplication::setApplicationDisplayName(QString::fromUtf8(name));
    }
}

void QGuiApplicationBind::setDesktopFileName(const char* name) {
    if (name) {
        QGuiApplication::setDesktopFileName(QString::fromUtf8(name));
    }
}

void QGuiApplicationBind::setLayoutDirection(int direction) {
    QGuiApplication::setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
}

void QGuiApplicationBind::setQuitOnLastWindowClosed(bool quit) {
    QGuiApplication::setQuitOnLastWindowClosed(quit);
}

void QGuiApplicationBind::setWindowIcon(const QIcon* icon) {
    if (icon) {
        QGuiApplication::setWindowIcon(*icon);
    }
}

double QGuiApplicationBind::devicePixelRatio(QGuiApplication* app) {
    if (app) {
        return app->devicePixelRatio();
    }
    return 1.0;
}

bool QGuiApplicationBind::isSavingSession(QGuiApplication* app) {
    if (app) {
        return app->isSavingSession();
    }
    return false;
}

bool QGuiApplicationBind::isSessionRestored(QGuiApplication* app) {
    if (app) {
        return app->isSessionRestored();
    }
    return false;
}

const char* QGuiApplicationBind::sessionId(QGuiApplication* app) {
    if (app) {
        static QString id;
        id = app->sessionId();
        return id.toUtf8().constData();
    }
    return nullptr;
}

const char* QGuiApplicationBind::sessionKey(QGuiApplication* app) {
    if (app) {
        static QString key;
        key = app->sessionKey();
        return key.toUtf8().constData();
    }
    return nullptr;
}

void QGuiApplicationBind::setBadgeNumber(QGuiApplication* app, long long number) {
    if (app) {
        app->setBadgeNumber(number);
    }
}

QWindow** QGuiApplicationBind::allWindows(int* count) {
    static QList<QWindow*> windowPtrs;
    QWindowList windows = QGuiApplication::allWindows();
    
    windowPtrs.clear();
    for (QWindow* window : windows) {
        windowPtrs.append(window);
    }
    
    if (count) {
        *count = windowPtrs.size();
    }
    
    return windowPtrs.isEmpty() ? nullptr : windowPtrs.data();
}

int QGuiApplicationBind::applicationState() {
    return static_cast<int>(QGuiApplication::applicationState());
}

void QGuiApplicationBind::changeOverrideCursor(const QCursor* cursor) {
    if (cursor) {
        QGuiApplication::changeOverrideCursor(*cursor);
    }
}

QClipboard* QGuiApplicationBind::clipboard() {
    return QGuiApplication::clipboard();
}

bool QGuiApplicationBind::desktopSettingsAware() {
    return QGuiApplication::desktopSettingsAware();
}

QObject* QGuiApplicationBind::focusObject() {
    return QGuiApplication::focusObject();
}

QWindow* QGuiApplicationBind::focusWindow() {
    return QGuiApplication::focusWindow();
}

QFont* QGuiApplicationBind::font() {
    static QFont font;
    font = QGuiApplication::font();
    return &font;
}

int QGuiApplicationBind::highDpiScaleFactorRoundingPolicy() {
    return static_cast<int>(QGuiApplication::highDpiScaleFactorRoundingPolicy());
}

QInputMethod* QGuiApplicationBind::inputMethod() {
    return QGuiApplication::inputMethod();
}

bool QGuiApplicationBind::isLeftToRight() {
    return QGuiApplication::isLeftToRight();
}

bool QGuiApplicationBind::isRightToLeft() {
    return QGuiApplication::isRightToLeft();
}

int QGuiApplicationBind::keyboardModifiers() {
    return static_cast<int>(QGuiApplication::keyboardModifiers());
}

QWindow* QGuiApplicationBind::modalWindow() {
    return QGuiApplication::modalWindow();
}

int QGuiApplicationBind::mouseButtons() {
    return static_cast<int>(QGuiApplication::mouseButtons());
}

QCursor* QGuiApplicationBind::overrideCursor() {
    static QCursor cursor;
    QCursor* overrideCursor = QGuiApplication::overrideCursor();
    if (overrideCursor) {
        cursor = *overrideCursor;
        return &cursor;
    }
    return nullptr;
}

QPalette* QGuiApplicationBind::palette() {
    static QPalette palette;
    palette = QGuiApplication::palette();
    return &palette;
}

int QGuiApplicationBind::queryKeyboardModifiers() {
    return static_cast<int>(QGuiApplication::queryKeyboardModifiers());
}

void QGuiApplicationBind::restoreOverrideCursor() {
    QGuiApplication::restoreOverrideCursor();
}

QScreen* QGuiApplicationBind::screenAt(int x, int y) {
    return QGuiApplication::screenAt(QPoint(x, y));
}

QScreen** QGuiApplicationBind::screens(int* count) {
    static QList<QScreen*> screenPtrs;
    QList<QScreen*> screens = QGuiApplication::screens();
    
    screenPtrs.clear();
    for (QScreen* screen : screens) {
        screenPtrs.append(screen);
    }
    
    if (count) {
        *count = screenPtrs.size();
    }
    
    return screenPtrs.isEmpty() ? nullptr : screenPtrs.data();
}

void QGuiApplicationBind::setDesktopSettingsAware(bool on) {
    QGuiApplication::setDesktopSettingsAware(on);
}

void QGuiApplicationBind::setFont(const QFont* font) {
    if (font) {
        QGuiApplication::setFont(*font);
    }
}

void QGuiApplicationBind::setHighDpiScaleFactorRoundingPolicy(int policy) {
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(static_cast<Qt::HighDpiScaleFactorRoundingPolicy>(policy));
}

void QGuiApplicationBind::setOverrideCursor(const QCursor* cursor) {
    if (cursor) {
        QGuiApplication::setOverrideCursor(*cursor);
    }
}

void QGuiApplicationBind::setPalette(const QPalette* palette) {
    if (palette) {
        QGuiApplication::setPalette(*palette);
    }
}

QStyleHints* QGuiApplicationBind::styleHints() {
    return QGuiApplication::styleHints();
}

void QGuiApplicationBind::sync() {
    QGuiApplication::sync();
}

QWindow* QGuiApplicationBind::topLevelAt(int x, int y) {
    return QGuiApplication::topLevelAt(QPoint(x, y));
}

QWindow** QGuiApplicationBind::topLevelWindows(int* count) {
    static QList<QWindow*> windowPtrs;
    QWindowList windows = QGuiApplication::topLevelWindows();
    
    windowPtrs.clear();
    for (QWindow* window : windows) {
        windowPtrs.append(window);
    }
    
    if (count) {
        *count = windowPtrs.size();
    }
    
    return windowPtrs.isEmpty() ? nullptr : windowPtrs.data();
}

QIcon* QGuiApplicationBind::windowIcon() {
    static QIcon icon;
    icon = QGuiApplication::windowIcon();
    return &icon;
}
