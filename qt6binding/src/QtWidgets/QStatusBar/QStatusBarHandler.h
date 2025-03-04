#ifndef QSTATUSBAR_HANDLER_H
#define QSTATUSBAR_HANDLER_H

#include <QObject>

class QStatusBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QStatusBar_MessageChangedCallback)(void*, const char*);
public:
    explicit QStatusBarHandler(QObject* parent = nullptr);
    void setMessageChangedCallback(QStatusBar_MessageChangedCallback callback);

public slots:
    void onMessageChanged(const QString& message) const;

private:
    QStatusBar_MessageChangedCallback messageChangedCallback;
};

#endif // QSTATUSBAR_HANDLER_H
