#include "bind_q_tree_view.h"

BindQTreeView::BindQTreeView(QWidget *parent)
    : QTreeView(parent)
    , m_handler(nullptr)
{
}

BindQTreeView::~BindQTreeView()
{
    delete m_handler;
}

void BindQTreeView::setTreeViewHandler(TreeViewHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QTreeView::clicked,
                  m_handler, &TreeViewHandler::onClicked);
        disconnect(this, &QTreeView::doubleClicked,
                  m_handler, &TreeViewHandler::onDoubleClicked);
        disconnect(this, &QTreeView::expanded,
                  m_handler, &TreeViewHandler::onExpanded);
        disconnect(this, &QTreeView::collapsed,
                  m_handler, &TreeViewHandler::onCollapsed);
        disconnect(this, &QTreeView::activated,
                  m_handler, &TreeViewHandler::onActivated);
        disconnect(this, &QTreeView::entered,
                  m_handler, &TreeViewHandler::onEntered);
        disconnect(this, &QTreeView::pressed,
                  m_handler, &TreeViewHandler::onPressed);
        disconnect(selectionModel(), &QItemSelectionModel::selectionChanged,
                  m_handler, &TreeViewHandler::onSelectionChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QTreeView::clicked,
                m_handler, &TreeViewHandler::onClicked);
        connect(this, &QTreeView::doubleClicked,
                m_handler, &TreeViewHandler::onDoubleClicked);
        connect(this, &QTreeView::expanded,
                m_handler, &TreeViewHandler::onExpanded);
        connect(this, &QTreeView::collapsed,
                m_handler, &TreeViewHandler::onCollapsed);
        connect(this, &QTreeView::activated,
                m_handler, &TreeViewHandler::onActivated);
        connect(this, &QTreeView::entered,
                m_handler, &TreeViewHandler::onEntered);
        connect(this, &QTreeView::pressed,
                m_handler, &TreeViewHandler::onPressed);
        if (selectionModel()) {
            connect(selectionModel(), &QItemSelectionModel::selectionChanged,
                    m_handler, &TreeViewHandler::onSelectionChanged);
        }
    }
}

TreeViewHandler *BindQTreeView::handler() const
{
    return m_handler;
}
