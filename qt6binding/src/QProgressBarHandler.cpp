#include "QProgressBarHandler.h"

ProgressBarHandler::ProgressBarHandler(QObject *parent)
    : QObject(parent)
    , m_valueChangedCallback(nullptr)
{
}

ProgressBarHandler::~ProgressBarHandler()
{
}

void ProgressBarHandler::setValueChangedCallback(void (*callback)(int))
{
    m_valueChangedCallback = callback;
}

void ProgressBarHandler::onValueChanged(int value)
{
    if (m_valueChangedCallback) {
        m_valueChangedCallback(value);
    }
}
