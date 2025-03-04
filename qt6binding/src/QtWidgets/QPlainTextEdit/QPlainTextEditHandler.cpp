#include "QPlainTextEditHandler.h"

QPlainTextEditHandler::QPlainTextEditHandler(QObject* parent)
    : QObject(parent)
    , textChangedCallback(nullptr)
    , cursorPositionChangedCallback(nullptr)
    , copyAvailableCallback(nullptr)
    , undoAvailableCallback(nullptr)
    , redoAvailableCallback(nullptr)
    , selectionChangedCallback(nullptr) {
}

void QPlainTextEditHandler::setTextChangedCallback(QPlainTextEdit_TextChangedCallback callback) {
    textChangedCallback = callback;
}

void QPlainTextEditHandler::setCursorPositionChangedCallback(QPlainTextEdit_CursorPositionChangedCallback callback) {
    cursorPositionChangedCallback = callback;
}

void QPlainTextEditHandler::setCopyAvailableCallback(QPlainTextEdit_CopyAvailableCallback callback) {
    copyAvailableCallback = callback;
}

void QPlainTextEditHandler::setUndoAvailableCallback(QPlainTextEdit_UndoAvailableCallback callback) {
    undoAvailableCallback = callback;
}

void QPlainTextEditHandler::setRedoAvailableCallback(QPlainTextEdit_RedoAvailableCallback callback) {
    redoAvailableCallback = callback;
}

void QPlainTextEditHandler::setSelectionChangedCallback(QPlainTextEdit_SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void QPlainTextEditHandler::onTextChanged() const {
    if (textChangedCallback) {
        textChangedCallback(parent());
    }
}

void QPlainTextEditHandler::onCursorPositionChanged() const {
    if (cursorPositionChangedCallback) {
        cursorPositionChangedCallback(parent());
    }
}

void QPlainTextEditHandler::onCopyAvailable(bool available) const {
    if (copyAvailableCallback) {
        copyAvailableCallback(parent(), available);
    }
}

void QPlainTextEditHandler::onUndoAvailable(bool available) const {
    if (undoAvailableCallback) {
        undoAvailableCallback(parent(), available);
    }
}

void QPlainTextEditHandler::onRedoAvailable(bool available) const {
    if (redoAvailableCallback) {
        redoAvailableCallback(parent(), available);
    }
}

void QPlainTextEditHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}
