#ifndef QCHECKBOX_BIND_H
#define QCHECKBOX_BIND_H

#include <QCheckBox>

typedef void (*QCheckBoxStateChangedCallback)(void* checkbox, int state);
typedef void (*QCheckBoxToggledCallback)(void* checkbox, bool checked);

class QCheckBoxBind {
public:
    static QCheckBox* create(const char* text, QWidget* parent = nullptr);
    static void destroy(QCheckBox* checkbox);
    static void setText(QCheckBox* checkbox, const char* text);
    static const char* text(QCheckBox* checkbox);
    static void setChecked(QCheckBox* checkbox, bool checked);
    static bool isChecked(QCheckBox* checkbox);
    static void setTristate(QCheckBox* checkbox, bool tristate);
    static bool isTristate(QCheckBox* checkbox);
    static void setCheckState(QCheckBox* checkbox, int state);
    static int checkState(QCheckBox* checkbox);
    static void setEnabled(QCheckBox* checkbox, bool enabled);
    static bool isEnabled(QCheckBox* checkbox);
    static void setStateChangedCallback(QCheckBox* checkbox, QCheckBoxStateChangedCallback callback);
    static void setToggledCallback(QCheckBox* checkbox, QCheckBoxToggledCallback callback);
    static void setClickedCallback(QCheckBox* checkbox, QCheckBoxToggledCallback callback);
};

#endif // QCHECKBOX_BIND_H
