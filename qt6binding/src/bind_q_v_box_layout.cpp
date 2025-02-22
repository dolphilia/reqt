#include "bind_q_v_box_layout.h"

QVBoxLayout* QVBoxLayoutBind::create(QWidget* parent) {
    return new QVBoxLayout(parent);
}

void QVBoxLayoutBind::destroy(QVBoxLayout* layout) {
    if (layout) {
        delete layout;
    }
}

void QVBoxLayoutBind::addWidget(QVBoxLayout* layout, QWidget* widget) {
    if (layout && widget) {
        layout->addWidget(widget);
    }
}

void QVBoxLayoutBind::addLayout(QVBoxLayout* layout, QLayout* other) {
    if (layout && other) {
        layout->addLayout(other);
    }
}

void QVBoxLayoutBind::addStretch(QVBoxLayout* layout, int stretch) {
    if (layout) {
        layout->addStretch(stretch);
    }
}

void QVBoxLayoutBind::addSpacing(QVBoxLayout* layout, int size) {
    if (layout) {
        layout->addSpacing(size);
    }
}

void QVBoxLayoutBind::setSpacing(QVBoxLayout* layout, int spacing) {
    if (layout) {
        layout->setSpacing(spacing);
    }
}

int QVBoxLayoutBind::spacing(QVBoxLayout* layout) {
    return layout ? layout->spacing() : 0;
}

void QVBoxLayoutBind::setContentsMargins(QVBoxLayout* layout, int left, int top, int right, int bottom) {
    if (layout) {
        layout->setContentsMargins(left, top, right, bottom);
    }
}

void QVBoxLayoutBind::getContentsMargins(QVBoxLayout* layout, int* left, int* top, int* right, int* bottom) {
    if (layout) {
        layout->getContentsMargins(left, top, right, bottom);
    } else {
        if (left) *left = 0;
        if (top) *top = 0;
        if (right) *right = 0;
        if (bottom) *bottom = 0;
    }
}
