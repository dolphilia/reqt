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
