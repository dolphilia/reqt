#include "QLineEditBind.h"

extern "C" {

void* QLineEdit_create(void* parent) {
    return new QLineEditBind(static_cast<QWidget*>(parent));
}

void* QLineEdit_create_2(const char* text, void* parent) {
    return new QLineEditBind(QString::fromUtf8(text), static_cast<QWidget*>(parent));
}

void QLineEdit_delete(void* lineEdit) {
    delete static_cast<QLineEditBind*>(lineEdit);
}

void QLineEdit_setText(void* lineEdit, const char* text) {
    static_cast<QLineEditBind*>(lineEdit)->setText(QString::fromUtf8(text));
}

const char* QLineEdit_text(void* lineEdit) {
    static QString str;
    str = static_cast<QLineEditBind*>(lineEdit)->text();
    return str.toUtf8().constData();
}

void QLineEdit_setPlaceholderText(void* lineEdit, const char* text) {
    static_cast<QLineEditBind*>(lineEdit)->setPlaceholderText(QString::fromUtf8(text));
}

const char* QLineEdit_placeholderText(void* lineEdit) {
    static QString str;
    str = static_cast<QLineEditBind*>(lineEdit)->placeholderText();
    return str.toUtf8().constData();
}

void QLineEdit_setMaxLength(void* lineEdit, int length) {
    static_cast<QLineEditBind*>(lineEdit)->setMaxLength(length);
}

int QLineEdit_maxLength(void* lineEdit) {
    return static_cast<QLineEditBind*>(lineEdit)->maxLength();
}

void QLineEdit_setReadOnly(void* lineEdit, bool readOnly) {
    static_cast<QLineEditBind*>(lineEdit)->setReadOnly(readOnly);
}

bool QLineEdit_isReadOnly(void* lineEdit) {
    return static_cast<QLineEditBind*>(lineEdit)->isReadOnly();
}

void QLineEdit_setClearButtonEnabled(void* lineEdit, bool enable) {
    static_cast<QLineEditBind*>(lineEdit)->setClearButtonEnabled(enable);
}

bool QLineEdit_isClearButtonEnabled(void* lineEdit) {
    return static_cast<QLineEditBind*>(lineEdit)->isClearButtonEnabled();
}

void QLineEdit_setEnabled(void* lineEdit, bool enabled) {
    static_cast<QLineEditBind*>(lineEdit)->setEnabled(enabled);
}

bool QLineEdit_isEnabled(void* lineEdit) {
    return static_cast<QLineEditBind*>(lineEdit)->isEnabled();
}

void QLineEdit_clear(void* lineEdit) {
    static_cast<QLineEditBind*>(lineEdit)->clear();
}

void QLineEdit_selectAll(void* lineEdit) {
    static_cast<QLineEditBind*>(lineEdit)->selectAll();
}

void QLineEdit_setEchoMode(void* lineEdit, int mode) {
    static_cast<QLineEditBind*>(lineEdit)->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
}

int QLineEdit_echoMode(void* lineEdit) {
    return static_cast<int>(static_cast<QLineEditBind*>(lineEdit)->echoMode());
}

typedef void (*QLineEdit_TextChangedCallback)(void*, const char*);
typedef void (*QLineEdit_TextEditedCallback)(void*, const char*);
typedef void (*QLineEdit_ReturnPressedCallback)(void*, const char*);

void QLineEdit_setTextChangedCallback(void* lineEdit, QLineEdit_TextChangedCallback callback) {
    static_cast<QLineEditBind*>(lineEdit)->setTextChangedCallback(callback);
}

void QLineEdit_setTextEditedCallback(void* lineEdit, QLineEdit_TextEditedCallback callback) {
    static_cast<QLineEditBind*>(lineEdit)->setTextEditedCallback(callback);
}

void QLineEdit_setReturnPressedCallback(void* lineEdit, QLineEdit_ReturnPressedCallback callback) {
    static_cast<QLineEditBind*>(lineEdit)->setReturnPressedCallback(callback);
}

}
