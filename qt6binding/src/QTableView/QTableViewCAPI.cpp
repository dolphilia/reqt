#include "qtableview.h"
#include "QTableViewBind.h"
#include "QTableViewHandler.h"

extern "C" {

void* QTableView_create(void* parent)
{
    return new BindQTableView(reinterpret_cast<QWidget*>(parent));
}

void QTableView_delete(void* table_view)
{
    delete static_cast<BindQTableView*>(table_view);
}

void QTableView_setModel(void* table_view, void* model)
{
    static_cast<BindQTableView*>(table_view)->setModel(static_cast<QAbstractItemModel*>(model));
}

void* QTableView_model(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->model();
}

void QTableView_setSelectionModel(void* table_view, void* selection_model)
{
    static_cast<BindQTableView*>(table_view)->setSelectionModel(static_cast<QItemSelectionModel*>(selection_model));
}

void* QTableView_selectionModel(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->selectionModel();
}

void QTableView_setShowGrid(void* table_view, bool show)
{
    static_cast<BindQTableView*>(table_view)->setShowGrid(show);
}

bool QTableView_showGrid(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->showGrid();
}

void QTableView_setGridStyle(void* table_view, int style)
{
    static_cast<BindQTableView*>(table_view)->setGridStyle(static_cast<Qt::PenStyle>(style));
}

int QTableView_gridStyle(void* table_view)
{
    return static_cast<int>(static_cast<BindQTableView*>(table_view)->gridStyle());
}

void QTableView_setSortingEnabled(void* table_view, bool enable)
{
    static_cast<BindQTableView*>(table_view)->setSortingEnabled(enable);
}

bool QTableView_isSortingEnabled(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->isSortingEnabled();
}

void QTableView_setWordWrap(void* table_view, bool on)
{
    static_cast<BindQTableView*>(table_view)->setWordWrap(on);
}

bool QTableView_wordWrap(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->wordWrap();
}

void QTableView_setCornerButtonEnabled(void* table_view, bool enable)
{
    static_cast<BindQTableView*>(table_view)->setCornerButtonEnabled(enable);
}

bool QTableView_isCornerButtonEnabled(void* table_view)
{
    return static_cast<BindQTableView*>(table_view)->isCornerButtonEnabled();
}

void QTableView_setColumnWidth(void* table_view, int column, int width)
{
    static_cast<BindQTableView*>(table_view)->setColumnWidth(column, width);
}

int QTableView_columnWidth(void* table_view, int column)
{
    return static_cast<BindQTableView*>(table_view)->columnWidth(column);
}

void QTableView_setRowHeight(void* table_view, int row, int height)
{
    static_cast<BindQTableView*>(table_view)->setRowHeight(row, height);
}

int QTableView_rowHeight(void* table_view, int row)
{
    return static_cast<BindQTableView*>(table_view)->rowHeight(row);
}

void QTableView_setColumnHidden(void* table_view, int column, bool hide)
{
    static_cast<BindQTableView*>(table_view)->setColumnHidden(column, hide);
}

bool QTableView_isColumnHidden(void* table_view, int column)
{
    return static_cast<BindQTableView*>(table_view)->isColumnHidden(column);
}

void QTableView_setRowHidden(void* table_view, int row, bool hide)
{
    static_cast<BindQTableView*>(table_view)->setRowHidden(row, hide);
}

bool QTableView_isRowHidden(void* table_view, int row)
{
    return static_cast<BindQTableView*>(table_view)->isRowHidden(row);
}

void QTableView_resizeColumnToContents(void* table_view, int column)
{
    static_cast<BindQTableView*>(table_view)->resizeColumnToContents(column);
}

void QTableView_resizeRowToContents(void* table_view, int row)
{
    static_cast<BindQTableView*>(table_view)->resizeRowToContents(row);
}

void QTableView_resizeColumnsToContents(void* table_view)
{
    static_cast<BindQTableView*>(table_view)->resizeColumnsToContents();
}

void QTableView_resizeRowsToContents(void* table_view)
{
    static_cast<BindQTableView*>(table_view)->resizeRowsToContents();
}

void QTableView_sortByColumn(void* table_view, int column, int order)
{
    static_cast<BindQTableView*>(table_view)->sortByColumn(column, static_cast<Qt::SortOrder>(order));
}

void QTableView_setClickedCallback(void* table_view, QTableViewClickedCallback callback)
{
    auto handler = new TableViewHandler();
    handler->setClickedCallback(callback);
    static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
}

void QTableView_setDoubleClickedCallback(void* table_view, QTableViewDoubleClickedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setDoubleClickedCallback(callback);
}

void QTableView_setActivatedCallback(void* table_view, QTableViewActivatedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setActivatedCallback(callback);
}

void QTableView_setEnteredCallback(void* table_view, QTableViewEnteredCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setEnteredCallback(callback);
}

void QTableView_setPressedCallback(void* table_view, QTableViewPressedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setPressedCallback(callback);
}

void QTableView_setSelectionChangedCallback(void* table_view, QTableViewSelectionChangedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setSelectionChangedCallback(callback);
}

void QTableView_setHorizontalHeaderClickedCallback(void* table_view, QTableViewHorizontalHeaderClickedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setHorizontalHeaderClickedCallback(callback);
}

void QTableView_setVerticalHeaderClickedCallback(void* table_view, QTableViewVerticalHeaderClickedCallback callback)
{
    auto handler = static_cast<BindQTableView*>(table_view)->handler();
    if (!handler) {
        handler = new TableViewHandler();
        static_cast<BindQTableView*>(table_view)->setTableViewHandler(handler);
    }
    handler->setVerticalHeaderClickedCallback(callback);
}

}
