#include "QToolBoxBind.h"
#include "QToolBoxHandler.h"

QToolBoxBind::QToolBoxBind(QWidget* parent)
    : QToolBox(parent)
    , handler(new QToolBoxHandler(this)) {
    connect(this, &QToolBox::currentChanged, handler, &QToolBoxHandler::onCurrentChanged);
}

QToolBoxBind::~QToolBoxBind() {
    delete handler;
}

void QToolBoxBind::setCurrentChangedCallback(QToolBox_CurrentChangedCallback callback) const {
    handler->setCurrentChangedCallback(callback);
}
