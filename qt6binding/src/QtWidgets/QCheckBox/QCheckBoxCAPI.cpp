#include "qcheckbox.h"
#include "QCheckBoxBind.h"

extern "C" {

void* QCheckBox_create(const char* text, void* parent) {
    const QString qstr = QString::fromUtf8(text);
    return new QCheckBoxBind(qstr, static_cast<QWidget*>(parent));
}

void QCheckBox_delete(void* checkbox) {
    delete static_cast<QCheckBoxBind*>(checkbox);
}

void QCheckBox_setText(void* checkbox, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QCheckBoxBind*>(checkbox)->setText(qstr);
}

const char* QCheckBox_text(void* checkbox) {
    const QString qstr = static_cast<QCheckBoxBind*>(checkbox)->text();
    return qstr.toUtf8().constData();
}

void QCheckBox_setChecked(void* checkbox, bool checked) {
    static_cast<QCheckBoxBind*>(checkbox)->setChecked(checked);
}

bool QCheckBox_isChecked(void* checkbox) {
    return static_cast<QCheckBoxBind*>(checkbox)->isChecked();
}

void QCheckBox_setTristate(void* checkbox, bool tristate) {
    static_cast<QCheckBoxBind*>(checkbox)->setTristate(tristate);
}

bool QCheckBox_isTristate(void* checkbox) {
    return static_cast<QCheckBoxBind*>(checkbox)->isTristate();
}

void QCheckBox_setCheckState(void* checkbox, int state) {
    static_cast<QCheckBoxBind*>(checkbox)->setCheckState(static_cast<Qt::CheckState>(state));
}

int QCheckBox_checkState(void* checkbox) {
    return static_cast<QCheckBoxBind*>(checkbox)->checkState();
}

void QCheckBox_setEnabled(void* checkbox, bool enabled) {
    static_cast<QCheckBoxBind*>(checkbox)->setEnabled(enabled);
}

bool QCheckBox_isEnabled(void* checkbox) {
    return static_cast<QCheckBoxBind*>(checkbox)->isEnabled();
}

void QCheckBox_setStateChangedCallback(void* checkbox, StateChangedCallback callback) {
    static_cast<QCheckBoxBind*>(checkbox)->setStateChangedCallback(callback);
}

void QCheckBox_setToggledCallback(void* checkbox, ToggledCallback callback) {
    static_cast<QCheckBoxBind*>(checkbox)->setToggledCallback(callback);
}

void QCheckBox_setClickedCallback(void* checkbox, Callback callback) {
    static_cast<QCheckBoxBind*>(checkbox)->setClickedCallback(callback);
}

}
