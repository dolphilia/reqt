#ifndef QTEXTEDIT_C_H
#define QTEXTEDIT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QTextEdit creation/deletion
void* QTextEdit_create(void* parent);
void QTextEdit_delete(void* text_edit);

// Text operations
void QTextEdit_setText(void* text_edit, const char* text);
const char* QTextEdit_text(void* text_edit);
void QTextEdit_setPlainText(void* text_edit, const char* text);
const char* QTextEdit_toPlainText(void* text_edit);
void QTextEdit_setHtml(void* text_edit, const char* text);
const char* QTextEdit_toHtml(void* text_edit);
void QTextEdit_append(void* text_edit, const char* text);
void QTextEdit_clear(void* text_edit);

// Selection operations
void QTextEdit_selectAll(void* text_edit);
void QTextEdit_copy(void* text_edit);
void QTextEdit_cut(void* text_edit);
void QTextEdit_paste(void* text_edit);
void QTextEdit_undo(void* text_edit);
void QTextEdit_redo(void* text_edit);

// Properties
void QTextEdit_setReadOnly(void* text_edit, bool read_only);
bool QTextEdit_isReadOnly(void* text_edit);
void QTextEdit_setPlaceholderText(void* text_edit, const char* text);
const char* QTextEdit_placeholderText(void* text_edit);
void QTextEdit_setOverwriteMode(void* text_edit, bool overwrite);
bool QTextEdit_overwriteMode(void* text_edit);
void QTextEdit_setTabChangesFocus(void* text_edit, bool changes);
bool QTextEdit_tabChangesFocus(void* text_edit);
void QTextEdit_setAcceptRichText(void* text_edit, bool accept);
bool QTextEdit_acceptRichText(void* text_edit);

// Cursor and selection
void QTextEdit_setTextCursor(void* text_edit, int position);
int QTextEdit_textCursor(void* text_edit);
void QTextEdit_setCursorWidth(void* text_edit, int width);
int QTextEdit_cursorWidth(void* text_edit);
bool QTextEdit_find(void* text_edit, const char* text, int options);

// Word wrap
void QTextEdit_setWordWrapMode(void* text_edit, int mode);
int QTextEdit_wordWrapMode(void* text_edit);
void QTextEdit_setLineWrapMode(void* text_edit, int mode);
int QTextEdit_lineWrapMode(void* text_edit);

// Signal handlers
typedef void (*QTextEditTextChangedCallback)();
typedef void (*QTextEditCopyAvailableCallback)(bool available);
typedef void (*QTextEditUndoAvailableCallback)(bool available);
typedef void (*QTextEditRedoAvailableCallback)(bool available);
typedef void (*QTextEditSelectionChangedCallback)();
typedef void (*QTextEditCursorPositionChangedCallback)();

void QTextEdit_setTextChangedCallback(void* text_edit, QTextEditTextChangedCallback callback);
void QTextEdit_setCopyAvailableCallback(void* text_edit, QTextEditCopyAvailableCallback callback);
void QTextEdit_setUndoAvailableCallback(void* text_edit, QTextEditUndoAvailableCallback callback);
void QTextEdit_setRedoAvailableCallback(void* text_edit, QTextEditRedoAvailableCallback callback);
void QTextEdit_setSelectionChangedCallback(void* text_edit, QTextEditSelectionChangedCallback callback);
void QTextEdit_setCursorPositionChangedCallback(void* text_edit, QTextEditCursorPositionChangedCallback callback);

// Constants
#define QTEXTEDIT_WORDWRAP_NONE 0
#define QTEXTEDIT_WORDWRAP_WORD 1
#define QTEXTEDIT_WORDWRAP_MANUAL 2
#define QTEXTEDIT_WORDWRAP_MANUALWIDTH 3

#define QTEXTEDIT_LINEWRAP_NONE 0
#define QTEXTEDIT_LINEWRAP_WIDGET 1
#define QTEXTEDIT_LINEWRAP_FIXED 2

#define QTEXTEDIT_FIND_BACKWARD 0x00001
#define QTEXTEDIT_FIND_CASESENSITIVELY 0x00002
#define QTEXTEDIT_FIND_WHOLEWORDS 0x00004

#ifdef __cplusplus
}
#endif

#endif // QTEXTEDIT_C_H
