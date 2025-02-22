#include "handler_spin_box.h"

SpinBoxHandler::SpinBoxHandler(QObject *parent)
    : QObject(parent)
    , m_valueChangedCallback(nullptr)
    , m_textChangedCallback(nullptr)
    , m_editingFinishedCallback(nullptr)
{
}

SpinBoxHandler::~SpinBoxHandler()
{
}

void SpinBoxHandler::setValueChangedCallback(void (*callback)(int))
{
    m_valueChangedCallback = callback;
}

void SpinBoxHandler::setTextChangedCallback(void (*callback)(const char*))
{
    m_textChangedCallback = callback;
}

void SpinBoxHandler::setEditingFinishedCallback(void (*callback)())
{
    m_editingFinishedCallback = callback;
}

void SpinBoxHandler::onValueChanged(int value)
{
    if (m_valueChangedCallback) {
        m_valueChangedCallback(value);
    }
}

void SpinBoxHandler::onTextChanged(const QString &text)
{
    if (m_textChangedCallback) {
        m_textChangedCallback(text.toUtf8().constData());
    }
}

void SpinBoxHandler::onEditingFinished()
{
    if (m_editingFinishedCallback) {
        m_editingFinishedCallback();
    }
}
