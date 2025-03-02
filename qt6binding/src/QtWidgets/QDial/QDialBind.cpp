#include "QDialBind.h"
#include "QDialHandler.h"

QDialBind::QDialBind(QWidget* parent)
    : QDial(parent), handler(nullptr)
{
}

QDialBind::~QDialBind()
{
    delete handler;
}

void QDialBind::setValueChangedCallback(ValueChangedCallback callback)
{
    if (!handler) {
        handler = new DialHandler(this);
        connect(this, &QDial::valueChanged, handler, &DialHandler::onValueChanged);
    }
    handler->setValueChangedCallback(callback);
}

void QDialBind::setSliderMovedCallback(SliderMovedCallback callback)
{
    if (!handler) {
        handler = new DialHandler(this);
        connect(this, &QDial::sliderMoved, handler, &DialHandler::onSliderMoved);
    }
    handler->setSliderMovedCallback(callback);
}

void QDialBind::setSliderPressedCallback(SliderPressedCallback callback)
{
    if (!handler) {
        handler = new DialHandler(this);
        connect(this, &QDial::sliderPressed, handler, &DialHandler::onSliderPressed);
    }
    handler->setSliderPressedCallback(callback);
}

void QDialBind::setSliderReleasedCallback(SliderReleasedCallback callback)
{
    if (!handler) {
        handler = new DialHandler(this);
        connect(this, &QDial::sliderReleased, handler, &DialHandler::onSliderReleased);
    }
    handler->setSliderReleasedCallback(callback);
}
