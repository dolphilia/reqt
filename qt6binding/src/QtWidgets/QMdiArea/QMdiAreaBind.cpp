#include "QMdiAreaBind.h"
#include "QMdiAreaHandler.h"

QMdiAreaBind::QMdiAreaBind(QWidget* parent)
    : QMdiArea(parent)
    , handler(new QMdiAreaHandler(this)) {
    connect(this, &QMdiArea::subWindowActivated, handler, &QMdiAreaHandler::onSubWindowActivated);
}

QMdiAreaBind::~QMdiAreaBind() {
    delete handler;
}

void QMdiAreaBind::setSubWindowActivatedCallback(QMdiArea_SubWindowActivatedCallback callback) const {
    handler->setSubWindowActivatedCallback(callback);
}
