#ifndef QPROGRESSBAR_C_H
#define QPROGRESSBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QProgressBar creation/deletion
void* QProgressBar_create(void* parent);
void QProgressBar_delete(void* progress_bar);

// Value operations
void QProgressBar_setValue(void* progress_bar, int value);
int QProgressBar_value(void* progress_bar);
void QProgressBar_setRange(void* progress_bar, int minimum, int maximum);
int QProgressBar_minimum(void* progress_bar);
int QProgressBar_maximum(void* progress_bar);
void QProgressBar_reset(void* progress_bar);

// Format
void QProgressBar_setFormat(void* progress_bar, const char* format);
const char* QProgressBar_format(void* progress_bar);
void QProgressBar_resetFormat(void* progress_bar);
void QProgressBar_setTextVisible(void* progress_bar, bool visible);
bool QProgressBar_isTextVisible(void* progress_bar);

// Orientation
void QProgressBar_setOrientation(void* progress_bar, int orientation);
int QProgressBar_orientation(void* progress_bar);

// Appearance
void QProgressBar_setInvertedAppearance(void* progress_bar, bool invert);
bool QProgressBar_invertedAppearance(void* progress_bar);
void QProgressBar_setTextDirection(void* progress_bar, int direction);
int QProgressBar_textDirection(void* progress_bar);

// Signal handlers
typedef void (*QProgressBar_ValueChangedCallback)(void*, int);
void QProgressBar_setValueChangedCallback(void* progress_bar, QProgressBar_ValueChangedCallback callback);

// Constants
#define QPROGRESSBAR_HORIZONTAL 0
#define QPROGRESSBAR_VERTICAL 1

#define QPROGRESSBAR_BOTTOMTOTOP 0
#define QPROGRESSBAR_TOPTOBOTTOM 1

#ifdef __cplusplus
}
#endif

#endif // QPROGRESSBAR_C_H
