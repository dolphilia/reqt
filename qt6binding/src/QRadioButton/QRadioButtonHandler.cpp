#include "QRadioButtonHandler.h"

RadioButtonHandler::RadioButtonHandler(QObject *parent)
    : QObject(parent)
    , m_toggledCallback(nullptr)
    , m_clickedCallback(nullptr)
    , m_pressedCallback(nullptr)
    , m_releasedCallback(nullptr)
{
}

RadioButtonHandler::~RadioButtonHandler()
{
}

void RadioButtonHandler::setToggledCallback(void (*callback)(bool))
{
    m_toggledCallback = callback;
}

void RadioButtonHandler::setClickedCallback(void (*callback)(bool))
{
    m_clickedCallback = callback;
}

void RadioButtonHandler::setPressedCallback(void (*callback)())
{
    m_pressedCallback = callback;
}

void RadioButtonHandler::setReleasedCallback(void (*callback)())
{
    m_releasedCallback = callback;
}

void RadioButtonHandler::onToggled(bool checked)
{
    if (m_toggledCallback) {
        m_toggledCallback(checked);
    }
}

void RadioButtonHandler::onClicked(bool checked)
{
    if (m_clickedCallback) {
        m_clickedCallback(checked);
    }
}

void RadioButtonHandler::onPressed()
{
    if (m_pressedCallback) {
        m_pressedCallback();
    }
}

void RadioButtonHandler::onReleased()
{
    if (m_releasedCallback) {
        m_releasedCallback();
    }
}
