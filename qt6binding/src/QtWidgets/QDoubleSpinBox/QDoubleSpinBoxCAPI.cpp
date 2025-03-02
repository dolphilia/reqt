#include "qdoublespinbox.h"
#include "QDoubleSpinBoxBind.h"
#include "QDoubleSpinBoxHandler.h"

extern "C" {

void* QDoubleSpinBox_create(void* parent)
{
    return new BindQDoubleSpinBox(reinterpret_cast<QWidget*>(parent));
}

void QDoubleSpinBox_delete(void* double_spin_box)
{
    delete static_cast<BindQDoubleSpinBox*>(double_spin_box);
}

void QDoubleSpinBox_setValue(void* double_spin_box, double value)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setValue(value);
}

double QDoubleSpinBox_value(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->value();
}

void QDoubleSpinBox_setRange(void* double_spin_box, double minimum, double maximum)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setRange(minimum, maximum);
}

double QDoubleSpinBox_minimum(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->minimum();
}

double QDoubleSpinBox_maximum(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->maximum();
}

void QDoubleSpinBox_setSingleStep(void* double_spin_box, double step)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setSingleStep(step);
}

double QDoubleSpinBox_singleStep(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->singleStep();
}

void QDoubleSpinBox_setDecimals(void* double_spin_box, int decimals)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setDecimals(decimals);
}

int QDoubleSpinBox_decimals(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->decimals();
}

void QDoubleSpinBox_setPrefix(void* double_spin_box, const char* prefix)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setPrefix(QString::fromUtf8(prefix));
}

const char* QDoubleSpinBox_prefix(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->prefix().toUtf8().constData();
}

void QDoubleSpinBox_setSuffix(void* double_spin_box, const char* suffix)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setSuffix(QString::fromUtf8(suffix));
}

const char* QDoubleSpinBox_suffix(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->suffix().toUtf8().constData();
}

void QDoubleSpinBox_setWrapping(void* double_spin_box, bool wrapping)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setWrapping(wrapping);
}

bool QDoubleSpinBox_wrapping(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->wrapping();
}

void QDoubleSpinBox_setSpecialValueText(void* double_spin_box, const char* text)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->setSpecialValueText(QString::fromUtf8(text));
}

const char* QDoubleSpinBox_specialValueText(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->specialValueText().toUtf8().constData();
}

void QDoubleSpinBox_stepUp(void* double_spin_box)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->stepUp();
}

void QDoubleSpinBox_stepDown(void* double_spin_box)
{
    static_cast<BindQDoubleSpinBox*>(double_spin_box)->stepDown();
}

const char* QDoubleSpinBox_text(void* double_spin_box)
{
    return static_cast<BindQDoubleSpinBox*>(double_spin_box)->text().toUtf8().constData();
}

void QDoubleSpinBox_setValueChangedCallback(void* double_spin_box, QDoubleSpinBoxValueChangedCallback callback)
{
    BindQDoubleSpinBox* spin_box = static_cast<BindQDoubleSpinBox*>(double_spin_box);
    DoubleSpinBoxHandler* handler = spin_box->handler();
    if (!handler) {
        handler = new DoubleSpinBoxHandler(spin_box);
        spin_box->setDoubleSpinBoxHandler(handler);
    }
    handler->setValueChangedCallback(callback);
}

void QDoubleSpinBox_setEditingFinishedCallback(void* double_spin_box, QDoubleSpinBoxEditingFinishedCallback callback)
{
    BindQDoubleSpinBox* spin_box = static_cast<BindQDoubleSpinBox*>(double_spin_box);
    DoubleSpinBoxHandler* handler = spin_box->handler();
    if (!handler) {
        handler = new DoubleSpinBoxHandler(spin_box);
        spin_box->setDoubleSpinBoxHandler(handler);
    }
    handler->setEditingFinishedCallback(callback);
}

}
