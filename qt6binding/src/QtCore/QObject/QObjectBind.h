#ifndef QOBJECT_BIND_H
#define QOBJECT_BIND_H

#include <QObject>

#include "QObjectHandler.h"

class QObjectHandler;

class QObjectBind : public QObject {
    Q_OBJECT
    typedef void (*QObject_DestroyedCallback)(void*);
    typedef void (*QObject_ObjectNameChangedCallback)(void*, const QString*);
    typedef void (*QObject_EventCallback)(void*, QEvent*);
public:
    explicit QObjectBind(QObject *parent = nullptr);
    ~QObjectBind() override;

    void setDestroyedCallback(QObject_DestroyedCallback callback) const;
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) const;
    void setEventCallback(QObject_EventCallback callback) const;

private:
    QObjectHandler* handler;
};

#endif // QOBJECT_BIND_H
