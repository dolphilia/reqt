#include "QSpinBoxHandler.h"

QSpinBoxHandler::QSpinBoxHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr)
    , textChangedCallback(nullptr)
    , editingFinishedCallback(nullptr) {
}

QSpinBoxHandler::~QSpinBoxHandler() {
}

void QSpinBoxHandler::setValueChangedCallback(QSpinBox_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void QSpinBoxHandler::setTextChangedCallback(QSpinBox_TextChangedCallback callback) {
    textChangedCallback = callback;
}

void QSpinBoxHandler::setEditingFinishedCallback(QSpinBox_EditingFinishedCallback callback) {
    editingFinishedCallback = callback;
}

void QSpinBoxHandler::onValueChanged(int value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}

void QSpinBoxHandler::onTextChanged(const QString &text) const {
    if (textChangedCallback) {
        textChangedCallback(parent(), text.toUtf8().constData());
    }
}

void QSpinBoxHandler::onEditingFinished() const {
    if (editingFinishedCallback) {
        editingFinishedCallback(parent());
    }
}
