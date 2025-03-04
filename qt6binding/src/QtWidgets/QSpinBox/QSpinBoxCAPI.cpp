#include "QSpinBoxBind.h"
#include <QString>

extern "C" {

void* QSpinBox_create(void* parent) {
    return new QSpinBoxBind(static_cast<QWidget*>(parent));
}

void QSpinBox_delete(void* spinbox) {
    delete static_cast<QSpinBoxBind*>(spinbox);
}

void QSpinBox_setValue(void* spinbox, int value) {
    static_cast<QSpinBoxBind*>(spinbox)->setValue(value);
}

int QSpinBox_value(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->value();
}

void QSpinBox_setRange(void* spinbox, int minimum, int maximum) {
    static_cast<QSpinBoxBind*>(spinbox)->setRange(minimum, maximum);
}

int QSpinBox_minimum(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->minimum();
}

int QSpinBox_maximum(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->maximum();
}

void QSpinBox_setMinimum(void* spinbox, int minimum) {
    static_cast<QSpinBoxBind*>(spinbox)->setMinimum(minimum);
}

void QSpinBox_setMaximum(void* spinbox, int maximum) {
    static_cast<QSpinBoxBind*>(spinbox)->setMaximum(maximum);
}

void QSpinBox_setSingleStep(void* spinbox, int step) {
    static_cast<QSpinBoxBind*>(spinbox)->setSingleStep(step);
}

int QSpinBox_singleStep(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->singleStep();
}

void QSpinBox_setPrefix(void* spinbox, const char* prefix) {
    const QString qstr = QString::fromUtf8(prefix);
    static_cast<QSpinBoxBind*>(spinbox)->setPrefix(qstr);
}

const char* QSpinBox_prefix(void* spinbox) {
    const QString qstr = static_cast<QSpinBoxBind*>(spinbox)->prefix();
    return qstr.toUtf8().constData();
}

void QSpinBox_setSuffix(void* spinbox, const char* suffix) {
    const QString qstr = QString::fromUtf8(suffix);
    static_cast<QSpinBoxBind*>(spinbox)->setSuffix(qstr);
}

const char* QSpinBox_suffix(void* spinbox) {
    const QString qstr = static_cast<QSpinBoxBind*>(spinbox)->suffix();
    return qstr.toUtf8().constData();
}

void QSpinBox_setDisplayIntegerBase(void* spinbox, int base) {
    static_cast<QSpinBoxBind*>(spinbox)->setDisplayIntegerBase(base);
}

int QSpinBox_displayIntegerBase(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->displayIntegerBase();
}

void QSpinBox_setWrapping(void* spinbox, bool wrapping) {
    static_cast<QSpinBoxBind*>(spinbox)->setWrapping(wrapping);
}

bool QSpinBox_wrapping(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->wrapping();
}

void QSpinBox_setSpecialValueText(void* spinbox, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QSpinBoxBind*>(spinbox)->setSpecialValueText(qstr);
}

const char* QSpinBox_specialValueText(void* spinbox) {
    const QString qstr = static_cast<QSpinBoxBind*>(spinbox)->specialValueText();
    return qstr.toUtf8().constData();
}

void QSpinBox_setAccelerated(void* spinbox, bool accelerated) {
    static_cast<QSpinBoxBind*>(spinbox)->setAccelerated(accelerated);
}

bool QSpinBox_isAccelerated(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->isAccelerated();
}

void QSpinBox_setReadOnly(void* spinbox, bool read_only) {
    static_cast<QSpinBoxBind*>(spinbox)->setReadOnly(read_only);
}

bool QSpinBox_isReadOnly(void* spinbox) {
    return static_cast<QSpinBoxBind*>(spinbox)->isReadOnly();
}

void QSpinBox_setButtonSymbols(void* spinbox, int button_symbols) {
    static_cast<QSpinBoxBind*>(spinbox)->setButtonSymbols(static_cast<QAbstractSpinBox::ButtonSymbols>(button_symbols));
}

int QSpinBox_buttonSymbols(void* spinbox) {
    return static_cast<int>(static_cast<QSpinBoxBind*>(spinbox)->buttonSymbols());
}

typedef void (*QSpinBox_ValueChangedCallback)(void*, int);
typedef void (*QSpinBox_TextChangedCallback)(void*, const char*);
typedef void (*QSpinBox_EditingFinishedCallback)(void*);

void QSpinBox_setValueChangedCallback(void* spinbox, QSpinBox_ValueChangedCallback callback) {
    static_cast<QSpinBoxBind*>(spinbox)->setValueChangedCallback(callback);
}

void QSpinBox_setTextChangedCallback(void* spinbox, QSpinBox_TextChangedCallback callback) {
    static_cast<QSpinBoxBind*>(spinbox)->setTextChangedCallback(callback);
}

void QSpinBox_setEditingFinishedCallback(void* spinbox, QSpinBox_EditingFinishedCallback callback) {
    static_cast<QSpinBoxBind*>(spinbox)->setEditingFinishedCallback(callback);
}

}
