#include "QBoxLayoutHandler.h"

QBoxLayoutHandler::QBoxLayoutHandler(QObject* parent)
    : QObject(parent), m_geometryChangedCallback(nullptr)
{
}

QBoxLayoutHandler::~QBoxLayoutHandler()
{
}

void QBoxLayoutHandler::setGeometryChangedCallback(void (*callback)())
{
    m_geometryChangedCallback = callback;
}

void QBoxLayoutHandler::onGeometryChanged()
{
    if (m_geometryChangedCallback) {
        m_geometryChangedCallback();
    }
}
