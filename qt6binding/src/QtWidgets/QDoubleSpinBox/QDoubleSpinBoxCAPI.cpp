#include "QDoubleSpinBoxBind.h"
#include "qdoublespinbox.h"

extern "C" {

void* QDoubleSpinBox_create(void* parent) {
    return new QDoubleSpinBoxBind(static_cast<QWidget*>(parent));
}

void QDoubleSpinBox_delete(void* doubleSpinBox) {
    delete static_cast<QDoubleSpinBoxBind*>(doubleSpinBox);
}

void QDoubleSpinBox_setValue(void* doubleSpinBox, double value) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setValue(value);
}

double QDoubleSpinBox_value(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->value();
}

void QDoubleSpinBox_setRange(void* doubleSpinBox, double minimum, double maximum) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setRange(minimum, maximum);
}

double QDoubleSpinBox_minimum(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->minimum();
}

double QDoubleSpinBox_maximum(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->maximum();
}

void QDoubleSpinBox_setSingleStep(void* doubleSpinBox, double step) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setSingleStep(step);
}

double QDoubleSpinBox_singleStep(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->singleStep();
}

void QDoubleSpinBox_setDecimals(void* doubleSpinBox, int decimals) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setDecimals(decimals);
}

int QDoubleSpinBox_decimals(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->decimals();
}

void QDoubleSpinBox_setPrefix(void* doubleSpinBox, const char* prefix) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setPrefix(QString::fromUtf8(prefix));
}

const char* QDoubleSpinBox_prefix(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->prefix().toUtf8().constData();
}

void QDoubleSpinBox_setSuffix(void* doubleSpinBox, const char* suffix) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setSuffix(QString::fromUtf8(suffix));
}

const char* QDoubleSpinBox_suffix(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->suffix().toUtf8().constData();
}

void QDoubleSpinBox_setWrapping(void* doubleSpinBox, bool wrapping) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setWrapping(wrapping);
}

bool QDoubleSpinBox_wrapping(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->wrapping();
}

void QDoubleSpinBox_setSpecialValueText(void* doubleSpinBox, const char* text) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setSpecialValueText(QString::fromUtf8(text));
}

const char* QDoubleSpinBox_specialValueText(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->specialValueText().toUtf8().constData();
}

void QDoubleSpinBox_stepUp(void* doubleSpinBox) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->stepUp();
}

void QDoubleSpinBox_stepDown(void* doubleSpinBox) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->stepDown();
}

const char* QDoubleSpinBox_text(void* doubleSpinBox) {
    return static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->text().toUtf8().constData();
}

void QDoubleSpinBox_setValueChangedCallback(void* doubleSpinBox, ValueChangedCallback callback) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setValueChangedCallback(callback);
}

void QDoubleSpinBox_setEditingFinishedCallback(void* doubleSpinBox, EditingFinishedCallback callback) {
    static_cast<QDoubleSpinBoxBind*>(doubleSpinBox)->setEditingFinishedCallback(callback);
}

}
