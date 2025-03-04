#include "QTextEditHandler.h"

QTextEditHandler::QTextEditHandler(QObject* parent)
    : QObject(parent)
    , textChangedCallback(nullptr)
    , copyAvailableCallback(nullptr)
    , undoAvailableCallback(nullptr)
    , redoAvailableCallback(nullptr)
    , selectionChangedCallback(nullptr)
    , cursorPositionChangedCallback(nullptr) {
}

void QTextEditHandler::setTextChangedCallback(QTextEdit_TextChangedCallback callback) {
    textChangedCallback = callback;
}

void QTextEditHandler::setCopyAvailableCallback(QTextEdit_CopyAvailableCallback callback) {
    copyAvailableCallback = callback;
}

void QTextEditHandler::setUndoAvailableCallback(QTextEdit_UndoAvailableCallback callback) {
    undoAvailableCallback = callback;
}

void QTextEditHandler::setRedoAvailableCallback(QTextEdit_RedoAvailableCallback callback) {
    redoAvailableCallback = callback;
}

void QTextEditHandler::setSelectionChangedCallback(QTextEdit_SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void QTextEditHandler::setCursorPositionChangedCallback(QTextEdit_CursorPositionChangedCallback callback) {
    cursorPositionChangedCallback = callback;
}

void QTextEditHandler::onTextChanged() const {
    if (textChangedCallback) {
        textChangedCallback(parent());
    }
}

void QTextEditHandler::onCopyAvailable(bool available) const {
    if (copyAvailableCallback) {
        copyAvailableCallback(parent(), available);
    }
}

void QTextEditHandler::onUndoAvailable(bool available) const {
    if (undoAvailableCallback) {
        undoAvailableCallback(parent(), available);
    }
}

void QTextEditHandler::onRedoAvailable(bool available) const {
    if (redoAvailableCallback) {
        redoAvailableCallback(parent(), available);
    }
}

void QTextEditHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}

void QTextEditHandler::onCursorPositionChanged() const {
    if (cursorPositionChangedCallback) {
        cursorPositionChangedCallback(parent());
    }
}
