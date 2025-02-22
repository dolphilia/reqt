#include "handler_dial.h"

DialHandler::DialHandler(QObject* parent)
    : QObject(parent)
    , dial(nullptr)
    , valueChangedCallback(nullptr)
    , sliderMovedCallback(nullptr)
    , sliderPressedCallback(nullptr)
    , sliderReleasedCallback(nullptr)
{
}

void DialHandler::setDial(QDial* dial) {
    this->dial = dial;
    connect(dial, &QDial::valueChanged, this, &DialHandler::onValueChanged);
    connect(dial, &QDial::sliderMoved, this, &DialHandler::onSliderMoved);
    connect(dial, &QDial::sliderPressed, this, &DialHandler::onSliderPressed);
    connect(dial, &QDial::sliderReleased, this, &DialHandler::onSliderReleased);
}

void DialHandler::setValueChangedCallback(void (*callback)(void*, int)) {
    valueChangedCallback = callback;
}

void DialHandler::setSliderMovedCallback(void (*callback)(void*, int)) {
    sliderMovedCallback = callback;
}

void DialHandler::setSliderPressedCallback(void (*callback)(void*)) {
    sliderPressedCallback = callback;
}

void DialHandler::setSliderReleasedCallback(void (*callback)(void*)) {
    sliderReleasedCallback = callback;
}

void DialHandler::onValueChanged(int value) {
    if (valueChangedCallback && dial) {
        valueChangedCallback(dial, value);
    }
}

void DialHandler::onSliderMoved(int value) {
    if (sliderMovedCallback && dial) {
        sliderMovedCallback(dial, value);
    }
}

void DialHandler::onSliderPressed() {
    if (sliderPressedCallback && dial) {
        sliderPressedCallback(dial);
    }
}

void DialHandler::onSliderReleased() {
    if (sliderReleasedCallback && dial) {
        sliderReleasedCallback(dial);
    }
}
