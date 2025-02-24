#include "qstandarditem.h"
#include "QStandardItemBind.h"

extern "C" {

void* QStandardItem_create(const char* text)
{
    return new BindQStandardItem(QString::fromUtf8(text));
}

void QStandardItem_delete(void* item)
{
    delete static_cast<BindQStandardItem*>(item);
}

void QStandardItem_setText(void* item, const char* text)
{
    static_cast<BindQStandardItem*>(item)->setText(QString::fromUtf8(text));
}

void QStandardItem_appendRow(void* item, void* child)
{
    static_cast<BindQStandardItem*>(item)->appendRow(static_cast<BindQStandardItem*>(child));
}

}
