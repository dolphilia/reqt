#include "QDateTimeEditBind.h"
#include <QDateTime>

extern "C" {

void* QDateTimeEdit_create(void* parent) {
    return QDateTimeEditBind::create(static_cast<QWidget*>(parent));
}

void* QDateTimeEdit_createWithDateTime(int year, int month, int day, int hour, int minute, int second, void* parent) {
    return QDateTimeEditBind::createWithDateTime(year, month, day, hour, minute, second, static_cast<QWidget*>(parent));
}

void QDateTimeEdit_delete(void* dateTimeEdit) {
    QDateTimeEditBind::destroy(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    QDateTimeEditBind::setDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_getDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTimeEditBind::getDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_setMinimumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    QDateTimeEditBind::setMinimumDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_setMaximumDateTime(void* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    QDateTimeEditBind::setMaximumDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_getMinimumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTimeEditBind::getMinimumDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_getMaximumDateTime(void* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    QDateTimeEditBind::getMaximumDateTime(static_cast<QDateTimeEdit*>(dateTimeEdit), year, month, day, hour, minute, second);
}

void QDateTimeEdit_setDisplayFormat(void* dateTimeEdit, const char* format) {
    QDateTimeEditBind::setDisplayFormat(static_cast<QDateTimeEdit*>(dateTimeEdit), format);
}

const char* QDateTimeEdit_displayFormat(void* dateTimeEdit) {
    return QDateTimeEditBind::displayFormat(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setCalendarPopup(void* dateTimeEdit, bool enable) {
    QDateTimeEditBind::setCalendarPopup(static_cast<QDateTimeEdit*>(dateTimeEdit), enable);
}

bool QDateTimeEdit_calendarPopup(void* dateTimeEdit) {
    return QDateTimeEditBind::calendarPopup(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setTimeZone(void* dateTimeEdit, const char* id) {
    QDateTimeEditBind::setTimeZone(static_cast<QDateTimeEdit*>(dateTimeEdit), id);
}

const char* QDateTimeEdit_timeZone(void* dateTimeEdit) {
    return QDateTimeEditBind::timeZone(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setEnabled(void* dateTimeEdit, bool enabled) {
    QDateTimeEditBind::setEnabled(static_cast<QDateTimeEdit*>(dateTimeEdit), enabled);
}

bool QDateTimeEdit_isEnabled(void* dateTimeEdit) {
    return QDateTimeEditBind::isEnabled(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setReadOnly(void* dateTimeEdit, bool readOnly) {
    QDateTimeEditBind::setReadOnly(static_cast<QDateTimeEdit*>(dateTimeEdit), readOnly);
}

bool QDateTimeEdit_isReadOnly(void* dateTimeEdit) {
    return QDateTimeEditBind::isReadOnly(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

void QDateTimeEdit_setCurrentSectionIndex(void* dateTimeEdit, int index) {
    QDateTimeEditBind::setCurrentSectionIndex(static_cast<QDateTimeEdit*>(dateTimeEdit), index);
}

int QDateTimeEdit_currentSectionIndex(void* dateTimeEdit) {
    return QDateTimeEditBind::currentSectionIndex(static_cast<QDateTimeEdit*>(dateTimeEdit));
}

}
