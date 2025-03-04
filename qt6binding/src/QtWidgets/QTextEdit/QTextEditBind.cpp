#include "QTextEditBind.h"
#include "QTextEditHandler.h"

QTextEditBind::QTextEditBind(QWidget* parent)
    : QTextEdit(parent)
    , handler(new QTextEditHandler(this)) {
    connect(this, &QTextEdit::textChanged, handler, &QTextEditHandler::onTextChanged);
    connect(this, &QTextEdit::copyAvailable, handler, &QTextEditHandler::onCopyAvailable);
    connect(this, &QTextEdit::undoAvailable, handler, &QTextEditHandler::onUndoAvailable);
    connect(this, &QTextEdit::redoAvailable, handler, &QTextEditHandler::onRedoAvailable);
    connect(this, &QTextEdit::selectionChanged, handler, &QTextEditHandler::onSelectionChanged);
    connect(this, &QTextEdit::cursorPositionChanged, handler, &QTextEditHandler::onCursorPositionChanged);
}

QTextEditBind::~QTextEditBind() {
    delete handler;
}

void QTextEditBind::setTextChangedCallback(QTextEdit_TextChangedCallback callback) const {
    handler->setTextChangedCallback(callback);
}

void QTextEditBind::setCopyAvailableCallback(QTextEdit_CopyAvailableCallback callback) const {
    handler->setCopyAvailableCallback(callback);
}

void QTextEditBind::setUndoAvailableCallback(QTextEdit_UndoAvailableCallback callback) const {
    handler->setUndoAvailableCallback(callback);
}

void QTextEditBind::setRedoAvailableCallback(QTextEdit_RedoAvailableCallback callback) const {
    handler->setRedoAvailableCallback(callback);
}

void QTextEditBind::setSelectionChangedCallback(QTextEdit_SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}

void QTextEditBind::setCursorPositionChangedCallback(QTextEdit_CursorPositionChangedCallback callback) const {
    handler->setCursorPositionChangedCallback(callback);
}
