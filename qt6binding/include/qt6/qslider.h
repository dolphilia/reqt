#ifndef QSLIDER_C_H
#define QSLIDER_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QSlider creation/deletion
void* QSlider_create(void* parent);
void* QSlider_createWithOrientation(int orientation, void* parent);
void QSlider_delete(void* slider);

// Value operations
void QSlider_setValue(void* slider, int value);
int QSlider_value(void* slider);
void QSlider_setRange(void* slider, int min, int max);
int QSlider_minimum(void* slider);
int QSlider_maximum(void* slider);
void QSlider_setMinimum(void* slider, int min);
void QSlider_setMaximum(void* slider, int max);

// Step size
void QSlider_setSingleStep(void* slider, int step);
int QSlider_singleStep(void* slider);
void QSlider_setPageStep(void* slider, int step);
int QSlider_pageStep(void* slider);

// Tracking
void QSlider_setTracking(void* slider, bool enable);
bool QSlider_hasTracking(void* slider);

// Orientation
void QSlider_setOrientation(void* slider, int orientation);
int QSlider_orientation(void* slider);

// Ticks
void QSlider_setTickPosition(void* slider, int position);
int QSlider_tickPosition(void* slider);
void QSlider_setTickInterval(void* slider, int interval);
int QSlider_tickInterval(void* slider);

// Inversion
void QSlider_setInvertedAppearance(void* slider, bool invert);
bool QSlider_invertedAppearance(void* slider);
void QSlider_setInvertedControls(void* slider, bool invert);
bool QSlider_invertedControls(void* slider);

// Signal handlers
typedef void (*QSliderValueChangedCallback)(int value);
typedef void (*QSliderMovedCallback)(int position);
typedef void (*QSliderPressedCallback)();
typedef void (*QSliderReleasedCallback)();
typedef void (*QSliderRangeChangedCallback)(int min, int max);
typedef void (*QSliderActionTriggeredCallback)(int action);

void QSlider_setValueChangedCallback(void* slider, QSliderValueChangedCallback callback);
void QSlider_setSliderMovedCallback(void* slider, QSliderMovedCallback callback);
void QSlider_setSliderPressedCallback(void* slider, QSliderPressedCallback callback);
void QSlider_setSliderReleasedCallback(void* slider, QSliderReleasedCallback callback);
void QSlider_setRangeChangedCallback(void* slider, QSliderRangeChangedCallback callback);
void QSlider_setActionTriggeredCallback(void* slider, QSliderActionTriggeredCallback callback);

// Constants
#define QSLIDER_HORIZONTAL 0
#define QSLIDER_VERTICAL 1

#define QSLIDER_NOTICKS 0
#define QSLIDER_TICKS_ABOVE 1
#define QSLIDER_TICKS_LEFT 1
#define QSLIDER_TICKS_BELOW 2
#define QSLIDER_TICKS_RIGHT 2
#define QSLIDER_TICKS_BOTH 3

#define QSLIDER_TRIGGER_NONE 0
#define QSLIDER_TRIGGER_SLIDERMOVED 1
#define QSLIDER_TRIGGER_SLIDERPRESSED 2
#define QSLIDER_TRIGGER_SLIDERPAGEDDOWN 3
#define QSLIDER_TRIGGER_SLIDERPAGEDRIGHT 4
#define QSLIDER_TRIGGER_SLIDERPAGEDLEFT 5

#ifdef __cplusplus
}
#endif

#endif // QSLIDER_C_H
