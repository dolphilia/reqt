#include "QItemSelectionModelHandler.h"

QItemSelectionModelHandler::QItemSelectionModelHandler(QObject* parent)
    : QObject(parent)
    , currentChangedCallback(nullptr)
    , currentColumnChangedCallback(nullptr)
    , currentRowChangedCallback(nullptr)
    , modelChangedCallback(nullptr)
    , selectionChangedCallback(nullptr)
    , currentChangedUserData(nullptr)
    , currentColumnChangedUserData(nullptr)
    , currentRowChangedUserData(nullptr)
    , modelChangedUserData(nullptr)
    , selectionChangedUserData(nullptr)
{
}

void QItemSelectionModelHandler::setCurrentChangedCallback(void (*callback)(void*, void*, void*), void* userData) {
    currentChangedCallback = callback;
    currentChangedUserData = userData;
}

void QItemSelectionModelHandler::setCurrentColumnChangedCallback(void (*callback)(void*, void*, void*), void* userData) {
    currentColumnChangedCallback = callback;
    currentColumnChangedUserData = userData;
}

void QItemSelectionModelHandler::setCurrentRowChangedCallback(void (*callback)(void*, void*, void*), void* userData) {
    currentRowChangedCallback = callback;
    currentRowChangedUserData = userData;
}

void QItemSelectionModelHandler::setModelChangedCallback(void (*callback)(void*, void*), void* userData) {
    modelChangedCallback = callback;
    modelChangedUserData = userData;
}

void QItemSelectionModelHandler::setSelectionChangedCallback(void (*callback)(void*, void*, void*), void* userData) {
    selectionChangedCallback = callback;
    selectionChangedUserData = userData;
}

void QItemSelectionModelHandler::currentChanged(const QModelIndex& current, const QModelIndex& previous) {
    if (currentChangedCallback) {
        currentChangedCallback(const_cast<void*>(static_cast<const void*>(&current)),
                             const_cast<void*>(static_cast<const void*>(&previous)),
                             currentChangedUserData);
    }
}

void QItemSelectionModelHandler::currentColumnChanged(const QModelIndex& current, const QModelIndex& previous) {
    if (currentColumnChangedCallback) {
        currentColumnChangedCallback(const_cast<void*>(static_cast<const void*>(&current)),
                                   const_cast<void*>(static_cast<const void*>(&previous)),
                                   currentColumnChangedUserData);
    }
}

void QItemSelectionModelHandler::currentRowChanged(const QModelIndex& current, const QModelIndex& previous) {
    if (currentRowChangedCallback) {
        currentRowChangedCallback(const_cast<void*>(static_cast<const void*>(&current)),
                                const_cast<void*>(static_cast<const void*>(&previous)),
                                currentRowChangedUserData);
    }
}

void QItemSelectionModelHandler::modelChanged(QAbstractItemModel* model) {
    if (modelChangedCallback) {
        modelChangedCallback(static_cast<void*>(model), modelChangedUserData);
    }
}

void QItemSelectionModelHandler::selectionChanged(const QItemSelection& selected, const QItemSelection& deselected) {
    if (selectionChangedCallback) {
        selectionChangedCallback(const_cast<void*>(static_cast<const void*>(&selected)),
                               const_cast<void*>(static_cast<const void*>(&deselected)),
                               selectionChangedUserData);
    }
}
