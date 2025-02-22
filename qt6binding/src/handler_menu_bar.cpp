#include "handler_menu_bar.h"
#include <QAction>

MenuBarHandler::MenuBarHandler(QObject *parent)
    : QObject(parent)
    , m_triggeredCallback(nullptr)
    , m_hoveredCallback(nullptr)
{
}

MenuBarHandler::~MenuBarHandler()
{
}

void MenuBarHandler::setTriggeredCallback(void (*callback)(void* action))
{
    m_triggeredCallback = callback;
}

void MenuBarHandler::setHoveredCallback(void (*callback)(void* action))
{
    m_hoveredCallback = callback;
}

void MenuBarHandler::onTriggered(QAction* action)
{
    if (m_triggeredCallback) {
        m_triggeredCallback(action);
    }
}

void MenuBarHandler::onHovered(QAction* action)
{
    if (m_hoveredCallback) {
        m_hoveredCallback(action);
    }
}
