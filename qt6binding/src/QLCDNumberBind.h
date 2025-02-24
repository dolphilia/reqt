#ifndef BIND_Q_LCD_NUMBER_H
#define BIND_Q_LCD_NUMBER_H

#include <QLCDNumber>
#include "QLCDNumberHandler.h"

class BindQLCDNumber : public QLCDNumber {
public:
    BindQLCDNumber(QWidget *parent = nullptr);
    explicit BindQLCDNumber(uint numDigits, QWidget *parent = nullptr);
    ~BindQLCDNumber();

    void setLCDNumberHandler(LCDNumberHandler *handler);
    LCDNumberHandler *handler() const;

private:
    LCDNumberHandler *m_handler;
};

#endif // BIND_Q_LCD_NUMBER_H
