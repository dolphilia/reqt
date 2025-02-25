#include "QSplitterHandleBind.h"

QSplitterHandleBind::QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent)
    : QSplitterHandle(orientation, parent)
    , handler(new QSplitterHandleHandler(this))
{
    handler->setSplitterHandle(this);
}

QSplitterHandleBind::~QSplitterHandleBind() {
    delete handler;
}

void QSplitterHandleBind::setDoubleClickedCallback(void (*callback)(void*)) {
    handler->setDoubleClickedCallback(callback);
}

void QSplitterHandleBind::setMovedCallback(void (*callback)(void*, int)) {
    handler->setMovedCallback(callback);
}
