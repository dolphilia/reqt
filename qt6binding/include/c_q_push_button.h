#ifndef QPUSHBUTTON_C_H
#define QPUSHBUTTON_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QPushButton
void* QPushButton_create(const char* text, void* parent);
void QPushButton_delete(void* button);
void QPushButton_setText(void* button, const char* text);
const char* QPushButton_text(void* button);
void QPushButton_setIcon(void* button, const char* iconPath);
void QPushButton_setEnabled(void* button, bool enabled);
bool QPushButton_isEnabled(void* button);
void QPushButton_setCheckable(void* button, bool checkable);
bool QPushButton_isCheckable(void* button);
void QPushButton_setChecked(void* button, bool checked);
bool QPushButton_isChecked(void* button);
void QPushButton_setAutoRepeat(void* button, bool autoRepeat);
bool QPushButton_autoRepeat(void* button);
void QPushButton_click(void* button);
void QPushButton_setFlat(void* button, bool flat);
bool QPushButton_isFlat(void* button);
void QPushButton_setDefault(void* button, bool default_);
bool QPushButton_isDefault(void* button);
typedef void (*QPushButtonClickCallback)(void* button);
void QPushButton_setClickCallback(void* button, QPushButtonClickCallback callback);
void QPushButton_setPressedCallback(void* button, QPushButtonClickCallback callback);
void QPushButton_setReleasedCallback(void* button, QPushButtonClickCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QPUSHBUTTON_C_H
