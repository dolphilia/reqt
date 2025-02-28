#ifndef QITEMSELECTIONMODEL_C_H
#define QITEMSELECTIONMODEL_C_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// SelectionFlag enum
typedef enum {
    QITEMSELECTIONMODEL_NOUPDATE = 0x0,
    QITEMSELECTIONMODEL_CLEAR = 0x1,
    QITEMSELECTIONMODEL_SELECT = 0x2,
    QITEMSELECTIONMODEL_DESELECT = 0x4,
    QITEMSELECTIONMODEL_TOGGLE = 0x8,
    QITEMSELECTIONMODEL_CURRENT = 0x10,
    QITEMSELECTIONMODEL_ROWS = 0x20,
    QITEMSELECTIONMODEL_COLUMNS = 0x40,
    QITEMSELECTIONMODEL_CLEARANDSELECT = QITEMSELECTIONMODEL_CLEAR | QITEMSELECTIONMODEL_SELECT
} QItemSelectionModel_SelectionFlag;

// Creation and destruction
void* QItemSelectionModel_create(void* model);
void* QItemSelectionModel_createWithParent(void* model, void* parent);
void QItemSelectionModel_delete(void* selectionModel);

// Model operations
bool QItemSelectionModel_columnIntersectsSelection(void* selectionModel, int column, void* parent);
void* QItemSelectionModel_currentIndex(void* selectionModel);
bool QItemSelectionModel_hasSelection(void* selectionModel);
bool QItemSelectionModel_isColumnSelected(void* selectionModel, int column, void* parent);
bool QItemSelectionModel_isRowSelected(void* selectionModel, int row, void* parent);
bool QItemSelectionModel_isSelected(void* selectionModel, void* index);
void* QItemSelectionModel_model(void* selectionModel);
bool QItemSelectionModel_rowIntersectsSelection(void* selectionModel, int row, void* parent);
void** QItemSelectionModel_selectedColumns(void* selectionModel, int row, int* count);
void** QItemSelectionModel_selectedIndexes(void* selectionModel, int* count);
void** QItemSelectionModel_selectedRows(void* selectionModel, int column, int* count);
void* QItemSelectionModel_selection(void* selectionModel);
void QItemSelectionModel_setModel(void* selectionModel, void* model);

// Slots
void QItemSelectionModel_clear(void* selectionModel);
void QItemSelectionModel_clearCurrentIndex(void* selectionModel);
void QItemSelectionModel_clearSelection(void* selectionModel);
void QItemSelectionModel_reset(void* selectionModel);
void QItemSelectionModel_select(void* selectionModel, void* index, int command);
void QItemSelectionModel_selectItemSelection(void* selectionModel, void* selection, int command);
void QItemSelectionModel_setCurrentIndex(void* selectionModel, void* index, int command);

// Signal handlers
typedef void (*QItemSelectionModel_currentChanged_Handler)(void* current, void* previous, void* userData);
typedef void (*QItemSelectionModel_currentColumnChanged_Handler)(void* current, void* previous, void* userData);
typedef void (*QItemSelectionModel_currentRowChanged_Handler)(void* current, void* previous, void* userData);
typedef void (*QItemSelectionModel_modelChanged_Handler)(void* model, void* userData);
typedef void (*QItemSelectionModel_selectionChanged_Handler)(void* selected, void* deselected, void* userData);

// Signal connections
void QItemSelectionModel_currentChanged_connect(void* selectionModel, QItemSelectionModel_currentChanged_Handler handler, void* userData);
void QItemSelectionModel_currentColumnChanged_connect(void* selectionModel, QItemSelectionModel_currentColumnChanged_Handler handler, void* userData);
void QItemSelectionModel_currentRowChanged_connect(void* selectionModel, QItemSelectionModel_currentRowChanged_Handler handler, void* userData);
void QItemSelectionModel_modelChanged_connect(void* selectionModel, QItemSelectionModel_modelChanged_Handler handler, void* userData);
void QItemSelectionModel_selectionChanged_connect(void* selectionModel, QItemSelectionModel_selectionChanged_Handler handler, void* userData);

#ifdef __cplusplus
}
#endif

#endif // QITEMSELECTIONMODEL_C_H
