#include "handler_tool_button.h"

ToolButtonHandler::ToolButtonHandler(QObject *parent)
    : QObject(parent)
    , m_clickedCallback(nullptr)
    , m_toggledCallback(nullptr)
    , m_triggeredCallback(nullptr)
{
}

ToolButtonHandler::~ToolButtonHandler()
{
}

void ToolButtonHandler::setClickedCallback(void (*callback)())
{
    m_clickedCallback = callback;
}

void ToolButtonHandler::setToggledCallback(void (*callback)(bool checked))
{
    m_toggledCallback = callback;
}

void ToolButtonHandler::setTriggeredCallback(void (*callback)())
{
    m_triggeredCallback = callback;
}

void ToolButtonHandler::onClicked()
{
    if (m_clickedCallback) {
        m_clickedCallback();
    }
}

void ToolButtonHandler::onToggled(bool checked)
{
    if (m_toggledCallback) {
        m_toggledCallback(checked);
    }
}

void ToolButtonHandler::onTriggered()
{
    if (m_triggeredCallback) {
        m_triggeredCallback();
    }
}
