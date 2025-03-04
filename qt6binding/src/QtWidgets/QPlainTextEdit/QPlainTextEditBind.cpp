#include "QPlainTextEditBind.h"
#include "QPlainTextEditHandler.h"

QPlainTextEditBind::QPlainTextEditBind(QWidget* parent)
    : QPlainTextEdit(parent)
    , handler(new QPlainTextEditHandler(this)) {
    connect(this, &QPlainTextEdit::textChanged, handler, &QPlainTextEditHandler::onTextChanged);
    connect(this, &QPlainTextEdit::cursorPositionChanged, handler, &QPlainTextEditHandler::onCursorPositionChanged);
    connect(this, &QPlainTextEdit::copyAvailable, handler, &QPlainTextEditHandler::onCopyAvailable);
    connect(this, &QPlainTextEdit::undoAvailable, handler, &QPlainTextEditHandler::onUndoAvailable);
    connect(this, &QPlainTextEdit::redoAvailable, handler, &QPlainTextEditHandler::onRedoAvailable);
    connect(this, &QPlainTextEdit::selectionChanged, handler, &QPlainTextEditHandler::onSelectionChanged);
}

QPlainTextEditBind::~QPlainTextEditBind() {
    delete handler;
}

void QPlainTextEditBind::setTextChangedCallback(QPlainTextEdit_TextChangedCallback callback) const {
    handler->setTextChangedCallback(callback);
}

void QPlainTextEditBind::setCursorPositionChangedCallback(QPlainTextEdit_CursorPositionChangedCallback callback) const {
    handler->setCursorPositionChangedCallback(callback);
}

void QPlainTextEditBind::setCopyAvailableCallback(QPlainTextEdit_CopyAvailableCallback callback) const {
    handler->setCopyAvailableCallback(callback);
}

void QPlainTextEditBind::setUndoAvailableCallback(QPlainTextEdit_UndoAvailableCallback callback) const {
    handler->setUndoAvailableCallback(callback);
}

void QPlainTextEditBind::setRedoAvailableCallback(QPlainTextEdit_RedoAvailableCallback callback) const {
    handler->setRedoAvailableCallback(callback);
}

void QPlainTextEditBind::setSelectionChangedCallback(QPlainTextEdit_SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}
