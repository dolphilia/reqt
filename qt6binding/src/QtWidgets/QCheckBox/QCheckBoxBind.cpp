#include "QCheckBoxBind.h"
#include "QCheckBoxHandler.h"

QCheckBoxBind::QCheckBoxBind(QString qstr, QWidget* parent)
    : QCheckBox(qstr, parent)
    , handler(new CheckBoxHandler(this)) {
    connect(this, &QCheckBox::checkStateChanged, handler, &CheckBoxHandler::onStateChanged);
    connect(this, &QCheckBox::toggled, handler, &CheckBoxHandler::onToggled);
    connect(this, &QAbstractButton::clicked, handler, &CheckBoxHandler::onClicked);
}

QCheckBoxBind::~QCheckBoxBind() {
    delete handler;
}

void QCheckBoxBind::setStateChangedCallback(StateCallback callback) const {
    handler->setStateChangedCallback(callback);
}

void QCheckBoxBind::setToggledCallback(ToggleCallback callback) const {
    handler->setToggledCallback(callback);
}

void QCheckBoxBind::setClickedCallback(ClickCallback callback) const {
    handler->setClickedCallback(callback);
}