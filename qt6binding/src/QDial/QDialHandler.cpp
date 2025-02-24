#include "QDialHandler.h"

DialHandler::DialHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr)
    , sliderMovedCallback(nullptr)
    , sliderPressedCallback(nullptr)
    , sliderReleasedCallback(nullptr)
{
}

void DialHandler::setValueChangedCallback(ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void DialHandler::setSliderMovedCallback(SliderMovedCallback callback) {
    sliderMovedCallback = callback;
}

void DialHandler::setSliderPressedCallback(SliderPressedCallback callback) {
    sliderPressedCallback = callback;
}

void DialHandler::setSliderReleasedCallback(SliderReleasedCallback callback) {
    sliderReleasedCallback = callback;
}

void DialHandler::onValueChanged(int value) {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}

void DialHandler::onSliderMoved(int position) {
    if (sliderMovedCallback) {
        sliderMovedCallback(parent(), position);
    }
}

void DialHandler::onSliderPressed() {
    if (sliderPressedCallback) {
        sliderPressedCallback(parent());
    }
}

void DialHandler::onSliderReleased() {
    if (sliderReleasedCallback) {
        sliderReleasedCallback(parent());
    }
}
