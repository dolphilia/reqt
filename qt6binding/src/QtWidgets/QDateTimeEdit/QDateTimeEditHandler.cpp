#include "QDateTimeEditHandler.h"

DateTimeEditHandler::DateTimeEditHandler(QObject* parent)
    : QObject(parent)
    , dateTimeEdit(nullptr)
    , callback(nullptr)
{
}

void DateTimeEditHandler::setDateTimeEdit(QDateTimeEdit* dateTimeEdit) {
    this->dateTimeEdit = dateTimeEdit;
    connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &DateTimeEditHandler::onDateTimeChanged);
}

void DateTimeEditHandler::setDateTimeChangedCallback(void (*callback)(void*, int, int, int, int, int, int)) {
    this->callback = callback;
}

void DateTimeEditHandler::onDateTimeChanged(const QDateTime& dateTime) {
    if (callback && dateTimeEdit) {
        callback(dateTimeEdit,
            dateTime.date().year(),
            dateTime.date().month(),
            dateTime.date().day(),
            dateTime.time().hour(),
            dateTime.time().minute(),
            dateTime.time().second());
    }
}
