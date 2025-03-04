#include "QScrollBarBind.h"

extern "C" {

void* QScrollBar_create(void* parent) {
    return new QScrollBarBind(static_cast<QWidget*>(parent));
}

void* QScrollBar_createWithOrientation(int orientation, void* parent) {
    return new QScrollBarBind(static_cast<Qt::Orientation>(orientation), static_cast<QWidget*>(parent));
}

void QScrollBar_delete(void* scrollbar) {
    delete static_cast<QScrollBarBind*>(scrollbar);
}

void QScrollBar_setValue(void* scrollbar, int value) {
    static_cast<QScrollBarBind*>(scrollbar)->setValue(value);
}

int QScrollBar_value(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->value();
}

void QScrollBar_setRange(void* scrollbar, int min, int max) {
    static_cast<QScrollBarBind*>(scrollbar)->setRange(min, max);
}

int QScrollBar_minimum(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->minimum();
}

int QScrollBar_maximum(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->maximum();
}

void QScrollBar_setMinimum(void* scrollbar, int min) {
    static_cast<QScrollBarBind*>(scrollbar)->setMinimum(min);
}

void QScrollBar_setMaximum(void* scrollbar, int max) {
    static_cast<QScrollBarBind*>(scrollbar)->setMaximum(max);
}

void QScrollBar_setSingleStep(void* scrollbar, int step) {
    static_cast<QScrollBarBind*>(scrollbar)->setSingleStep(step);
}

int QScrollBar_singleStep(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->singleStep();
}

void QScrollBar_setPageStep(void* scrollbar, int step) {
    static_cast<QScrollBarBind*>(scrollbar)->setPageStep(step);
}

int QScrollBar_pageStep(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->pageStep();
}

void QScrollBar_setTracking(void* scrollbar, bool enable) {
    static_cast<QScrollBarBind*>(scrollbar)->setTracking(enable);
}

bool QScrollBar_hasTracking(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->hasTracking();
}

void QScrollBar_setOrientation(void* scrollbar, int orientation) {
    static_cast<QScrollBarBind*>(scrollbar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QScrollBar_orientation(void* scrollbar) {
    return static_cast<int>(static_cast<QScrollBarBind*>(scrollbar)->orientation());
}

void QScrollBar_setInvertedAppearance(void* scrollbar, bool invert) {
    static_cast<QScrollBarBind*>(scrollbar)->setInvertedAppearance(invert);
}

bool QScrollBar_invertedAppearance(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->invertedAppearance();
}

void QScrollBar_setInvertedControls(void* scrollbar, bool invert) {
    static_cast<QScrollBarBind*>(scrollbar)->setInvertedControls(invert);
}

bool QScrollBar_invertedControls(void* scrollbar) {
    return static_cast<QScrollBarBind*>(scrollbar)->invertedControls();
}

typedef void (*QScrollBar_ValueChangedCallback)(void*, int);
typedef void (*QScrollBar_SliderMovedCallback)(void*, int);
typedef void (*QScrollBar_SliderPressedCallback)(void*);
typedef void (*QScrollBar_SliderReleasedCallback)(void*);
typedef void (*QScrollBar_RangeChangedCallback)(void*, int, int);
typedef void (*QScrollBar_ActionTriggeredCallback)(void*, int);

void QScrollBar_setValueChangedCallback(void* scrollbar, QScrollBar_ValueChangedCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setValueChangedCallback(callback);
}

void QScrollBar_setSliderMovedCallback(void* scrollbar, QScrollBar_SliderMovedCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setSliderMovedCallback(callback);
}

void QScrollBar_setSliderPressedCallback(void* scrollbar, QScrollBar_SliderPressedCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setSliderPressedCallback(callback);
}

void QScrollBar_setSliderReleasedCallback(void* scrollbar, QScrollBar_SliderReleasedCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setSliderReleasedCallback(callback);
}

void QScrollBar_setRangeChangedCallback(void* scrollbar, QScrollBar_RangeChangedCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setRangeChangedCallback(callback);
}

void QScrollBar_setActionTriggeredCallback(void* scrollbar, QScrollBar_ActionTriggeredCallback callback) {
    static_cast<QScrollBarBind*>(scrollbar)->setActionTriggeredCallback(callback);
}

}
