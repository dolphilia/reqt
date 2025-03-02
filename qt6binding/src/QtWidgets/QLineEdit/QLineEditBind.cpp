#include "QLineEditBind.h"
#include "QLineEditHandler.h"
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
