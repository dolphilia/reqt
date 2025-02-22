#include "c_q_scroll_bar.h"
#include "bind_q_scroll_bar.h"
#include "handler_scroll_bar.h"

extern "C" {

void* QScrollBar_create(void* parent)
{
    return new BindQScrollBar(reinterpret_cast<QWidget*>(parent));
}

void* QScrollBar_createWithOrientation(int orientation, void* parent)
{
    return new BindQScrollBar(static_cast<Qt::Orientation>(orientation), reinterpret_cast<QWidget*>(parent));
}

void QScrollBar_delete(void* scroll_bar)
{
    delete static_cast<BindQScrollBar*>(scroll_bar);
}

void QScrollBar_setValue(void* scroll_bar, int value)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setValue(value);
}

int QScrollBar_value(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->value();
}

void QScrollBar_setRange(void* scroll_bar, int min, int max)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setRange(min, max);
}

int QScrollBar_minimum(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->minimum();
}

int QScrollBar_maximum(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->maximum();
}

void QScrollBar_setMinimum(void* scroll_bar, int min)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setMinimum(min);
}

void QScrollBar_setMaximum(void* scroll_bar, int max)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setMaximum(max);
}

void QScrollBar_setSingleStep(void* scroll_bar, int step)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setSingleStep(step);
}

int QScrollBar_singleStep(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->singleStep();
}

void QScrollBar_setPageStep(void* scroll_bar, int step)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setPageStep(step);
}

int QScrollBar_pageStep(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->pageStep();
}

void QScrollBar_setTracking(void* scroll_bar, bool enable)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setTracking(enable);
}

bool QScrollBar_hasTracking(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->hasTracking();
}

void QScrollBar_setOrientation(void* scroll_bar, int orientation)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QScrollBar_orientation(void* scroll_bar)
{
    return static_cast<int>(static_cast<BindQScrollBar*>(scroll_bar)->orientation());
}

void QScrollBar_setInvertedAppearance(void* scroll_bar, bool invert)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setInvertedAppearance(invert);
}

bool QScrollBar_invertedAppearance(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->invertedAppearance();
}

void QScrollBar_setInvertedControls(void* scroll_bar, bool invert)
{
    static_cast<BindQScrollBar*>(scroll_bar)->setInvertedControls(invert);
}

bool QScrollBar_invertedControls(void* scroll_bar)
{
    return static_cast<BindQScrollBar*>(scroll_bar)->invertedControls();
}

void QScrollBar_setValueChangedCallback(void* scroll_bar, QScrollBarValueChangedCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setValueChangedCallback(callback);
}

void QScrollBar_setSliderMovedCallback(void* scroll_bar, QScrollBarSliderMovedCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setSliderMovedCallback(callback);
}

void QScrollBar_setSliderPressedCallback(void* scroll_bar, QScrollBarSliderPressedCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setSliderPressedCallback(callback);
}

void QScrollBar_setSliderReleasedCallback(void* scroll_bar, QScrollBarSliderReleasedCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setSliderReleasedCallback(callback);
}

void QScrollBar_setRangeChangedCallback(void* scroll_bar, QScrollBarRangeChangedCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setRangeChangedCallback(callback);
}

void QScrollBar_setActionTriggeredCallback(void* scroll_bar, QScrollBarActionTriggeredCallback callback)
{
    BindQScrollBar* qscroll_bar = static_cast<BindQScrollBar*>(scroll_bar);
    ScrollBarHandler* handler = qscroll_bar->handler();
    if (!handler) {
        handler = new ScrollBarHandler(qscroll_bar);
        qscroll_bar->setScrollBarHandler(handler);
    }
    handler->setActionTriggeredCallback(callback);
}

}
