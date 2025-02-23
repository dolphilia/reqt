#include "bind_q_standard_item_model.h"

BindQStandardItemModel::BindQStandardItemModel(int rows, int columns, QObject *parent)
    : QStandardItemModel(rows, columns, parent)
{
}

BindQStandardItemModel::~BindQStandardItemModel()
{
}
