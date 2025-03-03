#include "QLabelHandler.h"

QLabelHandler::QLabelHandler(QObject* parent)
    : QObject(parent)
    , linkActivatedCallback(nullptr)
    , linkHoveredCallback(nullptr) {
}

void QLabelHandler::setLinkActivatedCallback(LinkActivatedCallback callback) {
    linkActivatedCallback = callback;
}

void QLabelHandler::setLinkHoveredCallback(LinkHoveredCallback callback) {
    linkHoveredCallback = callback;
}

void QLabelHandler::onLinkActivated(const QString& link) const {
    if (linkActivatedCallback) {
        linkActivatedCallback(parent(), link.toUtf8().constData());
    }
}

void QLabelHandler::onLinkHovered(const QString& link) const {
    if (linkHoveredCallback) {
        linkHoveredCallback(parent(), link.toUtf8().constData());
    }
}
