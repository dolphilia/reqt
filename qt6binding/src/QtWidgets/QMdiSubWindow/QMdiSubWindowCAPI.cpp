#include "QMdiSubWindowBind.h"
#include <QMdiSubWindow>

extern "C" {

void* QMdiSubWindow_create(void* parent) {
    return new QMdiSubWindowBind(static_cast<QWidget*>(parent));
}

void QMdiSubWindow_delete(void* subWindow) {
    delete static_cast<QMdiSubWindowBind*>(subWindow);
}

void QMdiSubWindow_setWidget(void* subWindow, void* widget) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setWidget(static_cast<QWidget*>(widget));
}

void* QMdiSubWindow_widget(void* subWindow) {
    return static_cast<QMdiSubWindowBind*>(subWindow)->widget();
}

bool QMdiSubWindow_isShaded(void* subWindow) {
    return static_cast<QMdiSubWindowBind*>(subWindow)->isShaded();
}

void QMdiSubWindow_setOption(void* subWindow, int option, bool on) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setOption(static_cast<QMdiSubWindow::SubWindowOption>(option), on);
}

bool QMdiSubWindow_testOption(void* subWindow, int option) {
    return static_cast<QMdiSubWindowBind*>(subWindow)->testOption(static_cast<QMdiSubWindow::SubWindowOption>(option));
}

void QMdiSubWindow_setKeyboardSingleStep(void* subWindow, int step) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setKeyboardSingleStep(step);
}

int QMdiSubWindow_keyboardSingleStep(void* subWindow) {
    return static_cast<QMdiSubWindowBind*>(subWindow)->keyboardSingleStep();
}

void QMdiSubWindow_setKeyboardPageStep(void* subWindow, int step) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setKeyboardPageStep(step);
}

int QMdiSubWindow_keyboardPageStep(void* subWindow) {
    return static_cast<QMdiSubWindowBind*>(subWindow)->keyboardPageStep();
}

void QMdiSubWindow_showSystemMenu(void* subWindow) {
    static_cast<QMdiSubWindowBind*>(subWindow)->showSystemMenu();
}

void QMdiSubWindow_showShaded(void* subWindow) {
    static_cast<QMdiSubWindowBind*>(subWindow)->showShaded();
}

void QMdiSubWindow_setMinimumSize(void* subWindow, int width, int height) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setMinimumSize(width, height);
}

void QMdiSubWindow_setMaximumSize(void* subWindow, int width, int height) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setMaximumSize(width, height);
}

void QMdiSubWindow_setSizeIncrement(void* subWindow, int width, int height) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setSizeIncrement(width, height);
}

void QMdiSubWindow_setBaseSize(void* subWindow, int width, int height) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setBaseSize(width, height);
}

void QMdiSubWindow_setWindowStateChangedCallback(void* subWindow, WindowStateChangedCallback callback) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setWindowStateChangedCallback(callback);
}

void QMdiSubWindow_setAboutToActivateCallback(void* subWindow, AboutToActivateCallback callback) {
    static_cast<QMdiSubWindowBind*>(subWindow)->setAboutToActivateCallback(callback);
}

}
