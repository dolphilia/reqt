#include "qslider.h"
#include "QSliderBind.h"
#include "QSliderHandler.h"

extern "C" {

void* QSlider_create(void* parent)
{
    return new BindQSlider(reinterpret_cast<QWidget*>(parent));
}

void* QSlider_createWithOrientation(int orientation, void* parent)
{
    return new BindQSlider(static_cast<Qt::Orientation>(orientation), reinterpret_cast<QWidget*>(parent));
}

void QSlider_delete(void* slider)
{
    delete static_cast<BindQSlider*>(slider);
}

void QSlider_setValue(void* slider, int value)
{
    static_cast<BindQSlider*>(slider)->setValue(value);
}

int QSlider_value(void* slider)
{
    return static_cast<BindQSlider*>(slider)->value();
}

void QSlider_setRange(void* slider, int min, int max)
{
    static_cast<BindQSlider*>(slider)->setRange(min, max);
}

int QSlider_minimum(void* slider)
{
    return static_cast<BindQSlider*>(slider)->minimum();
}

int QSlider_maximum(void* slider)
{
    return static_cast<BindQSlider*>(slider)->maximum();
}

void QSlider_setMinimum(void* slider, int min)
{
    static_cast<BindQSlider*>(slider)->setMinimum(min);
}

void QSlider_setMaximum(void* slider, int max)
{
    static_cast<BindQSlider*>(slider)->setMaximum(max);
}

void QSlider_setSingleStep(void* slider, int step)
{
    static_cast<BindQSlider*>(slider)->setSingleStep(step);
}

int QSlider_singleStep(void* slider)
{
    return static_cast<BindQSlider*>(slider)->singleStep();
}

void QSlider_setPageStep(void* slider, int step)
{
    static_cast<BindQSlider*>(slider)->setPageStep(step);
}

int QSlider_pageStep(void* slider)
{
    return static_cast<BindQSlider*>(slider)->pageStep();
}

void QSlider_setTracking(void* slider, bool enable)
{
    static_cast<BindQSlider*>(slider)->setTracking(enable);
}

bool QSlider_hasTracking(void* slider)
{
    return static_cast<BindQSlider*>(slider)->hasTracking();
}

void QSlider_setOrientation(void* slider, int orientation)
{
    static_cast<BindQSlider*>(slider)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QSlider_orientation(void* slider)
{
    return static_cast<int>(static_cast<BindQSlider*>(slider)->orientation());
}

void QSlider_setTickPosition(void* slider, int position)
{
    static_cast<BindQSlider*>(slider)->setTickPosition(static_cast<QSlider::TickPosition>(position));
}

int QSlider_tickPosition(void* slider)
{
    return static_cast<int>(static_cast<BindQSlider*>(slider)->tickPosition());
}

void QSlider_setTickInterval(void* slider, int interval)
{
    static_cast<BindQSlider*>(slider)->setTickInterval(interval);
}

int QSlider_tickInterval(void* slider)
{
    return static_cast<BindQSlider*>(slider)->tickInterval();
}

void QSlider_setInvertedAppearance(void* slider, bool invert)
{
    static_cast<BindQSlider*>(slider)->setInvertedAppearance(invert);
}

bool QSlider_invertedAppearance(void* slider)
{
    return static_cast<BindQSlider*>(slider)->invertedAppearance();
}

void QSlider_setInvertedControls(void* slider, bool invert)
{
    static_cast<BindQSlider*>(slider)->setInvertedControls(invert);
}

bool QSlider_invertedControls(void* slider)
{
    return static_cast<BindQSlider*>(slider)->invertedControls();
}

void QSlider_setValueChangedCallback(void* slider, QSliderValueChangedCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setValueChangedCallback(callback);
}

void QSlider_setSliderMovedCallback(void* slider, QSliderMovedCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setSliderMovedCallback(callback);
}

void QSlider_setSliderPressedCallback(void* slider, QSliderPressedCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setSliderPressedCallback(callback);
}

void QSlider_setSliderReleasedCallback(void* slider, QSliderReleasedCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setSliderReleasedCallback(callback);
}

void QSlider_setRangeChangedCallback(void* slider, QSliderRangeChangedCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setRangeChangedCallback(callback);
}

void QSlider_setActionTriggeredCallback(void* slider, QSliderActionTriggeredCallback callback)
{
    BindQSlider* qslider = static_cast<BindQSlider*>(slider);
    SliderHandler* handler = qslider->handler();
    if (!handler) {
        handler = new SliderHandler(qslider);
        qslider->setSliderHandler(handler);
    }
    handler->setActionTriggeredCallback(callback);
}

}
