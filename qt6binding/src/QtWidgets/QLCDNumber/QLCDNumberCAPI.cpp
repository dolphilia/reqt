#include "qlcdnumber.h"
#include "QLCDNumberBind.h"
#include "QLCDNumberHandler.h"

extern "C" {

void* QLCDNumber_create(void* parent) {
    return new QLCDNumberBind(reinterpret_cast<QWidget*>(parent));
}

void* QLCDNumber_createWithDigits(int numDigits, void* parent) {
    return new QLCDNumberBind(numDigits, reinterpret_cast<QWidget*>(parent));
}

void QLCDNumber_delete(void* lcd) {
    delete static_cast<QLCDNumberBind*>(lcd);
}

void QLCDNumber_setBinMode(void* lcd) {
    static_cast<QLCDNumberBind*>(lcd)->setBinMode();
}

void QLCDNumber_setOctMode(void* lcd) {
    static_cast<QLCDNumberBind*>(lcd)->setOctMode();
}

void QLCDNumber_setDecMode(void* lcd) {
    static_cast<QLCDNumberBind*>(lcd)->setDecMode();
}

void QLCDNumber_setHexMode(void* lcd) {
    static_cast<QLCDNumberBind*>(lcd)->setHexMode();
}

void QLCDNumber_setSegmentStyle(void* lcd, int style) {
    static_cast<QLCDNumberBind*>(lcd)->setSegmentStyle(static_cast<QLCDNumber::SegmentStyle>(style));
}

int QLCDNumber_segmentStyle(void* lcd) {
    return static_cast<int>(static_cast<QLCDNumberBind*>(lcd)->segmentStyle());
}

void QLCDNumber_setDigitCount(void* lcd, int numDigits) {
    static_cast<QLCDNumberBind*>(lcd)->setDigitCount(numDigits);
}

int QLCDNumber_digitCount(void* lcd) {
    return static_cast<QLCDNumberBind*>(lcd)->digitCount();
}

void QLCDNumber_setSmallDecimalPoint(void* lcd, bool enabled) {
    static_cast<QLCDNumberBind*>(lcd)->setSmallDecimalPoint(enabled);
}

bool QLCDNumber_smallDecimalPoint(void* lcd) {
    return static_cast<QLCDNumberBind*>(lcd)->smallDecimalPoint();
}

void QLCDNumber_setMode(void* lcd, int mode) {
    static_cast<QLCDNumberBind*>(lcd)->setMode(static_cast<QLCDNumber::Mode>(mode));
}

int QLCDNumber_mode(void* lcd) {
    return static_cast<int>(static_cast<QLCDNumberBind*>(lcd)->mode());
}

void QLCDNumber_display(void* lcd, const char* str) {
    static_cast<QLCDNumberBind*>(lcd)->display(QString::fromUtf8(str));
}

void QLCDNumber_displayInt(void* lcd, int num) {
    static_cast<QLCDNumberBind*>(lcd)->display(num);
}

void QLCDNumber_displayDouble(void* lcd, double num) {
    static_cast<QLCDNumberBind*>(lcd)->display(num);
}

bool QLCDNumber_checkOverflow(void* lcd, double num) {
    return static_cast<QLCDNumberBind*>(lcd)->checkOverflow(num);
}

bool QLCDNumber_checkOverflowInt(void* lcd, int num) {
    return static_cast<QLCDNumberBind*>(lcd)->checkOverflow(num);
}

typedef void (*OverflowCallback)(void*);

void QLCDNumber_setOverflowCallback(void* lcd,OverflowCallback callback) {
    static_cast<QLCDNumberBind*>(lcd)->setOverflowCallback(callback);
}

}
