#include "QLineEditBind.h"
#include <QString>

QLineEditBind::QLineEditBind(QWidget* parent)
    : QLineEdit(parent)
    , handler(new LineEditHandler(this))
{
    connect(this, &QLineEdit::textChanged, handler, &LineEditHandler::onTextChanged);
    connect(this, &QLineEdit::textEdited, handler, &LineEditHandler::onTextEdited);
    connect(this, &QLineEdit::returnPressed, handler, &LineEditHandler::onReturnPressed);
}

QLineEditBind::QLineEditBind(const QString& text, QWidget* parent)
    : QLineEdit(text, parent)
    , handler(new LineEditHandler(this))
{
    connect(this, &QLineEdit::textChanged, handler, &LineEditHandler::onTextChanged);
    connect(this, &QLineEdit::textEdited, handler, &LineEditHandler::onTextEdited);
    connect(this, &QLineEdit::returnPressed, handler, &LineEditHandler::onReturnPressed);
}

QLineEditBind::~QLineEditBind() {
    delete handler;
}

void QLineEditBind::setTextChangedCallback(TextChangedCallback callback) const {
    handler->setTextChangedCallback(callback);
}

void QLineEditBind::setTextEditedCallback(TextChangedCallback callback) const {
    handler->setTextEditedCallback(callback);
}

void QLineEditBind::setReturnPressedCallback(TextChangedCallback callback) const {
    handler->setReturnPressedCallback(callback);
}
