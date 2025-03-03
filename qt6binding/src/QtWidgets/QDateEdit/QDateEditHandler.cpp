#include "QDateEditHandler.h"

DateEditHandler::DateEditHandler(QObject* parent)
    : QObject(parent)
    , dateCallback(nullptr) {
}

void DateEditHandler::setDateChangedCallback(DateChangedCallback callback) {
    dateCallback = callback;
}

void DateEditHandler::onDateChanged(const QDate& date) const {
    if (dateCallback) {
        dateCallback(parent(), date.year(), date.month(), date.day());
    }
}
