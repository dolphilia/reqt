#include "QBoxLayoutBind.h"
#include <QBoxLayout>

extern "C" {

// Creation/Deletion
void* QBoxLayout_create(int direction, void* parent) {
    return new QBoxLayout(static_cast<QBoxLayout::Direction>(direction), static_cast<QWidget*>(parent));
}

void QBoxLayout_delete(void* layout) {
    delete static_cast<QBoxLayout*>(layout);
}

// Layout operations
void QBoxLayout_addLayout(void* layout, void* sublayout, int stretch) {
    static_cast<QBoxLayout*>(layout)->addLayout(static_cast<QLayout*>(sublayout), stretch);
}

void QBoxLayout_insertLayout(void* layout, int index, void* sublayout, int stretch) {
    static_cast<QBoxLayout*>(layout)->insertLayout(index, static_cast<QLayout*>(sublayout), stretch);
}

void QBoxLayout_addWidget(void* layout, void* widget, int stretch, int alignment) {
    static_cast<QBoxLayout*>(layout)->addWidget(static_cast<QWidget*>(widget), stretch, static_cast<Qt::Alignment>(alignment));
}

void QBoxLayout_insertWidget(void* layout, int index, void* widget, int stretch, int alignment) {
    static_cast<QBoxLayout*>(layout)->insertWidget(index, static_cast<QWidget*>(widget), stretch, static_cast<Qt::Alignment>(alignment));
}

// Spacer operations
void QBoxLayout_addSpacing(void* layout, int size) {
    static_cast<QBoxLayout*>(layout)->addSpacing(size);
}

void QBoxLayout_addStretch(void* layout, int stretch) {
    static_cast<QBoxLayout*>(layout)->addStretch(stretch);
}

void QBoxLayout_addStrut(void* layout, int size) {
    static_cast<QBoxLayout*>(layout)->addStrut(size);
}

void QBoxLayout_insertSpacing(void* layout, int index, int size) {
    static_cast<QBoxLayout*>(layout)->insertSpacing(index, size);
}

void QBoxLayout_insertStretch(void* layout, int index, int stretch) {
    static_cast<QBoxLayout*>(layout)->insertStretch(index, stretch);
}

// Direction management
int QBoxLayout_direction(void* layout) {
    return static_cast<int>(static_cast<QBoxLayout*>(layout)->direction());
}

void QBoxLayout_setDirection(void* layout, int direction) {
    static_cast<QBoxLayout*>(layout)->setDirection(static_cast<QBoxLayout::Direction>(direction));
}

// Stretch management
void QBoxLayout_setStretch(void* layout, int index, int stretch) {
    static_cast<QBoxLayout*>(layout)->setStretch(index, stretch);
}

bool QBoxLayout_setStretchFactorWidget(void* layout, void* widget, int stretch) {
    return static_cast<QBoxLayout*>(layout)->setStretchFactor(static_cast<QWidget*>(widget), stretch);
}

bool QBoxLayout_setStretchFactorLayout(void* layout, void* sublayout, int stretch) {
    return static_cast<QBoxLayout*>(layout)->setStretchFactor(static_cast<QLayout*>(sublayout), stretch);
}

int QBoxLayout_stretch(void* layout, int index) {
    return static_cast<QBoxLayout*>(layout)->stretch(index);
}

// Layout properties
int QBoxLayout_count(void* layout) {
    return static_cast<QBoxLayout*>(layout)->count();
}

void QBoxLayout_setSpacing(void* layout, int spacing) {
    static_cast<QBoxLayout*>(layout)->setSpacing(spacing);
}

int QBoxLayout_spacing(void* layout) {
    return static_cast<QBoxLayout*>(layout)->spacing();
}
}
