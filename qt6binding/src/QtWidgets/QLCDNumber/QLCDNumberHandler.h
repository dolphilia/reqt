#ifndef QLCDNUMBER_HANDLER_H
#define QLCDNUMBER_HANDLER_H

#include <QObject>

class QLCDNumberHandler : public QObject {
    Q_OBJECT
    typedef void (*QLCDNumber_OverflowCallback)(void*);
public:
    explicit QLCDNumberHandler(QObject* parent = nullptr);
    void setOverflowCallback(QLCDNumber_OverflowCallback callback);

public slots:
    void onOverflow() const;

private:
    QLCDNumber_OverflowCallback overflowCallback;
};

#endif // QLCDNUMBER_HANDLER_H
