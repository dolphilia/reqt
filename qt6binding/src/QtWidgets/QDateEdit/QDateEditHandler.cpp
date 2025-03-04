#include "QDateEditHandler.h"

QDateEditHandler::QDateEditHandler(QObject* parent)
    : QObject(parent)
    , dateCallback(nullptr) {
}

void QDateEditHandler::setDateChangedCallback(QDateEdit_DateChangedCallback callback) {
    dateCallback = callback;
}

void QDateEditHandler::onDateChanged(const QDate& date) const {
    if (dateCallback) {
        dateCallback(parent(), date.year(), date.month(), date.day());
    }
}
