#include "QLabelBind.h"
#include "QLabelHandler.h"

QLabelBind::QLabelBind(QWidget* parent)
    : QLabel(parent)
    , handler(new QLabelHandler(this)) {
    connect(this, &QLabel::linkActivated, handler, &QLabelHandler::onLinkActivated);
    connect(this, &QLabel::linkHovered, handler, &QLabelHandler::onLinkHovered);
}

QLabelBind::QLabelBind(const QString& text, QWidget* parent)
    : QLabel(text, parent)
    , handler(new QLabelHandler(this)) {
    connect(this, &QLabel::linkActivated, handler, &QLabelHandler::onLinkActivated);
    connect(this, &QLabel::linkHovered, handler, &QLabelHandler::onLinkHovered);
}

QLabelBind::~QLabelBind() {
    delete handler;
}

void QLabelBind::setLinkActivatedCallback(QLabel_LinkActivatedCallback callback) const {
    handler->setLinkActivatedCallback(callback);
}

void QLabelBind::setLinkHoveredCallback(QLabel_LinkHoveredCallback callback) const {
    handler->setLinkHoveredCallback(callback);
}
