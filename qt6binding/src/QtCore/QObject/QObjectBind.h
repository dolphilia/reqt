#ifndef QOBJECT_BIND_H
#define QOBJECT_BIND_H

#include <QObject>
#include <QMetaMethod>

#include "QObjectHandler.h"

class QObjectHandler;

class QObjectBind : public QObject {
    Q_OBJECT
    typedef void (*QObject_DestroyedCallback)(void*);
    typedef void (*QObject_ObjectNameChangedCallback)(void*, const QString*);
    typedef void (*QObject_EventCallback)(void*, QEvent*);
    typedef void (*QObject_ChildEventCallback)(void*, QChildEvent*);
    typedef void (*QObject_ConnectNotifyCallback)(void*, const QMetaMethod*);
    typedef void (*QObject_CustomEventCallback)(void*, QEvent*);
    typedef void (*QObject_DisconnectNotifyCallback)(void*, const QMetaMethod*);
    typedef void (*QObject_TimerEventCallback)(void*, QTimerEvent*);
public:
    explicit QObjectBind(QObject *parent = nullptr);
    ~QObjectBind() override;

    void setDestroyedCallback(QObject_DestroyedCallback callback) const;
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) const;
    void setEventCallback(QObject_EventCallback callback) const;
    void setChildEventCallback(QObject_ChildEventCallback callback) const;
    void setConnectNotifyCallback(QObject_ConnectNotifyCallback callback) const;
    void setCustomEventCallback(QObject_CustomEventCallback callback) const;
    void setDisconnectNotifyCallback(QObject_DisconnectNotifyCallback callback) const;
    void setTimerEventCallback(QObject_TimerEventCallback callback) const;

    // Protected Functions made public
    bool isSignalConnected(const QMetaMethod &signal) const;
    int receivers(const char *signal) const;
    QObject *sender() const;
    int senderSignalIndex() const;

protected:
    // Reimplemented Protected Functions
    void childEvent(QChildEvent *event) override;
    bool event(QEvent *e) override;
    void connectNotify(const QMetaMethod &signal) override;
    void customEvent(QEvent *event) override;
    void disconnectNotify(const QMetaMethod &signal) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QObjectHandler* handler;
};

#endif // QOBJECT_BIND_H
