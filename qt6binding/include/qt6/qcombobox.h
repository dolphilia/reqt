#ifndef QCOMBOBOX_C_H
#define QCOMBOBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QComboBox
void* QComboBox_create(void* parent);
void QComboBox_delete(void* comboBox);
void QComboBox_addItem(void* comboBox, const char* text);
void QComboBox_addItems(void* comboBox, const char** items, int count);
void QComboBox_clear(void* comboBox);
const char* QComboBox_currentText(void* comboBox);
int QComboBox_currentIndex(void* comboBox);
int QComboBox_count(void* comboBox);
const char* QComboBox_itemText(void* comboBox, int index);
void QComboBox_setCurrentIndex(void* comboBox, int index);
void QComboBox_setCurrentText(void* comboBox, const char* text);
void QComboBox_setEditable(void* comboBox, bool editable);
bool QComboBox_isEditable(void* comboBox);
void QComboBox_setEnabled(void* comboBox, bool enabled);
bool QComboBox_isEnabled(void* comboBox);
typedef void (*CurrentIndexChangedCallback)(void* comboBox, int index);
typedef void (*CurrentTextChangedCallback)(void* comboBox, const char* text);
void QComboBox_setCurrentIndexChangedCallback(void* comboBox, CurrentIndexChangedCallback callback);
void QComboBox_setCurrentTextChangedCallback(void* comboBox, CurrentTextChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QCOMBOBOX_C_H
