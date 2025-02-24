#include "QTableViewHandler.h"

TableViewHandler::TableViewHandler(QObject *parent)
    : QObject(parent)
    , m_clickedCallback(nullptr)
    , m_doubleClickedCallback(nullptr)
    , m_activatedCallback(nullptr)
    , m_enteredCallback(nullptr)
    , m_pressedCallback(nullptr)
    , m_selectionChangedCallback(nullptr)
    , m_horizontalHeaderClickedCallback(nullptr)
    , m_verticalHeaderClickedCallback(nullptr)
{
}

TableViewHandler::~TableViewHandler()
{
}

void TableViewHandler::setClickedCallback(void (*callback)(void* index))
{
    m_clickedCallback = callback;
}

void TableViewHandler::setDoubleClickedCallback(void (*callback)(void* index))
{
    m_doubleClickedCallback = callback;
}

void TableViewHandler::setActivatedCallback(void (*callback)(void* index))
{
    m_activatedCallback = callback;
}

void TableViewHandler::setEnteredCallback(void (*callback)(void* index))
{
    m_enteredCallback = callback;
}

void TableViewHandler::setPressedCallback(void (*callback)(void* index))
{
    m_pressedCallback = callback;
}

void TableViewHandler::setSelectionChangedCallback(void (*callback)())
{
    m_selectionChangedCallback = callback;
}

void TableViewHandler::setHorizontalHeaderClickedCallback(void (*callback)(int section))
{
    m_horizontalHeaderClickedCallback = callback;
}

void TableViewHandler::setVerticalHeaderClickedCallback(void (*callback)(int section))
{
    m_verticalHeaderClickedCallback = callback;
}

void TableViewHandler::onClicked(const QModelIndex &index)
{
    if (m_clickedCallback) {
        m_clickedCallback((void*)&index);
    }
}

void TableViewHandler::onDoubleClicked(const QModelIndex &index)
{
    if (m_doubleClickedCallback) {
        m_doubleClickedCallback((void*)&index);
    }
}

void TableViewHandler::onActivated(const QModelIndex &index)
{
    if (m_activatedCallback) {
        m_activatedCallback((void*)&index);
    }
}

void TableViewHandler::onEntered(const QModelIndex &index)
{
    if (m_enteredCallback) {
        m_enteredCallback((void*)&index);
    }
}

void TableViewHandler::onPressed(const QModelIndex &index)
{
    if (m_pressedCallback) {
        m_pressedCallback((void*)&index);
    }
}

void TableViewHandler::onSelectionChanged()
{
    if (m_selectionChangedCallback) {
        m_selectionChangedCallback();
    }
}

void TableViewHandler::onHorizontalHeaderClicked(int section)
{
    if (m_horizontalHeaderClickedCallback) {
        m_horizontalHeaderClickedCallback(section);
    }
}

void TableViewHandler::onVerticalHeaderClicked(int section)
{
    if (m_verticalHeaderClickedCallback) {
        m_verticalHeaderClickedCallback(section);
    }
}
