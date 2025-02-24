#include "QScrollAreaHandler.h"

ScrollAreaHandler::ScrollAreaHandler(QObject *parent)
    : QObject(parent)
    , m_verticalScrollBarValueChangedCallback(nullptr)
    , m_horizontalScrollBarValueChangedCallback(nullptr)
{
}

ScrollAreaHandler::~ScrollAreaHandler()
{
}

void ScrollAreaHandler::setVerticalScrollBarValueChangedCallback(void (*callback)(int))
{
    m_verticalScrollBarValueChangedCallback = callback;
}

void ScrollAreaHandler::setHorizontalScrollBarValueChangedCallback(void (*callback)(int))
{
    m_horizontalScrollBarValueChangedCallback = callback;
}

void ScrollAreaHandler::onVerticalScrollBarValueChanged(int value)
{
    if (m_verticalScrollBarValueChangedCallback) {
        m_verticalScrollBarValueChangedCallback(value);
    }
}

void ScrollAreaHandler::onHorizontalScrollBarValueChanged(int value)
{
    if (m_horizontalScrollBarValueChangedCallback) {
        m_horizontalScrollBarValueChangedCallback(value);
    }
}
