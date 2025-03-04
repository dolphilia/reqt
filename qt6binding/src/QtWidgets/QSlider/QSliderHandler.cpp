#include "QSliderHandler.h"

QSliderHandler::QSliderHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr)
    , sliderMovedCallback(nullptr)
    , sliderPressedCallback(nullptr)
    , sliderReleasedCallback(nullptr)
    , rangeChangedCallback(nullptr)
    , actionTriggeredCallback(nullptr) {
}

void QSliderHandler::setValueChangedCallback(QSlider_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void QSliderHandler::setSliderMovedCallback(QSlider_SliderMovedCallback callback) {
    sliderMovedCallback = callback;
}

void QSliderHandler::setSliderPressedCallback(QSlider_SliderPressedCallback callback) {
    sliderPressedCallback = callback;
}

void QSliderHandler::setSliderReleasedCallback(QSlider_SliderReleasedCallback callback) {
    sliderReleasedCallback = callback;
}

void QSliderHandler::setRangeChangedCallback(QSlider_RangeChangedCallback callback) {
    rangeChangedCallback = callback;
}

void QSliderHandler::setActionTriggeredCallback(QSlider_ActionTriggeredCallback callback) {
    actionTriggeredCallback = callback;
}

void QSliderHandler::onValueChanged(int value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}

void QSliderHandler::onSliderMoved(int position) const {
    if (sliderMovedCallback) {
        sliderMovedCallback(parent(), position);
    }
}

void QSliderHandler::onSliderPressed() const {
    if (sliderPressedCallback) {
        sliderPressedCallback(parent());
    }
}

void QSliderHandler::onSliderReleased() const {
    if (sliderReleasedCallback) {
        sliderReleasedCallback(parent());
    }
}

void QSliderHandler::onRangeChanged(int min, int max) const {
    if (rangeChangedCallback) {
        rangeChangedCallback(parent(), min, max);
    }
}

void QSliderHandler::onActionTriggered(int action) const {
    if (actionTriggeredCallback) {
        actionTriggeredCallback(parent(), action);
    }
}
