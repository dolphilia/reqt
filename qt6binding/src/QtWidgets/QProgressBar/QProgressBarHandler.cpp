#include "QProgressBarHandler.h"

QProgressBarHandler::QProgressBarHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr) {
}

void QProgressBarHandler::setValueChangedCallback(QProgressBar_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void QProgressBarHandler::onValueChanged(int value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}
