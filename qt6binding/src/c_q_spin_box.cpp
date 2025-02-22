#include "c_q_spin_box.h"
#include "bind_q_spin_box.h"
#include "handler_spin_box.h"
#include <QString>

extern "C" {

void* QSpinBox_create(void* parent)
{
    return new BindQSpinBox(reinterpret_cast<QWidget*>(parent));
}

void QSpinBox_delete(void* spin_box)
{
    delete static_cast<BindQSpinBox*>(spin_box);
}

void QSpinBox_setValue(void* spin_box, int value)
{
    static_cast<BindQSpinBox*>(spin_box)->setValue(value);
}

int QSpinBox_value(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->value();
}

void QSpinBox_setRange(void* spin_box, int minimum, int maximum)
{
    static_cast<BindQSpinBox*>(spin_box)->setRange(minimum, maximum);
}

int QSpinBox_minimum(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->minimum();
}

int QSpinBox_maximum(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->maximum();
}

void QSpinBox_setMinimum(void* spin_box, int minimum)
{
    static_cast<BindQSpinBox*>(spin_box)->setMinimum(minimum);
}

void QSpinBox_setMaximum(void* spin_box, int maximum)
{
    static_cast<BindQSpinBox*>(spin_box)->setMaximum(maximum);
}

void QSpinBox_setSingleStep(void* spin_box, int step)
{
    static_cast<BindQSpinBox*>(spin_box)->setSingleStep(step);
}

int QSpinBox_singleStep(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->singleStep();
}

void QSpinBox_setPrefix(void* spin_box, const char* prefix)
{
    static_cast<BindQSpinBox*>(spin_box)->setPrefix(QString::fromUtf8(prefix));
}

const char* QSpinBox_prefix(void* spin_box)
{
    QString prefix = static_cast<BindQSpinBox*>(spin_box)->prefix();
    return qstrdup(prefix.toUtf8().constData());
}

void QSpinBox_setSuffix(void* spin_box, const char* suffix)
{
    static_cast<BindQSpinBox*>(spin_box)->setSuffix(QString::fromUtf8(suffix));
}

const char* QSpinBox_suffix(void* spin_box)
{
    QString suffix = static_cast<BindQSpinBox*>(spin_box)->suffix();
    return qstrdup(suffix.toUtf8().constData());
}

void QSpinBox_setDisplayIntegerBase(void* spin_box, int base)
{
    static_cast<BindQSpinBox*>(spin_box)->setDisplayIntegerBase(base);
}

int QSpinBox_displayIntegerBase(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->displayIntegerBase();
}

void QSpinBox_setWrapping(void* spin_box, bool wrapping)
{
    static_cast<BindQSpinBox*>(spin_box)->setWrapping(wrapping);
}

bool QSpinBox_wrapping(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->wrapping();
}

void QSpinBox_setSpecialValueText(void* spin_box, const char* text)
{
    static_cast<BindQSpinBox*>(spin_box)->setSpecialValueText(QString::fromUtf8(text));
}

const char* QSpinBox_specialValueText(void* spin_box)
{
    QString text = static_cast<BindQSpinBox*>(spin_box)->specialValueText();
    return qstrdup(text.toUtf8().constData());
}

void QSpinBox_setAccelerated(void* spin_box, bool accelerated)
{
    static_cast<BindQSpinBox*>(spin_box)->setAccelerated(accelerated);
}

bool QSpinBox_isAccelerated(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->isAccelerated();
}

void QSpinBox_setReadOnly(void* spin_box, bool read_only)
{
    static_cast<BindQSpinBox*>(spin_box)->setReadOnly(read_only);
}

bool QSpinBox_isReadOnly(void* spin_box)
{
    return static_cast<BindQSpinBox*>(spin_box)->isReadOnly();
}

void QSpinBox_setButtonSymbols(void* spin_box, int button_symbols)
{
    static_cast<BindQSpinBox*>(spin_box)->setButtonSymbols(static_cast<QAbstractSpinBox::ButtonSymbols>(button_symbols));
}

int QSpinBox_buttonSymbols(void* spin_box)
{
    return static_cast<int>(static_cast<BindQSpinBox*>(spin_box)->buttonSymbols());
}

void QSpinBox_setValueChangedCallback(void* spin_box, QSpinBoxValueChangedCallback callback)
{
    BindQSpinBox* qspin_box = static_cast<BindQSpinBox*>(spin_box);
    SpinBoxHandler* handler = qspin_box->handler();
    if (!handler) {
        handler = new SpinBoxHandler(qspin_box);
        qspin_box->setSpinBoxHandler(handler);
    }
    handler->setValueChangedCallback(callback);
}

void QSpinBox_setTextChangedCallback(void* spin_box, QSpinBoxTextChangedCallback callback)
{
    BindQSpinBox* qspin_box = static_cast<BindQSpinBox*>(spin_box);
    SpinBoxHandler* handler = qspin_box->handler();
    if (!handler) {
        handler = new SpinBoxHandler(qspin_box);
        qspin_box->setSpinBoxHandler(handler);
    }
    handler->setTextChangedCallback(callback);
}

void QSpinBox_setEditingFinishedCallback(void* spin_box, QSpinBoxEditingFinishedCallback callback)
{
    BindQSpinBox* qspin_box = static_cast<BindQSpinBox*>(spin_box);
    SpinBoxHandler* handler = qspin_box->handler();
    if (!handler) {
        handler = new SpinBoxHandler(qspin_box);
        qspin_box->setSpinBoxHandler(handler);
    }
    handler->setEditingFinishedCallback(callback);
}

}
