#ifndef QCHECKBOX_C_H
#define QCHECKBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QCheckBox
void* QCheckBox_create(const char* text, void* parent);
void QCheckBox_delete(void* checkbox);
void QCheckBox_setText(void* checkbox, const char* text);
const char* QCheckBox_text(void* checkbox);
void QCheckBox_setChecked(void* checkbox, bool checked);
bool QCheckBox_isChecked(void* checkbox);
void QCheckBox_setTristate(void* checkbox, bool tristate);
bool QCheckBox_isTristate(void* checkbox);
void QCheckBox_setCheckState(void* checkbox, int state);
int QCheckBox_checkState(void* checkbox);
void QCheckBox_setEnabled(void* checkbox, bool enabled);
bool QCheckBox_isEnabled(void* checkbox);

// チェック状態の定数
#define QCHECKBOX_UNCHECKED 0
#define QCHECKBOX_PARTIALLY_CHECKED 1
#define QCHECKBOX_CHECKED 2

// コールバック関数の型定義
typedef void (*StateChangedCallback)(void* checkbox, int state);
typedef void (*ToggledCallback)(void* checkbox, bool checked);
typedef void (*Callback)(void* checkbox, bool checked);

// コールバック設定関数
void QCheckBox_setStateChangedCallback(void* checkbox, StateChangedCallback callback);
void QCheckBox_setToggledCallback(void* checkbox, ToggledCallback callback);
void QCheckBox_setClickedCallback(void* checkbox, Callback callback);

#ifdef __cplusplus
}
#endif

#endif // QCHECKBOX_C_H
