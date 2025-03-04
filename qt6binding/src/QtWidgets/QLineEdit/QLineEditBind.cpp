#include "QLineEditBind.h"
#include <QString>

QLineEditBind::QLineEditBind(QWidget* parent)
    : QLineEdit(parent)
    , handler(new QLineEditHandler(this)) {
    connect(this, &QLineEdit::textChanged, handler, &QLineEditHandler::onTextChanged);
    connect(this, &QLineEdit::textEdited, handler, &QLineEditHandler::onTextEdited);
    connect(this, &QLineEdit::returnPressed, handler, &QLineEditHandler::onReturnPressed);
}

QLineEditBind::QLineEditBind(const QString& text, QWidget* parent)
    : QLineEdit(text, parent)
    , handler(new QLineEditHandler(this)) {
    connect(this, &QLineEdit::textChanged, handler, &QLineEditHandler::onTextChanged);
    connect(this, &QLineEdit::textEdited, handler, &QLineEditHandler::onTextEdited);
    connect(this, &QLineEdit::returnPressed, handler, &QLineEditHandler::onReturnPressed);
}

QLineEditBind::~QLineEditBind() {
    delete handler;
}

void QLineEditBind::setTextChangedCallback(QLineEdit_TextChangedCallback callback) const {
    handler->setTextChangedCallback(callback);
}

void QLineEditBind::setTextEditedCallback(QLineEdit_TextEditedCallback callback) const {
    handler->setTextEditedCallback(callback);
}

void QLineEditBind::setReturnPressedCallback(QLineEdit_ReturnPressedCallback callback) const {
    handler->setReturnPressedCallback(callback);
}
