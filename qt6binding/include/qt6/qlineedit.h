#ifndef QLINEEDIT_C_H
#define QLINEEDIT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// エコーモード定数
#define QLINEEDIT_NORMAL 0
#define QLINEEDIT_NOECHO 1
#define QLINEEDIT_PASSWORD 2
#define QLINEEDIT_PASSWORDECHOONEDIT 3

// QLineEdit
void* QLineEdit_create(void* parent);
void* QLineEdit_create_2(const char* text, void* parent);
void QLineEdit_delete(void* lineEdit);
void QLineEdit_setText(void* lineEdit, const char* text);
const char* QLineEdit_text(void* lineEdit);
void QLineEdit_setPlaceholderText(void* lineEdit, const char* text);
const char* QLineEdit_placeholderText(void* lineEdit);
void QLineEdit_setMaxLength(void* lineEdit, int length);
int QLineEdit_maxLength(void* lineEdit);
void QLineEdit_setReadOnly(void* lineEdit, bool readOnly);
bool QLineEdit_isReadOnly(void* lineEdit);
void QLineEdit_setClearButtonEnabled(void* lineEdit, bool enable);
bool QLineEdit_isClearButtonEnabled(void* lineEdit);
void QLineEdit_setEnabled(void* lineEdit, bool enabled);
bool QLineEdit_isEnabled(void* lineEdit);
void QLineEdit_clear(void* lineEdit);
void QLineEdit_selectAll(void* lineEdit);
void QLineEdit_setEchoMode(void* lineEdit, int mode);
int QLineEdit_echoMode(void* lineEdit);
typedef void (*QLineEditTextChangedCallback)(void* lineEdit, const char* text);
void QLineEdit_setTextChangedCallback(void* lineEdit, QLineEditTextChangedCallback callback);
void QLineEdit_setTextEditedCallback(void* lineEdit, QLineEditTextChangedCallback callback);
void QLineEdit_setReturnPressedCallback(void* lineEdit, QLineEditTextChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QLINEEDIT_C_H
