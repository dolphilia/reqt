#include "QComboBoxBind.h"
#include "QComboBoxHandler.h"

QComboBoxBind::QComboBoxBind(QWidget* parent)
    : QComboBox(parent)
    , handler(new ComboBoxHandler(this)) {
    connect(this, &QComboBox::currentIndexChanged, handler, &ComboBoxHandler::onCurrentIndexChanged);
    connect(this, &QComboBox::currentTextChanged, handler, &ComboBoxHandler::onCurrentTextChanged);
}

QComboBoxBind::~QComboBoxBind() {
    delete handler;
}

void QComboBoxBind::setCurrentIndexChangedCallback(CurrentIndexChangedCallback callback) const {
    handler->setCurrentIndexCallback(callback);
}

void QComboBoxBind::setCurrentTextChangedCallback(CurrentTextChangedCallback callback) const {
    handler->setCurrentTextCallback(callback);
}
