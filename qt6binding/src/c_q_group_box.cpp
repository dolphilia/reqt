#include "../include/c_q_group_box.h"
#include "../include/bind_q_group_box.h"
#include "../include/handler_group_box.h"
#include <QString>
#include <QObject>

extern "C" {

void* QGroupBox_create(void* parent) {
    return new BindQGroupBox(reinterpret_cast<QWidget*>(parent));
}

void* QGroupBox_create_with_title(const char* title, void* parent) {
    return new BindQGroupBox(QString::fromUtf8(title), reinterpret_cast<QWidget*>(parent));
}

void QGroupBox_delete(void* groupBox) {
    delete static_cast<BindQGroupBox*>(groupBox);
}

void QGroupBox_setTitle(void* groupBox, const char* title) {
    static_cast<BindQGroupBox*>(groupBox)->setTitle(QString::fromUtf8(title));
}

const char* QGroupBox_title(void* groupBox) {
    return static_cast<BindQGroupBox*>(groupBox)->title().toUtf8().constData();
}

void QGroupBox_setAlignment(void* groupBox, int alignment) {
    static_cast<BindQGroupBox*>(groupBox)->setAlignment(alignment);
}

void QGroupBox_setFlat(void* groupBox, bool flat) {
    static_cast<BindQGroupBox*>(groupBox)->setFlat(flat);
}

bool QGroupBox_isFlat(void* groupBox) {
    return static_cast<BindQGroupBox*>(groupBox)->isFlat();
}

void QGroupBox_setCheckable(void* groupBox, bool checkable) {
    static_cast<BindQGroupBox*>(groupBox)->setCheckable(checkable);
}

bool QGroupBox_isCheckable(void* groupBox) {
    return static_cast<BindQGroupBox*>(groupBox)->isCheckable();
}

void QGroupBox_setChecked(void* groupBox, bool checked) {
    static_cast<BindQGroupBox*>(groupBox)->setChecked(checked);
}

bool QGroupBox_isChecked(void* groupBox) {
    return static_cast<BindQGroupBox*>(groupBox)->isChecked();
}

void QGroupBox_setToggleCallback(void* groupBox, void (*callback)(void*, bool)) {
    auto* handler = new HandlerGroupBox();
    handler->widget = groupBox;
    handler->setToggleCallback(callback);
    QObject::connect(static_cast<BindQGroupBox*>(groupBox), &QGroupBox::toggled,
                    handler, &HandlerGroupBox::onToggled);
}

}
