#ifndef BIND_Q_STANDARD_ITEM_H
#define BIND_Q_STANDARD_ITEM_H

#include <QStandardItem>

class BindQStandardItem : public QStandardItem {
public:
    explicit BindQStandardItem(const QString &text);
    ~BindQStandardItem();
};

#endif // BIND_Q_STANDARD_ITEM_H
