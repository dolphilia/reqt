#ifndef QDIAL_C_H
#define QDIAL_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QDial作成・削除
void* QDial_create(void* parent);
void QDial_delete(void* dial);

// プロパティ設定
void QDial_setMinimum(void* dial, int min);
void QDial_setMaximum(void* dial, int max);
void QDial_setRange(void* dial, int min, int max);
void QDial_setValue(void* dial, int value);
void QDial_setSingleStep(void* dial, int step);
void QDial_setPageStep(void* dial, int step);
void QDial_setNotchTarget(void* dial, double target);
void QDial_setNotchesVisible(void* dial, bool visible);
void QDial_setWrapping(void* dial, bool wrapping);

// プロパティ取得
int QDial_minimum(void* dial);
int QDial_maximum(void* dial);
int QDial_value(void* dial);
int QDial_singleStep(void* dial);
int QDial_pageStep(void* dial);
double QDial_notchTarget(void* dial);
bool QDial_notchesVisible(void* dial);
bool QDial_wrapping(void* dial);

// イベントコールバック
typedef void (*QDialValueChangedCallback)(void* dial, int value);
typedef void (*QDialSliderMovedCallback)(void* dial, int position);
typedef void (*QDialSliderPressedCallback)(void* dial);
typedef void (*QDialSliderReleasedCallback)(void* dial);

void QDial_setValueChangedCallback(void* dial, QDialValueChangedCallback callback);
void QDial_setSliderMovedCallback(void* dial, QDialSliderMovedCallback callback);
void QDial_setSliderPressedCallback(void* dial, QDialSliderPressedCallback callback);
void QDial_setSliderReleasedCallback(void* dial, QDialSliderReleasedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QDIAL_C_H
