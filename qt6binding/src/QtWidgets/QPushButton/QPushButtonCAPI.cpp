#include "QPushButtonBind.h"
#include "qpushbutton.h"

extern "C" {

void* QPushButton_create(const char* text, void* parent) {
    return new QPushButtonBind(text, static_cast<QWidget*>(parent));
}

void QPushButton_delete(void* pushButton) {
    delete static_cast<QPushButtonBind*>(pushButton);
}

void QPushButton_setText(void* pushButton, const char* text) {
    if (text) {
        static_cast<QPushButtonBind*>(pushButton)->setText(QString::fromUtf8(text));
    }
}

const char* QPushButton_text(void* pushButton) {
    static QString str;
    str = static_cast<QPushButtonBind*>(pushButton)->text();
    return str.toUtf8().constData();
}

void QPushButton_setIcon(void* pushButton, const char* iconPath) {
    if (iconPath) {
        static_cast<QPushButtonBind*>(pushButton)->setIcon(QIcon(QString::fromUtf8(iconPath)));
    }
}

void QPushButton_setEnabled(void* pushButton, bool enabled) {
    static_cast<QPushButtonBind*>(pushButton)->setEnabled(enabled);
}

bool QPushButton_isEnabled(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->isEnabled();
}

void QPushButton_setCheckable(void* pushButton, bool checkable) {
    static_cast<QPushButtonBind*>(pushButton)->setCheckable(checkable);
}

bool QPushButton_isCheckable(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->isCheckable();
}

void QPushButton_setChecked(void* pushButton, bool checked) {
    static_cast<QPushButtonBind*>(pushButton)->setChecked(checked);
}

bool QPushButton_isChecked(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->isChecked();
}

void QPushButton_setAutoRepeat(void* pushButton, bool autoRepeat) {
    static_cast<QPushButtonBind*>(pushButton)->setAutoRepeat(autoRepeat);
}

bool QPushButton_autoRepeat(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->autoRepeat();
}

void QPushButton_click(void* pushButton) {
    static_cast<QPushButtonBind*>(pushButton)->click();
}

void QPushButton_setFlat(void* pushButton, bool flat) {
    static_cast<QPushButtonBind*>(pushButton)->setFlat(flat);
}

bool QPushButton_isFlat(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->isFlat();
}

void QPushButton_setDefault(void* pushButton, bool default_) {
    static_cast<QPushButtonBind*>(pushButton)->setDefault(default_);
}

bool QPushButton_isDefault(void* pushButton) {
    return static_cast<QPushButtonBind*>(pushButton)->isDefault();
}

void QPushButton_setClickedCallback(void* pushButton, ClickedCallback callback) {
    static_cast<QPushButtonBind*>(pushButton)->setClickedCallback(callback);
}

void QPushButton_setPressedCallback(void* pushButton, PressedCallback callback) {
    static_cast<QPushButtonBind*>(pushButton)->setPressedCallback(callback);
}

void QPushButton_setReleasedCallback(void* pushButton, ReleasedCallback callback) {
    static_cast<QPushButtonBind*>(pushButton)->setReleasedCallback(callback);
}

}
