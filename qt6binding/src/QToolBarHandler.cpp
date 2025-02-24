#include "QToolBarHandler.h"

ToolBarHandler::ToolBarHandler(QObject *parent)
    : QObject(parent)
    , m_actionTriggeredCallback(nullptr)
    , m_movableChangedCallback(nullptr)
    , m_orientationChangedCallback(nullptr)
    , m_topLevelChangedCallback(nullptr)
    , m_visibilityChangedCallback(nullptr)
    , m_allowedAreasChangedCallback(nullptr)
{
}

ToolBarHandler::~ToolBarHandler()
{
}

void ToolBarHandler::setActionTriggeredCallback(void (*callback)(void* action))
{
    m_actionTriggeredCallback = callback;
}

void ToolBarHandler::setMovableChangedCallback(void (*callback)(bool movable))
{
    m_movableChangedCallback = callback;
}

void ToolBarHandler::setOrientationChangedCallback(void (*callback)(int orientation))
{
    m_orientationChangedCallback = callback;
}

void ToolBarHandler::setTopLevelChangedCallback(void (*callback)(bool topLevel))
{
    m_topLevelChangedCallback = callback;
}

void ToolBarHandler::setVisibilityChangedCallback(void (*callback)(bool visible))
{
    m_visibilityChangedCallback = callback;
}

void ToolBarHandler::setAllowedAreasChangedCallback(void (*callback)(int areas))
{
    m_allowedAreasChangedCallback = callback;
}

void ToolBarHandler::onActionTriggered(QAction* action)
{
    if (m_actionTriggeredCallback) {
        m_actionTriggeredCallback(action);
    }
}

void ToolBarHandler::onMovableChanged(bool movable)
{
    if (m_movableChangedCallback) {
        m_movableChangedCallback(movable);
    }
}

void ToolBarHandler::onOrientationChanged(int orientation)
{
    if (m_orientationChangedCallback) {
        m_orientationChangedCallback(orientation);
    }
}

void ToolBarHandler::onTopLevelChanged(bool topLevel)
{
    if (m_topLevelChangedCallback) {
        m_topLevelChangedCallback(topLevel);
    }
}

void ToolBarHandler::onVisibilityChanged(bool visible)
{
    if (m_visibilityChangedCallback) {
        m_visibilityChangedCallback(visible);
    }
}

void ToolBarHandler::onAllowedAreasChanged(int areas)
{
    if (m_allowedAreasChangedCallback) {
        m_allowedAreasChangedCallback(areas);
    }
}
