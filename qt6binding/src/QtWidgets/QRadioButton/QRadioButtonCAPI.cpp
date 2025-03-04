#include "QRadioButtonBind.h"

extern "C" {

void* QRadioButton_create(void* parent) {
    return new QRadioButtonBind(static_cast<QWidget*>(parent));
}

void* QRadioButton_createWithText(const char* text, void* parent) {
    return new QRadioButtonBind(QString::fromUtf8(text), static_cast<QWidget*>(parent));
}

void QRadioButton_delete(void* radioButton) {
    delete static_cast<QRadioButtonBind*>(radioButton);
}

void QRadioButton_setText(void* radioButton, const char* text) {
    static_cast<QRadioButtonBind*>(radioButton)->setText(QString::fromUtf8(text));
}

const char* QRadioButton_text(void* radioButton) {
    const QString qstr = static_cast<QRadioButtonBind*>(radioButton)->text();
    return qstr.toUtf8().constData();
}

void QRadioButton_setChecked(void* radioButton, bool checked) {
    static_cast<QRadioButtonBind*>(radioButton)->setChecked(checked);
}

bool QRadioButton_isChecked(void* radioButton) {
    return static_cast<QRadioButtonBind*>(radioButton)->isChecked();
}

void QRadioButton_setEnabled(void* radioButton, bool enabled) {
    static_cast<QRadioButtonBind*>(radioButton)->setEnabled(enabled);
}

bool QRadioButton_isEnabled(void* radioButton) {
    return static_cast<QRadioButtonBind*>(radioButton)->isEnabled();
}

void QRadioButton_setIcon(void* radioButton, const char* iconPath) {
    static_cast<QRadioButtonBind*>(radioButton)->setIcon(QIcon(QString::fromUtf8(iconPath)));
}

void QRadioButton_setShortcut(void* radioButton, const char* shortcut) {
    static_cast<QRadioButtonBind*>(radioButton)->setShortcut(QKeySequence(QString::fromUtf8(shortcut)));
}

void QRadioButton_setAutoExclusive(void* radioButton, bool autoExclusive) {
    static_cast<QRadioButtonBind*>(radioButton)->setAutoExclusive(autoExclusive);
}

bool QRadioButton_autoExclusive(void* radioButton) {
    return static_cast<QRadioButtonBind*>(radioButton)->autoExclusive();
}

typedef void (*QRadioButton_ToggledCallback)(void*, bool);
typedef void (*QRadioButton_ClickedCallback)(void*, bool);
typedef void (*QRadioButton_PressedCallback)(void*);
typedef void (*QRadioButton_ReleasedCallback)(void*);

void QRadioButton_setToggledCallback(void* radioButton, QRadioButton_ToggledCallback callback) {
    static_cast<QRadioButtonBind*>(radioButton)->setToggledCallback(callback);
}

void QRadioButton_setClickedCallback(void* radioButton, QRadioButton_ClickedCallback callback) {
    static_cast<QRadioButtonBind*>(radioButton)->setClickedCallback(callback);
}

void QRadioButton_setPressedCallback(void* radioButton, QRadioButton_PressedCallback callback) {
    static_cast<QRadioButtonBind*>(radioButton)->setPressedCallback(callback);
}

void QRadioButton_setReleasedCallback(void* radioButton, QRadioButton_ReleasedCallback callback) {
    static_cast<QRadioButtonBind*>(radioButton)->setReleasedCallback(callback);
}

}
