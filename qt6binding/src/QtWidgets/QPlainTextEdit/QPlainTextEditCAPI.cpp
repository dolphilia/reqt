#include "QPlainTextEditBind.h"

extern "C" {

void* QPlainTextEdit_create(void* parent) {
    return new QPlainTextEditBind(static_cast<QWidget*>(parent));
}

void QPlainTextEdit_delete(void* plainTextEdit) {
    delete static_cast<QPlainTextEditBind*>(plainTextEdit);
}

void QPlainTextEdit_setPlainText(void* plainTextEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setPlainText(qstr);
}

const char* QPlainTextEdit_toPlainText(void* plainTextEdit) {
    const QString qstr = static_cast<QPlainTextEditBind*>(plainTextEdit)->toPlainText();
    return qstrdup(qstr.toUtf8().constData());
}

void QPlainTextEdit_appendPlainText(void* plainTextEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QPlainTextEditBind*>(plainTextEdit)->appendPlainText(qstr);
}

void QPlainTextEdit_cut(void* plainTextEdit) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->cut();
}

void QPlainTextEdit_copy(void* plainTextEdit) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->copy();
}

void QPlainTextEdit_paste(void* plainTextEdit) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->paste();
}

void QPlainTextEdit_undo(void* plainTextEdit) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->undo();
}

void QPlainTextEdit_redo(void* plainTextEdit) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->redo();
}

typedef void (*QPlainTextEdit_TextChangedCallback)(void*);
typedef void (*QPlainTextEdit_CursorPositionChangedCallback)(void*);
typedef void (*QPlainTextEdit_CopyAvailableCallback)(void*, bool);
typedef void (*QPlainTextEdit_UndoAvailableCallback)(void*, bool);
typedef void (*QPlainTextEdit_RedoAvailableCallback)(void*, bool);
typedef void (*QPlainTextEdit_SelectionChangedCallback)(void*);

void QPlainTextEdit_setTextChangedCallback(void* plainTextEdit, QPlainTextEdit_TextChangedCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setTextChangedCallback(callback);
}

void QPlainTextEdit_setCursorPositionChangedCallback(void* plainTextEdit, QPlainTextEdit_CursorPositionChangedCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setCursorPositionChangedCallback(callback);
}

void QPlainTextEdit_setCopyAvailableCallback(void* plainTextEdit, QPlainTextEdit_CopyAvailableCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setCopyAvailableCallback(callback);
}

void QPlainTextEdit_setUndoAvailableCallback(void* plainTextEdit, QPlainTextEdit_UndoAvailableCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setUndoAvailableCallback(callback);
}

void QPlainTextEdit_setRedoAvailableCallback(void* plainTextEdit, QPlainTextEdit_RedoAvailableCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setRedoAvailableCallback(callback);
}

void QPlainTextEdit_setSelectionChangedCallback(void* plainTextEdit, QPlainTextEdit_SelectionChangedCallback callback) {
    static_cast<QPlainTextEditBind*>(plainTextEdit)->setSelectionChangedCallback(callback);
}

}
