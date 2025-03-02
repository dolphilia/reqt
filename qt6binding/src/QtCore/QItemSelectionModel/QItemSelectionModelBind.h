#ifndef QITEMSELECTIONMODEL_BIND_H
#define QITEMSELECTIONMODEL_BIND_H

#include <QItemSelectionModel>
#include <QModelIndex>
#include <QItemSelection>
#include <QAbstractItemModel>

class QItemSelectionModelBind {
public:
    // Creation and destruction
    static QItemSelectionModel* create(QAbstractItemModel* model);
    static QItemSelectionModel* createWithParent(QAbstractItemModel* model, QObject* parent);
    static void destroy(QItemSelectionModel* selectionModel);

    // Model operations
    static bool columnIntersectsSelection(QItemSelectionModel* selectionModel, int column, const QModelIndex* parent);
    static QModelIndex* currentIndex(QItemSelectionModel* selectionModel);
    static bool hasSelection(QItemSelectionModel* selectionModel);
    static bool isColumnSelected(QItemSelectionModel* selectionModel, int column, const QModelIndex* parent);
    static bool isRowSelected(QItemSelectionModel* selectionModel, int row, const QModelIndex* parent);
    static bool isSelected(QItemSelectionModel* selectionModel, const QModelIndex* index);
    static QAbstractItemModel* model(QItemSelectionModel* selectionModel);
    static bool rowIntersectsSelection(QItemSelectionModel* selectionModel, int row, const QModelIndex* parent);
    static QList<QModelIndex>* selectedColumns(QItemSelectionModel* selectionModel, int row);
    static QList<QModelIndex>* selectedIndexes(QItemSelectionModel* selectionModel);
    static QList<QModelIndex>* selectedRows(QItemSelectionModel* selectionModel, int column);
    static QItemSelection* selection(QItemSelectionModel* selectionModel);
    static void setModel(QItemSelectionModel* selectionModel, QAbstractItemModel* model);

    // Slots
    static void clear(QItemSelectionModel* selectionModel);
    static void clearCurrentIndex(QItemSelectionModel* selectionModel);
    static void clearSelection(QItemSelectionModel* selectionModel);
    static void reset(QItemSelectionModel* selectionModel);
    static void select(QItemSelectionModel* selectionModel, const QModelIndex* index, QItemSelectionModel::SelectionFlags command);
    static void selectItemSelection(QItemSelectionModel* selectionModel, const QItemSelection* selection, QItemSelectionModel::SelectionFlags command);
    static void setCurrentIndex(QItemSelectionModel* selectionModel, const QModelIndex* index, QItemSelectionModel::SelectionFlags command);

    // Signal connections
    static void connectCurrentChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData);
    static void connectCurrentColumnChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData);
    static void connectCurrentRowChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData);
    static void connectModelChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*), void* userData);
    static void connectSelectionChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData);
};

#endif // QITEMSELECTIONMODEL_BIND_H
