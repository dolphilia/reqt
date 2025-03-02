#ifndef QITEMSELECTIONMODEL_HANDLER_H
#define QITEMSELECTIONMODEL_HANDLER_H

#include <QObject>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QItemSelection>

class QItemSelectionModelHandler : public QObject {
    Q_OBJECT

public:
    explicit QItemSelectionModelHandler(QObject* parent = nullptr);

    void setCurrentChangedCallback(void (*callback)(void*, void*, void*), void* userData);
    void setCurrentColumnChangedCallback(void (*callback)(void*, void*, void*), void* userData);
    void setCurrentRowChangedCallback(void (*callback)(void*, void*, void*), void* userData);
    void setModelChangedCallback(void (*callback)(void*, void*), void* userData);
    void setSelectionChangedCallback(void (*callback)(void*, void*, void*), void* userData);

public slots:
    void currentChanged(const QModelIndex& current, const QModelIndex& previous);
    void currentColumnChanged(const QModelIndex& current, const QModelIndex& previous);
    void currentRowChanged(const QModelIndex& current, const QModelIndex& previous);
    void modelChanged(QAbstractItemModel* model);
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:
    void (*currentChangedCallback)(void*, void*, void*);
    void (*currentColumnChangedCallback)(void*, void*, void*);
    void (*currentRowChangedCallback)(void*, void*, void*);
    void (*modelChangedCallback)(void*, void*);
    void (*selectionChangedCallback)(void*, void*, void*);

    void* currentChangedUserData;
    void* currentColumnChangedUserData;
    void* currentRowChangedUserData;
    void* modelChangedUserData;
    void* selectionChangedUserData;
};

#endif // QITEMSELECTIONMODEL_HANDLER_H
