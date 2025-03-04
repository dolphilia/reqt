#include "QDialBind.h"
#include "QDialHandler.h"

extern "C" {

void* QDial_create(void* parent) {
    return new QDialBind(static_cast<QWidget*>(parent));
}

void QDial_delete(void* dial) {
    delete static_cast<QDialBind*>(dial);
}

// プロパティ設定
void QDial_setMinimum(void* dial, int min) {
    static_cast<QDialBind*>(dial)->setMinimum(min);
}

void QDial_setMaximum(void* dial, int max) {
    static_cast<QDialBind*>(dial)->setMaximum(max);
}

void QDial_setRange(void* dial, int min, int max) {
    static_cast<QDialBind*>(dial)->setRange(min, max);
}

void QDial_setValue(void* dial, int value) {
    static_cast<QDialBind*>(dial)->setValue(value);
}

void QDial_setSingleStep(void* dial, int step) {
    static_cast<QDialBind*>(dial)->setSingleStep(step);
}

void QDial_setPageStep(void* dial, int step) {
    static_cast<QDialBind*>(dial)->setPageStep(step);
}

void QDial_setNotchTarget(void* dial, double target) {
    static_cast<QDialBind*>(dial)->setNotchTarget(target);
}

void QDial_setNotchesVisible(void* dial, bool visible) {
    static_cast<QDialBind*>(dial)->setNotchesVisible(visible);
}

void QDial_setWrapping(void* dial, bool wrapping) {
    static_cast<QDialBind*>(dial)->setWrapping(wrapping);
}

// プロパティ取得
int QDial_minimum(void* dial) {
    return static_cast<QDialBind*>(dial)->minimum();
}

int QDial_maximum(void* dial) {
    return static_cast<QDialBind*>(dial)->maximum();
}

int QDial_value(void* dial) {
    return static_cast<QDialBind*>(dial)->value();
}

int QDial_singleStep(void* dial) {
    return static_cast<QDialBind*>(dial)->singleStep();
}

int QDial_pageStep(void* dial) {
    return static_cast<QDialBind*>(dial)->pageStep();
}

double QDial_notchTarget(void* dial) {
    return static_cast<QDialBind*>(dial)->notchTarget();
}

bool QDial_notchesVisible(void* dial) {
    return static_cast<QDialBind*>(dial)->notchesVisible();
}

bool QDial_wrapping(void* dial) {
    return static_cast<QDialBind*>(dial)->wrapping();
}

typedef void (*QDial_ValueChangedCallback)(void*, int);
typedef void (*QDial_SliderMovedCallback)(void*, int);
typedef void (*QDial_SliderPressedCallback)(void*);
typedef void (*QDial_SliderReleasedCallback)(void*);

void QDial_setValueChangedCallback(void* dial, QDial_ValueChangedCallback callback) {
    static_cast<QDialBind*>(dial)->setValueChangedCallback(callback);
}

void QDial_setSliderMovedCallback(void* dial, QDial_SliderMovedCallback callback) {
    static_cast<QDialBind*>(dial)->setSliderMovedCallback(callback);
}

void QDial_setSliderPressedCallback(void* dial, QDial_SliderPressedCallback callback) {
    static_cast<QDialBind*>(dial)->setSliderPressedCallback(callback);
}

void QDial_setSliderReleasedCallback(void* dial, QDial_SliderReleasedCallback callback) {
    static_cast<QDialBind*>(dial)->setSliderReleasedCallback(callback);
}

}
