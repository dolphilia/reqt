#ifndef QLCDNUMBER_BIND_H
#define QLCDNUMBER_BIND_H

#include <QLCDNumber>
#include "QLCDNumberHandler.h"

class QLCDNumberBind : public QLCDNumber {
    Q_OBJECT
    typedef void (*QLCDNumber_OverflowCallback)(void*);
public:
    explicit QLCDNumberBind(QWidget *parent = nullptr);
    explicit QLCDNumberBind(uint numDigits, QWidget *parent = nullptr);
    ~QLCDNumberBind() override;

    void setOverflowCallback(QLCDNumber_OverflowCallback callback) const;

private:
    QLCDNumberHandler* handler;
};

#endif // QLCDNUMBER_BIND_H
