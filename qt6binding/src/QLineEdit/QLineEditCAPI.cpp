#include "QLineEditBind.h"

extern "C" {

void* QLineEdit_create(const char* text, void* parent) {
    return QLineEditBind::create(text, static_cast<QWidget*>(parent));
}

void QLineEdit_delete(void* lineEdit) {
    QLineEditBind::destroy(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setText(void* lineEdit, const char* text) {
    QLineEditBind::setText(static_cast<QLineEdit*>(lineEdit), text);
}

const char* QLineEdit_text(void* lineEdit) {
    return QLineEditBind::text(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setPlaceholderText(void* lineEdit, const char* text) {
    QLineEditBind::setPlaceholderText(static_cast<QLineEdit*>(lineEdit), text);
}

const char* QLineEdit_placeholderText(void* lineEdit) {
    return QLineEditBind::placeholderText(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setMaxLength(void* lineEdit, int length) {
    QLineEditBind::setMaxLength(static_cast<QLineEdit*>(lineEdit), length);
}

int QLineEdit_maxLength(void* lineEdit) {
    return QLineEditBind::maxLength(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setReadOnly(void* lineEdit, bool readOnly) {
    QLineEditBind::setReadOnly(static_cast<QLineEdit*>(lineEdit), readOnly);
}

bool QLineEdit_isReadOnly(void* lineEdit) {
    return QLineEditBind::isReadOnly(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setClearButtonEnabled(void* lineEdit, bool enable) {
    QLineEditBind::setClearButtonEnabled(static_cast<QLineEdit*>(lineEdit), enable);
}

bool QLineEdit_isClearButtonEnabled(void* lineEdit) {
    return QLineEditBind::isClearButtonEnabled(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setEnabled(void* lineEdit, bool enabled) {
    QLineEditBind::setEnabled(static_cast<QLineEdit*>(lineEdit), enabled);
}

bool QLineEdit_isEnabled(void* lineEdit) {
    return QLineEditBind::isEnabled(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_clear(void* lineEdit) {
    QLineEditBind::clear(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_selectAll(void* lineEdit) {
    QLineEditBind::selectAll(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setEchoMode(void* lineEdit, int mode) {
    QLineEditBind::setEchoMode(static_cast<QLineEdit*>(lineEdit), mode);
}

int QLineEdit_echoMode(void* lineEdit) {
    return QLineEditBind::echoMode(static_cast<QLineEdit*>(lineEdit));
}

void QLineEdit_setTextChangedCallback(void* lineEdit, QLineEditTextChangedCallback callback) {
    QLineEditBind::setTextChangedCallback(static_cast<QLineEdit*>(lineEdit), callback);
}

void QLineEdit_setTextEditedCallback(void* lineEdit, QLineEditTextChangedCallback callback) {
    QLineEditBind::setTextEditedCallback(static_cast<QLineEdit*>(lineEdit), callback);
}

void QLineEdit_setReturnPressedCallback(void* lineEdit, QLineEditTextChangedCallback callback) {
    QLineEditBind::setReturnPressedCallback(static_cast<QLineEdit*>(lineEdit), callback);
}

}
