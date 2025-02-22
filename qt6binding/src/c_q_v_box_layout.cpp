#include "bind_q_v_box_layout.h"
#include "c_q_v_box_layout.h"

extern "C" {

void* QVBoxLayout_create(void* parent) {
    return QVBoxLayoutBind::create(static_cast<QWidget*>(parent));
}

void QVBoxLayout_delete(void* layout) {
    QVBoxLayoutBind::destroy(static_cast<QVBoxLayout*>(layout));
}

void QVBoxLayout_addWidget(void* layout, void* widget) {
    QVBoxLayoutBind::addWidget(static_cast<QVBoxLayout*>(layout), static_cast<QWidget*>(widget));
}

void QVBoxLayout_addLayout(void* layout, void* other) {
    QVBoxLayoutBind::addLayout(static_cast<QVBoxLayout*>(layout), static_cast<QLayout*>(other));
}

void QVBoxLayout_addStretch(void* layout, int stretch) {
    QVBoxLayoutBind::addStretch(static_cast<QVBoxLayout*>(layout), stretch);
}

void QVBoxLayout_addSpacing(void* layout, int size) {
    QVBoxLayoutBind::addSpacing(static_cast<QVBoxLayout*>(layout), size);
}

void QVBoxLayout_setSpacing(void* layout, int spacing) {
    QVBoxLayoutBind::setSpacing(static_cast<QVBoxLayout*>(layout), spacing);
}

int QVBoxLayout_spacing(void* layout) {
    return QVBoxLayoutBind::spacing(static_cast<QVBoxLayout*>(layout));
}

void QVBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom) {
    QVBoxLayoutBind::setContentsMargins(static_cast<QVBoxLayout*>(layout), left, top, right, bottom);
}

void QVBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom) {
    QVBoxLayoutBind::getContentsMargins(static_cast<QVBoxLayout*>(layout), left, top, right, bottom);
}

}
