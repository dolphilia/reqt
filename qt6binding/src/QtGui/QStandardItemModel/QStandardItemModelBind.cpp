#include "QStandardItemModelBind.h"

BindQStandardItemModel::BindQStandardItemModel(int rows, int columns, QObject *parent)
    : QStandardItemModel(rows, columns, parent)
{
}

BindQStandardItemModel::~BindQStandardItemModel()
{
}
