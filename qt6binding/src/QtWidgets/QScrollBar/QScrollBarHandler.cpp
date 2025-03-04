#include "QScrollBarHandler.h"

QScrollBarHandler::QScrollBarHandler(QObject* parent)
    : QObject(parent)
    , valueChangedCallback(nullptr)
    , sliderMovedCallback(nullptr)
    , sliderPressedCallback(nullptr)
    , sliderReleasedCallback(nullptr)
    , rangeChangedCallback(nullptr)
    , actionTriggeredCallback(nullptr) {
}

void QScrollBarHandler::setValueChangedCallback(QScrollBar_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

void QScrollBarHandler::setSliderMovedCallback(QScrollBar_SliderMovedCallback callback) {
    sliderMovedCallback = callback;
}

void QScrollBarHandler::setSliderPressedCallback(QScrollBar_SliderPressedCallback callback) {
    sliderPressedCallback = callback;
}

void QScrollBarHandler::setSliderReleasedCallback(QScrollBar_SliderReleasedCallback callback) {
    sliderReleasedCallback = callback;
}

void QScrollBarHandler::setRangeChangedCallback(QScrollBar_RangeChangedCallback callback) {
    rangeChangedCallback = callback;
}

void QScrollBarHandler::setActionTriggeredCallback(QScrollBar_ActionTriggeredCallback callback) {
    actionTriggeredCallback = callback;
}

void QScrollBarHandler::onValueChanged(int value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), value);
    }
}

void QScrollBarHandler::onSliderMoved(int position) const {
    if (sliderMovedCallback) {
        sliderMovedCallback(parent(), position);
    }
}

void QScrollBarHandler::onSliderPressed() const {
    if (sliderPressedCallback) {
        sliderPressedCallback(parent());
    }
}

void QScrollBarHandler::onSliderReleased() const {
    if (sliderReleasedCallback) {
        sliderReleasedCallback(parent());
    }
}

void QScrollBarHandler::onRangeChanged(int min, int max) const {
    if (rangeChangedCallback) {
        rangeChangedCallback(parent(), min, max);
    }
}

void QScrollBarHandler::onActionTriggered(int action) const {
    if (actionTriggeredCallback) {
        actionTriggeredCallback(parent(), action);
    }
}
