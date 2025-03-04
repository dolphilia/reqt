#include "QVBoxLayoutBind.h"

extern "C" {

void* QVBoxLayout_create(void* parent) {
    return new QVBoxLayoutBind(static_cast<QWidget*>(parent));
}

void QVBoxLayout_delete(void* layout) {
    delete static_cast<QVBoxLayoutBind*>(layout);
}

void QVBoxLayout_addWidget(void* layout, void* widget) {
    static_cast<QVBoxLayoutBind*>(layout)->addWidget(static_cast<QWidget*>(widget));
}

void QVBoxLayout_addLayout(void* layout, void* other) {
    static_cast<QVBoxLayoutBind*>(layout)->addLayout(static_cast<QLayout*>(other));
}

void QVBoxLayout_addStretch(void* layout, int stretch) {
    static_cast<QVBoxLayoutBind*>(layout)->addStretch(stretch);
}

void QVBoxLayout_addSpacing(void* layout, int size) {
    static_cast<QVBoxLayoutBind*>(layout)->addSpacing(size);
}

void QVBoxLayout_setSpacing(void* layout, int spacing) {
    static_cast<QVBoxLayoutBind*>(layout)->setSpacing(spacing);
}

int QVBoxLayout_spacing(void* layout) {
    return static_cast<QVBoxLayoutBind*>(layout)->spacing();
}

void QVBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom) {
    static_cast<QVBoxLayoutBind*>(layout)->setContentsMargins(left, top, right, bottom);
}

void QVBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom) {
    static_cast<QVBoxLayoutBind*>(layout)->getContentsMargins(left, top, right, bottom);
}

}
