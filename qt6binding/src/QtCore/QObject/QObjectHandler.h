#ifndef QOBJECT_HANDLER_H
#define QOBJECT_HANDLER_H

#include <QObject>
#include <QMetaMethod>

class QObjectHandler : public QObject {
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
    explicit QObjectHandler(QObject* parent = nullptr);
    void setDestroyedCallback(QObject_DestroyedCallback callback);
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback);
    void setEventCallback(QObject_EventCallback callback);
    void setChildEventCallback(QObject_ChildEventCallback callback);
    void setConnectNotifyCallback(QObject_ConnectNotifyCallback callback);
    void setCustomEventCallback(QObject_CustomEventCallback callback);
    void setDisconnectNotifyCallback(QObject_DisconnectNotifyCallback callback);
    void setTimerEventCallback(QObject_TimerEventCallback callback);

public slots:
    void onDestroyed() const;
    void onObjectNameChanged(const QString& objectName) const;
    void onEvent(QEvent* event) const;
    void onChildEvent(QChildEvent* event) const;
    void onConnectNotify(const QMetaMethod& signal) const;
    void onCustomEvent(QEvent* event) const;
    void onDisconnectNotify(const QMetaMethod& signal) const;
    void onTimerEvent(QTimerEvent* event) const;

private:
    QObject_DestroyedCallback destroyedCallback;
    QObject_ObjectNameChangedCallback objectNameChangedCallback;
    QObject_EventCallback eventCallback;
    QObject_ChildEventCallback childEventCallback;
    QObject_ConnectNotifyCallback connectNotifyCallback;
    QObject_CustomEventCallback customEventCallback;
    QObject_DisconnectNotifyCallback disconnectNotifyCallback;
    QObject_TimerEventCallback timerEventCallback;
};

#endif // QOBJECT_HANDLER_H
