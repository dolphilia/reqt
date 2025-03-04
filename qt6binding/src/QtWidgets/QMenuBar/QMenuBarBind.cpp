#include "QMenuBarBind.h"
#include "QMenuBarHandler.h"

QMenuBarBind::QMenuBarBind(QWidget* parent)
    : QMenuBar(parent)
    , handler(new QMenuBarHandler(this)) {
    connect(this, &QMenuBar::triggered, handler, &QMenuBarHandler::onTriggered);
    connect(this, &QMenuBar::hovered, handler, &QMenuBarHandler::onHovered);
}

QMenuBarBind::~QMenuBarBind() {
    delete handler;
}

void QMenuBarBind::setTriggeredCallback(QMenuBar_TriggeredCallback callback) const {
    handler->setTriggeredCallback(callback);
}

void QMenuBarBind::setHoveredCallback(QMenuBar_HoveredCallback callback) const {
    handler->setHoveredCallback(callback);
}
