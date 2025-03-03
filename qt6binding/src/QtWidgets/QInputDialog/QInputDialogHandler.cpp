#include "QInputDialogHandler.h"

QInputDialogHandler::QInputDialogHandler(QObject* parent)
    : QObject(parent)
    , doubleValueChangedCallback(nullptr)
    , doubleValueSelectedCallback(nullptr)
    , intValueChangedCallback(nullptr)
    , intValueSelectedCallback(nullptr)
    , textValueChangedCallback(nullptr)
    , textValueSelectedCallback(nullptr) {
}

void QInputDialogHandler::setDoubleValueChangedCallback(DoubleValueChangedCallback callback) {
    doubleValueChangedCallback = callback;
}

void QInputDialogHandler::setDoubleValueSelectedCallback(DoubleValueSelectedCallback callback) {
    doubleValueSelectedCallback = callback;
}

void QInputDialogHandler::setIntValueChangedCallback(IntValueChangedCallback callback) {
    intValueChangedCallback = callback;
}

void QInputDialogHandler::setIntValueSelectedCallback(IntValueSelectedCallback callback) {
    intValueSelectedCallback = callback;
}

void QInputDialogHandler::setTextValueChangedCallback(TextValueChangedCallback callback) {
    textValueChangedCallback = callback;
}

void QInputDialogHandler::setTextValueSelectedCallback(TextValueSelectedCallback callback) {
    textValueSelectedCallback = callback;
}

void QInputDialogHandler::onDoubleValueChanged(double value) const {
    if (doubleValueChangedCallback) {
        doubleValueChangedCallback(parent(), value);
    }
}

void QInputDialogHandler::onDoubleValueSelected(double value) const {
    if (doubleValueSelectedCallback) {
        doubleValueSelectedCallback(parent(), value);
    }
}

void QInputDialogHandler::onIntValueChanged(int value) const {
    if (intValueChangedCallback) {
        intValueChangedCallback(parent(), value);
    }
}

void QInputDialogHandler::onIntValueSelected(int value) const {
    if (intValueSelectedCallback) {
        intValueSelectedCallback(parent(), value);
    }
}

void QInputDialogHandler::onTextValueChanged(const QString& text) const {
    if (textValueChangedCallback) {
        textValueChangedCallback(parent(), text.toUtf8().constData());
    }
}

void QInputDialogHandler::onTextValueSelected(const QString& text) const {
    if (textValueSelectedCallback) {
        textValueSelectedCallback(parent(), text.toUtf8().constData());
    }
}
