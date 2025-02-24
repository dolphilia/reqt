#include "QTextEditHandler.h"

TextEditHandler::TextEditHandler(QObject *parent)
    : QObject(parent)
    , m_textChangedCallback(nullptr)
    , m_copyAvailableCallback(nullptr)
    , m_undoAvailableCallback(nullptr)
    , m_redoAvailableCallback(nullptr)
    , m_selectionChangedCallback(nullptr)
    , m_cursorPositionChangedCallback(nullptr)
{
}

TextEditHandler::~TextEditHandler()
{
}

void TextEditHandler::setTextChangedCallback(void (*callback)())
{
    m_textChangedCallback = callback;
}

void TextEditHandler::setCopyAvailableCallback(void (*callback)(bool))
{
    m_copyAvailableCallback = callback;
}

void TextEditHandler::setUndoAvailableCallback(void (*callback)(bool))
{
    m_undoAvailableCallback = callback;
}

void TextEditHandler::setRedoAvailableCallback(void (*callback)(bool))
{
    m_redoAvailableCallback = callback;
}

void TextEditHandler::setSelectionChangedCallback(void (*callback)())
{
    m_selectionChangedCallback = callback;
}

void TextEditHandler::setCursorPositionChangedCallback(void (*callback)())
{
    m_cursorPositionChangedCallback = callback;
}

void TextEditHandler::onTextChanged()
{
    if (m_textChangedCallback) {
        m_textChangedCallback();
    }
}

void TextEditHandler::onCopyAvailable(bool available)
{
    if (m_copyAvailableCallback) {
        m_copyAvailableCallback(available);
    }
}

void TextEditHandler::onUndoAvailable(bool available)
{
    if (m_undoAvailableCallback) {
        m_undoAvailableCallback(available);
    }
}

void TextEditHandler::onRedoAvailable(bool available)
{
    if (m_redoAvailableCallback) {
        m_redoAvailableCallback(available);
    }
}

void TextEditHandler::onSelectionChanged()
{
    if (m_selectionChangedCallback) {
        m_selectionChangedCallback();
    }
}

void TextEditHandler::onCursorPositionChanged()
{
    if (m_cursorPositionChangedCallback) {
        m_cursorPositionChangedCallback();
    }
}
