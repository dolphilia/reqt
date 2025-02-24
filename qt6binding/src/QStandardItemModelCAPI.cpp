#include "qstandarditemmodel.h"
#include "QStandardItemModelBind.h"
#include "QStandardItemBind.h"

extern "C" {

void* QStandardItemModel_create(int rows, int columns, void* parent)
{
    return new BindQStandardItemModel(rows, columns, reinterpret_cast<QObject*>(parent));
}

void QStandardItemModel_delete(void* model)
{
    delete static_cast<BindQStandardItemModel*>(model);
}

void QStandardItemModel_setItem(void* model, void* item, int row, int column)
{
    static_cast<BindQStandardItemModel*>(model)->setItem(row, column, static_cast<BindQStandardItem*>(item));
}

}
