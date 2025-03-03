#ifndef QLCDNUMBER_C_H
#define QLCDNUMBER_C_H

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QLCDNumber_create(void* parent);
void* QLCDNumber_createWithDigits(int numDigits, void* parent);
void QLCDNumber_delete(void* lcd);

// Display modes
void QLCDNumber_setBinMode(void* lcd);
void QLCDNumber_setOctMode(void* lcd);
void QLCDNumber_setDecMode(void* lcd);
void QLCDNumber_setHexMode(void* lcd);

// Segment styles
#define QLCDNUMBER_OUTLINE 0
#define QLCDNUMBER_FILLED 1
#define QLCDNUMBER_FLAT 2

void QLCDNumber_setSegmentStyle(void* lcd, int style);
int QLCDNumber_segmentStyle(void* lcd);

// Display properties
void QLCDNumber_setDigitCount(void* lcd, int numDigits);
int QLCDNumber_digitCount(void* lcd);
void QLCDNumber_setSmallDecimalPoint(void* lcd, bool enabled);
bool QLCDNumber_smallDecimalPoint(void* lcd);
void QLCDNumber_setMode(void* lcd, int mode);
int QLCDNumber_mode(void* lcd);

// Display values
void QLCDNumber_display(void* lcd, const char* str);
void QLCDNumber_displayInt(void* lcd, int num);
void QLCDNumber_displayDouble(void* lcd, double num);
bool QLCDNumber_checkOverflow(void* lcd, double num);
bool QLCDNumber_checkOverflowInt(void* lcd, int num);

// Mode constants
#define QLCDNUMBER_HEX 0
#define QLCDNUMBER_DEC 1
#define QLCDNUMBER_OCT 2
#define QLCDNUMBER_BIN 3

// Callbacks
typedef void (*OverflowCallback)(void*);

void QLCDNumber_setOverflowCallback(void* lcd, OverflowCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QLCDNUMBER_C_H
