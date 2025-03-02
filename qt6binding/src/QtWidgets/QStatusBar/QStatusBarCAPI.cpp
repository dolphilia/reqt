#include "QStatusBarBind.h"

extern "C" {

void* QStatusBar_create(void* parent) {
    return QStatusBarBind::create(static_cast<QWidget*>(parent));
}

void QStatusBar_delete(void* statusBar) {
    QStatusBarBind::destroy(static_cast<QStatusBar*>(statusBar));
}

void QStatusBar_showMessage(void* statusBar, const char* message) {
    QStatusBarBind::showMessage(static_cast<QStatusBar*>(statusBar), message);
}

void QStatusBar_clearMessage(void* statusBar) {
    QStatusBarBind::clearMessage(static_cast<QStatusBar*>(statusBar));
}

void QStatusBar_setEnabled(void* statusBar, bool enabled) {
    QStatusBarBind::setEnabled(static_cast<QStatusBar*>(statusBar), enabled);
}

bool QStatusBar_isEnabled(void* statusBar) {
    return QStatusBarBind::isEnabled(static_cast<QStatusBar*>(statusBar));
}

}
