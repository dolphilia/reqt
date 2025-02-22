#include "handler_tab_widget.h"

TabWidgetHandler::TabWidgetHandler(QObject *parent)
    : QObject(parent)
    , m_currentChangedCallback(nullptr)
    , m_tabCloseRequestedCallback(nullptr)
{
}

TabWidgetHandler::~TabWidgetHandler()
{
}

void TabWidgetHandler::setCurrentChangedCallback(void (*callback)(int))
{
    m_currentChangedCallback = callback;
}

void TabWidgetHandler::setTabCloseRequestedCallback(void (*callback)(int))
{
    m_tabCloseRequestedCallback = callback;
}

void TabWidgetHandler::onCurrentChanged(int index)
{
    if (m_currentChangedCallback) {
        m_currentChangedCallback(index);
    }
}

void TabWidgetHandler::onTabCloseRequested(int index)
{
    if (m_tabCloseRequestedCallback) {
        m_tabCloseRequestedCallback(index);
    }
}
