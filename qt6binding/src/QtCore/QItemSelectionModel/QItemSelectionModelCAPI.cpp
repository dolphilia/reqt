#include "qitemselectionmodel.h"
#include "QItemSelectionModelBind.h"
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QItemSelection>

extern "C" {

void* QItemSelectionModel_create(void* model) {
    return QItemSelectionModelBind::create(static_cast<QAbstractItemModel*>(model));
}

void* QItemSelectionModel_createWithParent(void* model, void* parent) {
    return QItemSelectionModelBind::createWithParent(static_cast<QAbstractItemModel*>(model), static_cast<QObject*>(parent));
}

void QItemSelectionModel_delete(void* selectionModel) {
    QItemSelectionModelBind::destroy(static_cast<QItemSelectionModel*>(selectionModel));
}

bool QItemSelectionModel_columnIntersectsSelection(void* selectionModel, int column, void* parent) {
    return QItemSelectionModelBind::columnIntersectsSelection(
        static_cast<QItemSelectionModel*>(selectionModel),
        column,
        static_cast<QModelIndex*>(parent)
    );
}

void* QItemSelectionModel_currentIndex(void* selectionModel) {
    return QItemSelectionModelBind::currentIndex(static_cast<QItemSelectionModel*>(selectionModel));
}

bool QItemSelectionModel_hasSelection(void* selectionModel) {
    return QItemSelectionModelBind::hasSelection(static_cast<QItemSelectionModel*>(selectionModel));
}

bool QItemSelectionModel_isColumnSelected(void* selectionModel, int column, void* parent) {
    return QItemSelectionModelBind::isColumnSelected(
        static_cast<QItemSelectionModel*>(selectionModel),
        column,
        static_cast<QModelIndex*>(parent)
    );
}

bool QItemSelectionModel_isRowSelected(void* selectionModel, int row, void* parent) {
    return QItemSelectionModelBind::isRowSelected(
        static_cast<QItemSelectionModel*>(selectionModel),
        row,
        static_cast<QModelIndex*>(parent)
    );
}

bool QItemSelectionModel_isSelected(void* selectionModel, void* index) {
    return QItemSelectionModelBind::isSelected(
        static_cast<QItemSelectionModel*>(selectionModel),
        static_cast<QModelIndex*>(index)
    );
}

void* QItemSelectionModel_model(void* selectionModel) {
    return QItemSelectionModelBind::model(static_cast<QItemSelectionModel*>(selectionModel));
}

bool QItemSelectionModel_rowIntersectsSelection(void* selectionModel, int row, void* parent) {
    return QItemSelectionModelBind::rowIntersectsSelection(
        static_cast<QItemSelectionModel*>(selectionModel),
        row,
        static_cast<QModelIndex*>(parent)
    );
}

void** QItemSelectionModel_selectedColumns(void* selectionModel, int row, int* count) {
    QList<QModelIndex>* list = QItemSelectionModelBind::selectedColumns(
        static_cast<QItemSelectionModel*>(selectionModel),
        row
    );
    if (list) {
        *count = list->size();
        void** result = new void*[*count];
        for (int i = 0; i < *count; ++i) {
            result[i] = new QModelIndex(list->at(i));
        }
        delete list;
        return result;
    }
    *count = 0;
    return nullptr;
}

void** QItemSelectionModel_selectedIndexes(void* selectionModel, int* count) {
    QList<QModelIndex>* list = QItemSelectionModelBind::selectedIndexes(
        static_cast<QItemSelectionModel*>(selectionModel)
    );
    if (list) {
        *count = list->size();
        void** result = new void*[*count];
        for (int i = 0; i < *count; ++i) {
            result[i] = new QModelIndex(list->at(i));
        }
        delete list;
        return result;
    }
    *count = 0;
    return nullptr;
}

void** QItemSelectionModel_selectedRows(void* selectionModel, int column, int* count) {
    QList<QModelIndex>* list = QItemSelectionModelBind::selectedRows(
        static_cast<QItemSelectionModel*>(selectionModel),
        column
    );
    if (list) {
        *count = list->size();
        void** result = new void*[*count];
        for (int i = 0; i < *count; ++i) {
            result[i] = new QModelIndex(list->at(i));
        }
        delete list;
        return result;
    }
    *count = 0;
    return nullptr;
}

void* QItemSelectionModel_selection(void* selectionModel) {
    return QItemSelectionModelBind::selection(static_cast<QItemSelectionModel*>(selectionModel));
}

void QItemSelectionModel_setModel(void* selectionModel, void* model) {
    QItemSelectionModelBind::setModel(
        static_cast<QItemSelectionModel*>(selectionModel),
        static_cast<QAbstractItemModel*>(model)
    );
}

void QItemSelectionModel_clear(void* selectionModel) {
    QItemSelectionModelBind::clear(static_cast<QItemSelectionModel*>(selectionModel));
}

void QItemSelectionModel_clearCurrentIndex(void* selectionModel) {
    QItemSelectionModelBind::clearCurrentIndex(static_cast<QItemSelectionModel*>(selectionModel));
}

void QItemSelectionModel_clearSelection(void* selectionModel) {
    QItemSelectionModelBind::clearSelection(static_cast<QItemSelectionModel*>(selectionModel));
}

void QItemSelectionModel_reset(void* selectionModel) {
    QItemSelectionModelBind::reset(static_cast<QItemSelectionModel*>(selectionModel));
}

void QItemSelectionModel_select(void* selectionModel, void* index, int command) {
    QItemSelectionModelBind::select(
        static_cast<QItemSelectionModel*>(selectionModel),
        static_cast<QModelIndex*>(index),
        static_cast<QItemSelectionModel::SelectionFlags>(command)
    );
}

void QItemSelectionModel_selectItemSelection(void* selectionModel, void* selection, int command) {
    QItemSelectionModelBind::selectItemSelection(
        static_cast<QItemSelectionModel*>(selectionModel),
        static_cast<QItemSelection*>(selection),
        static_cast<QItemSelectionModel::SelectionFlags>(command)
    );
}

void QItemSelectionModel_setCurrentIndex(void* selectionModel, void* index, int command) {
    QItemSelectionModelBind::setCurrentIndex(
        static_cast<QItemSelectionModel*>(selectionModel),
        static_cast<QModelIndex*>(index),
        static_cast<QItemSelectionModel::SelectionFlags>(command)
    );
}

void QItemSelectionModel_currentChanged_connect(void* selectionModel, QItemSelectionModel_currentChanged_Handler handler, void* userData) {
    QItemSelectionModelBind::connectCurrentChanged(
        static_cast<QItemSelectionModel*>(selectionModel),
        handler,
        userData
    );
}

void QItemSelectionModel_currentColumnChanged_connect(void* selectionModel, QItemSelectionModel_currentColumnChanged_Handler handler, void* userData) {
    QItemSelectionModelBind::connectCurrentColumnChanged(
        static_cast<QItemSelectionModel*>(selectionModel),
        handler,
        userData
    );
}

void QItemSelectionModel_currentRowChanged_connect(void* selectionModel, QItemSelectionModel_currentRowChanged_Handler handler, void* userData) {
    QItemSelectionModelBind::connectCurrentRowChanged(
        static_cast<QItemSelectionModel*>(selectionModel),
        handler,
        userData
    );
}

void QItemSelectionModel_modelChanged_connect(void* selectionModel, QItemSelectionModel_modelChanged_Handler handler, void* userData) {
    QItemSelectionModelBind::connectModelChanged(
        static_cast<QItemSelectionModel*>(selectionModel),
        handler,
        userData
    );
}

void QItemSelectionModel_selectionChanged_connect(void* selectionModel, QItemSelectionModel_selectionChanged_Handler handler, void* userData) {
    QItemSelectionModelBind::connectSelectionChanged(
        static_cast<QItemSelectionModel*>(selectionModel),
        handler,
        userData
    );
}

}
