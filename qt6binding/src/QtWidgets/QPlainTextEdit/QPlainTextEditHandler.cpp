#include "QPlainTextEditHandler.h"

QPlainTextEditHandler::QPlainTextEditHandler(QObject* parent)
    : QObject(parent),
      m_textChangedCallback(nullptr),
      m_cursorPositionChangedCallback(nullptr),
      m_copyAvailableCallback(nullptr),
      m_undoAvailableCallback(nullptr),
      m_redoAvailableCallback(nullptr),
      m_selectionChangedCallback(nullptr) {
}

QPlainTextEditHandler::~QPlainTextEditHandler() {
}

void QPlainTextEditHandler::setTextChangedCallback(void (*callback)()) {
    m_textChangedCallback = callback;
}

void QPlainTextEditHandler::setCursorPositionChangedCallback(void (*callback)()) {
    m_cursorPositionChangedCallback = callback;
}

void QPlainTextEditHandler::setCopyAvailableCallback(void (*callback)(bool)) {
    m_copyAvailableCallback = callback;
}

void QPlainTextEditHandler::setUndoAvailableCallback(void (*callback)(bool)) {
    m_undoAvailableCallback = callback;
}

void QPlainTextEditHandler::setRedoAvailableCallback(void (*callback)(bool)) {
    m_redoAvailableCallback = callback;
}

void QPlainTextEditHandler::setSelectionChangedCallback(void (*callback)()) {
    m_selectionChangedCallback = callback;
}

void QPlainTextEditHandler::onTextChanged() {
    if (m_textChangedCallback) {
        m_textChangedCallback();
    }
}

void QPlainTextEditHandler::onCursorPositionChanged() {
    if (m_cursorPositionChangedCallback) {
        m_cursorPositionChangedCallback();
    }
}

void QPlainTextEditHandler::onCopyAvailable(bool available) {
    if (m_copyAvailableCallback) {
        m_copyAvailableCallback(available);
    }
}

void QPlainTextEditHandler::onUndoAvailable(bool available) {
    if (m_undoAvailableCallback) {
        m_undoAvailableCallback(available);
    }
}

void QPlainTextEditHandler::onRedoAvailable(bool available) {
    if (m_redoAvailableCallback) {
        m_redoAvailableCallback(available);
    }
}

void QPlainTextEditHandler::onSelectionChanged() {
    if (m_selectionChangedCallback) {
        m_selectionChangedCallback();
    }
}
