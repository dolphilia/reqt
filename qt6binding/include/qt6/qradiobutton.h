#ifndef QRADIOBUTTON_C_H
#define QRADIOBUTTON_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QRadioButton creation/deletion
void* QRadioButton_create(void* parent);
void* QRadioButton_createWithText(const char* text, void* parent);
void QRadioButton_delete(void* radio_button);

// Properties
void QRadioButton_setText(void* radio_button, const char* text);
const char* QRadioButton_text(void* radio_button);
void QRadioButton_setChecked(void* radio_button, bool checked);
bool QRadioButton_isChecked(void* radio_button);
void QRadioButton_setEnabled(void* radio_button, bool enabled);
bool QRadioButton_isEnabled(void* radio_button);

// Icon and shortcut
void QRadioButton_setIcon(void* radio_button, const char* icon_path);
void QRadioButton_setShortcut(void* radio_button, const char* shortcut);

// Auto exclusive
void QRadioButton_setAutoExclusive(void* radio_button, bool auto_exclusive);
bool QRadioButton_autoExclusive(void* radio_button);

// Signal handlers
typedef void (*QRadioButtonToggledCallback)(bool checked);
typedef void (*QRadioButtonClickedCallback)(bool checked);
typedef void (*QRadioButtonPressedCallback)();
typedef void (*QRadioButtonReleasedCallback)();

void QRadioButton_setToggledCallback(void* radio_button, QRadioButtonToggledCallback callback);
void QRadioButton_setClickedCallback(void* radio_button, QRadioButtonClickedCallback callback);
void QRadioButton_setPressedCallback(void* radio_button, QRadioButtonPressedCallback callback);
void QRadioButton_setReleasedCallback(void* radio_button, QRadioButtonReleasedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QRADIOBUTTON_C_H
