#include "QLCDNumberBind.h"

BindQLCDNumber::BindQLCDNumber(QWidget *parent)
    : QLCDNumber(parent)
    , m_handler(nullptr)
{
}

BindQLCDNumber::BindQLCDNumber(uint numDigits, QWidget *parent)
    : QLCDNumber(numDigits, parent)
    , m_handler(nullptr)
{
}

BindQLCDNumber::~BindQLCDNumber()
{
    delete m_handler;
}

void BindQLCDNumber::setLCDNumberHandler(LCDNumberHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QLCDNumber::overflow,
                  m_handler, &LCDNumberHandler::onOverflow);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QLCDNumber::overflow,
                m_handler, &LCDNumberHandler::onOverflow);
    }
}

LCDNumberHandler *BindQLCDNumber::handler() const
{
    return m_handler;
}
