#include "QPushButtonBind.h"
#include "QPushButtonHandler.h"

QPushButtonBind::QPushButtonBind(const char* text, QWidget* parent)
    : QPushButton(text ? QString::fromUtf8(text) : QString(), parent)
    , handler(new ButtonClickHandler(this)) {
    connect(this, &QPushButton::clicked, handler, &ButtonClickHandler::onClicked);
    connect(this, &QPushButton::pressed, handler, &ButtonClickHandler::onPressed);
    connect(this, &QPushButton::released, handler, &ButtonClickHandler::onReleased);
}

QPushButtonBind::~QPushButtonBind() {
    delete handler;
}

void QPushButtonBind::setClickedCallback(ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QPushButtonBind::setPressedCallback(PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QPushButtonBind::setReleasedCallback(ReleasedCallback callback) const {
    handler->setReleasedCallback(callback);
}
