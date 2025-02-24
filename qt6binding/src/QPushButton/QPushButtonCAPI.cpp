#include "QPushButtonBind.h"

extern "C" {

void* QPushButton_create(const char* text, void* parent) {
    return QPushButtonBind::create(text, static_cast<QWidget*>(parent));
}

void QPushButton_delete(void* button) {
    QPushButtonBind::destroy(static_cast<QPushButton*>(button));
}

void QPushButton_setText(void* button, const char* text) {
    QPushButtonBind::setText(static_cast<QPushButton*>(button), text);
}

const char* QPushButton_text(void* button) {
    return QPushButtonBind::text(static_cast<QPushButton*>(button));
}

void QPushButton_setIcon(void* button, const char* iconPath) {
    QPushButtonBind::setIcon(static_cast<QPushButton*>(button), iconPath);
}

void QPushButton_setEnabled(void* button, bool enabled) {
    QPushButtonBind::setEnabled(static_cast<QPushButton*>(button), enabled);
}

bool QPushButton_isEnabled(void* button) {
    return QPushButtonBind::isEnabled(static_cast<QPushButton*>(button));
}

void QPushButton_setCheckable(void* button, bool checkable) {
    QPushButtonBind::setCheckable(static_cast<QPushButton*>(button), checkable);
}

bool QPushButton_isCheckable(void* button) {
    return QPushButtonBind::isCheckable(static_cast<QPushButton*>(button));
}

void QPushButton_setChecked(void* button, bool checked) {
    QPushButtonBind::setChecked(static_cast<QPushButton*>(button), checked);
}

bool QPushButton_isChecked(void* button) {
    return QPushButtonBind::isChecked(static_cast<QPushButton*>(button));
}

void QPushButton_setAutoRepeat(void* button, bool autoRepeat) {
    QPushButtonBind::setAutoRepeat(static_cast<QPushButton*>(button), autoRepeat);
}

bool QPushButton_autoRepeat(void* button) {
    return QPushButtonBind::autoRepeat(static_cast<QPushButton*>(button));
}

void QPushButton_click(void* button) {
    QPushButtonBind::click(static_cast<QPushButton*>(button));
}

void QPushButton_setFlat(void* button, bool flat) {
    QPushButtonBind::setFlat(static_cast<QPushButton*>(button), flat);
}

bool QPushButton_isFlat(void* button) {
    return QPushButtonBind::isFlat(static_cast<QPushButton*>(button));
}

void QPushButton_setDefault(void* button, bool default_) {
    QPushButtonBind::setDefault(static_cast<QPushButton*>(button), default_);
}

bool QPushButton_isDefault(void* button) {
    return QPushButtonBind::isDefault(static_cast<QPushButton*>(button));
}

void QPushButton_setClickCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setClickCallback(static_cast<QPushButton*>(button), callback);
}

void QPushButton_setPressedCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setPressedCallback(static_cast<QPushButton*>(button), callback);
}

void QPushButton_setReleasedCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setReleasedCallback(static_cast<QPushButton*>(button), callback);
}

}
