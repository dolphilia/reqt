#include "handler_lcd_number.h"

LCDNumberHandler::LCDNumberHandler(QObject *parent)
    : QObject(parent)
    , m_overflowCallback(nullptr)
{
}

LCDNumberHandler::~LCDNumberHandler()
{
}

void LCDNumberHandler::setOverflowCallback(void (*callback)())
{
    m_overflowCallback = callback;
}

void LCDNumberHandler::onOverflow()
{
    if (m_overflowCallback) {
        m_overflowCallback();
    }
}
