#include "QDateEditHandler.h"

DateEditHandler::DateEditHandler(QObject* parent)
    : QObject(parent)
    , dateEdit(nullptr)
    , callback(nullptr)
{
}

void DateEditHandler::setDateEdit(QDateEdit* dateEdit) {
    this->dateEdit = dateEdit;
    connect(dateEdit, &QDateEdit::dateChanged, this, &DateEditHandler::onDateChanged);
}

void DateEditHandler::setDateChangedCallback(void (*callback)(void*, int, int, int)) {
    this->callback = callback;
}

void DateEditHandler::onDateChanged(const QDate& date) {
    if (callback && dateEdit) {
        callback(dateEdit, date.year(), date.month(), date.day());
    }
}
