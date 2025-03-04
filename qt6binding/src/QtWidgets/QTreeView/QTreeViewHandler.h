#ifndef QTREEVIEW_HANDLER_H
#define QTREEVIEW_HANDLER_H

#include <QObject>
#include <QModelIndex>

class QTreeViewHandler : public QObject {
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
    explicit QTreeViewHandler(QObject *parent = nullptr);
    ~QTreeViewHandler() override;

    void setClickedCallback(QTreeView_ClickedCallback callback);
    void setDoubleClickedCallback(QTreeView_DoubleClickedCallback callback);
    void setExpandedCallback(QTreeView_ExpandedCallback callback);
    void setCollapsedCallback(QTreeView_CollapsedCallback callback);
    void setActivatedCallback(QTreeView_ActivatedCallback callback);
    void setEnteredCallback(QTreeView_EnteredCallback callback);
    void setPressedCallback(QTreeView_PressedCallback callback);
    void setSelectionChangedCallback(QTreeView_SelectionChangedCallback callback);

public slots:
    void onClicked(const QModelIndex &index) const;
    void onDoubleClicked(const QModelIndex &index) const;
    void onExpanded(const QModelIndex &index) const;
    void onCollapsed(const QModelIndex &index) const;
    void onActivated(const QModelIndex &index) const;
    void onEntered(const QModelIndex &index) const;
    void onPressed(const QModelIndex &index) const;
    void onSelectionChanged() const;

private:
    QTreeView_ClickedCallback clickedCallback;
    QTreeView_DoubleClickedCallback doubleClickedCallback;
    QTreeView_ExpandedCallback expandedCallback;
    QTreeView_CollapsedCallback collapsedCallback;
    QTreeView_ActivatedCallback activatedCallback;
    QTreeView_EnteredCallback enteredCallback;
    QTreeView_PressedCallback pressedCallback;
    QTreeView_SelectionChangedCallback selectionChangedCallback;
};

#endif // QTREEVIEW_HANDLER_H
