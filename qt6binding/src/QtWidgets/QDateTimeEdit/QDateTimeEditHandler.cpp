#include "QDateTimeEditHandler.h"

QDateTimeEditHandler::QDateTimeEditHandler(QObject* parent)
    : QObject(parent)
    , dateCallback(nullptr)
    , timeCallback(nullptr) {
}

void QDateTimeEditHandler::setDateCallback(QDateTimeEdit_DateChangedCallback callback) {
    dateCallback = callback;
}

void QDateTimeEditHandler::setTimeCallback(QDateTimeEdit_TimeChangedCallback callback) {
    timeCallback = callback;
}

void QDateTimeEditHandler::onDateTimeChanged(const QDateTime& datetime) const {
    if (dateCallback) {
        dateCallback(parent(), datetime.date().year(), datetime.date().month(), datetime.date().day());
    }
    if (timeCallback) {
        timeCallback(parent(), datetime.time().hour(), datetime.time().minute(), datetime.time().second());
    }
}
