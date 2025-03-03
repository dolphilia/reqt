#include "QDoubleSpinBoxBind.h"
#include "QDoubleSpinBoxHandler.h"

QDoubleSpinBoxBind::QDoubleSpinBoxBind(QWidget* parent)
    : QDoubleSpinBox(parent)
    , handler(new DoubleSpinBoxHandler(this)) {
    connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), handler, &DoubleSpinBoxHandler::onValueChanged);
    connect(this, &QDoubleSpinBox::editingFinished, handler, &DoubleSpinBoxHandler::onEditingFinished);
}

QDoubleSpinBoxBind::~QDoubleSpinBoxBind() {
    delete handler;
}

void QDoubleSpinBoxBind::setValueChangedCallback(ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QDoubleSpinBoxBind::setEditingFinishedCallback(EditingFinishedCallback callback) const {
    handler->setEditingFinishedCallback(callback);
}
