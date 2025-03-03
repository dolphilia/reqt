#include "QGridLayoutBind.h"
#include "qgridlayout.h"

extern "C" {

void* QGridLayout_create(void* parent) {
    return new QGridLayoutBind(static_cast<QWidget*>(parent));
}

void QGridLayout_delete(void* gridLayout) {
    delete static_cast<QGridLayoutBind*>(gridLayout);
}

void QGridLayout_addWidget(void* gridLayout, void* widget, int row, int column) {
    static_cast<QGridLayoutBind*>(gridLayout)->addWidgetToGrid(static_cast<QWidget*>(widget), row, column);
}

void QGridLayout_addLayout(void* gridLayout, void* layout, int row, int column) {
    static_cast<QGridLayoutBind*>(gridLayout)->addLayout(static_cast<QLayout*>(layout), row, column);
}

void QGridLayout_addLayoutWithSpan(void* gridLayout, void* layout, int row, int column, int rowSpan, int columnSpan) {
    static_cast<QGridLayoutBind*>(gridLayout)->addLayout(static_cast<QLayout*>(layout), row, column, rowSpan, columnSpan);
}

void QGridLayout_addWidgetWithSpan(void* gridLayout, void* widget, int row, int column, int rowSpan, int columnSpan) {
    static_cast<QGridLayoutBind*>(gridLayout)->addWidget(static_cast<QWidget*>(widget), row, column, rowSpan, columnSpan);
}

int QGridLayout_rowCount(void* gridLayout) {
    return static_cast<QGridLayoutBind*>(gridLayout)->rowCount();
}

int QGridLayout_columnCount(void* gridLayout) {
    return static_cast<QGridLayoutBind*>(gridLayout)->columnCount();
}

void QGridLayout_setRowStretch(void* gridLayout, int row, int stretch) {
    static_cast<QGridLayoutBind*>(gridLayout)->setRowStretch(row, stretch);
}

void QGridLayout_setColumnStretch(void* gridLayout, int column, int stretch) {
    static_cast<QGridLayoutBind*>(gridLayout)->setColumnStretch(column, stretch);
}

void QGridLayout_setRowMinimumHeight(void* gridLayout, int row, int minSize) {
    static_cast<QGridLayoutBind*>(gridLayout)->setRowMinimumHeight(row, minSize);
}

void QGridLayout_setColumnMinimumWidth(void* gridLayout, int column, int minSize) {
    static_cast<QGridLayoutBind*>(gridLayout)->setColumnMinimumWidth(column, minSize);
}

void QGridLayout_setHorizontalSpacing(void* gridLayout, int spacing) {
    static_cast<QGridLayoutBind*>(gridLayout)->setHorizontalSpacing(spacing);
}

void QGridLayout_setVerticalSpacing(void* gridLayout, int spacing) {
    static_cast<QGridLayoutBind*>(gridLayout)->setVerticalSpacing(spacing);
}

int QGridLayout_horizontalSpacing(void* gridLayout) {
    return static_cast<QGridLayoutBind*>(gridLayout)->horizontalSpacing();
}

int QGridLayout_verticalSpacing(void* gridLayout) {
    return static_cast<QGridLayoutBind*>(gridLayout)->verticalSpacing();
}

void QGridLayout_setSpacing(void* gridLayout, int spacing) {
    static_cast<QGridLayoutBind*>(gridLayout)->setSpacing(spacing);
}

int QGridLayout_spacing(void* gridLayout) {
    return static_cast<QGridLayoutBind*>(gridLayout)->spacing();
}

typedef void (*CellEmptyChangedCallback)(void*, int, int);

void QGridLayout_setCellEmptyChangedCallback(void* gridLayout, CellEmptyChangedCallback callback) {
    static_cast<QGridLayoutBind*>(gridLayout)->setCellEmptyChangedCallback(callback);
}

}
