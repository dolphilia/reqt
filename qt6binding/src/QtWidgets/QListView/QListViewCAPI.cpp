#include "QListViewBind.h"
#include "qlistview.h"

extern "C" {

void* QListView_create(void* parent) {
    return new QListViewBind(static_cast<QWidget*>(parent));
}

void QListView_delete(void* listView) {
    delete static_cast<QListViewBind*>(listView);
}

void QListView_setModel(void* listView, void* model) {
    static_cast<QListViewBind*>(listView)->setModel(static_cast<QAbstractItemModel*>(model));
}

void* QListView_model(void* listView) {
    return static_cast<QListViewBind*>(listView)->model();
}

void QListView_setSelectionMode(void* listView, int mode) {
    static_cast<QListViewBind*>(listView)->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
}

int QListView_selectionMode(void* listView) {
    return static_cast<int>(static_cast<QListViewBind*>(listView)->selectionMode());
}

void QListView_setFlow(void* listView, int flow) {
    static_cast<QListViewBind*>(listView)->setFlow(static_cast<QListView::Flow>(flow));
}

int QListView_flow(void* listView) {
    return static_cast<int>(static_cast<QListViewBind*>(listView)->flow());
}

void QListView_setWrapping(void* listView, bool wrap) {
    static_cast<QListViewBind*>(listView)->setWrapping(wrap);
}

bool QListView_isWrapping(void* listView) {
    return static_cast<QListViewBind*>(listView)->isWrapping();
}

void QListView_setResizeMode(void* listView, int mode) {
    static_cast<QListViewBind*>(listView)->setResizeMode(static_cast<QListView::ResizeMode>(mode));
}

int QListView_resizeMode(void* listView) {
    return static_cast<int>(static_cast<QListViewBind*>(listView)->resizeMode());
}

void QListView_setSpacing(void* listView, int space) {
    static_cast<QListViewBind*>(listView)->setSpacing(space);
}

int QListView_spacing(void* listView) {
    return static_cast<QListViewBind*>(listView)->spacing();
}

void QListView_setBatchSize(void* listView, int batchSize) {
    static_cast<QListViewBind*>(listView)->setBatchSize(batchSize);
}

int QListView_batchSize(void* listView) {
    return static_cast<QListViewBind*>(listView)->batchSize();
}

void QListView_setGridSize(void* listView, int width, int height) {
    static_cast<QListViewBind*>(listView)->setGridSize(QSize(width, height));
}

void QListView_gridSize(void* listView, int* width, int* height) {
    QSize size = static_cast<QListViewBind*>(listView)->gridSize();
    if (width) *width = size.width();
    if (height) *height = size.height();
}

void QListView_setViewMode(void* listView, int mode) {
    static_cast<QListViewBind*>(listView)->setViewMode(static_cast<QListView::ViewMode>(mode));
}

int QListView_viewMode(void* listView) {
    return static_cast<int>(static_cast<QListViewBind*>(listView)->viewMode());
}

void QListView_setUniformItemSizes(void* listView, bool enable) {
    static_cast<QListViewBind*>(listView)->setUniformItemSizes(enable);
}

bool QListView_uniformItemSizes(void* listView) {
    return static_cast<QListViewBind*>(listView)->uniformItemSizes();
}

void QListView_setWordWrap(void* listView, bool on) {
    static_cast<QListViewBind*>(listView)->setWordWrap(on);
}

bool QListView_wordWrap(void* listView) {
    return static_cast<QListViewBind*>(listView)->wordWrap();
}

void QListView_setSelectionRectVisible(void* listView, bool show) {
    static_cast<QListViewBind*>(listView)->setSelectionRectVisible(show);
}

bool QListView_isSelectionRectVisible(void* listView) {
    return static_cast<QListViewBind*>(listView)->isSelectionRectVisible();
}

void QListView_setItemAlignment(void* listView, int alignment) {
    static_cast<QListViewBind*>(listView)->setItemAlignment(static_cast<Qt::Alignment>(alignment));
}

int QListView_itemAlignment(void* listView) {
    return static_cast<int>(static_cast<QListViewBind*>(listView)->itemAlignment());
}

void QListView_setModelColumn(void* listView, int column) {
    static_cast<QListViewBind*>(listView)->setModelColumn(column);
}

int QListView_modelColumn(void* listView) {
    return static_cast<QListViewBind*>(listView)->modelColumn();
}

typedef void (*ClickedCallback)(void*, int, int);
typedef void (*DoubleClickedCallback)(void*, int, int);
typedef void (*SelectionChangedCallback)(void*);

void QListView_setClickedCallback(void* listView, ClickedCallback callback) {
    static_cast<QListViewBind*>(listView)->setClickedCallback(callback);
}

void QListView_setDoubleClickedCallback(void* listView, DoubleClickedCallback callback) {
    static_cast<QListViewBind*>(listView)->setDoubleClickedCallback(callback);
}

void QListView_setSelectionChangedCallback(void* listView, SelectionChangedCallback callback) {
    static_cast<QListViewBind*>(listView)->setSelectionChangedCallback(callback);
}

}
