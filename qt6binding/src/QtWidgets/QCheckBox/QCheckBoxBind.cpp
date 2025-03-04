#include "QCheckBoxBind.h"
#include "QCheckBoxHandler.h"

QCheckBoxBind::QCheckBoxBind(QString qstr, QWidget* parent)
    : QCheckBox(qstr, parent)
    , handler(new QCheckBoxHandler(this)) {
    connect(this, &QCheckBox::checkStateChanged, handler, &QCheckBoxHandler::onStateChanged);
    connect(this, &QCheckBox::toggled, handler, &QCheckBoxHandler::onToggled);
    connect(this, &QAbstractButton::clicked, handler, &QCheckBoxHandler::onClicked);
}

QCheckBoxBind::~QCheckBoxBind() {
    delete handler;
}

void QCheckBoxBind::setStateChangedCallback(QCheckBox_StateChangedCallback callback) const {
    handler->setStateChangedCallback(callback);
}

void QCheckBoxBind::setToggledCallback(QCheckBox_ToggledCallback callback) const {
    handler->setToggledCallback(callback);
}

void QCheckBoxBind::setClickedCallback(QCheckBox_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}