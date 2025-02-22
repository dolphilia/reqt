#include "handler_menu.h"

MenuHandler::MenuHandler(QObject *parent)
    : QObject(parent)
    , m_aboutToShowCallback(nullptr)
    , m_aboutToHideCallback(nullptr)
    , m_triggeredCallback(nullptr)
    , m_hoveredCallback(nullptr)
{
}

MenuHandler::~MenuHandler()
{
}

void MenuHandler::setAboutToShowCallback(void (*callback)())
{
    m_aboutToShowCallback = callback;
}

void MenuHandler::setAboutToHideCallback(void (*callback)())
{
    m_aboutToHideCallback = callback;
}

void MenuHandler::setTriggeredCallback(void (*callback)(void* action))
{
    m_triggeredCallback = callback;
}

void MenuHandler::setHoveredCallback(void (*callback)(void* action))
{
    m_hoveredCallback = callback;
}

void MenuHandler::onAboutToShow()
{
    if (m_aboutToShowCallback) {
        m_aboutToShowCallback();
    }
}

void MenuHandler::onAboutToHide()
{
    if (m_aboutToHideCallback) {
        m_aboutToHideCallback();
    }
}

void MenuHandler::onTriggered(QAction* action)
{
    if (m_triggeredCallback) {
        m_triggeredCallback(action);
    }
}

void MenuHandler::onHovered(QAction* action)
{
    if (m_hoveredCallback) {
        m_hoveredCallback(action);
    }
}
