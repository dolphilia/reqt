#include "QDateTimeEditHandler.h"

DateTimeEditHandler::DateTimeEditHandler(QObject* parent)
    : QObject(parent)
    , dateCallback(nullptr)
    , timeCallback(nullptr)
{
}

void DateTimeEditHandler::setDateCallback(DateChangedCallback callback) {
    dateCallback = callback;
}

void DateTimeEditHandler::setTimeCallback(TimeChangedCallback callback) {
    timeCallback = callback;
}

void DateTimeEditHandler::onDateTimeChanged(const QDateTime& datetime) const {
    if (dateCallback) {
        dateCallback(parent(), datetime.date().year(), datetime.date().month(), datetime.date().day());
    }
    if (timeCallback) {
        timeCallback(parent(), datetime.time().hour(), datetime.time().minute(), datetime.time().second());
    }
}
