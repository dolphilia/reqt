#include "QDialBind.h"
#include "QDialHandler.h"

QDialBind::QDialBind(QWidget* parent)
    : QDial(parent)
    , handler(new QDialHandler(this)) {
    connect(this, &QDial::valueChanged, handler, &QDialHandler::onValueChanged);
    connect(this, &QDial::sliderMoved, handler, &QDialHandler::onSliderMoved);
    connect(this, &QDial::sliderPressed, handler, &QDialHandler::onSliderPressed);
    connect(this, &QDial::sliderReleased, handler, &QDialHandler::onSliderReleased);
}

QDialBind::~QDialBind() {
    delete handler;
}

void QDialBind::setValueChangedCallback(QDial_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QDialBind::setSliderMovedCallback(QDial_SliderMovedCallback callback) const {
    handler->setSliderMovedCallback(callback);
}

void QDialBind::setSliderPressedCallback(QDial_SliderPressedCallback callback) const {
    handler->setSliderPressedCallback(callback);
}

void QDialBind::setSliderReleasedCallback(QDial_SliderReleasedCallback callback) const {
    handler->setSliderReleasedCallback(callback);
}
