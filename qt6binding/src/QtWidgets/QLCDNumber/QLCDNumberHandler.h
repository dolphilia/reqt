#ifndef QLCDNUMBER_HANDLER_H
#define QLCDNUMBER_HANDLER_H

#include <QObject>

class QLCDNumberHandler : public QObject {
    Q_OBJECT
    typedef void (*OverflowCallback)(void*);
public:
    explicit QLCDNumberHandler(QObject* parent = nullptr);
    void setOverflowCallback(OverflowCallback callback);

public slots:
    void onOverflow() const;

private:
    OverflowCallback overflowCallback;
};

#endif // QLCDNUMBER_HANDLER_H
