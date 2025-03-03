#include "QGroupBoxBind.h"
#include "qgroupbox.h"

extern "C" {
typedef void (*ToggledCallback)(void*, bool);

void* QGroupBox_create(void* parent) {
    return new QGroupBoxBind(static_cast<QWidget*>(parent));
}

void* QGroupBox_create_with_title(const char* title, void* parent) {
    return new QGroupBoxBind(QString::fromUtf8(title), static_cast<QWidget*>(parent));
}

void QGroupBox_delete(void* groupBox) {
    delete static_cast<QGroupBoxBind*>(groupBox);
}

void QGroupBox_setTitle(void* groupBox, const char* title) {
    static_cast<QGroupBoxBind*>(groupBox)->setTitle(QString::fromUtf8(title));
}

const char* QGroupBox_title(void* groupBox) {
    return static_cast<QGroupBoxBind*>(groupBox)->title().toUtf8().constData();
}

void QGroupBox_setAlignment(void* groupBox, int alignment) {
    static_cast<QGroupBoxBind*>(groupBox)->setAlignment(static_cast<Qt::Alignment>(alignment));
}

void QGroupBox_setFlat(void* groupBox, bool flat) {
    static_cast<QGroupBoxBind*>(groupBox)->setFlat(flat);
}

bool QGroupBox_isFlat(void* groupBox) {
    return static_cast<QGroupBoxBind*>(groupBox)->isFlat();
}

void QGroupBox_setCheckable(void* groupBox, bool checkable) {
    static_cast<QGroupBoxBind*>(groupBox)->setCheckable(checkable);
}

bool QGroupBox_isCheckable(void* groupBox) {
    return static_cast<QGroupBoxBind*>(groupBox)->isCheckable();
}

void QGroupBox_setChecked(void* groupBox, bool checked) {
    static_cast<QGroupBoxBind*>(groupBox)->setChecked(checked);
}

bool QGroupBox_isChecked(void* groupBox) {
    return static_cast<QGroupBoxBind*>(groupBox)->isChecked();
}

void QGroupBox_setToggledCallback(void* groupBox, ToggledCallback callback) {
    static_cast<QGroupBoxBind*>(groupBox)->setToggledCallback(callback);
}

}
