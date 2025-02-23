#include "c_q_grid_layout.h"
#include "bind_q_grid_layout.h"
#include "bind_q_widget.h"

extern "C" {

void* QGridLayout_create() {
    return new BindQGridLayout();
}

void QGridLayout_addWidget(void* layout, void* widget, int row, int column) {
    BindQGridLayout* gridLayout = static_cast<BindQGridLayout*>(layout);
    BindQWidget* qwidget = static_cast<BindQWidget*>(widget);
    gridLayout->addWidgetToGrid(qwidget, row, column);
}

}
