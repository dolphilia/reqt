#include "QScrollAreaHandler.h"

QScrollAreaHandler::QScrollAreaHandler(QObject* parent)
    : QObject(parent)
    , verticalCallback(nullptr)
    , horizontalCallback(nullptr) {
}

void QScrollAreaHandler::setVerticalScrollCallback(QScrollArea_VerticalScrollBarValueChangedCallback callback) {
    verticalCallback = callback;
}

void QScrollAreaHandler::setHorizontalScrollCallback(QScrollArea_HorizontalScrollBarValueChangedCallback callback) {
    horizontalCallback = callback;
}

void QScrollAreaHandler::onVerticalScrollBarValueChanged(int value) const {
    if (verticalCallback) {
        verticalCallback(parent(), value);
    }
}

void QScrollAreaHandler::onHorizontalScrollBarValueChanged(int value) const {
    if (horizontalCallback) {
        horizontalCallback(parent(), value);
    }
}
