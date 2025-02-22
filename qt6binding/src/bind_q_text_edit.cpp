#include "bind_q_text_edit.h"

BindQTextEdit::BindQTextEdit(QWidget *parent)
    : QTextEdit(parent)
    , m_handler(nullptr)
{
}

BindQTextEdit::~BindQTextEdit()
{
    delete m_handler;
}

void BindQTextEdit::setTextEditHandler(TextEditHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QTextEdit::textChanged,
                  m_handler, &TextEditHandler::onTextChanged);
        disconnect(this, &QTextEdit::copyAvailable,
                  m_handler, &TextEditHandler::onCopyAvailable);
        disconnect(this, &QTextEdit::undoAvailable,
                  m_handler, &TextEditHandler::onUndoAvailable);
        disconnect(this, &QTextEdit::redoAvailable,
                  m_handler, &TextEditHandler::onRedoAvailable);
        disconnect(this, &QTextEdit::selectionChanged,
                  m_handler, &TextEditHandler::onSelectionChanged);
        disconnect(this, &QTextEdit::cursorPositionChanged,
                  m_handler, &TextEditHandler::onCursorPositionChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QTextEdit::textChanged,
                m_handler, &TextEditHandler::onTextChanged);
        connect(this, &QTextEdit::copyAvailable,
                m_handler, &TextEditHandler::onCopyAvailable);
        connect(this, &QTextEdit::undoAvailable,
                m_handler, &TextEditHandler::onUndoAvailable);
        connect(this, &QTextEdit::redoAvailable,
                m_handler, &TextEditHandler::onRedoAvailable);
        connect(this, &QTextEdit::selectionChanged,
                m_handler, &TextEditHandler::onSelectionChanged);
        connect(this, &QTextEdit::cursorPositionChanged,
                m_handler, &TextEditHandler::onCursorPositionChanged);
    }
}

TextEditHandler *BindQTextEdit::handler() const
{
    return m_handler;
}
