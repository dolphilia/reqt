#include "QSliderBind.h"

extern "C" {

void* QSlider_create(QWidget* parent) {
    return new QSliderBind(parent);
}

void* QSlider_createWithOrientation(int orientation, QWidget* parent) {
    return new QSliderBind(static_cast<Qt::Orientation>(orientation), parent);
}

void QSlider_delete(void* slider) {
    delete static_cast<QSliderBind*>(slider);
}

void QSlider_setValue(void* slider, int value) {
    static_cast<QSliderBind*>(slider)->setValue(value);
}

int QSlider_value(void* slider) {
    return static_cast<QSliderBind*>(slider)->value();
}

void QSlider_setRange(void* slider, int min, int max) {
    static_cast<QSliderBind*>(slider)->setRange(min, max);
}

int QSlider_minimum(void* slider) {
    return static_cast<QSliderBind*>(slider)->minimum();
}

int QSlider_maximum(void* slider) {
    return static_cast<QSliderBind*>(slider)->maximum();
}

void QSlider_setMinimum(void* slider, int min) {
    static_cast<QSliderBind*>(slider)->setMinimum(min);
}

void QSlider_setMaximum(void* slider, int max) {
    static_cast<QSliderBind*>(slider)->setMaximum(max);
}

void QSlider_setSingleStep(void* slider, int step) {
    static_cast<QSliderBind*>(slider)->setSingleStep(step);
}

int QSlider_singleStep(void* slider) {
    return static_cast<QSliderBind*>(slider)->singleStep();
}

void QSlider_setPageStep(void* slider, int step) {
    static_cast<QSliderBind*>(slider)->setPageStep(step);
}

int QSlider_pageStep(void* slider) {
    return static_cast<QSliderBind*>(slider)->pageStep();
}

void QSlider_setTracking(void* slider, bool enable) {
    static_cast<QSliderBind*>(slider)->setTracking(enable);
}

bool QSlider_hasTracking(void* slider) {
    return static_cast<QSliderBind*>(slider)->hasTracking();
}

void QSlider_setOrientation(void* slider, int orientation) {
    static_cast<QSliderBind*>(slider)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QSlider_orientation(void* slider) {
    return static_cast<int>(static_cast<QSliderBind*>(slider)->orientation());
}

void QSlider_setTickPosition(void* slider, int position) {
    static_cast<QSliderBind*>(slider)->setTickPosition(static_cast<QSlider::TickPosition>(position));
}

int QSlider_tickPosition(void* slider) {
    return static_cast<int>(static_cast<QSliderBind*>(slider)->tickPosition());
}

void QSlider_setTickInterval(void* slider, int interval) {
    static_cast<QSliderBind*>(slider)->setTickInterval(interval);
}

int QSlider_tickInterval(void* slider) {
    return static_cast<QSliderBind*>(slider)->tickInterval();
}

void QSlider_setInvertedAppearance(void* slider, bool invert) {
    static_cast<QSliderBind*>(slider)->setInvertedAppearance(invert);
}

bool QSlider_invertedAppearance(void* slider) {
    return static_cast<QSliderBind*>(slider)->invertedAppearance();
}

void QSlider_setInvertedControls(void* slider, bool invert) {
    static_cast<QSliderBind*>(slider)->setInvertedControls(invert);
}

bool QSlider_invertedControls(void* slider) {
    return static_cast<QSliderBind*>(slider)->invertedControls();
}

typedef void (*QSlider_ValueChangedCallback)(void*, int);
typedef void (*QSlider_SliderMovedCallback)(void*, int);
typedef void (*QSlider_SliderPressedCallback)(void*);
typedef void (*QSlider_SliderReleasedCallback)(void*);
typedef void (*QSlider_RangeChangedCallback)(void*, int, int);
typedef void (*QSlider_ActionTriggeredCallback)(void*, int);

void QSlider_setValueChangedCallback(void* slider, QSlider_ValueChangedCallback callback) {
    static_cast<QSliderBind*>(slider)->setValueChangedCallback(callback);
}

void QSlider_setSliderMovedCallback(void* slider, QSlider_SliderMovedCallback callback) {
    static_cast<QSliderBind*>(slider)->setSliderMovedCallback(callback);
}

void QSlider_setSliderPressedCallback(void* slider, QSlider_SliderPressedCallback callback) {
    static_cast<QSliderBind*>(slider)->setSliderPressedCallback(callback);
}

void QSlider_setSliderReleasedCallback(void* slider, QSlider_SliderReleasedCallback callback) {
    static_cast<QSliderBind*>(slider)->setSliderReleasedCallback(callback);
}

void QSlider_setRangeChangedCallback(void* slider, QSlider_RangeChangedCallback callback) {
    static_cast<QSliderBind*>(slider)->setRangeChangedCallback(callback);
}

void QSlider_setActionTriggeredCallback(void* slider, QSlider_ActionTriggeredCallback callback) {
    static_cast<QSliderBind*>(slider)->setActionTriggeredCallback(callback);
}

}
