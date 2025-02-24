#ifndef QDATETIMEEDIT_C_H
#define QDATETIMEEDIT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QDateTimeEdit
void* QDateTimeEdit_create(void* parent);
void* QDateTimeEdit_createWithDateTime(int year, int month, int day, int hour, int minute, int second, void* parent);
void QDateTimeEdit_delete(void* dateTimeEdit);
void QDateTimeEdit_setDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
void QDateTimeEdit_getDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
void QDateTimeEdit_setMinimumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
void QDateTimeEdit_setMaximumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
void QDateTimeEdit_getMinimumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
void QDateTimeEdit_getMaximumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
void QDateTimeEdit_setDisplayFormat(void* dateTimeEdit, const char* format);
const char* QDateTimeEdit_displayFormat(void* dateTimeEdit);
void QDateTimeEdit_setCalendarPopup(void* dateTimeEdit, bool enable);
bool QDateTimeEdit_calendarPopup(void* dateTimeEdit);
void QDateTimeEdit_setTimeZone(void* dateTimeEdit, const char* id);
const char* QDateTimeEdit_timeZone(void* dateTimeEdit);
void QDateTimeEdit_setEnabled(void* dateTimeEdit, bool enabled);
bool QDateTimeEdit_isEnabled(void* dateTimeEdit);
void QDateTimeEdit_setReadOnly(void* dateTimeEdit, bool readOnly);
bool QDateTimeEdit_isReadOnly(void* dateTimeEdit);
void QDateTimeEdit_setCurrentSectionIndex(void* dateTimeEdit, int index);
int QDateTimeEdit_currentSectionIndex(void* dateTimeEdit);

#ifdef __cplusplus
}
#endif

#endif // QDATETIMEEDIT_C_H
