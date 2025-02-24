#include "QScrollBarHandler.h"

ScrollBarHandler::ScrollBarHandler(QObject *parent)
    : QObject(parent)
    , m_valueChangedCallback(nullptr)
    , m_sliderMovedCallback(nullptr)
    , m_sliderPressedCallback(nullptr)
    , m_sliderReleasedCallback(nullptr)
    , m_rangeChangedCallback(nullptr)
    , m_actionTriggeredCallback(nullptr)
{
}

ScrollBarHandler::~ScrollBarHandler()
{
}

void ScrollBarHandler::setValueChangedCallback(void (*callback)(int))
{
    m_valueChangedCallback = callback;
}

void ScrollBarHandler::setSliderMovedCallback(void (*callback)(int))
{
    m_sliderMovedCallback = callback;
}

void ScrollBarHandler::setSliderPressedCallback(void (*callback)())
{
    m_sliderPressedCallback = callback;
}

void ScrollBarHandler::setSliderReleasedCallback(void (*callback)())
{
    m_sliderReleasedCallback = callback;
}

void ScrollBarHandler::setRangeChangedCallback(void (*callback)(int, int))
{
    m_rangeChangedCallback = callback;
}

void ScrollBarHandler::setActionTriggeredCallback(void (*callback)(int))
{
    m_actionTriggeredCallback = callback;
}

void ScrollBarHandler::onValueChanged(int value)
{
    if (m_valueChangedCallback) {
        m_valueChangedCallback(value);
    }
}

void ScrollBarHandler::onSliderMoved(int position)
{
    if (m_sliderMovedCallback) {
        m_sliderMovedCallback(position);
    }
}

void ScrollBarHandler::onSliderPressed()
{
    if (m_sliderPressedCallback) {
        m_sliderPressedCallback();
    }
}

void ScrollBarHandler::onSliderReleased()
{
    if (m_sliderReleasedCallback) {
        m_sliderReleasedCallback();
    }
}

void ScrollBarHandler::onRangeChanged(int min, int max)
{
    if (m_rangeChangedCallback) {
        m_rangeChangedCallback(min, max);
    }
}

void ScrollBarHandler::onActionTriggered(int action)
{
    if (m_actionTriggeredCallback) {
        m_actionTriggeredCallback(action);
    }
}
