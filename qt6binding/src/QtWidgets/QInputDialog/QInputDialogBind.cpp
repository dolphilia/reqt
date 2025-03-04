#include "QInputDialogBind.h"
#include "QInputDialogHandler.h"

QInputDialogBind::QInputDialogBind(QWidget* parent, Qt::WindowFlags flags)
    : QInputDialog(parent, flags)
    , handler(new QInputDialogHandler(this)) {
    connect(this, &QInputDialog::doubleValueChanged, handler, &QInputDialogHandler::onDoubleValueChanged);
    connect(this, &QInputDialog::doubleValueSelected, handler, &QInputDialogHandler::onDoubleValueSelected);
    connect(this, &QInputDialog::intValueChanged, handler, &QInputDialogHandler::onIntValueChanged);
    connect(this, &QInputDialog::intValueSelected, handler, &QInputDialogHandler::onIntValueSelected);
    connect(this, &QInputDialog::textValueChanged, handler, &QInputDialogHandler::onTextValueChanged);
    connect(this, &QInputDialog::textValueSelected, handler, &QInputDialogHandler::onTextValueSelected);
}

QInputDialogBind::~QInputDialogBind() {
    delete handler;
}

void QInputDialogBind::setDoubleValueChangedCallback(QInputDialog_DoubleValueChangedCallback callback) const {
    handler->setDoubleValueChangedCallback(callback);
}

void QInputDialogBind::setDoubleValueSelectedCallback(QInputDialog_DoubleValueSelectedCallback callback) const {
    handler->setDoubleValueSelectedCallback(callback);
}

void QInputDialogBind::setIntValueChangedCallback(QInputDialog_IntValueChangedCallback callback) const {
    handler->setIntValueChangedCallback(callback);
}

void QInputDialogBind::setIntValueSelectedCallback(QInputDialog_IntValueSelectedCallback callback) const {
    handler->setIntValueSelectedCallback(callback);
}

void QInputDialogBind::setTextValueChangedCallback(QInputDialog_TextValueChangedCallback callback) const {
    handler->setTextValueChangedCallback(callback);
}

void QInputDialogBind::setTextValueSelectedCallback(QInputDialog_TextValueSelectedCallback callback) const {
    handler->setTextValueSelectedCallback(callback);
}
