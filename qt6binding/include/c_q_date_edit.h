#ifndef QDATEEDIT_C_H
#define QDATEEDIT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QDateEdit
void* QDateEdit_create(void* parent);
void* QDateEdit_createWithDate(int year, int month, int day, void* parent);
void QDateEdit_delete(void* dateEdit);
void QDateEdit_setDate(void* dateEdit, int year, int month, int day);
void QDateEdit_getDate(void* dateEdit, int* year, int* month, int* day);
void QDateEdit_setMinimumDate(void* dateEdit, int year, int month, int day);
void QDateEdit_setMaximumDate(void* dateEdit, int year, int month, int day);
void QDateEdit_getMinimumDate(void* dateEdit, int* year, int* month, int* day);
void QDateEdit_getMaximumDate(void* dateEdit, int* year, int* month, int* day);
void QDateEdit_setDisplayFormat(void* dateEdit, const char* format);
const char* QDateEdit_displayFormat(void* dateEdit);
void QDateEdit_setCalendarPopup(void* dateEdit, bool enable);
bool QDateEdit_calendarPopup(void* dateEdit);
void QDateEdit_setEnabled(void* dateEdit, bool enabled);
bool QDateEdit_isEnabled(void* dateEdit);
void QDateEdit_setReadOnly(void* dateEdit, bool readOnly);
bool QDateEdit_isReadOnly(void* dateEdit);

// コールバック関数の型定義
typedef void (*QDateEditDateChangedCallback)(void* dateEdit, int year, int month, int day);

// コールバック設定関数
void QDateEdit_setDateChangedCallback(void* dateEdit, QDateEditDateChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QDATEEDIT_C_H
