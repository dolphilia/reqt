#ifndef BIND_Q_TREE_VIEW_H
#define BIND_Q_TREE_VIEW_H

#include <QTreeView>
#include "handler_tree_view.h"

class BindQTreeView : public QTreeView {
    Q_OBJECT
public:
    explicit BindQTreeView(QWidget *parent = nullptr);
    ~BindQTreeView();

    void setTreeViewHandler(TreeViewHandler *handler);
    TreeViewHandler *handler() const;

private:
    TreeViewHandler *m_handler;
};

#endif // BIND_Q_TREE_VIEW_H
