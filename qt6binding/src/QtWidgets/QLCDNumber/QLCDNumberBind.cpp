#include "QLCDNumberBind.h"

QLCDNumberBind::QLCDNumberBind(QWidget* parent)
    : QLCDNumber(parent)
{
    handler = new QLCDNumberHandler(this);
    connect(this, &QLCDNumber::overflow, handler, &QLCDNumberHandler::onOverflow);
}

QLCDNumberBind::QLCDNumberBind(uint numDigits, QWidget* parent)
    : QLCDNumber(numDigits, parent)
{
    handler = new QLCDNumberHandler(this);
    connect(this, &QLCDNumber::overflow, handler, &QLCDNumberHandler::onOverflow);
}

QLCDNumberBind::~QLCDNumberBind()
{
    delete handler;
}

void QLCDNumberBind::setOverflowCallback(OverflowCallback callback) const
{
    handler->setOverflowCallback(callback);
}
