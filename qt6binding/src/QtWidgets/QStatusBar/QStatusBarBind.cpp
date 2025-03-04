#include "QStatusBarBind.h"
#include "QStatusBarHandler.h"

QStatusBarBind::QStatusBarBind(QWidget* parent)
    : QStatusBar(parent)
    , handler(new QStatusBarHandler(this)) {
    connect(this, &QStatusBar::messageChanged, handler, &QStatusBarHandler::onMessageChanged);
}

QStatusBarBind::~QStatusBarBind() {
    delete handler;
}

void QStatusBarBind::setMessageChangedCallback(QStatusBar_MessageChangedCallback callback) const {
    handler->setMessageChangedCallback(callback);
}
