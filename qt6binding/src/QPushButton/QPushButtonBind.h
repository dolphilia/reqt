#ifndef QPUSHBUTTON_BIND_H
#define QPUSHBUTTON_BIND_H

#include <QPushButton>

typedef void (*QPushButtonClickCallback)(void* button);

class QPushButtonBind {
public:
    static QPushButton* create(const char* text, QWidget* parent = nullptr);
    static void destroy(QPushButton* button);
    static void setText(QPushButton* button, const char* text);
    static const char* text(QPushButton* button);
    static void setIcon(QPushButton* button, const char* iconPath);
    static void setEnabled(QPushButton* button, bool enabled);
    static bool isEnabled(QPushButton* button);
    static void setCheckable(QPushButton* button, bool checkable);
    static bool isCheckable(QPushButton* button);
    static void setChecked(QPushButton* button, bool checked);
    static bool isChecked(QPushButton* button);
    static void setAutoRepeat(QPushButton* button, bool autoRepeat);
    static bool autoRepeat(QPushButton* button);
    static void click(QPushButton* button);
    static void setFlat(QPushButton* button, bool flat);
    static bool isFlat(QPushButton* button);
    static void setDefault(QPushButton* button, bool default_);
    static bool isDefault(QPushButton* button);
    static void setClickCallback(QPushButton* button, QPushButtonClickCallback callback);
    static void setPressedCallback(QPushButton* button, QPushButtonClickCallback callback);
    static void setReleasedCallback(QPushButton* button, QPushButtonClickCallback callback);
};

#endif // QPUSHBUTTON_BIND_H
