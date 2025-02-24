#include "qtextedit.h"
#include "QTextEditBind.h"
#include "QTextEditHandler.h"

extern "C" {

void* QTextEdit_create(void* parent)
{
    return new BindQTextEdit(reinterpret_cast<QWidget*>(parent));
}

void QTextEdit_delete(void* text_edit)
{
    delete static_cast<BindQTextEdit*>(text_edit);
}

void QTextEdit_setText(void* text_edit, const char* text)
{
    static_cast<BindQTextEdit*>(text_edit)->setText(QString::fromUtf8(text));
}

const char* QTextEdit_text(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->toPlainText().toUtf8().constData();
}

void QTextEdit_setPlainText(void* text_edit, const char* text)
{
    static_cast<BindQTextEdit*>(text_edit)->setPlainText(QString::fromUtf8(text));
}

const char* QTextEdit_toPlainText(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->toPlainText().toUtf8().constData();
}

void QTextEdit_setHtml(void* text_edit, const char* text)
{
    static_cast<BindQTextEdit*>(text_edit)->setHtml(QString::fromUtf8(text));
}

const char* QTextEdit_toHtml(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->toHtml().toUtf8().constData();
}

void QTextEdit_append(void* text_edit, const char* text)
{
    static_cast<BindQTextEdit*>(text_edit)->append(QString::fromUtf8(text));
}

void QTextEdit_clear(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->clear();
}

void QTextEdit_selectAll(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->selectAll();
}

void QTextEdit_copy(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->copy();
}

void QTextEdit_cut(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->cut();
}

void QTextEdit_paste(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->paste();
}

void QTextEdit_undo(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->undo();
}

void QTextEdit_redo(void* text_edit)
{
    static_cast<BindQTextEdit*>(text_edit)->redo();
}

void QTextEdit_setReadOnly(void* text_edit, bool read_only)
{
    static_cast<BindQTextEdit*>(text_edit)->setReadOnly(read_only);
}

bool QTextEdit_isReadOnly(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->isReadOnly();
}

void QTextEdit_setPlaceholderText(void* text_edit, const char* text)
{
    static_cast<BindQTextEdit*>(text_edit)->setPlaceholderText(QString::fromUtf8(text));
}

const char* QTextEdit_placeholderText(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->placeholderText().toUtf8().constData();
}

void QTextEdit_setOverwriteMode(void* text_edit, bool overwrite)
{
    static_cast<BindQTextEdit*>(text_edit)->setOverwriteMode(overwrite);
}

bool QTextEdit_overwriteMode(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->overwriteMode();
}

void QTextEdit_setTabChangesFocus(void* text_edit, bool changes)
{
    static_cast<BindQTextEdit*>(text_edit)->setTabChangesFocus(changes);
}

bool QTextEdit_tabChangesFocus(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->tabChangesFocus();
}

void QTextEdit_setAcceptRichText(void* text_edit, bool accept)
{
    static_cast<BindQTextEdit*>(text_edit)->setAcceptRichText(accept);
}

bool QTextEdit_acceptRichText(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->acceptRichText();
}

void QTextEdit_setTextCursor(void* text_edit, int position)
{
    QTextCursor cursor = static_cast<BindQTextEdit*>(text_edit)->textCursor();
    cursor.setPosition(position);
    static_cast<BindQTextEdit*>(text_edit)->setTextCursor(cursor);
}

int QTextEdit_textCursor(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->textCursor().position();
}

void QTextEdit_setCursorWidth(void* text_edit, int width)
{
    static_cast<BindQTextEdit*>(text_edit)->setCursorWidth(width);
}

int QTextEdit_cursorWidth(void* text_edit)
{
    return static_cast<BindQTextEdit*>(text_edit)->cursorWidth();
}

bool QTextEdit_find(void* text_edit, const char* text, int options)
{
    return static_cast<BindQTextEdit*>(text_edit)->find(QString::fromUtf8(text), static_cast<QTextDocument::FindFlags>(options));
}

void QTextEdit_setWordWrapMode(void* text_edit, int mode)
{
    static_cast<BindQTextEdit*>(text_edit)->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
}

int QTextEdit_wordWrapMode(void* text_edit)
{
    return static_cast<int>(static_cast<BindQTextEdit*>(text_edit)->wordWrapMode());
}

void QTextEdit_setLineWrapMode(void* text_edit, int mode)
{
    static_cast<BindQTextEdit*>(text_edit)->setLineWrapMode(static_cast<QTextEdit::LineWrapMode>(mode));
}

int QTextEdit_lineWrapMode(void* text_edit)
{
    return static_cast<int>(static_cast<BindQTextEdit*>(text_edit)->lineWrapMode());
}

void QTextEdit_setTextChangedCallback(void* text_edit, QTextEditTextChangedCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setTextChangedCallback(callback);
}

void QTextEdit_setCopyAvailableCallback(void* text_edit, QTextEditCopyAvailableCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setCopyAvailableCallback(callback);
}

void QTextEdit_setUndoAvailableCallback(void* text_edit, QTextEditUndoAvailableCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setUndoAvailableCallback(callback);
}

void QTextEdit_setRedoAvailableCallback(void* text_edit, QTextEditRedoAvailableCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setRedoAvailableCallback(callback);
}

void QTextEdit_setSelectionChangedCallback(void* text_edit, QTextEditSelectionChangedCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setSelectionChangedCallback(callback);
}

void QTextEdit_setCursorPositionChangedCallback(void* text_edit, QTextEditCursorPositionChangedCallback callback)
{
    BindQTextEdit* qtext_edit = static_cast<BindQTextEdit*>(text_edit);
    TextEditHandler* handler = qtext_edit->handler();
    if (!handler) {
        handler = new TextEditHandler(qtext_edit);
        qtext_edit->setTextEditHandler(handler);
    }
    handler->setCursorPositionChangedCallback(callback);
}

}
