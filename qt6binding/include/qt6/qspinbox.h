#ifndef QSPINBOX_C_H
#define QSPINBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QSpinBox creation/deletion
void* QSpinBox_create(void* parent);
void QSpinBox_delete(void* spin_box);

// Value operations
void QSpinBox_setValue(void* spin_box, int value);
int QSpinBox_value(void* spin_box);
void QSpinBox_setRange(void* spin_box, int minimum, int maximum);
int QSpinBox_minimum(void* spin_box);
int QSpinBox_maximum(void* spin_box);
void QSpinBox_setMinimum(void* spin_box, int minimum);
void QSpinBox_setMaximum(void* spin_box, int maximum);

// Step operations
void QSpinBox_setSingleStep(void* spin_box, int step);
int QSpinBox_singleStep(void* spin_box);

// Prefix and suffix
void QSpinBox_setPrefix(void* spin_box, const char* prefix);
const char* QSpinBox_prefix(void* spin_box);
void QSpinBox_setSuffix(void* spin_box, const char* suffix);
const char* QSpinBox_suffix(void* spin_box);

// Display format
void QSpinBox_setDisplayIntegerBase(void* spin_box, int base);
int QSpinBox_displayIntegerBase(void* spin_box);

// Wrapping
void QSpinBox_setWrapping(void* spin_box, bool wrapping);
bool QSpinBox_wrapping(void* spin_box);

// Special values
void QSpinBox_setSpecialValueText(void* spin_box, const char* text);
const char* QSpinBox_specialValueText(void* spin_box);

// Acceleration
void QSpinBox_setAccelerated(void* spin_box, bool accelerated);
bool QSpinBox_isAccelerated(void* spin_box);

// Read only
void QSpinBox_setReadOnly(void* spin_box, bool read_only);
bool QSpinBox_isReadOnly(void* spin_box);

// Button symbols
void QSpinBox_setButtonSymbols(void* spin_box, int button_symbols);
int QSpinBox_buttonSymbols(void* spin_box);

// Signal handlers
typedef void (*QSpinBoxValueChangedCallback)(int value);
typedef void (*QSpinBoxTextChangedCallback)(const char* text);
typedef void (*QSpinBoxEditingFinishedCallback)();

void QSpinBox_setValueChangedCallback(void* spin_box, QSpinBoxValueChangedCallback callback);
void QSpinBox_setTextChangedCallback(void* spin_box, QSpinBoxTextChangedCallback callback);
void QSpinBox_setEditingFinishedCallback(void* spin_box, QSpinBoxEditingFinishedCallback callback);

// Constants
#define QSPINBOX_BUTTON_SYMBOLS_UPDOWN 0
#define QSPINBOX_BUTTON_SYMBOLS_PLUSMINUS 1
#define QSPINBOX_BUTTON_SYMBOLS_NONE 2

#ifdef __cplusplus
}
#endif

#endif // QSPINBOX_C_H
