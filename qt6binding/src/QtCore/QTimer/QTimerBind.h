#ifndef QTIMER_BIND_H
#define QTIMER_BIND_H

#include <QTimer>

#include "QTimerHandler.h"

class QTimerHandler;

class QTimerBind : public QTimer {
    Q_OBJECT
    typedef void (*QTimer_TimeoutCallback)(void*);
public:
    explicit QTimerBind(QObject* parent = nullptr);
    ~QTimerBind() override;
    void setTimeoutCallback(QTimer_TimeoutCallback callback) const;
private:
    QTimerHandler* handler;
};

#endif // QTIMER_BIND_H
