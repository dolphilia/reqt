#include "QItemSelectionModelBind.h"
#include "QItemSelectionModelHandler.h"
#include <QModelIndex>

QItemSelectionModel* QItemSelectionModelBind::create(QAbstractItemModel* model) {
    return new QItemSelectionModel(model);
}

QItemSelectionModel* QItemSelectionModelBind::createWithParent(QAbstractItemModel* model, QObject* parent) {
    return new QItemSelectionModel(model, parent);
}

void QItemSelectionModelBind::destroy(QItemSelectionModel* selectionModel) {
    delete selectionModel;
}

bool QItemSelectionModelBind::columnIntersectsSelection(QItemSelectionModel* selectionModel, int column, const QModelIndex* parent) {
    return selectionModel ? selectionModel->columnIntersectsSelection(column, parent ? *parent : QModelIndex()) : false;
}

QModelIndex* QItemSelectionModelBind::currentIndex(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        return new QModelIndex(selectionModel->currentIndex());
    }
    return nullptr;
}

bool QItemSelectionModelBind::hasSelection(QItemSelectionModel* selectionModel) {
    return selectionModel ? selectionModel->hasSelection() : false;
}

bool QItemSelectionModelBind::isColumnSelected(QItemSelectionModel* selectionModel, int column, const QModelIndex* parent) {
    return selectionModel ? selectionModel->isColumnSelected(column, parent ? *parent : QModelIndex()) : false;
}

bool QItemSelectionModelBind::isRowSelected(QItemSelectionModel* selectionModel, int row, const QModelIndex* parent) {
    return selectionModel ? selectionModel->isRowSelected(row, parent ? *parent : QModelIndex()) : false;
}

bool QItemSelectionModelBind::isSelected(QItemSelectionModel* selectionModel, const QModelIndex* index) {
    return selectionModel && index ? selectionModel->isSelected(*index) : false;
}

QAbstractItemModel* QItemSelectionModelBind::model(QItemSelectionModel* selectionModel) {
    return selectionModel ? selectionModel->model() : nullptr;
}

bool QItemSelectionModelBind::rowIntersectsSelection(QItemSelectionModel* selectionModel, int row, const QModelIndex* parent) {
    return selectionModel ? selectionModel->rowIntersectsSelection(row, parent ? *parent : QModelIndex()) : false;
}

QList<QModelIndex>* QItemSelectionModelBind::selectedColumns(QItemSelectionModel* selectionModel, int row) {
    if (selectionModel) {
        return new QList<QModelIndex>(selectionModel->selectedColumns(row));
    }
    return nullptr;
}

QList<QModelIndex>* QItemSelectionModelBind::selectedIndexes(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        return new QList<QModelIndex>(selectionModel->selectedIndexes());
    }
    return nullptr;
}

QList<QModelIndex>* QItemSelectionModelBind::selectedRows(QItemSelectionModel* selectionModel, int column) {
    if (selectionModel) {
        return new QList<QModelIndex>(selectionModel->selectedRows(column));
    }
    return nullptr;
}

QItemSelection* QItemSelectionModelBind::selection(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        return new QItemSelection(selectionModel->selection());
    }
    return nullptr;
}

void QItemSelectionModelBind::setModel(QItemSelectionModel* selectionModel, QAbstractItemModel* model) {
    if (selectionModel) {
        selectionModel->setModel(model);
    }
}

void QItemSelectionModelBind::clear(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        selectionModel->clear();
    }
}

void QItemSelectionModelBind::clearCurrentIndex(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        selectionModel->clearCurrentIndex();
    }
}

void QItemSelectionModelBind::clearSelection(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        selectionModel->clearSelection();
    }
}

void QItemSelectionModelBind::reset(QItemSelectionModel* selectionModel) {
    if (selectionModel) {
        selectionModel->reset();
    }
}

void QItemSelectionModelBind::select(QItemSelectionModel* selectionModel, const QModelIndex* index, QItemSelectionModel::SelectionFlags command) {
    if (selectionModel && index) {
        selectionModel->select(*index, command);
    }
}

void QItemSelectionModelBind::selectItemSelection(QItemSelectionModel* selectionModel, const QItemSelection* selection, QItemSelectionModel::SelectionFlags command) {
    if (selectionModel && selection) {
        selectionModel->select(*selection, command);
    }
}

void QItemSelectionModelBind::setCurrentIndex(QItemSelectionModel* selectionModel, const QModelIndex* index, QItemSelectionModel::SelectionFlags command) {
    if (selectionModel && index) {
        selectionModel->setCurrentIndex(*index, command);
    }
}

void QItemSelectionModelBind::connectCurrentChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData) {
    if (selectionModel && handler) {
        auto signalHandler = new QItemSelectionModelHandler(selectionModel);
        signalHandler->setCurrentChangedCallback(handler, userData);
        QObject::connect(selectionModel, &QItemSelectionModel::currentChanged, signalHandler, &QItemSelectionModelHandler::currentChanged);
    }
}

void QItemSelectionModelBind::connectCurrentColumnChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData) {
    if (selectionModel && handler) {
        auto signalHandler = new QItemSelectionModelHandler(selectionModel);
        signalHandler->setCurrentColumnChangedCallback(handler, userData);
        QObject::connect(selectionModel, &QItemSelectionModel::currentColumnChanged, signalHandler, &QItemSelectionModelHandler::currentColumnChanged);
    }
}

void QItemSelectionModelBind::connectCurrentRowChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData) {
    if (selectionModel && handler) {
        auto signalHandler = new QItemSelectionModelHandler(selectionModel);
        signalHandler->setCurrentRowChangedCallback(handler, userData);
        QObject::connect(selectionModel, &QItemSelectionModel::currentRowChanged, signalHandler, &QItemSelectionModelHandler::currentRowChanged);
    }
}

void QItemSelectionModelBind::connectModelChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*), void* userData) {
    if (selectionModel && handler) {
        auto signalHandler = new QItemSelectionModelHandler(selectionModel);
        signalHandler->setModelChangedCallback(handler, userData);
        QObject::connect(selectionModel, &QItemSelectionModel::modelChanged, signalHandler, &QItemSelectionModelHandler::modelChanged);
    }
}

void QItemSelectionModelBind::connectSelectionChanged(QItemSelectionModel* selectionModel, void (*handler)(void*, void*, void*), void* userData) {
    if (selectionModel && handler) {
        auto signalHandler = new QItemSelectionModelHandler(selectionModel);
        signalHandler->setSelectionChangedCallback(handler, userData);
        QObject::connect(selectionModel, &QItemSelectionModel::selectionChanged, signalHandler, &QItemSelectionModelHandler::selectionChanged);
    }
}
