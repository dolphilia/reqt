#include "QSplitterHandler.h"

QSplitterHandler::QSplitterHandler(QObject* parent)
    : QObject(parent)
    , splitterMovedCallback(nullptr) {
}

void QSplitterHandler::setSplitterMovedCallback(QSplitter_SplitterMovedCallback callback) {
    splitterMovedCallback = callback;
}

void QSplitterHandler::onSplitterMoved(int pos, int index) const {
    if (splitterMovedCallback) {
        splitterMovedCallback(parent(), pos, index);
    }
}
