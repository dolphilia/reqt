#include "qplaintextedit.h"
#include "QPlainTextEditBind.h"
#include "QPlainTextEditHandler.h"
#include <QString>

extern "C" {

void* QPlainTextEdit_create(void* parent) {
    return new BindQPlainTextEdit(reinterpret_cast<QWidget*>(parent));
}

void QPlainTextEdit_delete(void* ptr) {
    delete static_cast<BindQPlainTextEdit*>(ptr);
}

void QPlainTextEdit_setPlainText(void* text_edit, const char* text) {
    static_cast<BindQPlainTextEdit*>(text_edit)->setPlainText(QString::fromUtf8(text));
}

const char* QPlainTextEdit_toPlainText(void* text_edit) {
    QString text = static_cast<BindQPlainTextEdit*>(text_edit)->toPlainText();
    return qstrdup(text.toUtf8().constData());
}

void QPlainTextEdit_appendPlainText(void* text_edit, const char* text) {
    static_cast<BindQPlainTextEdit*>(text_edit)->appendPlainText(QString::fromUtf8(text));
}

void QPlainTextEdit_cut(void* text_edit) {
    static_cast<BindQPlainTextEdit*>(text_edit)->cut();
}

void QPlainTextEdit_copy(void* text_edit) {
    static_cast<BindQPlainTextEdit*>(text_edit)->copy();
}

void QPlainTextEdit_paste(void* text_edit) {
    static_cast<BindQPlainTextEdit*>(text_edit)->paste();
}

void QPlainTextEdit_undo(void* text_edit) {
    static_cast<BindQPlainTextEdit*>(text_edit)->undo();
}

void QPlainTextEdit_redo(void* text_edit) {
    static_cast<BindQPlainTextEdit*>(text_edit)->redo();
}

void QPlainTextEdit_setTextChangedCallback(void* text_edit, void (*callback)()) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setTextChangedCallback(callback);
}

void QPlainTextEdit_setCursorPositionChangedCallback(void* text_edit, void (*callback)()) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setCursorPositionChangedCallback(callback);
}

void QPlainTextEdit_setCopyAvailableCallback(void* text_edit, void (*callback)(bool)) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setCopyAvailableCallback(callback);
}

void QPlainTextEdit_setUndoAvailableCallback(void* text_edit, void (*callback)(bool)) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setUndoAvailableCallback(callback);
}

void QPlainTextEdit_setRedoAvailableCallback(void* text_edit, void (*callback)(bool)) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setRedoAvailableCallback(callback);
}

void QPlainTextEdit_setSelectionChangedCallback(void* text_edit, void (*callback)()) {
    auto* edit = static_cast<BindQPlainTextEdit*>(text_edit);
    QPlainTextEditHandler* handler = edit->handler();
    if (!handler) {
        handler = new QPlainTextEditHandler(edit);
        edit->setPlainTextEditHandler(handler);
    }
    handler->setSelectionChangedCallback(callback);
}

}
