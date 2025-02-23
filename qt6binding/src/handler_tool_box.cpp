#include "handler_tool_box.h"

ToolBoxHandler::ToolBoxHandler(QObject *parent)
    : QObject(parent)
    , m_currentChangedCallback(nullptr)
{
}

ToolBoxHandler::~ToolBoxHandler()
{
}

void ToolBoxHandler::setCurrentChangedCallback(void (*callback)(int index))
{
    m_currentChangedCallback = callback;
}

void ToolBoxHandler::onCurrentChanged(int index)
{
    if (m_currentChangedCallback) {
        m_currentChangedCallback(index);
    }
}
