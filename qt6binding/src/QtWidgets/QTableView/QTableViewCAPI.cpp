#include "QTableViewBind.h"

extern "C" {

void* QTableView_create(void* parent) {
    return new QTableViewBind(static_cast<QWidget*>(parent));
}

void QTableView_delete(void* table_view) {
    delete static_cast<QTableViewBind*>(table_view);
}

void QTableView_setModel(void* table_view, void* model) {
    static_cast<QTableViewBind*>(table_view)->setModel(static_cast<QAbstractItemModel*>(model));
}

void* QTableView_model(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->model();
}

void QTableView_setSelectionModel(void* table_view, void* selection_model) {
    static_cast<QTableViewBind*>(table_view)->setSelectionModel(static_cast<QItemSelectionModel*>(selection_model));
}

void* QTableView_selectionModel(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->selectionModel();
}

void QTableView_setShowGrid(void* table_view, bool show) {
    static_cast<QTableViewBind*>(table_view)->setShowGrid(show);
}

bool QTableView_showGrid(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->showGrid();
}

void QTableView_setGridStyle(void* table_view, int style) {
    static_cast<QTableViewBind*>(table_view)->setGridStyle(static_cast<Qt::PenStyle>(style));
}

int QTableView_gridStyle(void* table_view) {
    return static_cast<int>(static_cast<QTableViewBind*>(table_view)->gridStyle());
}

void QTableView_setSortingEnabled(void* table_view, bool enable) {
    static_cast<QTableViewBind*>(table_view)->setSortingEnabled(enable);
}

bool QTableView_isSortingEnabled(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->isSortingEnabled();
}

void QTableView_setWordWrap(void* table_view, bool on) {
    static_cast<QTableViewBind*>(table_view)->setWordWrap(on);
}

bool QTableView_wordWrap(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->wordWrap();
}

void QTableView_setCornerButtonEnabled(void* table_view, bool enable) {
    static_cast<QTableViewBind*>(table_view)->setCornerButtonEnabled(enable);
}

bool QTableView_isCornerButtonEnabled(void* table_view) {
    return static_cast<QTableViewBind*>(table_view)->isCornerButtonEnabled();
}

void QTableView_setColumnWidth(void* table_view, int column, int width) {
    static_cast<QTableViewBind*>(table_view)->setColumnWidth(column, width);
}

int QTableView_columnWidth(void* table_view, int column) {
    return static_cast<QTableViewBind*>(table_view)->columnWidth(column);
}

void QTableView_setRowHeight(void* table_view, int row, int height) {
    static_cast<QTableViewBind*>(table_view)->setRowHeight(row, height);
}

int QTableView_rowHeight(void* table_view, int row) {
    return static_cast<QTableViewBind*>(table_view)->rowHeight(row);
}

void QTableView_setColumnHidden(void* table_view, int column, bool hide) {
    static_cast<QTableViewBind*>(table_view)->setColumnHidden(column, hide);
}

bool QTableView_isColumnHidden(void* table_view, int column) {
    return static_cast<QTableViewBind*>(table_view)->isColumnHidden(column);
}

void QTableView_setRowHidden(void* table_view, int row, bool hide) {
    static_cast<QTableViewBind*>(table_view)->setRowHidden(row, hide);
}

bool QTableView_isRowHidden(void* table_view, int row) {
    return static_cast<QTableViewBind*>(table_view)->isRowHidden(row);
}

void QTableView_resizeColumnToContents(void* table_view, int column) {
    static_cast<QTableViewBind*>(table_view)->resizeColumnToContents(column);
}

void QTableView_resizeRowToContents(void* table_view, int row) {
    static_cast<QTableViewBind*>(table_view)->resizeRowToContents(row);
}

void QTableView_resizeColumnsToContents(void* table_view) {
    static_cast<QTableViewBind*>(table_view)->resizeColumnsToContents();
}

void QTableView_resizeRowsToContents(void* table_view) {
    static_cast<QTableViewBind*>(table_view)->resizeRowsToContents();
}

void QTableView_sortByColumn(void* table_view, int column, int order) {
    static_cast<QTableViewBind*>(table_view)->sortByColumn(column, static_cast<Qt::SortOrder>(order));
}

typedef void (*QTableView_ClickedCallback)(void*, void* index);
typedef void (*QTableView_DoubleClickedCallback)(void*, void* index);
typedef void (*QTableView_ActivatedCallback)(void*, void* index);
typedef void (*QTableView_EnteredCallback)(void*, void* index);
typedef void (*QTableView_PressedCallback)(void*, void* index);
typedef void (*QTableView_SelectionChangedCallback)(void*);
typedef void (*QTableView_HorizontalHeaderClickedCallback)(void*, int section);
typedef void (*QTableView_VerticalHeaderClickedCallback)(void*, int section);

void QTableView_setClickedCallback(void* table_view, QTableView_ClickedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setClickedCallback(callback);
}

void QTableView_setDoubleClickedCallback(void* table_view, QTableView_DoubleClickedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setDoubleClickedCallback(callback);
}

void QTableView_setActivatedCallback(void* table_view, QTableView_ActivatedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setActivatedCallback(callback);
}

void QTableView_setEnteredCallback(void* table_view, QTableView_EnteredCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setEnteredCallback(callback);
}

void QTableView_setPressedCallback(void* table_view, QTableView_PressedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setPressedCallback(callback);
}

void QTableView_setSelectionChangedCallback(void* table_view, QTableView_SelectionChangedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setSelectionChangedCallback(callback);
}

void QTableView_setHorizontalHeaderClickedCallback(void* table_view, QTableView_HorizontalHeaderClickedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setHorizontalHeaderClickedCallback(callback);
}

void QTableView_setVerticalHeaderClickedCallback(void* table_view, QTableView_VerticalHeaderClickedCallback callback) {
    static_cast<QTableViewBind*>(table_view)->setVerticalHeaderClickedCallback(callback);
}

}
