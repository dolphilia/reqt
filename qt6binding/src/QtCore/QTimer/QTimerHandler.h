#ifndef QTIMER_HANDLER_H
#define QTIMER_HANDLER_H

#include <QObject>

class QTimerHandler : public QObject {
    Q_OBJECT
    typedef void (*QTimer_TimeoutCallback)(void*);
public:
    explicit QTimerHandler(QObject* parent = nullptr);
    void setTimeoutCallback(QTimer_TimeoutCallback callback);

public slots:
    void onTimeout() const;

private:
    QTimer_TimeoutCallback timeoutCallback;
};

#endif // QTIMER_HANDLER_H
