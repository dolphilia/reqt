#include "QRadioButtonBind.h"
#include "QRadioButtonHandler.h"

QRadioButtonBind::QRadioButtonBind(QWidget* parent)
    : QRadioButton(parent)
    , handler(new QRadioButtonHandler(this)) {
    connect(this, &QRadioButton::toggled, handler, &QRadioButtonHandler::onToggled);
    connect(this, &QRadioButton::clicked, handler, &QRadioButtonHandler::onClicked);
    connect(this, &QRadioButton::pressed, handler, &QRadioButtonHandler::onPressed);
    connect(this, &QRadioButton::released, handler, &QRadioButtonHandler::onReleased);
}

QRadioButtonBind::QRadioButtonBind(const QString& text, QWidget* parent)
    : QRadioButton(text, parent)
    , handler(new QRadioButtonHandler(this)) {
    connect(this, &QRadioButton::toggled, handler, &QRadioButtonHandler::onToggled);
    connect(this, &QRadioButton::clicked, handler, &QRadioButtonHandler::onClicked);
    connect(this, &QRadioButton::pressed, handler, &QRadioButtonHandler::onPressed);
    connect(this, &QRadioButton::released, handler, &QRadioButtonHandler::onReleased);
}

QRadioButtonBind::~QRadioButtonBind() {
    delete handler;
}

void QRadioButtonBind::setToggledCallback(QRadioButton_ToggledCallback callback) const {
    handler->setToggledCallback(callback);
}

void QRadioButtonBind::setClickedCallback(QRadioButton_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QRadioButtonBind::setPressedCallback(QRadioButton_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QRadioButtonBind::setReleasedCallback(QRadioButton_ReleasedCallback callback) const {
    handler->setReleasedCallback(callback);
}
