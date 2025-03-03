#include "QDialBind.h"
#include "QDialHandler.h"

QDialBind::QDialBind(QWidget* parent)
    : QDial(parent)
    , handler(new DialHandler(this))
{
    connect(this, &QDial::valueChanged, handler, &DialHandler::onValueChanged);
    connect(this, &QDial::sliderMoved, handler, &DialHandler::onSliderMoved);
    connect(this, &QDial::sliderPressed, handler, &DialHandler::onSliderPressed);
    connect(this, &QDial::sliderReleased, handler, &DialHandler::onSliderReleased);
}

QDialBind::~QDialBind() {
    delete handler;
}

void QDialBind::setValueChangedCallback(ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QDialBind::setSliderMovedCallback(SliderMovedCallback callback) const {
    handler->setSliderMovedCallback(callback);
}

void QDialBind::setSliderPressedCallback(SliderPressedCallback callback) const {
    handler->setSliderPressedCallback(callback);
}

void QDialBind::setSliderReleasedCallback(SliderReleasedCallback callback) const {
    handler->setSliderReleasedCallback(callback);
}
