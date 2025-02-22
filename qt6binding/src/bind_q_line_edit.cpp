#include "bind_q_line_edit.h"
#include "handler_line_edit_text.h"
#include <QString>

QLineEdit* QLineEditBind::create(const char* text, QWidget* parent) {
    if (text) {
        return new QLineEdit(QString::fromUtf8(text), parent);
    }
    return new QLineEdit(parent);
}

void QLineEditBind::destroy(QLineEdit* lineEdit) {
    if (lineEdit) {
        // ハンドラーの削除
        QObject* handler = lineEdit->findChild<LineEditTextHandler*>();
        if (handler) {
            delete handler;
        }
        delete lineEdit;
    }
}

void QLineEditBind::setText(QLineEdit* lineEdit, const char* text) {
    if (lineEdit && text) {
        lineEdit->setText(QString::fromUtf8(text));
    }
}

const char* QLineEditBind::text(QLineEdit* lineEdit) {
    if (lineEdit) {
        static QString str;
        str = lineEdit->text();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QLineEditBind::setPlaceholderText(QLineEdit* lineEdit, const char* text) {
    if (lineEdit && text) {
        lineEdit->setPlaceholderText(QString::fromUtf8(text));
    }
}

const char* QLineEditBind::placeholderText(QLineEdit* lineEdit) {
    if (lineEdit) {
        static QString str;
        str = lineEdit->placeholderText();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QLineEditBind::setMaxLength(QLineEdit* lineEdit, int length) {
    if (lineEdit) {
        lineEdit->setMaxLength(length);
    }
}

int QLineEditBind::maxLength(QLineEdit* lineEdit) {
    return lineEdit ? lineEdit->maxLength() : 0;
}

void QLineEditBind::setReadOnly(QLineEdit* lineEdit, bool readOnly) {
    if (lineEdit) {
        lineEdit->setReadOnly(readOnly);
    }
}

bool QLineEditBind::isReadOnly(QLineEdit* lineEdit) {
    return lineEdit ? lineEdit->isReadOnly() : false;
}

void QLineEditBind::setClearButtonEnabled(QLineEdit* lineEdit, bool enable) {
    if (lineEdit) {
        lineEdit->setClearButtonEnabled(enable);
    }
}

bool QLineEditBind::isClearButtonEnabled(QLineEdit* lineEdit) {
    return lineEdit ? lineEdit->isClearButtonEnabled() : false;
}

void QLineEditBind::setEnabled(QLineEdit* lineEdit, bool enabled) {
    if (lineEdit) {
        lineEdit->setEnabled(enabled);
    }
}

bool QLineEditBind::isEnabled(QLineEdit* lineEdit) {
    return lineEdit ? lineEdit->isEnabled() : false;
}

void QLineEditBind::clear(QLineEdit* lineEdit) {
    if (lineEdit) {
        lineEdit->clear();
    }
}

void QLineEditBind::selectAll(QLineEdit* lineEdit) {
    if (lineEdit) {
        lineEdit->selectAll();
    }
}

void QLineEditBind::setEchoMode(QLineEdit* lineEdit, int mode) {
    if (lineEdit) {
        lineEdit->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }
}

int QLineEditBind::echoMode(QLineEdit* lineEdit) {
    return lineEdit ? static_cast<int>(lineEdit->echoMode()) : 0;
}

void QLineEditBind::setTextChangedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback) {
    if (lineEdit) {
        // 既存のハンドラーを削除
        QObject* existingHandler = lineEdit->findChild<LineEditTextHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        LineEditTextHandler* handler = new LineEditTextHandler(callback);
        handler->setParent(lineEdit);
        QObject::connect(lineEdit, &QLineEdit::textChanged, handler, &LineEditTextHandler::onTextChanged);
    }
}

void QLineEditBind::setTextEditedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback) {
    if (lineEdit) {
        // 既存のハンドラーを削除
        QObject* existingHandler = lineEdit->findChild<LineEditTextHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        LineEditTextHandler* handler = new LineEditTextHandler(callback);
        handler->setParent(lineEdit);
        QObject::connect(lineEdit, &QLineEdit::textEdited, handler, &LineEditTextHandler::onTextChanged);
    }
}

void QLineEditBind::setReturnPressedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback) {
    if (lineEdit) {
        // 既存のハンドラーを削除
        QObject* existingHandler = lineEdit->findChild<LineEditTextHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        LineEditTextHandler* handler = new LineEditTextHandler(callback);
        handler->setParent(lineEdit);
        QObject::connect(lineEdit, &QLineEdit::returnPressed, [handler, lineEdit]() {
            handler->onTextChanged(lineEdit->text());
        });
    }
}

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
