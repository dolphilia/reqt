#include "QToolBoxHandler.h"

QToolBoxHandler::QToolBoxHandler(QObject* parent)
    : QObject(parent)
    , currentChangedCallback(nullptr) {
}

QToolBoxHandler::~QToolBoxHandler() {
}

void QToolBoxHandler::setCurrentChangedCallback(QToolBox_CurrentChangedCallback callback) {
    currentChangedCallback = callback;
}

void QToolBoxHandler::onCurrentChanged(int index) const {
    if (currentChangedCallback) {
        currentChangedCallback(parent(), index);
    }
}
