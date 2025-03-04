#ifndef QTREEVIEW_BIND_H
#define QTREEVIEW_BIND_H

#include <QTreeView>
#include "QTreeViewHandler.h"

class QTreeViewHandler;

class QTreeViewBind : public QTreeView {
    Q_OBJECT
    typedef void (*QTreeView_ClickedCallback)(void*, void*);
    typedef void (*QTreeView_DoubleClickedCallback)(void*, void*);
    typedef void (*QTreeView_ExpandedCallback)(void*, void*);
    typedef void (*QTreeView_CollapsedCallback)(void*, void*);
    typedef void (*QTreeView_ActivatedCallback)(void*, void*);
    typedef void (*QTreeView_EnteredCallback)(void*, void*);
    typedef void (*QTreeView_PressedCallback)(void*, void*);
    typedef void (*QTreeView_SelectionChangedCallback)(void*);
public:
    explicit QTreeViewBind(QWidget *parent = nullptr);
    ~QTreeViewBind() override;
    
    void setClickedCallback(QTreeView_ClickedCallback callback) const;
    void setDoubleClickedCallback(QTreeView_DoubleClickedCallback callback) const;
    void setExpandedCallback(QTreeView_ExpandedCallback callback) const;
    void setCollapsedCallback(QTreeView_CollapsedCallback callback) const;
    void setActivatedCallback(QTreeView_ActivatedCallback callback) const;
    void setEnteredCallback(QTreeView_EnteredCallback callback) const;
    void setPressedCallback(QTreeView_PressedCallback callback) const;
    void setSelectionChangedCallback(QTreeView_SelectionChangedCallback callback) const;

private:
    QTreeViewHandler* handler;
};

#endif // QTREEVIEW_BIND_H
