#include "QDateTimeEditBind.h"
#include <QDateTime>

extern "C" {

void* QDateTimeEdit_create(void* parent) {
    return new QDateTimeEditBind(static_cast<QWidget*>(parent));
}

void QDateTimeEdit_delete(void* dateTimeEdit) {
    delete static_cast<QDateTimeEditBind*>(dateTimeEdit);
}

void QDateTimeEdit_setDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setDateTime(QDateTime(QDate(year, month, day), QTime(hour, minute, second)));
}

void QDateTimeEdit_getDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTime dt = static_cast<QDateTimeEditBind*>(dateTimeEdit)->dateTime();
    *year = dt.date().year();
    *month = dt.date().month();
    *day = dt.date().day();
    *hour = dt.time().hour();
    *minute = dt.time().minute();
    *second = dt.time().second();
}

void QDateTimeEdit_setMinimumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setMinimumDateTime(QDateTime(QDate(year, month, day), QTime(hour, minute, second)));
}

void QDateTimeEdit_setMaximumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setMaximumDateTime(QDateTime(QDate(year, month, day), QTime(hour, minute, second)));
}

void QDateTimeEdit_getMinimumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTime dt = static_cast<QDateTimeEditBind*>(dateTimeEdit)->minimumDateTime();
    *year = dt.date().year();
    *month = dt.date().month();
    *day = dt.date().day();
    *hour = dt.time().hour();
    *minute = dt.time().minute();
    *second = dt.time().second();
}

void QDateTimeEdit_getMaximumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTime dt = static_cast<QDateTimeEditBind*>(dateTimeEdit)->maximumDateTime();
    *year = dt.date().year();
    *month = dt.date().month();
    *day = dt.date().day();
    *hour = dt.time().hour();
    *minute = dt.time().minute();
    *second = dt.time().second();
}

void QDateTimeEdit_setDisplayFormat(void* dateTimeEdit, const char* format) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setDisplayFormat(QString::fromUtf8(format));
}

const char* QDateTimeEdit_displayFormat(void* dateTimeEdit) {
    return static_cast<QDateTimeEditBind*>(dateTimeEdit)->displayFormat().toUtf8().constData();
}

void QDateTimeEdit_setCalendarPopup(void* dateTimeEdit, bool enable) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setCalendarPopup(enable);
}

bool QDateTimeEdit_calendarPopup(void* dateTimeEdit) {
    return static_cast<QDateTimeEditBind*>(dateTimeEdit)->calendarPopup();
}

void QDateTimeEdit_setEnabled(void* dateTimeEdit, bool enabled) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setEnabled(enabled);
}

bool QDateTimeEdit_isEnabled(void* dateTimeEdit) {
    return static_cast<QDateTimeEditBind*>(dateTimeEdit)->isEnabled();
}

void QDateTimeEdit_setReadOnly(void* dateTimeEdit, bool readOnly) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setReadOnly(readOnly);
}

bool QDateTimeEdit_isReadOnly(void* dateTimeEdit) {
    return static_cast<QDateTimeEditBind*>(dateTimeEdit)->isReadOnly();
}

typedef void (*QDateTimeEdit_DateChangedCallback)(void*, int, int, int);
typedef void (*QDateTimeEdit_TimeChangedCallback)(void*, int, int, int);

void QDateTimeEdit_setDateChangedCallback(void* dateTimeEdit, QDateTimeEdit_DateChangedCallback callback) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setDateChangedCallback(callback);
}

void QDateTimeEdit_setTimeChangedCallback(void* dateTimeEdit, QDateTimeEdit_TimeChangedCallback callback) {
    static_cast<QDateTimeEditBind*>(dateTimeEdit)->setTimeChangedCallback(callback);
}

}
