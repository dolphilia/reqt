#ifndef HANDLER_TREE_VIEW_H
#define HANDLER_TREE_VIEW_H

#include <QObject>
#include <QModelIndex>

class TreeViewHandler : public QObject {
    Q_OBJECT
public:
    explicit TreeViewHandler(QObject *parent = nullptr);
    ~TreeViewHandler();

    void setClickedCallback(void (*callback)(void* index));
    void setDoubleClickedCallback(void (*callback)(void* index));
    void setExpandedCallback(void (*callback)(void* index));
    void setCollapsedCallback(void (*callback)(void* index));
    void setActivatedCallback(void (*callback)(void* index));
    void setEnteredCallback(void (*callback)(void* index));
    void setPressedCallback(void (*callback)(void* index));
    void setSelectionChangedCallback(void (*callback)());

public slots:
    void onClicked(const QModelIndex &index);
    void onDoubleClicked(const QModelIndex &index);
    void onExpanded(const QModelIndex &index);
    void onCollapsed(const QModelIndex &index);
    void onActivated(const QModelIndex &index);
    void onEntered(const QModelIndex &index);
    void onPressed(const QModelIndex &index);
    void onSelectionChanged();

private:
    void (*m_clickedCallback)(void* index);
    void (*m_doubleClickedCallback)(void* index);
    void (*m_expandedCallback)(void* index);
    void (*m_collapsedCallback)(void* index);
    void (*m_activatedCallback)(void* index);
    void (*m_enteredCallback)(void* index);
    void (*m_pressedCallback)(void* index);
    void (*m_selectionChangedCallback)();
};

#endif // HANDLER_TREE_VIEW_H
