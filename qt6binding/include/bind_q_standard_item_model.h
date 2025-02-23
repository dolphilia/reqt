#ifndef BIND_Q_STANDARD_ITEM_MODEL_H
#define BIND_Q_STANDARD_ITEM_MODEL_H

#include <QStandardItemModel>

class BindQStandardItemModel : public QStandardItemModel {
    Q_OBJECT
public:
    explicit BindQStandardItemModel(int rows, int columns, QObject *parent = nullptr);
    ~BindQStandardItemModel();
};

#endif // BIND_Q_STANDARD_ITEM_MODEL_H
