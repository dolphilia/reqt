#include "QStatusBarBind.h"
#include <QString>

QStatusBar* QStatusBarBind::create(QWidget* parent) {
    return new QStatusBar(parent);
}

void QStatusBarBind::destroy(QStatusBar* statusBar) {
    if (statusBar) {
        delete statusBar;
    }
}

void QStatusBarBind::showMessage(QStatusBar* statusBar, const char* message) {
    if (statusBar && message) {
        statusBar->showMessage(QString::fromUtf8(message));
    }
}

void QStatusBarBind::clearMessage(QStatusBar* statusBar) {
    if (statusBar) {
        statusBar->clearMessage();
    }
}

void QStatusBarBind::setEnabled(QStatusBar* statusBar, bool enabled) {
    if (statusBar) {
        statusBar->setEnabled(enabled);
    }
}

bool QStatusBarBind::isEnabled(QStatusBar* statusBar) {
    return statusBar ? statusBar->isEnabled() : false;
}

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
