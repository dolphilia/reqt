#include "../../include/qt6/qcheckbox.h"
#include "QCheckBoxBind.h"
#include <QWidget>
#include <QCheckBox>

extern "C" {

void* QCheckBox_create(const char* text, void* parent) {
    return QCheckBoxBind::create(text, static_cast<QWidget*>(parent));
}

void QCheckBox_delete(void* checkbox) {
    QCheckBoxBind::destroy(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setText(void* checkbox, const char* text) {
    QCheckBoxBind::setText(static_cast<QCheckBox*>(checkbox), text);
}

const char* QCheckBox_text(void* checkbox) {
    return QCheckBoxBind::text(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setChecked(void* checkbox, bool checked) {
    QCheckBoxBind::setChecked(static_cast<QCheckBox*>(checkbox), checked);
}

bool QCheckBox_isChecked(void* checkbox) {
    return QCheckBoxBind::isChecked(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setTristate(void* checkbox, bool tristate) {
    QCheckBoxBind::setTristate(static_cast<QCheckBox*>(checkbox), tristate);
}

bool QCheckBox_isTristate(void* checkbox) {
    return QCheckBoxBind::isTristate(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setCheckState(void* checkbox, int state) {
    QCheckBoxBind::setCheckState(static_cast<QCheckBox*>(checkbox), state);
}

int QCheckBox_checkState(void* checkbox) {
    return QCheckBoxBind::checkState(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setEnabled(void* checkbox, bool enabled) {
    QCheckBoxBind::setEnabled(static_cast<QCheckBox*>(checkbox), enabled);
}

bool QCheckBox_isEnabled(void* checkbox) {
    return QCheckBoxBind::isEnabled(static_cast<QCheckBox*>(checkbox));
}

void QCheckBox_setStateChangedCallback(void* checkbox, QCheckBoxStateChangedCallback callback) {
    QCheckBoxBind::setStateChangedCallback(static_cast<QCheckBox*>(checkbox), callback);
}

void QCheckBox_setToggledCallback(void* checkbox, QCheckBoxToggledCallback callback) {
    QCheckBoxBind::setToggledCallback(static_cast<QCheckBox*>(checkbox), callback);
}

void QCheckBox_setClickedCallback(void* checkbox, QCheckBoxToggledCallback callback) {
    QCheckBoxBind::setClickedCallback(static_cast<QCheckBox*>(checkbox), callback);
}

}
