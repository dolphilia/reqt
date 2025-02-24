#include "QSplitterBind.h"

QSplitterBind::QSplitterBind(Qt::Orientation orientation, QWidget* parent)
    : QSplitter(orientation, parent)
    , handler(new QSplitterHandler(this))
{
    handler->setSplitter(this);
}

QSplitterBind::QSplitterBind(QWidget* parent)
    : QSplitter(parent)
    , handler(new QSplitterHandler(this))
{
    handler->setSplitter(this);
}

QSplitterBind::~QSplitterBind() {
    delete handler;
}

void QSplitterBind::setSplitterMovedCallback(void (*callback)(void*, int, int)) {
    handler->setSplitterMovedCallback(callback);
}
