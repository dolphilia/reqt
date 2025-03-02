#include "QMdiAreaBind.h"
#include "qmdiarea.h"

QMdiAreaBind::QMdiAreaBind(QWidget* parent)
    : QMdiArea(parent)
    , handler(new MdiAreaHandler(this))
{
    connect(this, &QMdiArea::subWindowActivated, handler, &MdiAreaHandler::onSubWindowActivated);
    handler->setMdiArea(this);
}

QMdiAreaBind::~QMdiAreaBind() {
    delete handler;
}

void QMdiAreaBind::setSubWindowActivatedCallback(void (*callback)(void*, void*)) {
    handler->setSubWindowActivatedCallback(callback);
}
