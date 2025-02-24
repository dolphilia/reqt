#ifndef QTREEVIEW_C_H
#define QTREEVIEW_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QTreeView_create(void* parent);
void QTreeView_delete(void* tree_view);

// Properties
void QTreeView_setModel(void* tree_view, void* model);
void* QTreeView_model(void* tree_view);
void QTreeView_setRootIndex(void* tree_view, void* index);
void* QTreeView_rootIndex(void* tree_view);
void QTreeView_setSelectionModel(void* tree_view, void* selection_model);
void* QTreeView_selectionModel(void* tree_view);

// Tree behavior
void QTreeView_setAnimated(void* tree_view, bool enable);
bool QTreeView_isAnimated(void* tree_view);
void QTreeView_setAllColumnsShowFocus(void* tree_view, bool enable);
bool QTreeView_allColumnsShowFocus(void* tree_view);
void QTreeView_setExpandsOnDoubleClick(void* tree_view, bool enable);
bool QTreeView_expandsOnDoubleClick(void* tree_view);
void QTreeView_setHeaderHidden(void* tree_view, bool hide);
bool QTreeView_isHeaderHidden(void* tree_view);
void QTreeView_setIndentation(void* tree_view, int i);
int QTreeView_indentation(void* tree_view);
void QTreeView_setItemsExpandable(void* tree_view, bool enable);
bool QTreeView_itemsExpandable(void* tree_view);
void QTreeView_setSortingEnabled(void* tree_view, bool enable);
bool QTreeView_isSortingEnabled(void* tree_view);
void QTreeView_setUniformRowHeights(void* tree_view, bool uniform);
bool QTreeView_uniformRowHeights(void* tree_view);
void QTreeView_setWordWrap(void* tree_view, bool on);
bool QTreeView_wordWrap(void* tree_view);

// Operations
void QTreeView_expand(void* tree_view, void* index);
void QTreeView_collapse(void* tree_view, void* index);
void QTreeView_expandAll(void* tree_view);
void QTreeView_collapseAll(void* tree_view);
void QTreeView_expandToDepth(void* tree_view, int depth);
void QTreeView_resizeColumnToContents(void* tree_view, int column);
void QTreeView_sortByColumn(void* tree_view, int column, int order);
void QTreeView_setColumnWidth(void* tree_view, int column, int width);
int QTreeView_columnWidth(void* tree_view, int column);
void QTreeView_setColumnHidden(void* tree_view, int column, bool hide);
bool QTreeView_isColumnHidden(void* tree_view, int column);

// Sort order constants
#define QTREEVIEW_SORT_ASCENDING 0
#define QTREEVIEW_SORT_DESCENDING 1

// Callbacks
typedef void (*QTreeViewClickedCallback)(void* index);
typedef void (*QTreeViewDoubleClickedCallback)(void* index);
typedef void (*QTreeViewExpandedCallback)(void* index);
typedef void (*QTreeViewCollapsedCallback)(void* index);
typedef void (*QTreeViewActivatedCallback)(void* index);
typedef void (*QTreeViewEnteredCallback)(void* index);
typedef void (*QTreeViewPressedCallback)(void* index);
typedef void (*QTreeViewSelectionChangedCallback)();

void QTreeView_setClickedCallback(void* tree_view, QTreeViewClickedCallback callback);
void QTreeView_setDoubleClickedCallback(void* tree_view, QTreeViewDoubleClickedCallback callback);
void QTreeView_setExpandedCallback(void* tree_view, QTreeViewExpandedCallback callback);
void QTreeView_setCollapsedCallback(void* tree_view, QTreeViewCollapsedCallback callback);
void QTreeView_setActivatedCallback(void* tree_view, QTreeViewActivatedCallback callback);
void QTreeView_setEnteredCallback(void* tree_view, QTreeViewEnteredCallback callback);
void QTreeView_setPressedCallback(void* tree_view, QTreeViewPressedCallback callback);
void QTreeView_setSelectionChangedCallback(void* tree_view, QTreeViewSelectionChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTREEVIEW_C_H
