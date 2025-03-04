#include "QComboBoxBind.h"
#include "QComboBoxHandler.h"

QComboBoxBind::QComboBoxBind(QWidget* parent)
    : QComboBox(parent)
    , handler(new QComboBoxHandler(this)) {
    connect(this, &QComboBox::currentIndexChanged, handler, &QComboBoxHandler::onCurrentIndexChanged);
    connect(this, &QComboBox::currentTextChanged, handler, &QComboBoxHandler::onCurrentTextChanged);
}

QComboBoxBind::~QComboBoxBind() {
    delete handler;
}

void QComboBoxBind::setCurrentIndexChangedCallback(QComboBox_CurrentIndexChangedCallback callback) const {
    handler->setCurrentIndexCallback(callback);
}

void QComboBoxBind::setCurrentTextChangedCallback(QComboBox_CurrentTextChangedCallback callback) const {
    handler->setCurrentTextCallback(callback);
}
