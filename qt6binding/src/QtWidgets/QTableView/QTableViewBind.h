#ifndef QTABLEVIEW_BIND_H
#define QTABLEVIEW_BIND_H

#include <QTableView>

#include "QTableViewHandler.h"

class QTableViewHandler;

class QTableViewBind : public QTableView {
    Q_OBJECT
    typedef void (*QTableView_ClickedCallback)(void*, void* index);
    typedef void (*QTableView_DoubleClickedCallback)(void*, void* index);
    typedef void (*QTableView_ActivatedCallback)(void*, void* index);
    typedef void (*QTableView_EnteredCallback)(void*, void* index);
    typedef void (*QTableView_PressedCallback)(void*, void* index);
    typedef void (*QTableView_SelectionChangedCallback)(void*);
    typedef void (*QTableView_HorizontalHeaderClickedCallback)(void*, int section);
    typedef void (*QTableView_VerticalHeaderClickedCallback)(void*, int section);
public:
    explicit QTableViewBind(QWidget* parent = nullptr);
    ~QTableViewBind() override;
    void setClickedCallback(QTableView_ClickedCallback callback) const;
    void setDoubleClickedCallback(QTableView_DoubleClickedCallback callback) const;
    void setActivatedCallback(QTableView_ActivatedCallback callback) const;
    void setEnteredCallback(QTableView_EnteredCallback callback) const;
    void setPressedCallback(QTableView_PressedCallback callback) const;
    void setSelectionChangedCallback(QTableView_SelectionChangedCallback callback) const;
    void setHorizontalHeaderClickedCallback(QTableView_HorizontalHeaderClickedCallback callback) const;
    void setVerticalHeaderClickedCallback(QTableView_VerticalHeaderClickedCallback callback) const;
private:
    QTableViewHandler* handler;
};

#endif // BIND_Q_TABLE_VIEW_H
