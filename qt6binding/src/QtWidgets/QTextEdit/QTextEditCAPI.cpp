#include "QTextEditBind.h"

extern "C" {

typedef void (*QTextEdit_TextChangedCallback)(void*);
typedef void (*QTextEdit_CopyAvailableCallback)(void*, bool);
typedef void (*QTextEdit_UndoAvailableCallback)(void*, bool);
typedef void (*QTextEdit_RedoAvailableCallback)(void*, bool);
typedef void (*QTextEdit_SelectionChangedCallback)(void*);
typedef void (*QTextEdit_CursorPositionChangedCallback)(void*);

void* QTextEdit_create(void* parent) {
    return new QTextEditBind(static_cast<QWidget*>(parent));
}

void QTextEdit_delete(void* textEdit) {
    delete static_cast<QTextEditBind*>(textEdit);
}

void QTextEdit_setText(void* textEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTextEditBind*>(textEdit)->setText(qstr);
}

const char* QTextEdit_text(void* textEdit) {
    const QString qstr = static_cast<QTextEditBind*>(textEdit)->toPlainText();
    return qstr.toUtf8().constData();
}

void QTextEdit_setPlainText(void* textEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTextEditBind*>(textEdit)->setPlainText(qstr);
}

const char* QTextEdit_toPlainText(void* textEdit) {
    const QString qstr = static_cast<QTextEditBind*>(textEdit)->toPlainText();
    return qstr.toUtf8().constData();
}

void QTextEdit_setHtml(void* textEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTextEditBind*>(textEdit)->setHtml(qstr);
}

const char* QTextEdit_toHtml(void* textEdit) {
    const QString qstr = static_cast<QTextEditBind*>(textEdit)->toHtml();
    return qstr.toUtf8().constData();
}

void QTextEdit_append(void* textEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTextEditBind*>(textEdit)->append(qstr);
}

void QTextEdit_clear(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->clear();
}

void QTextEdit_selectAll(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->selectAll();
}

void QTextEdit_copy(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->copy();
}

void QTextEdit_cut(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->cut();
}

void QTextEdit_paste(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->paste();
}

void QTextEdit_undo(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->undo();
}

void QTextEdit_redo(void* textEdit) {
    static_cast<QTextEditBind*>(textEdit)->redo();
}

void QTextEdit_setReadOnly(void* textEdit, bool readOnly) {
    static_cast<QTextEditBind*>(textEdit)->setReadOnly(readOnly);
}

bool QTextEdit_isReadOnly(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->isReadOnly();
}

void QTextEdit_setPlaceholderText(void* textEdit, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QTextEditBind*>(textEdit)->setPlaceholderText(qstr);
}

const char* QTextEdit_placeholderText(void* textEdit) {
    const QString qstr = static_cast<QTextEditBind*>(textEdit)->placeholderText();
    return qstr.toUtf8().constData();
}

void QTextEdit_setOverwriteMode(void* textEdit, bool overwrite) {
    static_cast<QTextEditBind*>(textEdit)->setOverwriteMode(overwrite);
}

bool QTextEdit_overwriteMode(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->overwriteMode();
}

void QTextEdit_setTabChangesFocus(void* textEdit, bool changes) {
    static_cast<QTextEditBind*>(textEdit)->setTabChangesFocus(changes);
}

bool QTextEdit_tabChangesFocus(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->tabChangesFocus();
}

void QTextEdit_setAcceptRichText(void* textEdit, bool accept) {
    static_cast<QTextEditBind*>(textEdit)->setAcceptRichText(accept);
}

bool QTextEdit_acceptRichText(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->acceptRichText();
}

void QTextEdit_setTextCursor(void* textEdit, int position) {
    QTextCursor cursor = static_cast<QTextEditBind*>(textEdit)->textCursor();
    cursor.setPosition(position);
    static_cast<QTextEditBind*>(textEdit)->setTextCursor(cursor);
}

int QTextEdit_textCursor(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->textCursor().position();
}

void QTextEdit_setCursorWidth(void* textEdit, int width) {
    static_cast<QTextEditBind*>(textEdit)->setCursorWidth(width);
}

int QTextEdit_cursorWidth(void* textEdit) {
    return static_cast<QTextEditBind*>(textEdit)->cursorWidth();
}

bool QTextEdit_find(void* textEdit, const char* text, int options) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QTextEditBind*>(textEdit)->find(qstr, static_cast<QTextDocument::FindFlags>(options));
}

void QTextEdit_setWordWrapMode(void* textEdit, int mode) {
    static_cast<QTextEditBind*>(textEdit)->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
}

int QTextEdit_wordWrapMode(void* textEdit) {
    return static_cast<int>(static_cast<QTextEditBind*>(textEdit)->wordWrapMode());
}

void QTextEdit_setLineWrapMode(void* textEdit, int mode) {
    static_cast<QTextEditBind*>(textEdit)->setLineWrapMode(static_cast<QTextEdit::LineWrapMode>(mode));
}

int QTextEdit_lineWrapMode(void* textEdit) {
    return static_cast<int>(static_cast<QTextEditBind*>(textEdit)->lineWrapMode());
}

void QTextEdit_setTextChangedCallback(void* textEdit, QTextEdit_TextChangedCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setTextChangedCallback(callback);
}

void QTextEdit_setCopyAvailableCallback(void* textEdit, QTextEdit_CopyAvailableCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setCopyAvailableCallback(callback);
}

void QTextEdit_setUndoAvailableCallback(void* textEdit, QTextEdit_UndoAvailableCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setUndoAvailableCallback(callback);
}

void QTextEdit_setRedoAvailableCallback(void* textEdit, QTextEdit_RedoAvailableCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setRedoAvailableCallback(callback);
}

void QTextEdit_setSelectionChangedCallback(void* textEdit, QTextEdit_SelectionChangedCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setSelectionChangedCallback(callback);
}

void QTextEdit_setCursorPositionChangedCallback(void* textEdit, QTextEdit_CursorPositionChangedCallback callback) {
    static_cast<QTextEditBind*>(textEdit)->setCursorPositionChangedCallback(callback);
}

}
