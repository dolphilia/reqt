#include "QTreeViewBind.h"
#include <QHeaderView>

extern "C" {

typedef void (*QTreeView_ClickedCallback)(void*, void*);
typedef void (*QTreeView_DoubleClickedCallback)(void*, void*);
typedef void (*QTreeView_ExpandedCallback)(void*, void*);
typedef void (*QTreeView_CollapsedCallback)(void*, void*);
typedef void (*QTreeView_ActivatedCallback)(void*, void*);
typedef void (*QTreeView_EnteredCallback)(void*, void*);
typedef void (*QTreeView_PressedCallback)(void*, void*);
typedef void (*QTreeView_SelectionChangedCallback)(void*);

void* QTreeView_create(void* parent) {
    return new QTreeViewBind(static_cast<QWidget*>(parent));
}

void QTreeView_delete(void* tree_view) {
    delete static_cast<QTreeViewBind*>(tree_view);
}

void QTreeView_setModel(void* tree_view, void* model) {
    static_cast<QTreeViewBind*>(tree_view)->setModel(static_cast<QAbstractItemModel*>(model));
}

void* QTreeView_model(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->model();
}

void QTreeView_setRootIndex(void* tree_view, void* index) {
    static_cast<QTreeViewBind*>(tree_view)->setRootIndex(*static_cast<QModelIndex*>(index));
}

void* QTreeView_rootIndex(void* tree_view) {
    static QModelIndex index = static_cast<QTreeViewBind*>(tree_view)->rootIndex();
    return &index;
}

void QTreeView_setSelectionModel(void* tree_view, void* selection_model) {
    static_cast<QTreeViewBind*>(tree_view)->setSelectionModel(static_cast<QItemSelectionModel*>(selection_model));
}

void* QTreeView_selectionModel(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->selectionModel();
}

void QTreeView_setAnimated(void* tree_view, bool enable) {
    static_cast<QTreeViewBind*>(tree_view)->setAnimated(enable);
}

bool QTreeView_isAnimated(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->isAnimated();
}

void QTreeView_setAllColumnsShowFocus(void* tree_view, bool enable) {
    static_cast<QTreeViewBind*>(tree_view)->setAllColumnsShowFocus(enable);
}

bool QTreeView_allColumnsShowFocus(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->allColumnsShowFocus();
}

void QTreeView_setExpandsOnDoubleClick(void* tree_view, bool enable) {
    static_cast<QTreeViewBind*>(tree_view)->setExpandsOnDoubleClick(enable);
}

bool QTreeView_expandsOnDoubleClick(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->expandsOnDoubleClick();
}

void QTreeView_setHeaderHidden(void* tree_view, bool hide) {
    static_cast<QTreeViewBind*>(tree_view)->setHeaderHidden(hide);
}

bool QTreeView_isHeaderHidden(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->isHeaderHidden();
}

void QTreeView_setIndentation(void* tree_view, int i) {
    static_cast<QTreeViewBind*>(tree_view)->setIndentation(i);
}

int QTreeView_indentation(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->indentation();
}

void QTreeView_setItemsExpandable(void* tree_view, bool enable) {
    static_cast<QTreeViewBind*>(tree_view)->setItemsExpandable(enable);
}

bool QTreeView_itemsExpandable(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->itemsExpandable();
}

void QTreeView_setSortingEnabled(void* tree_view, bool enable) {
    static_cast<QTreeViewBind*>(tree_view)->setSortingEnabled(enable);
}

bool QTreeView_isSortingEnabled(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->isSortingEnabled();
}

void QTreeView_setUniformRowHeights(void* tree_view, bool uniform) {
    static_cast<QTreeViewBind*>(tree_view)->setUniformRowHeights(uniform);
}

bool QTreeView_uniformRowHeights(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->uniformRowHeights();
}

void QTreeView_setWordWrap(void* tree_view, bool on) {
    static_cast<QTreeViewBind*>(tree_view)->setWordWrap(on);
}

bool QTreeView_wordWrap(void* tree_view) {
    return static_cast<QTreeViewBind*>(tree_view)->wordWrap();
}

void QTreeView_expand(void* tree_view, void* index) {
    static_cast<QTreeViewBind*>(tree_view)->expand(*static_cast<QModelIndex*>(index));
}

void QTreeView_collapse(void* tree_view, void* index) {
    static_cast<QTreeViewBind*>(tree_view)->collapse(*static_cast<QModelIndex*>(index));
}

void QTreeView_expandAll(void* tree_view) {
    static_cast<QTreeViewBind*>(tree_view)->expandAll();
}

void QTreeView_collapseAll(void* tree_view) {
    static_cast<QTreeViewBind*>(tree_view)->collapseAll();
}

void QTreeView_expandToDepth(void* tree_view, int depth) {
    static_cast<QTreeViewBind*>(tree_view)->expandToDepth(depth);
}

void QTreeView_resizeColumnToContents(void* tree_view, int column) {
    static_cast<QTreeViewBind*>(tree_view)->resizeColumnToContents(column);
}

void QTreeView_sortByColumn(void* tree_view, int column, int order) {
    static_cast<QTreeViewBind*>(tree_view)->sortByColumn(column, static_cast<Qt::SortOrder>(order));
}

void QTreeView_setColumnWidth(void* tree_view, int column, int width) {
    static_cast<QTreeViewBind*>(tree_view)->setColumnWidth(column, width);
}

int QTreeView_columnWidth(void* tree_view, int column) {
    return static_cast<QTreeViewBind*>(tree_view)->columnWidth(column);
}

void QTreeView_setColumnHidden(void* tree_view, int column, bool hide) {
    static_cast<QTreeViewBind*>(tree_view)->setColumnHidden(column, hide);
}

bool QTreeView_isColumnHidden(void* tree_view, int column) {
    return static_cast<QTreeViewBind*>(tree_view)->isColumnHidden(column);
}

void QTreeView_setClickedCallback(void* tree_view, QTreeView_ClickedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setClickedCallback(callback);
}

void QTreeView_setDoubleClickedCallback(void* tree_view, QTreeView_DoubleClickedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setDoubleClickedCallback(callback);
}

void QTreeView_setExpandedCallback(void* tree_view, QTreeView_ExpandedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setExpandedCallback(callback);
}

void QTreeView_setCollapsedCallback(void* tree_view, QTreeView_CollapsedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setCollapsedCallback(callback);
}

void QTreeView_setActivatedCallback(void* tree_view, QTreeView_ActivatedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setActivatedCallback(callback);
}

void QTreeView_setEnteredCallback(void* tree_view, QTreeView_EnteredCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setEnteredCallback(callback);
}

void QTreeView_setPressedCallback(void* tree_view, QTreeView_PressedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setPressedCallback(callback);
}

void QTreeView_setSelectionChangedCallback(void* tree_view, QTreeView_SelectionChangedCallback callback) {
    static_cast<QTreeViewBind*>(tree_view)->setSelectionChangedCallback(callback);
}

}
