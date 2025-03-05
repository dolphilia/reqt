#ifndef QOBJECT_HANDLER_H
#define QOBJECT_HANDLER_H

#include <QObject>

class QObjectHandler : public QObject {
    Q_OBJECT
    typedef void (*QObject_DestroyedCallback)(void*);
    typedef void (*QObject_ObjectNameChangedCallback)(void*, const QString*);
    typedef void (*QObject_EventCallback)(void*, QEvent*);
public:
    explicit QObjectHandler(QObject* parent = nullptr);
    void setDestroyedCallback(QObject_DestroyedCallback callback);
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback);
    void setEventCallback(QObject_EventCallback callback);

public slots:
    void onDestroyed() const;
    void onObjectNameChanged(const QString& objectName) const;
    void onEvent(QEvent* event) const;

private:
    QObject_DestroyedCallback destroyedCallback;
    QObject_ObjectNameChangedCallback objectNameChangedCallback;
    QObject_EventCallback eventCallback;
};

#endif // QOBJECT_HANDLER_H
