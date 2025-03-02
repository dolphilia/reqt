#include "QSliderHandler.h"

SliderHandler::SliderHandler(QObject *parent)
    : QObject(parent)
    , m_valueChangedCallback(nullptr)
    , m_sliderMovedCallback(nullptr)
    , m_sliderPressedCallback(nullptr)
    , m_sliderReleasedCallback(nullptr)
    , m_rangeChangedCallback(nullptr)
    , m_actionTriggeredCallback(nullptr)
{
}

SliderHandler::~SliderHandler()
{
}

void SliderHandler::setValueChangedCallback(void (*callback)(int))
{
    m_valueChangedCallback = callback;
}

void SliderHandler::setSliderMovedCallback(void (*callback)(int))
{
    m_sliderMovedCallback = callback;
}

void SliderHandler::setSliderPressedCallback(void (*callback)())
{
    m_sliderPressedCallback = callback;
}

void SliderHandler::setSliderReleasedCallback(void (*callback)())
{
    m_sliderReleasedCallback = callback;
}

void SliderHandler::setRangeChangedCallback(void (*callback)(int, int))
{
    m_rangeChangedCallback = callback;
}

void SliderHandler::setActionTriggeredCallback(void (*callback)(int))
{
    m_actionTriggeredCallback = callback;
}

void SliderHandler::onValueChanged(int value)
{
    if (m_valueChangedCallback) {
        m_valueChangedCallback(value);
    }
}

void SliderHandler::onSliderMoved(int position)
{
    if (m_sliderMovedCallback) {
        m_sliderMovedCallback(position);
    }
}

void SliderHandler::onSliderPressed()
{
    if (m_sliderPressedCallback) {
        m_sliderPressedCallback();
    }
}

void SliderHandler::onSliderReleased()
{
    if (m_sliderReleasedCallback) {
        m_sliderReleasedCallback();
    }
}

void SliderHandler::onRangeChanged(int min, int max)
{
    if (m_rangeChangedCallback) {
        m_rangeChangedCallback(min, max);
    }
}

void SliderHandler::onActionTriggered(int action)
{
    if (m_actionTriggeredCallback) {
        m_actionTriggeredCallback(action);
    }
}
