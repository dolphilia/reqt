#include "bind_q_date_time_edit.h"
#include <QString>
#include <QDateTime>
#include <QTimeZone>

QDateTimeEdit* QDateTimeEditBind::create(QWidget* parent) {
    return new QDateTimeEdit(parent);
}

QDateTimeEdit* QDateTimeEditBind::createWithDateTime(int year, int month, int day, int hour, int minute, int second, QWidget* parent) {
    QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second));
    return new QDateTimeEdit(dateTime, parent);
}

void QDateTimeEditBind::destroy(QDateTimeEdit* dateTimeEdit) {
    if (dateTimeEdit) {
        delete dateTimeEdit;
    }
}

void QDateTimeEditBind::setDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    if (dateTimeEdit) {
        QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second));
        dateTimeEdit->setDateTime(dateTime);
    }
}

void QDateTimeEditBind::getDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    if (dateTimeEdit) {
        QDateTime dateTime = dateTimeEdit->dateTime();
        if (year) *year = dateTime.date().year();
        if (month) *month = dateTime.date().month();
        if (day) *day = dateTime.date().day();
        if (hour) *hour = dateTime.time().hour();
        if (minute) *minute = dateTime.time().minute();
        if (second) *second = dateTime.time().second();
    }
}

void QDateTimeEditBind::setMinimumDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    if (dateTimeEdit) {
        QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second));
        dateTimeEdit->setMinimumDateTime(dateTime);
    }
}

void QDateTimeEditBind::setMaximumDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second) {
    if (dateTimeEdit) {
        QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second));
        dateTimeEdit->setMaximumDateTime(dateTime);
    }
}

void QDateTimeEditBind::getMinimumDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    if (dateTimeEdit) {
        QDateTime dateTime = dateTimeEdit->minimumDateTime();
        if (year) *year = dateTime.date().year();
        if (month) *month = dateTime.date().month();
        if (day) *day = dateTime.date().day();
        if (hour) *hour = dateTime.time().hour();
        if (minute) *minute = dateTime.time().minute();
        if (second) *second = dateTime.time().second();
    }
}

void QDateTimeEditBind::getMaximumDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    if (dateTimeEdit) {
        QDateTime dateTime = dateTimeEdit->maximumDateTime();
        if (year) *year = dateTime.date().year();
        if (month) *month = dateTime.date().month();
        if (day) *day = dateTime.date().day();
        if (hour) *hour = dateTime.time().hour();
        if (minute) *minute = dateTime.time().minute();
        if (second) *second = dateTime.time().second();
    }
}

void QDateTimeEditBind::setDisplayFormat(QDateTimeEdit* dateTimeEdit, const char* format) {
    if (dateTimeEdit && format) {
        dateTimeEdit->setDisplayFormat(QString::fromUtf8(format));
    }
}

const char* QDateTimeEditBind::displayFormat(QDateTimeEdit* dateTimeEdit) {
    if (dateTimeEdit) {
        static QString str;
        str = dateTimeEdit->displayFormat();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QDateTimeEditBind::setCalendarPopup(QDateTimeEdit* dateTimeEdit, bool enable) {
    if (dateTimeEdit) {
        dateTimeEdit->setCalendarPopup(enable);
    }
}

bool QDateTimeEditBind::calendarPopup(QDateTimeEdit* dateTimeEdit) {
    return dateTimeEdit ? dateTimeEdit->calendarPopup() : false;
}

void QDateTimeEditBind::setTimeZone(QDateTimeEdit* dateTimeEdit, const char* id) {
    if (dateTimeEdit && id) {
        dateTimeEdit->setTimeZone(QTimeZone(id));
    }
}

const char* QDateTimeEditBind::timeZone(QDateTimeEdit* dateTimeEdit) {
    if (dateTimeEdit) {
        static QString str;
        str = QString::fromUtf8(dateTimeEdit->timeZone().id());
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QDateTimeEditBind::setEnabled(QDateTimeEdit* dateTimeEdit, bool enabled) {
    if (dateTimeEdit) {
        dateTimeEdit->setEnabled(enabled);
    }
}

bool QDateTimeEditBind::isEnabled(QDateTimeEdit* dateTimeEdit) {
    return dateTimeEdit ? dateTimeEdit->isEnabled() : false;
}

void QDateTimeEditBind::setReadOnly(QDateTimeEdit* dateTimeEdit, bool readOnly) {
    if (dateTimeEdit) {
        dateTimeEdit->setReadOnly(readOnly);
    }
}

bool QDateTimeEditBind::isReadOnly(QDateTimeEdit* dateTimeEdit) {
    return dateTimeEdit ? dateTimeEdit->isReadOnly() : false;
}

void QDateTimeEditBind::setCurrentSectionIndex(QDateTimeEdit* dateTimeEdit, int index) {
    if (dateTimeEdit) {
        dateTimeEdit->setCurrentSectionIndex(index);
    }
}

int QDateTimeEditBind::currentSectionIndex(QDateTimeEdit* dateTimeEdit) {
    return dateTimeEdit ? dateTimeEdit->currentSectionIndex() : -1;
}

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
