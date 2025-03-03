#include "QLineEditBind.h"
#include <QString>

extern "C" {

void* QLineEdit_create(void* parent) {
    return new QLineEditBind(static_cast<QWidget*>(parent));
}

void* QLineEdit_create_2(const char* text, void* parent) {
    return new QLineEditBind(QString::fromUtf8(text), reinterpret_cast<QWidget*>(parent));
}

void QLineEdit_delete(void* lineEdit) {
    delete static_cast<QLineEditBind*>(lineEdit);
}

void QLineEdit_setText(void* lineEdit, const char* text) {
    if (lineEdit && text) {
        static_cast<QLineEditBind*>(lineEdit)->setText(QString::fromUtf8(text));
    }
}

const char* QLineEdit_text(void* lineEdit) {
    if (lineEdit) {
        static QString str;
        str = static_cast<QLineEditBind*>(lineEdit)->text();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QLineEdit_setPlaceholderText(void* lineEdit, const char* text) {
    if (lineEdit && text) {
        static_cast<QLineEditBind*>(lineEdit)->setPlaceholderText(QString::fromUtf8(text));
    }
}

const char* QLineEdit_placeholderText(void* lineEdit) {
    if (lineEdit) {
        static QString str;
        str = static_cast<QLineEditBind*>(lineEdit)->placeholderText();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QLineEdit_setMaxLength(void* lineEdit, int length) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setMaxLength(length);
    }
}

int QLineEdit_maxLength(void* lineEdit) {
    return lineEdit ? static_cast<QLineEditBind*>(lineEdit)->maxLength() : 0;
}

void QLineEdit_setReadOnly(void* lineEdit, bool readOnly) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setReadOnly(readOnly);
    }
}

bool QLineEdit_isReadOnly(void* lineEdit) {
    return lineEdit ? static_cast<QLineEditBind*>(lineEdit)->isReadOnly() : false;
}

void QLineEdit_setClearButtonEnabled(void* lineEdit, bool enable) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setClearButtonEnabled(enable);
    }
}

bool QLineEdit_isClearButtonEnabled(void* lineEdit) {
    return lineEdit ? static_cast<QLineEditBind*>(lineEdit)->isClearButtonEnabled() : false;
}

void QLineEdit_setEnabled(void* lineEdit, bool enabled) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setEnabled(enabled);
    }
}

bool QLineEdit_isEnabled(void* lineEdit) {
    return lineEdit ? static_cast<QLineEditBind*>(lineEdit)->isEnabled() : false;
}

void QLineEdit_clear(void* lineEdit) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->clear();
    }
}

void QLineEdit_selectAll(void* lineEdit) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->selectAll();
    }
}

void QLineEdit_setEchoMode(void* lineEdit, int mode) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }
}

int QLineEdit_echoMode(void* lineEdit) {
    return lineEdit ? static_cast<int>(static_cast<QLineEditBind*>(lineEdit)->echoMode()) : 0;
}

void QLineEdit_setTextChangedCallback(void* lineEdit, void (*callback)(void*, const char*)) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setTextChangedCallback(callback);
    }
}

void QLineEdit_setTextEditedCallback(void* lineEdit, void (*callback)(void*, const char*)) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setTextEditedCallback(callback);
    }
}

void QLineEdit_setReturnPressedCallback(void* lineEdit, void (*callback)(void*, const char*)) {
    if (lineEdit) {
        static_cast<QLineEditBind*>(lineEdit)->setReturnPressedCallback(callback);
    }
}

}
