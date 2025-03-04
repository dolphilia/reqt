#include "QLCDNumberHandler.h"

QLCDNumberHandler::QLCDNumberHandler(QObject* parent)
    : QObject(parent)
    , overflowCallback(nullptr) {
}

void QLCDNumberHandler::setOverflowCallback(QLCDNumber_OverflowCallback callback) {
    overflowCallback = callback;
}

void QLCDNumberHandler::onOverflow() const {
    if (overflowCallback) {
        overflowCallback(nullptr);
    }
}
