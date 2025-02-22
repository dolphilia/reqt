#ifndef QMDISUBWINDOW_C_H
#define QMDISUBWINDOW_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QMdiSubWindow作成・削除
void* QMdiSubWindow_create(void* parent);
void QMdiSubWindow_delete(void* subWindow);

// ウィジェット管理
void QMdiSubWindow_setWidget(void* subWindow, void* widget);
void* QMdiSubWindow_widget(void* subWindow);

// ウィンドウ状態
bool QMdiSubWindow_isShaded(void* subWindow);
void QMdiSubWindow_setOption(void* subWindow, int option, bool on);
bool QMdiSubWindow_testOption(void* subWindow, int option);
void QMdiSubWindow_setKeyboardSingleStep(void* subWindow, int step);
int QMdiSubWindow_keyboardSingleStep(void* subWindow);
void QMdiSubWindow_setKeyboardPageStep(void* subWindow, int step);
int QMdiSubWindow_keyboardPageStep(void* subWindow);

// ウィンドウ操作
void QMdiSubWindow_showSystemMenu(void* subWindow);
void QMdiSubWindow_showShaded(void* subWindow);

// サイズ制約
void QMdiSubWindow_setMinimumSize(void* subWindow, int width, int height);
void QMdiSubWindow_setMaximumSize(void* subWindow, int width, int height);
void QMdiSubWindow_setSizeIncrement(void* subWindow, int width, int height);
void QMdiSubWindow_setBaseSize(void* subWindow, int width, int height);

// ウィンドウオプション定数
#define QMDISUBWINDOW_RASTEREDSHADOW 0x00000001
#define QMDISUBWINDOW_ALLOWOUTSIDEMOVE 0x00000002

// コールバック関数
typedef void (*QMdiSubWindowWindowStateChangedCallback)(void* subWindow, int oldState, int newState);
typedef void (*QMdiSubWindowAboutToActivateCallback)(void* subWindow);

void QMdiSubWindow_setWindowStateChangedCallback(void* subWindow, QMdiSubWindowWindowStateChangedCallback callback);
void QMdiSubWindow_setAboutToActivateCallback(void* subWindow, QMdiSubWindowAboutToActivateCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QMDISUBWINDOW_C_H
