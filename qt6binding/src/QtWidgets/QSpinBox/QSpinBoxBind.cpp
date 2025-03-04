#include "QSpinBoxBind.h"
#include "QSpinBoxHandler.h"

QSpinBoxBind::QSpinBoxBind(QWidget* parent)
    : QSpinBox(parent)
    , handler(new QSpinBoxHandler(this)) {
    connect(this, QOverload<int>::of(&QSpinBox::valueChanged), handler, &QSpinBoxHandler::onValueChanged);
    connect(this, &QSpinBox::textChanged, handler, &QSpinBoxHandler::onTextChanged);
    connect(this, &QSpinBox::editingFinished, handler, &QSpinBoxHandler::onEditingFinished);
}

QSpinBoxBind::~QSpinBoxBind() {
    delete handler;
}

void QSpinBoxBind::setValueChangedCallback(QSpinBox_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QSpinBoxBind::setTextChangedCallback(QSpinBox_TextChangedCallback callback) const {
    handler->setTextChangedCallback(callback);
}

void QSpinBoxBind::setEditingFinishedCallback(QSpinBox_EditingFinishedCallback callback) const {
    handler->setEditingFinishedCallback(callback);
}
