#include "bind_q_h_box_layout.h"

QHBoxLayout* QHBoxLayoutBind::create(QWidget* parent) {
    return new QHBoxLayout(parent);
}

void QHBoxLayoutBind::destroy(QHBoxLayout* layout) {
    if (layout) {
        delete layout;
    }
}

void QHBoxLayoutBind::addWidget(QHBoxLayout* layout, QWidget* widget) {
    if (layout && widget) {
        layout->addWidget(widget);
    }
}

void QHBoxLayoutBind::addLayout(QHBoxLayout* layout, QLayout* other) {
    if (layout && other) {
        layout->addLayout(other);
    }
}

void QHBoxLayoutBind::addStretch(QHBoxLayout* layout, int stretch) {
    if (layout) {
        layout->addStretch(stretch);
    }
}

void QHBoxLayoutBind::addSpacing(QHBoxLayout* layout, int size) {
    if (layout) {
        layout->addSpacing(size);
    }
}

void QHBoxLayoutBind::setSpacing(QHBoxLayout* layout, int spacing) {
    if (layout) {
        layout->setSpacing(spacing);
    }
}

int QHBoxLayoutBind::spacing(QHBoxLayout* layout) {
    return layout ? layout->spacing() : 0;
}

void QHBoxLayoutBind::setContentsMargins(QHBoxLayout* layout, int left, int top, int right, int bottom) {
    if (layout) {
        layout->setContentsMargins(left, top, right, bottom);
    }
}

void QHBoxLayoutBind::getContentsMargins(QHBoxLayout* layout, int* left, int* top, int* right, int* bottom) {
    if (layout) {
        layout->getContentsMargins(left, top, right, bottom);
    } else {
        if (left) *left = 0;
        if (top) *top = 0;
        if (right) *right = 0;
        if (bottom) *bottom = 0;
    }
}
