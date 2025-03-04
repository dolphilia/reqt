#include "QStatusBarBind.h"

extern "C" {

void* QStatusBar_create(void* parent) {
    return new QStatusBarBind(static_cast<QWidget*>(parent));
}

void QStatusBar_delete(void* statusBar) {
    delete static_cast<QStatusBarBind*>(statusBar);
}

void QStatusBar_showMessage(void* statusBar, const char* message) {
    const QString qstr = QString::fromUtf8(message);
    static_cast<QStatusBarBind*>(statusBar)->showMessage(qstr);
}

void QStatusBar_clearMessage(void* statusBar) {
    static_cast<QStatusBarBind*>(statusBar)->clearMessage();
}

void QStatusBar_setEnabled(void* statusBar, bool enabled) {
    static_cast<QStatusBarBind*>(statusBar)->setEnabled(enabled);
}

bool QStatusBar_isEnabled(void* statusBar) {
    return static_cast<QStatusBarBind*>(statusBar)->isEnabled();
}

typedef void (*QStatusBar_MessageChangedCallback)(void*, const char*);

void QStatusBar_setMessageChangedCallback(void* statusBar, QStatusBar_MessageChangedCallback callback) {
    static_cast<QStatusBarBind*>(statusBar)->setMessageChangedCallback(callback);
}

}
