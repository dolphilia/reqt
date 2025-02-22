#include "bind_q_date_edit.h"
#include "c_q_date_edit.h"
#include <QDate>

QDateEditBind::QDateEditBind(QWidget* parent)
    : QDateEdit(parent)
    , handler(new DateEditHandler(this))
{
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
    handler->setDateEdit(this);
}

QDateEditBind::QDateEditBind(const QDate& date, QWidget* parent)
    : QDateEdit(date, parent)
    , handler(new DateEditHandler(this))
{
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
    handler->setDateEdit(this);
}

QDateEditBind::~QDateEditBind() {
    delete handler;
}

void QDateEditBind::setDateChangedCallback(void (*callback)(void*, int, int, int)) {
    handler->setDateChangedCallback(callback);
}

extern "C" {

void* QDateEdit_create(void* parent) {
    return new QDateEditBind(static_cast<QWidget*>(parent));
}

void* QDateEdit_createWithDate(int year, int month, int day, void* parent) {
    return new QDateEditBind(QDate(year, month, day), static_cast<QWidget*>(parent));
}

void QDateEdit_delete(void* dateEdit) {
    delete static_cast<QDateEditBind*>(dateEdit);
}

void QDateEdit_setDate(void* dateEdit, int year, int month, int day) {
    static_cast<QDateEditBind*>(dateEdit)->setDate(QDate(year, month, day));
}

void QDateEdit_getDate(void* dateEdit, int* year, int* month, int* day) {
    QDate date = static_cast<QDateEditBind*>(dateEdit)->date();
    if (year) *year = date.year();
    if (month) *month = date.month();
    if (day) *day = date.day();
}

void QDateEdit_setMinimumDate(void* dateEdit, int year, int month, int day) {
    static_cast<QDateEditBind*>(dateEdit)->setMinimumDate(QDate(year, month, day));
}

void QDateEdit_setMaximumDate(void* dateEdit, int year, int month, int day) {
    static_cast<QDateEditBind*>(dateEdit)->setMaximumDate(QDate(year, month, day));
}

void QDateEdit_getMinimumDate(void* dateEdit, int* year, int* month, int* day) {
    QDate date = static_cast<QDateEditBind*>(dateEdit)->minimumDate();
    if (year) *year = date.year();
    if (month) *month = date.month();
    if (day) *day = date.day();
}

void QDateEdit_getMaximumDate(void* dateEdit, int* year, int* month, int* day) {
    QDate date = static_cast<QDateEditBind*>(dateEdit)->maximumDate();
    if (year) *year = date.year();
    if (month) *month = date.month();
    if (day) *day = date.day();
}

void QDateEdit_setDisplayFormat(void* dateEdit, const char* format) {
    static_cast<QDateEditBind*>(dateEdit)->setDisplayFormat(QString::fromUtf8(format ? format : ""));
}

const char* QDateEdit_displayFormat(void* dateEdit) {
    static thread_local QByteArray format;
    format = static_cast<QDateEditBind*>(dateEdit)->displayFormat().toUtf8();
    return format.constData();
}

void QDateEdit_setCalendarPopup(void* dateEdit, bool enable) {
    static_cast<QDateEditBind*>(dateEdit)->setCalendarPopup(enable);
}

bool QDateEdit_calendarPopup(void* dateEdit) {
    return static_cast<QDateEditBind*>(dateEdit)->calendarPopup();
}

void QDateEdit_setEnabled(void* dateEdit, bool enabled) {
    static_cast<QDateEditBind*>(dateEdit)->setEnabled(enabled);
}

bool QDateEdit_isEnabled(void* dateEdit) {
    return static_cast<QDateEditBind*>(dateEdit)->isEnabled();
}

void QDateEdit_setReadOnly(void* dateEdit, bool readOnly) {
    static_cast<QDateEditBind*>(dateEdit)->setReadOnly(readOnly);
}

bool QDateEdit_isReadOnly(void* dateEdit) {
    return static_cast<QDateEditBind*>(dateEdit)->isReadOnly();
}

void QDateEdit_setDateChangedCallback(void* dateEdit, QDateEditDateChangedCallback callback) {
    static_cast<QDateEditBind*>(dateEdit)->setDateChangedCallback(callback);
}

}
