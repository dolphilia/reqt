#ifndef QLISTVIEW_BIND_H
#define QLISTVIEW_BIND_H

#include "QListViewHandler.h"
#include <QListView>

class QListViewBind : public QListView {
    Q_OBJECT
    typedef void (*ClickedCallback)(void*, int, int);
    typedef void (*DoubleClickedCallback)(void*, int, int);
    typedef void (*SelectionChangedCallback)(void*);
public:
    explicit QListViewBind(QWidget* parent = nullptr);
    ~QListViewBind() override;
    void setClickedCallback(ClickedCallback callback) const;
    void setDoubleClickedCallback(DoubleClickedCallback callback) const;
    void setSelectionChangedCallback(SelectionChangedCallback callback) const;
private:
    ListViewHandler* handler;
};

#endif // QLISTVIEW_BIND_H
