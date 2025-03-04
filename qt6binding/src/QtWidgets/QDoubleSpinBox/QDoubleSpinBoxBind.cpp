#include "QDoubleSpinBoxBind.h"
#include "QDoubleSpinBoxHandler.h"

QDoubleSpinBoxBind::QDoubleSpinBoxBind(QWidget* parent)
    : QDoubleSpinBox(parent)
    , handler(new QDoubleSpinBoxHandler(this)) {
    connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), handler, &QDoubleSpinBoxHandler::onValueChanged);
    connect(this, &QDoubleSpinBox::editingFinished, handler, &QDoubleSpinBoxHandler::onEditingFinished);
}

QDoubleSpinBoxBind::~QDoubleSpinBoxBind() {
    delete handler;
}

void QDoubleSpinBoxBind::setValueChangedCallback(QDoubleSpinBox_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QDoubleSpinBoxBind::setEditingFinishedCallback(QDoubleSpinBox_EditingFinishedCallback callback) const {
    handler->setEditingFinishedCallback(callback);
}
