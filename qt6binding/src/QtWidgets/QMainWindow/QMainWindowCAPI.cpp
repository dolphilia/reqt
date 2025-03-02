#include "QMainWindowBind.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QDockWidget>

extern "C" {

void* QMainWindow_create(void* parent) {
    return new QMainWindowBind(static_cast<QWidget*>(parent));
}

void QMainWindow_delete(void* mainWindow) {
    delete static_cast<QMainWindowBind*>(mainWindow);
}

void QMainWindow_setCentralWidget(void* mainWindow, void* widget) {
    static_cast<QMainWindowBind*>(mainWindow)->setCentralWidget(static_cast<QWidget*>(widget));
}

void* QMainWindow_centralWidget(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->centralWidget();
}

void* QMainWindow_takeCentralWidget(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->takeCentralWidget();
}

void* QMainWindow_menuBar(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->menuBar();
}

void QMainWindow_setMenuBar(void* mainWindow, void* menuBar) {
    static_cast<QMainWindowBind*>(mainWindow)->setMenuBar(static_cast<QMenuBar*>(menuBar));
}

void* QMainWindow_statusBar(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->statusBar();
}

void QMainWindow_setStatusBar(void* mainWindow, void* statusBar) {
    static_cast<QMainWindowBind*>(mainWindow)->setStatusBar(static_cast<QStatusBar*>(statusBar));
}

void QMainWindow_addToolBar(void* mainWindow, void* toolBar) {
    static_cast<QMainWindowBind*>(mainWindow)->addToolBar(static_cast<QToolBar*>(toolBar));
}

void QMainWindow_addToolBarBreak(void* mainWindow) {
    static_cast<QMainWindowBind*>(mainWindow)->addToolBarBreak();
}

void QMainWindow_insertToolBar(void* mainWindow, void* before, void* toolBar) {
    static_cast<QMainWindowBind*>(mainWindow)->insertToolBar(
        static_cast<QToolBar*>(before),
        static_cast<QToolBar*>(toolBar)
    );
}

void QMainWindow_insertToolBarBreak(void* mainWindow, void* before) {
    static_cast<QMainWindowBind*>(mainWindow)->insertToolBarBreak(static_cast<QToolBar*>(before));
}

void QMainWindow_removeToolBar(void* mainWindow, void* toolBar) {
    static_cast<QMainWindowBind*>(mainWindow)->removeToolBar(static_cast<QToolBar*>(toolBar));
}

void QMainWindow_removeToolBarBreak(void* mainWindow, void* before) {
    static_cast<QMainWindowBind*>(mainWindow)->removeToolBarBreak(static_cast<QToolBar*>(before));
}

void QMainWindow_addDockWidget(void* mainWindow, int area, void* dockWidget) {
    static_cast<QMainWindowBind*>(mainWindow)->addDockWidget(
        static_cast<Qt::DockWidgetArea>(area),
        static_cast<QDockWidget*>(dockWidget)
    );
}

void QMainWindow_removeDockWidget(void* mainWindow, void* dockWidget) {
    static_cast<QMainWindowBind*>(mainWindow)->removeDockWidget(static_cast<QDockWidget*>(dockWidget));
}

void QMainWindow_setDockOptions(void* mainWindow, int options) {
    static_cast<QMainWindowBind*>(mainWindow)->setDockOptions(
        static_cast<QMainWindow::DockOptions>(options)
    );
}

int QMainWindow_dockOptions(void* mainWindow) {
    return static_cast<int>(static_cast<QMainWindowBind*>(mainWindow)->dockOptions());
}

void QMainWindow_saveState(void* mainWindow, int version) {
    static_cast<QMainWindowBind*>(mainWindow)->saveState(version);
}

void QMainWindow_restoreState(void* mainWindow, const char* state, int version) {
    static_cast<QMainWindowBind*>(mainWindow)->restoreState(QByteArray(state), version);
}

void QMainWindow_setAnimated(void* mainWindow, bool enabled) {
    static_cast<QMainWindowBind*>(mainWindow)->setAnimated(enabled);
}

void QMainWindow_setDockNestingEnabled(void* mainWindow, bool enabled) {
    static_cast<QMainWindowBind*>(mainWindow)->setDockNestingEnabled(enabled);
}

bool QMainWindow_isAnimated(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->isAnimated();
}

bool QMainWindow_isDockNestingEnabled(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->isDockNestingEnabled();
}

void QMainWindow_setUnifiedTitleAndToolBarOnMac(void* mainWindow, bool set) {
    static_cast<QMainWindowBind*>(mainWindow)->setUnifiedTitleAndToolBarOnMac(set);
}

bool QMainWindow_unifiedTitleAndToolBarOnMac(void* mainWindow) {
    return static_cast<QMainWindowBind*>(mainWindow)->unifiedTitleAndToolBarOnMac();
}

}
