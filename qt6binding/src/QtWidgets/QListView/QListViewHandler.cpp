#include "QListViewHandler.h"

ListViewHandler::ListViewHandler(ListViewClickedCallback clicked,
                                 ListViewDoubleClickedCallback doubleClicked,
                                 ListViewSelectionChangedCallback selectionChanged,
                                 QObject* parent)
    : QObject(parent)
    , m_clickedCallback(clicked)
    , m_doubleClickedCallback(doubleClicked)
    , m_selectionChangedCallback(selectionChanged)
{
}

void ListViewHandler::onClicked(const QModelIndex& index)
{
    if (m_clickedCallback) {
        m_clickedCallback(this->parent(), index.row(), index.column());
    }
}

void ListViewHandler::onDoubleClicked(const QModelIndex& index)
{
    if (m_doubleClickedCallback) {
        m_doubleClickedCallback(this->parent(), index.row(), index.column());
    }
}

void ListViewHandler::onSelectionChanged()
{
    if (m_selectionChangedCallback) {
        m_selectionChangedCallback(this->parent());
    }
}
