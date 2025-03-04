#include "QDoubleSpinBoxHandler.h"

QDoubleSpinBoxHandler::QDoubleSpinBoxHandler(QObject* parent)
    : QObject(parent)
    , valueCallback(nullptr)
    , editingCallback(nullptr) {
}

void QDoubleSpinBoxHandler::setValueChangedCallback(QDoubleSpinBox_ValueChangedCallback callback) {
    valueCallback = callback;
}

void QDoubleSpinBoxHandler::setEditingFinishedCallback(QDoubleSpinBox_EditingFinishedCallback callback) {
    editingCallback = callback;
}

void QDoubleSpinBoxHandler::onValueChanged(double value) const {
    if (valueCallback) {
        valueCallback(parent(), value);
    }
}

void QDoubleSpinBoxHandler::onEditingFinished() const {
    if (editingCallback) {
        editingCallback(parent());
    }
}
