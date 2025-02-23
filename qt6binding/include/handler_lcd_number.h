#ifndef HANDLER_LCD_NUMBER_H
#define HANDLER_LCD_NUMBER_H

#include <QObject>

class LCDNumberHandler : public QObject {
    Q_OBJECT

public:
    explicit LCDNumberHandler(QObject *parent = nullptr);
    ~LCDNumberHandler();

    void setOverflowCallback(void (*callback)());

public slots:
    void onOverflow();

private:
    void (*m_overflowCallback)();
};

#endif // HANDLER_LCD_NUMBER_H
