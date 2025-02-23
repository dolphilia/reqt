#include "c_q_tree_view.h"
#include "bind_q_tree_view.h"
#include <QHeaderView>

extern "C" {

void* QTreeView_create(void* parent)
{
    return new BindQTreeView(reinterpret_cast<QWidget*>(parent));
}

void QTreeView_delete(void* tree_view)
{
    delete static_cast<BindQTreeView*>(tree_view);
}

void QTreeView_setModel(void* tree_view, void* model)
{
    static_cast<BindQTreeView*>(tree_view)->setModel(static_cast<QAbstractItemModel*>(model));
}

void* QTreeView_model(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->model();
}

void QTreeView_setRootIndex(void* tree_view, void* index)
{
    static_cast<BindQTreeView*>(tree_view)->setRootIndex(*static_cast<QModelIndex*>(index));
}

void* QTreeView_rootIndex(void* tree_view)
{
    static QModelIndex index = static_cast<BindQTreeView*>(tree_view)->rootIndex();
    return &index;
}

void QTreeView_setSelectionModel(void* tree_view, void* selection_model)
{
    static_cast<BindQTreeView*>(tree_view)->setSelectionModel(static_cast<QItemSelectionModel*>(selection_model));
}

void* QTreeView_selectionModel(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->selectionModel();
}

void QTreeView_setAnimated(void* tree_view, bool enable)
{
    static_cast<BindQTreeView*>(tree_view)->setAnimated(enable);
}

bool QTreeView_isAnimated(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->isAnimated();
}

void QTreeView_setAllColumnsShowFocus(void* tree_view, bool enable)
{
    static_cast<BindQTreeView*>(tree_view)->setAllColumnsShowFocus(enable);
}

bool QTreeView_allColumnsShowFocus(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->allColumnsShowFocus();
}

void QTreeView_setExpandsOnDoubleClick(void* tree_view, bool enable)
{
    static_cast<BindQTreeView*>(tree_view)->setExpandsOnDoubleClick(enable);
}

bool QTreeView_expandsOnDoubleClick(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->expandsOnDoubleClick();
}

void QTreeView_setHeaderHidden(void* tree_view, bool hide)
{
    static_cast<BindQTreeView*>(tree_view)->setHeaderHidden(hide);
}

bool QTreeView_isHeaderHidden(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->isHeaderHidden();
}

void QTreeView_setIndentation(void* tree_view, int i)
{
    static_cast<BindQTreeView*>(tree_view)->setIndentation(i);
}

int QTreeView_indentation(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->indentation();
}

void QTreeView_setItemsExpandable(void* tree_view, bool enable)
{
    static_cast<BindQTreeView*>(tree_view)->setItemsExpandable(enable);
}

bool QTreeView_itemsExpandable(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->itemsExpandable();
}

void QTreeView_setSortingEnabled(void* tree_view, bool enable)
{
    static_cast<BindQTreeView*>(tree_view)->setSortingEnabled(enable);
}

bool QTreeView_isSortingEnabled(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->isSortingEnabled();
}

void QTreeView_setUniformRowHeights(void* tree_view, bool uniform)
{
    static_cast<BindQTreeView*>(tree_view)->setUniformRowHeights(uniform);
}

bool QTreeView_uniformRowHeights(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->uniformRowHeights();
}

void QTreeView_setWordWrap(void* tree_view, bool on)
{
    static_cast<BindQTreeView*>(tree_view)->setWordWrap(on);
}

bool QTreeView_wordWrap(void* tree_view)
{
    return static_cast<BindQTreeView*>(tree_view)->wordWrap();
}

void QTreeView_expand(void* tree_view, void* index)
{
    static_cast<BindQTreeView*>(tree_view)->expand(*static_cast<QModelIndex*>(index));
}

void QTreeView_collapse(void* tree_view, void* index)
{
    static_cast<BindQTreeView*>(tree_view)->collapse(*static_cast<QModelIndex*>(index));
}

void QTreeView_expandAll(void* tree_view)
{
    static_cast<BindQTreeView*>(tree_view)->expandAll();
}

void QTreeView_collapseAll(void* tree_view)
{
    static_cast<BindQTreeView*>(tree_view)->collapseAll();
}

void QTreeView_expandToDepth(void* tree_view, int depth)
{
    static_cast<BindQTreeView*>(tree_view)->expandToDepth(depth);
}

void QTreeView_resizeColumnToContents(void* tree_view, int column)
{
    static_cast<BindQTreeView*>(tree_view)->resizeColumnToContents(column);
}

void QTreeView_sortByColumn(void* tree_view, int column, int order)
{
    static_cast<BindQTreeView*>(tree_view)->sortByColumn(column, static_cast<Qt::SortOrder>(order));
}

void QTreeView_setColumnWidth(void* tree_view, int column, int width)
{
    static_cast<BindQTreeView*>(tree_view)->setColumnWidth(column, width);
}

int QTreeView_columnWidth(void* tree_view, int column)
{
    return static_cast<BindQTreeView*>(tree_view)->columnWidth(column);
}

void QTreeView_setColumnHidden(void* tree_view, int column, bool hide)
{
    static_cast<BindQTreeView*>(tree_view)->setColumnHidden(column, hide);
}

bool QTreeView_isColumnHidden(void* tree_view, int column)
{
    return static_cast<BindQTreeView*>(tree_view)->isColumnHidden(column);
}

void QTreeView_setClickedCallback(void* tree_view, QTreeViewClickedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setClickedCallback(callback);
}

void QTreeView_setDoubleClickedCallback(void* tree_view, QTreeViewDoubleClickedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setDoubleClickedCallback(callback);
}

void QTreeView_setExpandedCallback(void* tree_view, QTreeViewExpandedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setExpandedCallback(callback);
}

void QTreeView_setCollapsedCallback(void* tree_view, QTreeViewCollapsedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setCollapsedCallback(callback);
}

void QTreeView_setActivatedCallback(void* tree_view, QTreeViewActivatedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setActivatedCallback(callback);
}

void QTreeView_setEnteredCallback(void* tree_view, QTreeViewEnteredCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setEnteredCallback(callback);
}

void QTreeView_setPressedCallback(void* tree_view, QTreeViewPressedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setPressedCallback(callback);
}

void QTreeView_setSelectionChangedCallback(void* tree_view, QTreeViewSelectionChangedCallback callback)
{
    BindQTreeView* view = static_cast<BindQTreeView*>(tree_view);
    TreeViewHandler* handler = view->handler();
    if (!handler) {
        handler = new TreeViewHandler(view);
        view->setTreeViewHandler(handler);
    }
    handler->setSelectionChangedCallback(callback);
}

}
