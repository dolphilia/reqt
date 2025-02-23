#ifndef QTABLEVIEW_C_H
#define QTABLEVIEW_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QTableView_create(void* parent);
void QTableView_delete(void* table_view);

// Properties
void QTableView_setModel(void* table_view, void* model);
void* QTableView_model(void* table_view);
void QTableView_setSelectionModel(void* table_view, void* selection_model);
void* QTableView_selectionModel(void* table_view);

// Table behavior
void QTableView_setShowGrid(void* table_view, bool show);
bool QTableView_showGrid(void* table_view);
void QTableView_setGridStyle(void* table_view, int style);
int QTableView_gridStyle(void* table_view);
void QTableView_setSortingEnabled(void* table_view, bool enable);
bool QTableView_isSortingEnabled(void* table_view);
void QTableView_setWordWrap(void* table_view, bool on);
bool QTableView_wordWrap(void* table_view);
void QTableView_setCornerButtonEnabled(void* table_view, bool enable);
bool QTableView_isCornerButtonEnabled(void* table_view);

// Column/Row operations
void QTableView_setColumnWidth(void* table_view, int column, int width);
int QTableView_columnWidth(void* table_view, int column);
void QTableView_setRowHeight(void* table_view, int row, int height);
int QTableView_rowHeight(void* table_view, int row);
void QTableView_setColumnHidden(void* table_view, int column, bool hide);
bool QTableView_isColumnHidden(void* table_view, int column);
void QTableView_setRowHidden(void* table_view, int row, bool hide);
bool QTableView_isRowHidden(void* table_view, int row);
void QTableView_resizeColumnToContents(void* table_view, int column);
void QTableView_resizeRowToContents(void* table_view, int row);
void QTableView_resizeColumnsToContents(void* table_view);
void QTableView_resizeRowsToContents(void* table_view);
void QTableView_sortByColumn(void* table_view, int column, int order);

// Grid style constants
#define QTABLEVIEW_GRID_NONE 0
#define QTABLEVIEW_GRID_SOLID 1
#define QTABLEVIEW_GRID_DASHED 2
#define QTABLEVIEW_GRID_DOTTED 3
#define QTABLEVIEW_GRID_DASH_DOTTED 4

// Sort order constants
#define QTABLEVIEW_SORT_ASCENDING 0
#define QTABLEVIEW_SORT_DESCENDING 1

// Callbacks
typedef void (*QTableViewClickedCallback)(void* index);
typedef void (*QTableViewDoubleClickedCallback)(void* index);
typedef void (*QTableViewActivatedCallback)(void* index);
typedef void (*QTableViewEnteredCallback)(void* index);
typedef void (*QTableViewPressedCallback)(void* index);
typedef void (*QTableViewSelectionChangedCallback)();
typedef void (*QTableViewHorizontalHeaderClickedCallback)(int section);
typedef void (*QTableViewVerticalHeaderClickedCallback)(int section);

void QTableView_setClickedCallback(void* table_view, QTableViewClickedCallback callback);
void QTableView_setDoubleClickedCallback(void* table_view, QTableViewDoubleClickedCallback callback);
void QTableView_setActivatedCallback(void* table_view, QTableViewActivatedCallback callback);
void QTableView_setEnteredCallback(void* table_view, QTableViewEnteredCallback callback);
void QTableView_setPressedCallback(void* table_view, QTableViewPressedCallback callback);
void QTableView_setSelectionChangedCallback(void* table_view, QTableViewSelectionChangedCallback callback);
void QTableView_setHorizontalHeaderClickedCallback(void* table_view, QTableViewHorizontalHeaderClickedCallback callback);
void QTableView_setVerticalHeaderClickedCallback(void* table_view, QTableViewVerticalHeaderClickedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTABLEVIEW_C_H
