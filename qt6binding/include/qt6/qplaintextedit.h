#ifndef QPLAINTEXTEDIT_CAPI_H
#define QPLAINTEXTEDIT_CAPI_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void* QPlainTextEdit_create(void* parent);
void QPlainTextEdit_delete(void* ptr);

// テキスト操作
void QPlainTextEdit_setPlainText(void* text_edit, const char* text);
const char* QPlainTextEdit_toPlainText(void* text_edit);
void QPlainTextEdit_appendPlainText(void* text_edit, const char* text);

// 編集操作
void QPlainTextEdit_cut(void* text_edit);
void QPlainTextEdit_copy(void* text_edit);
void QPlainTextEdit_paste(void* text_edit);
void QPlainTextEdit_undo(void* text_edit);
void QPlainTextEdit_redo(void* text_edit);

typedef void (*TextChangedCallback)(void*);
typedef void (*CursorPositionChangedCallback)(void*);
typedef void (*CopyAvailableCallback)(void*, bool);
typedef void (*UndoAvailableCallback)(void*, bool);
typedef void (*RedoAvailableCallback)(void*, bool);
typedef void (*SelectionChangedCallback)(void*);

// コールバック設定
void QPlainTextEdit_setTextChangedCallback(void* text_edit, TextChangedCallback callback);
void QPlainTextEdit_setCursorPositionChangedCallback(void* text_edit, CursorPositionChangedCallback callback);
void QPlainTextEdit_setCopyAvailableCallback(void* text_edit, CopyAvailableCallback callback);
void QPlainTextEdit_setUndoAvailableCallback(void* text_edit, UndoAvailableCallback callback);
void QPlainTextEdit_setRedoAvailableCallback(void* text_edit, RedoAvailableCallback callback);
void QPlainTextEdit_setSelectionChangedCallback(void* text_edit, SelectionChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QPLAINTEXTEDIT_CAPI_H
