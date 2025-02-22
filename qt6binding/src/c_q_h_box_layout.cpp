#include "bind_q_h_box_layout.h"
#include "c_q_h_box_layout.h"

extern "C" {

void* QHBoxLayout_create(void* parent) {
    return QHBoxLayoutBind::create(static_cast<QWidget*>(parent));
}

void QHBoxLayout_delete(void* layout) {
    QHBoxLayoutBind::destroy(static_cast<QHBoxLayout*>(layout));
}

void QHBoxLayout_addWidget(void* layout, void* widget) {
    QHBoxLayoutBind::addWidget(static_cast<QHBoxLayout*>(layout), static_cast<QWidget*>(widget));
}

void QHBoxLayout_addLayout(void* layout, void* other) {
    QHBoxLayoutBind::addLayout(static_cast<QHBoxLayout*>(layout), static_cast<QLayout*>(other));
}

void QHBoxLayout_addStretch(void* layout, int stretch) {
    QHBoxLayoutBind::addStretch(static_cast<QHBoxLayout*>(layout), stretch);
}

void QHBoxLayout_addSpacing(void* layout, int size) {
    QHBoxLayoutBind::addSpacing(static_cast<QHBoxLayout*>(layout), size);
}

void QHBoxLayout_setSpacing(void* layout, int spacing) {
    QHBoxLayoutBind::setSpacing(static_cast<QHBoxLayout*>(layout), spacing);
}

int QHBoxLayout_spacing(void* layout) {
    return QHBoxLayoutBind::spacing(static_cast<QHBoxLayout*>(layout));
}

void QHBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom) {
    QHBoxLayoutBind::setContentsMargins(static_cast<QHBoxLayout*>(layout), left, top, right, bottom);
}

void QHBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom) {
    QHBoxLayoutBind::getContentsMargins(static_cast<QHBoxLayout*>(layout), left, top, right, bottom);
}

}
