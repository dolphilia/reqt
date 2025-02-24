#include "QListViewBind.h"
#include "qlistview.h"
#include "QListViewHandler.h"

extern "C" {

void* QListView_create(void* parent) {
    return QListViewBind::create(static_cast<QWidget*>(parent));
}

void QListView_delete(void* listView) {
    QListViewBind::destroy(static_cast<QListView*>(listView));
}

void QListView_setModel(void* listView, void* model) {
    QListViewBind::setModel(static_cast<QListView*>(listView), static_cast<QAbstractItemModel*>(model));
}

void* QListView_model(void* listView) {
    return QListViewBind::model(static_cast<QListView*>(listView));
}

void QListView_setSelectionMode(void* listView, int mode) {
    QListViewBind::setSelectionMode(static_cast<QListView*>(listView), mode);
}

int QListView_selectionMode(void* listView) {
    return QListViewBind::selectionMode(static_cast<QListView*>(listView));
}

void QListView_setFlow(void* listView, int flow) {
    QListViewBind::setFlow(static_cast<QListView*>(listView), flow);
}

int QListView_flow(void* listView) {
    return QListViewBind::flow(static_cast<QListView*>(listView));
}

void QListView_setWrapping(void* listView, bool wrap) {
    QListViewBind::setWrapping(static_cast<QListView*>(listView), wrap);
}

bool QListView_isWrapping(void* listView) {
    return QListViewBind::isWrapping(static_cast<QListView*>(listView));
}

void QListView_setResizeMode(void* listView, int mode) {
    QListViewBind::setResizeMode(static_cast<QListView*>(listView), mode);
}

int QListView_resizeMode(void* listView) {
    return QListViewBind::resizeMode(static_cast<QListView*>(listView));
}

void QListView_setSpacing(void* listView, int space) {
    QListViewBind::setSpacing(static_cast<QListView*>(listView), space);
}

int QListView_spacing(void* listView) {
    return QListViewBind::spacing(static_cast<QListView*>(listView));
}

void QListView_setBatchSize(void* listView, int batchSize) {
    QListViewBind::setBatchSize(static_cast<QListView*>(listView), batchSize);
}

int QListView_batchSize(void* listView) {
    return QListViewBind::batchSize(static_cast<QListView*>(listView));
}

void QListView_setGridSize(void* listView, int width, int height) {
    QListViewBind::setGridSize(static_cast<QListView*>(listView), width, height);
}

void QListView_gridSize(void* listView, int* width, int* height) {
    QListViewBind::gridSize(static_cast<QListView*>(listView), width, height);
}

void QListView_setViewMode(void* listView, int mode) {
    QListViewBind::setViewMode(static_cast<QListView*>(listView), mode);
}

int QListView_viewMode(void* listView) {
    return QListViewBind::viewMode(static_cast<QListView*>(listView));
}

void QListView_setUniformItemSizes(void* listView, bool enable) {
    QListViewBind::setUniformItemSizes(static_cast<QListView*>(listView), enable);
}

bool QListView_uniformItemSizes(void* listView) {
    return QListViewBind::uniformItemSizes(static_cast<QListView*>(listView));
}

void QListView_setWordWrap(void* listView, bool on) {
    QListViewBind::setWordWrap(static_cast<QListView*>(listView), on);
}

bool QListView_wordWrap(void* listView) {
    return QListViewBind::wordWrap(static_cast<QListView*>(listView));
}

void QListView_setSelectionRectVisible(void* listView, bool show) {
    QListViewBind::setSelectionRectVisible(static_cast<QListView*>(listView), show);
}

bool QListView_isSelectionRectVisible(void* listView) {
    return QListViewBind::isSelectionRectVisible(static_cast<QListView*>(listView));
}

void QListView_setItemAlignment(void* listView, int alignment) {
    QListViewBind::setItemAlignment(static_cast<QListView*>(listView), alignment);
}

int QListView_itemAlignment(void* listView) {
    return QListViewBind::itemAlignment(static_cast<QListView*>(listView));
}

void QListView_setModelColumn(void* listView, int column) {
    QListViewBind::setModelColumn(static_cast<QListView*>(listView), column);
}

int QListView_modelColumn(void* listView) {
    return QListViewBind::modelColumn(static_cast<QListView*>(listView));
}

void QListView_setClickedCallback(void* listView, ListViewClickedCallback callback) {
    QListViewBind::setClickedCallback(static_cast<QListView*>(listView), callback);
}

void QListView_setDoubleClickedCallback(void* listView, ListViewDoubleClickedCallback callback) {
    QListViewBind::setDoubleClickedCallback(static_cast<QListView*>(listView), callback);
}

void QListView_setSelectionChangedCallback(void* listView, ListViewSelectionChangedCallback callback) {
    QListViewBind::setSelectionChangedCallback(static_cast<QListView*>(listView), callback);
}

}
