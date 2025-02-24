#include "qlcdnumber.h"
#include "QLCDNumberBind.h"
#include "QLCDNumberHandler.h"

extern "C" {

void* QLCDNumber_create(void* parent)
{
    return new BindQLCDNumber(reinterpret_cast<QWidget*>(parent));
}

void* QLCDNumber_createWithDigits(int numDigits, void* parent)
{
    return new BindQLCDNumber(numDigits, reinterpret_cast<QWidget*>(parent));
}

void QLCDNumber_delete(void* lcd)
{
    delete static_cast<BindQLCDNumber*>(lcd);
}

void QLCDNumber_setBinMode(void* lcd)
{
    static_cast<BindQLCDNumber*>(lcd)->setBinMode();
}

void QLCDNumber_setOctMode(void* lcd)
{
    static_cast<BindQLCDNumber*>(lcd)->setOctMode();
}

void QLCDNumber_setDecMode(void* lcd)
{
    static_cast<BindQLCDNumber*>(lcd)->setDecMode();
}

void QLCDNumber_setHexMode(void* lcd)
{
    static_cast<BindQLCDNumber*>(lcd)->setHexMode();
}

void QLCDNumber_setSegmentStyle(void* lcd, int style)
{
    static_cast<BindQLCDNumber*>(lcd)->setSegmentStyle(static_cast<QLCDNumber::SegmentStyle>(style));
}

int QLCDNumber_segmentStyle(void* lcd)
{
    return static_cast<int>(static_cast<BindQLCDNumber*>(lcd)->segmentStyle());
}

void QLCDNumber_setDigitCount(void* lcd, int numDigits)
{
    static_cast<BindQLCDNumber*>(lcd)->setDigitCount(numDigits);
}

int QLCDNumber_digitCount(void* lcd)
{
    return static_cast<BindQLCDNumber*>(lcd)->digitCount();
}

void QLCDNumber_setSmallDecimalPoint(void* lcd, bool enabled)
{
    static_cast<BindQLCDNumber*>(lcd)->setSmallDecimalPoint(enabled);
}

bool QLCDNumber_smallDecimalPoint(void* lcd)
{
    return static_cast<BindQLCDNumber*>(lcd)->smallDecimalPoint();
}

void QLCDNumber_setMode(void* lcd, int mode)
{
    static_cast<BindQLCDNumber*>(lcd)->setMode(static_cast<QLCDNumber::Mode>(mode));
}

int QLCDNumber_mode(void* lcd)
{
    return static_cast<int>(static_cast<BindQLCDNumber*>(lcd)->mode());
}

void QLCDNumber_display(void* lcd, const char* str)
{
    static_cast<BindQLCDNumber*>(lcd)->display(QString::fromUtf8(str));
}

void QLCDNumber_displayInt(void* lcd, int num)
{
    static_cast<BindQLCDNumber*>(lcd)->display(num);
}

void QLCDNumber_displayDouble(void* lcd, double num)
{
    static_cast<BindQLCDNumber*>(lcd)->display(num);
}

bool QLCDNumber_checkOverflow(void* lcd, double num)
{
    return static_cast<BindQLCDNumber*>(lcd)->checkOverflow(num);
}

bool QLCDNumber_checkOverflowInt(void* lcd, int num)
{
    return static_cast<BindQLCDNumber*>(lcd)->checkOverflow(num);
}

void QLCDNumber_setOverflowCallback(void* lcd, QLCDNumberOverflowCallback callback)
{
    auto handler = new LCDNumberHandler();
    handler->setOverflowCallback(callback);
    static_cast<BindQLCDNumber*>(lcd)->setLCDNumberHandler(handler);
}

}
