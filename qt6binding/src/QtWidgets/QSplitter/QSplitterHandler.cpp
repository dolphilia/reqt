#include "QSplitterHandler.h"

QSplitterHandler::QSplitterHandler(QObject* parent)
    : QObject(parent)
    , splitter(nullptr)
    , splitterMovedCallback(nullptr)
{
}

void QSplitterHandler::setSplitter(QSplitter* splitter) {
    this->splitter = splitter;
    if (splitter) {
        connect(splitter, &QSplitter::splitterMoved, this, &QSplitterHandler::onSplitterMoved);
    }
}

void QSplitterHandler::setSplitterMovedCallback(SplitterMovedCallback callback) {
    splitterMovedCallback = callback;
}

void QSplitterHandler::onSplitterMoved(int pos, int index) {
    if (splitterMovedCallback && splitter) {
        splitterMovedCallback(splitter, pos, index);
    }
}
