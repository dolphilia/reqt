#ifndef QLISTVIEW_BIND_H
#define QLISTVIEW_BIND_H

#include "QListViewHandler.h"
#include <QListView>

class QListViewBind : public QListView {
    Q_OBJECT
    typedef void (*QListView_ClickedCallback)(void*, int, int);
    typedef void (*QListView_DoubleClickedCallback)(void*, int, int);
    typedef void (*QListView_SelectionChangedCallback)(void*);
public:
    explicit QListViewBind(QWidget* parent = nullptr);
    ~QListViewBind() override;
    void setClickedCallback(QListView_ClickedCallback callback) const;
    void setDoubleClickedCallback(QListView_DoubleClickedCallback callback) const;
    void setSelectionChangedCallback(QListView_SelectionChangedCallback callback) const;
private:
    QListViewHandler* handler;
};

#endif // QLISTVIEW_BIND_H
