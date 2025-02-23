#include "handler_tree_view.h"

TreeViewHandler::TreeViewHandler(QObject *parent)
    : QObject(parent)
    , m_clickedCallback(nullptr)
    , m_doubleClickedCallback(nullptr)
    , m_expandedCallback(nullptr)
    , m_collapsedCallback(nullptr)
    , m_activatedCallback(nullptr)
    , m_enteredCallback(nullptr)
    , m_pressedCallback(nullptr)
    , m_selectionChangedCallback(nullptr)
{
}

TreeViewHandler::~TreeViewHandler()
{
}

void TreeViewHandler::setClickedCallback(void (*callback)(void* index))
{
    m_clickedCallback = callback;
}

void TreeViewHandler::setDoubleClickedCallback(void (*callback)(void* index))
{
    m_doubleClickedCallback = callback;
}

void TreeViewHandler::setExpandedCallback(void (*callback)(void* index))
{
    m_expandedCallback = callback;
}

void TreeViewHandler::setCollapsedCallback(void (*callback)(void* index))
{
    m_collapsedCallback = callback;
}

void TreeViewHandler::setActivatedCallback(void (*callback)(void* index))
{
    m_activatedCallback = callback;
}

void TreeViewHandler::setEnteredCallback(void (*callback)(void* index))
{
    m_enteredCallback = callback;
}

void TreeViewHandler::setPressedCallback(void (*callback)(void* index))
{
    m_pressedCallback = callback;
}

void TreeViewHandler::setSelectionChangedCallback(void (*callback)())
{
    m_selectionChangedCallback = callback;
}

void TreeViewHandler::onClicked(const QModelIndex &index)
{
    if (m_clickedCallback) {
        m_clickedCallback((void*)&index);
    }
}

void TreeViewHandler::onDoubleClicked(const QModelIndex &index)
{
    if (m_doubleClickedCallback) {
        m_doubleClickedCallback((void*)&index);
    }
}

void TreeViewHandler::onExpanded(const QModelIndex &index)
{
    if (m_expandedCallback) {
        m_expandedCallback((void*)&index);
    }
}

void TreeViewHandler::onCollapsed(const QModelIndex &index)
{
    if (m_collapsedCallback) {
        m_collapsedCallback((void*)&index);
    }
}

void TreeViewHandler::onActivated(const QModelIndex &index)
{
    if (m_activatedCallback) {
        m_activatedCallback((void*)&index);
    }
}

void TreeViewHandler::onEntered(const QModelIndex &index)
{
    if (m_enteredCallback) {
        m_enteredCallback((void*)&index);
    }
}

void TreeViewHandler::onPressed(const QModelIndex &index)
{
    if (m_pressedCallback) {
        m_pressedCallback((void*)&index);
    }
}

void TreeViewHandler::onSelectionChanged()
{
    if (m_selectionChangedCallback) {
        m_selectionChangedCallback();
    }
}
