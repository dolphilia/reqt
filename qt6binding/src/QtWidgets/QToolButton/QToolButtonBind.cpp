#include "QToolButtonBind.h"
#include "QToolButtonHandler.h"

QToolButtonBind::QToolButtonBind(QWidget* parent)
    : QToolButton(parent)
    , handler(new QToolButtonHandler(this)) {
    connect(this, &QToolButton::clicked, handler, &QToolButtonHandler::onClicked);
    connect(this, &QToolButton::toggled, handler, &QToolButtonHandler::onToggled);
    connect(this, &QToolButton::triggered, handler, &QToolButtonHandler::onTriggered);
}

QToolButtonBind::~QToolButtonBind() {
    delete handler;
}

void QToolButtonBind::setClickedCallback(QToolButton_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QToolButtonBind::setToggledCallback(QToolButton_ToggledCallback callback) const {
    handler->setToggledCallback(callback);
}

void QToolButtonBind::setTriggeredCallback(QToolButton_TriggeredCallback callback) const {
    handler->setTriggeredCallback(callback);
}
