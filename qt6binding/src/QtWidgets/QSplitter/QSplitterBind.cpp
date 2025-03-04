#include "QSplitterBind.h"
#include "QSplitterHandler.h"

QSplitterBind::QSplitterBind(Qt::Orientation orientation, QWidget* parent)
    : QSplitter(orientation, parent)
    , handler(new QSplitterHandler(this)) {
    connect(this, &QSplitter::splitterMoved, handler, &QSplitterHandler::onSplitterMoved);
}

QSplitterBind::QSplitterBind(QWidget* parent)
    : QSplitter(parent)
    , handler(new QSplitterHandler(this)) {
    connect(this, &QSplitter::splitterMoved, handler, &QSplitterHandler::onSplitterMoved);
}

QSplitterBind::~QSplitterBind() {
    delete handler;
}

void QSplitterBind::setSplitterMovedCallback(QSplitter_SplitterMovedCallback callback) const {
    handler->setSplitterMovedCallback(callback);
}
