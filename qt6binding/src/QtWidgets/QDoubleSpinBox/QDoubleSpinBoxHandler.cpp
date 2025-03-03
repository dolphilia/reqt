#include "QDoubleSpinBoxHandler.h"

DoubleSpinBoxHandler::DoubleSpinBoxHandler(QObject* parent)
    : QObject(parent)
    , valueCallback(nullptr)
    , editingCallback(nullptr) {
}

void DoubleSpinBoxHandler::setValueChangedCallback(ValueChangedCallback callback) {
    valueCallback = callback;
}

void DoubleSpinBoxHandler::setEditingFinishedCallback(EditingFinishedCallback callback) {
    editingCallback = callback;
}

void DoubleSpinBoxHandler::onValueChanged(double value) const {
    if (valueCallback) {
        valueCallback(parent(), value);
    }
}

void DoubleSpinBoxHandler::onEditingFinished() const {
    if (editingCallback) {
        editingCallback(parent());
    }
}
