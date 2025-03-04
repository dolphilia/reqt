#include "QMenuBarHandler.h"

QMenuBarHandler::QMenuBarHandler(QObject* parent)
    : QObject(parent)
    , triggeredCallback(nullptr)
    , hoveredCallback(nullptr) {
}

void QMenuBarHandler::setTriggeredCallback(QMenuBar_TriggeredCallback callback) {
    triggeredCallback = callback;
}

void QMenuBarHandler::setHoveredCallback(QMenuBar_HoveredCallback callback) {
    hoveredCallback = callback;
}

void QMenuBarHandler::onTriggered(QAction* action) const {
    if (triggeredCallback) {
        triggeredCallback(parent(), action);
    }
}

void QMenuBarHandler::onHovered(QAction* action) const {
    if (hoveredCallback) {
        hoveredCallback(parent(), action);
    }
}
