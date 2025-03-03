#include "QHBoxLayoutBind.h"
#include "qhboxlayout.h"

extern "C" {

typedef void (*VoidCallback)(void*);

void* QHBoxLayout_create(void* parent) {
    return new QHBoxLayoutBind(static_cast<QWidget*>(parent));
}

void QHBoxLayout_delete(void* layout) {
    delete static_cast<QHBoxLayoutBind*>(layout);
}

void QHBoxLayout_addWidget(void* layout, void* widget) {
    static_cast<QHBoxLayoutBind*>(layout)->addWidget(static_cast<QWidget*>(widget));
}

void QHBoxLayout_addLayout(void* layout, void* other) {
    static_cast<QHBoxLayoutBind*>(layout)->addLayout(static_cast<QLayout*>(other));
}

void QHBoxLayout_addStretch(void* layout, int stretch) {
    static_cast<QHBoxLayoutBind*>(layout)->addStretch(stretch);
}

void QHBoxLayout_addSpacing(void* layout, int size) {
    static_cast<QHBoxLayoutBind*>(layout)->addSpacing(size);
}

void QHBoxLayout_setSpacing(void* layout, int spacing) {
    static_cast<QHBoxLayoutBind*>(layout)->setSpacing(spacing);
}

int QHBoxLayout_spacing(void* layout) {
    return static_cast<QHBoxLayoutBind*>(layout)->spacing();
}

void QHBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom) {
    static_cast<QHBoxLayoutBind*>(layout)->setContentsMargins(left, top, right, bottom);
}

void QHBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom) {
    static_cast<QHBoxLayoutBind*>(layout)->getContentsMargins(left, top, right, bottom);
}

}
