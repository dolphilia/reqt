#include "QPushButtonBind.h"
#include "QPushButtonHandler.h"

QPushButtonBind::QPushButtonBind(const char* text, QWidget* parent)
    : QPushButton(text ? QString::fromUtf8(text) : QString(), parent)
    , handler(new QButtonClickHandler(this)) {
    connect(this, &QPushButton::clicked, handler, &QButtonClickHandler::onClicked);
    connect(this, &QPushButton::pressed, handler, &QButtonClickHandler::onPressed);
    connect(this, &QPushButton::released, handler, &QButtonClickHandler::onReleased);
}

QPushButtonBind::~QPushButtonBind() {
    delete handler;
}

void QPushButtonBind::setClickedCallback(QPushButton_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QPushButtonBind::setPressedCallback(QPushButton_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QPushButtonBind::setReleasedCallback(QPushButton_ReleasedCallback callback) const {
    handler->setReleasedCallback(callback);
}
