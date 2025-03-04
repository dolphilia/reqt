#include "QMdiAreaHandler.h"

QMdiAreaHandler::QMdiAreaHandler(QObject* parent)
    : QObject(parent)
    , callback(nullptr) {
}

void QMdiAreaHandler::setSubWindowActivatedCallback(QMdiArea_SubWindowActivatedCallback callback) {
    this->callback = callback;
}

void QMdiAreaHandler::onSubWindowActivated(QMdiSubWindow* window) const {
    if (callback) {
        callback(parent(), window);
    }
}
