#ifndef QDOUBLESPINBOX_C_H
#define QDOUBLESPINBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QDoubleSpinBox_create(void* parent);
void QDoubleSpinBox_delete(void* double_spin_box);

// Value
void QDoubleSpinBox_setValue(void* double_spin_box, double value);
double QDoubleSpinBox_value(void* double_spin_box);
void QDoubleSpinBox_setRange(void* double_spin_box, double minimum, double maximum);
double QDoubleSpinBox_minimum(void* double_spin_box);
double QDoubleSpinBox_maximum(void* double_spin_box);
void QDoubleSpinBox_setSingleStep(void* double_spin_box, double step);
double QDoubleSpinBox_singleStep(void* double_spin_box);

// Decimals
void QDoubleSpinBox_setDecimals(void* double_spin_box, int decimals);
int QDoubleSpinBox_decimals(void* double_spin_box);

// Prefix/Suffix
void QDoubleSpinBox_setPrefix(void* double_spin_box, const char* prefix);
const char* QDoubleSpinBox_prefix(void* double_spin_box);
void QDoubleSpinBox_setSuffix(void* double_spin_box, const char* suffix);
const char* QDoubleSpinBox_suffix(void* double_spin_box);

// Wrapping
void QDoubleSpinBox_setWrapping(void* double_spin_box, bool wrapping);
bool QDoubleSpinBox_wrapping(void* double_spin_box);

// Special values
void QDoubleSpinBox_setSpecialValueText(void* double_spin_box, const char* text);
const char* QDoubleSpinBox_specialValueText(void* double_spin_box);

// Stepping
void QDoubleSpinBox_stepUp(void* double_spin_box);
void QDoubleSpinBox_stepDown(void* double_spin_box);

// Text
const char* QDoubleSpinBox_text(void* double_spin_box);

// Callbacks
typedef void (*QDoubleSpinBoxValueChangedCallback)(double value);
typedef void (*QDoubleSpinBoxEditingFinishedCallback)();

void QDoubleSpinBox_setValueChangedCallback(void* double_spin_box, QDoubleSpinBoxValueChangedCallback callback);
void QDoubleSpinBox_setEditingFinishedCallback(void* double_spin_box, QDoubleSpinBoxEditingFinishedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QDOUBLESPINBOX_C_H
