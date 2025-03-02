#include "QPlainTextEditBind.h"

BindQPlainTextEdit::BindQPlainTextEdit(QWidget* parent)
    : QPlainTextEdit(parent), m_handler(nullptr) {
}

BindQPlainTextEdit::~BindQPlainTextEdit() {
    if (m_handler) {
        delete m_handler;
    }
}

void BindQPlainTextEdit::setPlainTextEditHandler(QPlainTextEditHandler* handler) {
    if (m_handler) {
        delete m_handler;
    }
    m_handler = handler;

    if (m_handler) {
        connect(this, &QPlainTextEdit::textChanged,
                m_handler, &QPlainTextEditHandler::onTextChanged);
        connect(this, &QPlainTextEdit::cursorPositionChanged,
                m_handler, &QPlainTextEditHandler::onCursorPositionChanged);
        connect(this, &QPlainTextEdit::copyAvailable,
                m_handler, &QPlainTextEditHandler::onCopyAvailable);
        connect(this, &QPlainTextEdit::undoAvailable,
                m_handler, &QPlainTextEditHandler::onUndoAvailable);
        connect(this, &QPlainTextEdit::redoAvailable,
                m_handler, &QPlainTextEditHandler::onRedoAvailable);
        connect(this, &QPlainTextEdit::selectionChanged,
                m_handler, &QPlainTextEditHandler::onSelectionChanged);
    }
}

QPlainTextEditHandler* BindQPlainTextEdit::handler() const {
    return m_handler;
}
