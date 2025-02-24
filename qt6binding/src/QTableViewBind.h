#ifndef BIND_Q_TABLE_VIEW_H
#define BIND_Q_TABLE_VIEW_H

#include <QTableView>
#include "QTableViewHandler.h"

class BindQTableView : public QTableView {
    Q_OBJECT
public:
    explicit BindQTableView(QWidget *parent = nullptr);
    ~BindQTableView();

    void setTableViewHandler(TableViewHandler *handler);
    TableViewHandler *handler() const;

private:
    TableViewHandler *m_handler;
};

#endif // BIND_Q_TABLE_VIEW_H
