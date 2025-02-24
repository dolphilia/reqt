#ifndef QMAINWINDOW_C_H
#define QMAINWINDOW_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QMainWindow作成・削除
void* QMainWindow_create(void* parent);
void QMainWindow_delete(void* mainWindow);

// セントラルウィジェット
void QMainWindow_setCentralWidget(void* mainWindow, void* widget);
void* QMainWindow_centralWidget(void* mainWindow);
void* QMainWindow_takeCentralWidget(void* mainWindow);

// メニューバー
void* QMainWindow_menuBar(void* mainWindow);
void QMainWindow_setMenuBar(void* mainWindow, void* menuBar);

// ステータスバー
void* QMainWindow_statusBar(void* mainWindow);
void QMainWindow_setStatusBar(void* mainWindow, void* statusBar);

// ツールバー
void QMainWindow_addToolBar(void* mainWindow, void* toolBar);
void QMainWindow_addToolBarBreak(void* mainWindow);
void QMainWindow_insertToolBar(void* mainWindow, void* before, void* toolBar);
void QMainWindow_insertToolBarBreak(void* mainWindow, void* before);
void QMainWindow_removeToolBar(void* mainWindow, void* toolBar);
void QMainWindow_removeToolBarBreak(void* mainWindow, void* before);

// ドックウィジェット
void QMainWindow_addDockWidget(void* mainWindow, int area, void* dockWidget);
void QMainWindow_removeDockWidget(void* mainWindow, void* dockWidget);
void QMainWindow_setDockOptions(void* mainWindow, int options);
int QMainWindow_dockOptions(void* mainWindow);

// ウィンドウ状態
void QMainWindow_saveState(void* mainWindow, int version);
void QMainWindow_restoreState(void* mainWindow, const char* state, int version);

// レイアウト
void QMainWindow_setAnimated(void* mainWindow, bool enabled);
void QMainWindow_setDockNestingEnabled(void* mainWindow, bool enabled);
bool QMainWindow_isAnimated(void* mainWindow);
bool QMainWindow_isDockNestingEnabled(void* mainWindow);

// サイズ制約
void QMainWindow_setUnifiedTitleAndToolBarOnMac(void* mainWindow, bool set);
bool QMainWindow_unifiedTitleAndToolBarOnMac(void* mainWindow);

// ドックウィジェットエリア定数
#define QMAINWINDOW_LEFTDOCKWIDGETAREA 1
#define QMAINWINDOW_RIGHTDOCKWIDGETAREA 2
#define QMAINWINDOW_TOPDOCKWIDGETAREA 4
#define QMAINWINDOW_BOTTOMDOCKWIDGETAREA 8
#define QMAINWINDOW_ALLDOCKWIDGETAREAS 15

// ドックウィジェットオプション定数
#define QMAINWINDOW_ANIMATEDOCKS 0x01
#define QMAINWINDOW_ALLOWTABBEDDOCKS 0x02
#define QMAINWINDOW_ALLOWNESTEDDOCKS 0x04
#define QMAINWINDOW_FORCETABBEDDOCKS 0x08
#define QMAINWINDOW_VERTICALANIMATED 0x10

#ifdef __cplusplus
}
#endif

#endif // QMAINWINDOW_C_H
