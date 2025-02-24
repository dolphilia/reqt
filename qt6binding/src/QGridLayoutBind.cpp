#include "QGridLayoutBind.h"

BindQGridLayout::BindQGridLayout() : QGridLayout() {}

void BindQGridLayout::addWidgetToGrid(QWidget* widget, int row, int column) {
    addWidget(widget, row, column);
}
