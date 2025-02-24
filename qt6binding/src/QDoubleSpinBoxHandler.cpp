#include "QDoubleSpinBoxHandler.h"

DoubleSpinBoxHandler::DoubleSpinBoxHandler(QObject *parent)
    : QObject(parent)
    , m_valueChangedCallback(nullptr)
    , m_editingFinishedCallback(nullptr)
{
}

DoubleSpinBoxHandler::~DoubleSpinBoxHandler()
{
}

void DoubleSpinBoxHandler::setValueChangedCallback(void (*callback)(double value))
{
    m_valueChangedCallback = callback;
}

void DoubleSpinBoxHandler::setEditingFinishedCallback(void (*callback)())
{
    m_editingFinishedCallback = callback;
}

void DoubleSpinBoxHandler::onValueChanged(double value)
{
    if (m_valueChangedCallback) {
        m_valueChangedCallback(value);
    }
}

void DoubleSpinBoxHandler::onEditingFinished()
{
    if (m_editingFinishedCallback) {
        m_editingFinishedCallback();
    }
}
