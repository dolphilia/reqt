#include "handler_tab_bar.h"

TabBarHandler::TabBarHandler(QObject *parent)
    : QObject(parent)
    , m_currentChangedCallback(nullptr)
    , m_tabCloseRequestedCallback(nullptr)
{
}

TabBarHandler::~TabBarHandler()
{
}

void TabBarHandler::setCurrentChangedCallback(void (*callback)(int))
{
    m_currentChangedCallback = callback;
}

void TabBarHandler::setTabCloseRequestedCallback(void (*callback)(int))
{
    m_tabCloseRequestedCallback = callback;
}

void TabBarHandler::onCurrentChanged(int index)
{
    if (m_currentChangedCallback) {
        m_currentChangedCallback(index);
    }
}

void TabBarHandler::onTabCloseRequested(int index)
{
    if (m_tabCloseRequestedCallback) {
        m_tabCloseRequestedCallback(index);
    }
}
