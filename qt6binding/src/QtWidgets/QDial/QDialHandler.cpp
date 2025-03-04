#include "QDialHandler.h"

QDialHandler::QDialHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr)
    , sliderMovedCallback(nullptr)
    , sliderPressedCallback(nullptr)
    , sliderReleasedCallback(nullptr) {
}

void QDialHandler::setValueChangedCallback(QDial_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void QDialHandler::setSliderMovedCallback(QDial_SliderMovedCallback callback) {
    sliderMovedCallback = callback;
}

void QDialHandler::setSliderPressedCallback(QDial_SliderPressedCallback callback) {
    sliderPressedCallback = callback;
}

void QDialHandler::setSliderReleasedCallback(QDial_SliderReleasedCallback callback) {
    sliderReleasedCallback = callback;
}

void QDialHandler::onValueChanged(int value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}

void QDialHandler::onSliderMoved(int position) const {
    if (sliderMovedCallback) {
        sliderMovedCallback(parent(), position);
    }
}

void QDialHandler::onSliderPressed() const {
    if (sliderPressedCallback) {
        sliderPressedCallback(parent());
    }
}

void QDialHandler::onSliderReleased() const {
    if (sliderReleasedCallback) {
        sliderReleasedCallback(parent());
    }
}
