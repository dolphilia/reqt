#include "QInputDialogHandler.h"

QInputDialogHandler::QInputDialogHandler(QObject* parent)
    : QObject(parent)
    , m_doubleValueChangedCallback(nullptr)
    , m_doubleValueSelectedCallback(nullptr)
    , m_intValueChangedCallback(nullptr)
    , m_intValueSelectedCallback(nullptr)
    , m_textValueChangedCallback(nullptr)
    , m_textValueSelectedCallback(nullptr)
{
}

QInputDialogHandler::~QInputDialogHandler()
{
}

void QInputDialogHandler::setDoubleValueChangedCallback(QInputDialogDoubleValueChangedCallback callback)
{
    m_doubleValueChangedCallback = callback;
}

void QInputDialogHandler::setDoubleValueSelectedCallback(QInputDialogDoubleValueSelectedCallback callback)
{
    m_doubleValueSelectedCallback = callback;
}

void QInputDialogHandler::setIntValueChangedCallback(QInputDialogIntValueChangedCallback callback)
{
    m_intValueChangedCallback = callback;
}

void QInputDialogHandler::setIntValueSelectedCallback(QInputDialogIntValueSelectedCallback callback)
{
    m_intValueSelectedCallback = callback;
}

void QInputDialogHandler::setTextValueChangedCallback(QInputDialogTextValueChangedCallback callback)
{
    m_textValueChangedCallback = callback;
}

void QInputDialogHandler::setTextValueSelectedCallback(QInputDialogTextValueSelectedCallback callback)
{
    m_textValueSelectedCallback = callback;
}

void QInputDialogHandler::onDoubleValueChanged(double value)
{
    if (m_doubleValueChangedCallback) {
        m_doubleValueChangedCallback(this, value);
    }
}

void QInputDialogHandler::onDoubleValueSelected(double value)
{
    if (m_doubleValueSelectedCallback) {
        m_doubleValueSelectedCallback(this, value);
    }
}

void QInputDialogHandler::onIntValueChanged(int value)
{
    if (m_intValueChangedCallback) {
        m_intValueChangedCallback(this, value);
    }
}

void QInputDialogHandler::onIntValueSelected(int value)
{
    if (m_intValueSelectedCallback) {
        m_intValueSelectedCallback(this, value);
    }
}

void QInputDialogHandler::onTextValueChanged(const QString& text)
{
    if (m_textValueChangedCallback) {
        m_textValueChangedCallback(this, text.toUtf8().constData());
    }
}

void QInputDialogHandler::onTextValueSelected(const QString& text)
{
    if (m_textValueSelectedCallback) {
        m_textValueSelectedCallback(this, text.toUtf8().constData());
    }
} 