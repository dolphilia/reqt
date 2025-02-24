#include "QStringListModelBind.h"
#include "qstringlistmodel.h"

QStringListModelBind::QStringListModelBind(QObject* parent)
    : QStringListModel(parent)
{
}

QStringListModelBind::~QStringListModelBind()
{
}

void* QStringListModelBind::create(QObject* parent)
{
    return new QStringListModelBind(parent);
}

void QStringListModelBind::destroy(QStringListModel* model)
{
    delete model;
}

void QStringListModelBind::addItem(QStringListModel* model, const char* text)
{
    QStringList list = model->stringList();
    list.append(QString::fromUtf8(text));
    model->setStringList(list);
}

void QStringListModelBind::removeItem(QStringListModel* model, int row)
{
    QStringList list = model->stringList();
    if (row >= 0 && row < list.size()) {
        list.removeAt(row);
        model->setStringList(list);
    }
}

void QStringListModelBind::setItem(QStringListModel* model, int row, const char* text)
{
    QStringList list = model->stringList();
    if (row >= 0 && row < list.size()) {
        list[row] = QString::fromUtf8(text);
        model->setStringList(list);
    }
}

const char* QStringListModelBind::item(QStringListModel* model, int row)
{
    QStringList list = model->stringList();
    if (row >= 0 && row < list.size()) {
        static QByteArray buffer;
        buffer = list[row].toUtf8();
        return buffer.constData();
    }
    return "";
}

int QStringListModelBind::rowCount(QStringListModel* model)
{
    return model->rowCount();
}

void QStringListModelBind::clear(QStringListModel* model)
{
    model->setStringList(QStringList());
}
