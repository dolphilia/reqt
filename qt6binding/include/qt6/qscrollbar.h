#ifndef QSCROLLBAR_C_H
#define QSCROLLBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QScrollBar creation/deletion
void* QScrollBar_create(void* parent);
void* QScrollBar_createWithOrientation(int orientation, void* parent);
void QScrollBar_delete(void* scroll_bar);

// Value operations
void QScrollBar_setValue(void* scroll_bar, int value);
int QScrollBar_value(void* scroll_bar);
void QScrollBar_setRange(void* scroll_bar, int min, int max);
int QScrollBar_minimum(void* scroll_bar);
int QScrollBar_maximum(void* scroll_bar);
void QScrollBar_setMinimum(void* scroll_bar, int min);
void QScrollBar_setMaximum(void* scroll_bar, int max);

// Step operations
void QScrollBar_setSingleStep(void* scroll_bar, int step);
int QScrollBar_singleStep(void* scroll_bar);
void QScrollBar_setPageStep(void* scroll_bar, int step);
int QScrollBar_pageStep(void* scroll_bar);

// Tracking
void QScrollBar_setTracking(void* scroll_bar, bool enable);
bool QScrollBar_hasTracking(void* scroll_bar);

// Orientation
void QScrollBar_setOrientation(void* scroll_bar, int orientation);
int QScrollBar_orientation(void* scroll_bar);

// Inversion
void QScrollBar_setInvertedAppearance(void* scroll_bar, bool invert);
bool QScrollBar_invertedAppearance(void* scroll_bar);
void QScrollBar_setInvertedControls(void* scroll_bar, bool invert);
bool QScrollBar_invertedControls(void* scroll_bar);

// Signal handlers
typedef void (*QScrollBarValueChangedCallback)(int value);
typedef void (*QScrollBarSliderMovedCallback)(int position);
typedef void (*QScrollBarSliderPressedCallback)();
typedef void (*QScrollBarSliderReleasedCallback)();
typedef void (*QScrollBarRangeChangedCallback)(int min, int max);
typedef void (*QScrollBarActionTriggeredCallback)(int action);

void QScrollBar_setValueChangedCallback(void* scroll_bar, QScrollBarValueChangedCallback callback);
void QScrollBar_setSliderMovedCallback(void* scroll_bar, QScrollBarSliderMovedCallback callback);
void QScrollBar_setSliderPressedCallback(void* scroll_bar, QScrollBarSliderPressedCallback callback);
void QScrollBar_setSliderReleasedCallback(void* scroll_bar, QScrollBarSliderReleasedCallback callback);
void QScrollBar_setRangeChangedCallback(void* scroll_bar, QScrollBarRangeChangedCallback callback);
void QScrollBar_setActionTriggeredCallback(void* scroll_bar, QScrollBarActionTriggeredCallback callback);

// Constants
#define QSCROLLBAR_HORIZONTAL 0
#define QSCROLLBAR_VERTICAL 1

#define QSCROLLBAR_SLIDERNOACTION 0
#define QSCROLLBAR_SLIDERMOVED 1
#define QSCROLLBAR_SLIDERPRESSED 2
#define QSCROLLBAR_SLIDERPAGEDDOWN 3
#define QSCROLLBAR_SLIDERPAGEDRIGHT 4
#define QSCROLLBAR_SLIDERPAGEDLEFT 5

#ifdef __cplusplus
}
#endif

#endif // QSCROLLBAR_C_H
