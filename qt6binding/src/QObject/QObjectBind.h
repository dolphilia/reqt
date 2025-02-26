#ifndef BIND_Q_OBJECT_H
#define BIND_Q_OBJECT_H

#include "QObjectHandler.h"
#include <QObject>
#include <QString>
#include <QVariant>
#include <QEvent>
#include <QThread>
#include <QMetaObject>

// コールバック関数の型定義
typedef void (*ObjectDestroyedCallback)(void*);
typedef void (*ObjectNameChangedCallback)(void*, const QString*);
typedef void (*EventCallback)(void*, QEvent*);

class BindQObject : public QObject {
    Q_OBJECT
public:
    explicit BindQObject(QObject *parent = nullptr);
    ~BindQObject();

    // Handler access
    QObjectHandler *handler;

    // Object name
    void setObjectName(const QString &name);
    QString objectName() const;

    // Parent
    QObject *parent() const;
    void setParent(QObject *parent);

    // Property
    bool setProperty(const char *name, const QVariant &value);
    QVariant property(const char *name) const;
    QList<QByteArray> dynamicPropertyNames() const;

    // Object management
    void deleteLater();
    bool blockSignals(bool block);
    bool signalsBlocked() const;

    // Object info
    QString className() const;
    bool inherits(const char *className) const;
    void dumpObjectInfo() const;
    void dumpObjectTree() const;
    
    // Child management
    QList<QObject*> children() const;
    
    // Event handling
    bool event(QEvent *e);
    bool eventFilter(QObject *watched, QEvent *event);
    void installEventFilter(QObject *filterObj);
    void removeEventFilter(QObject *obj);
    
    // Type checking
    bool isWidgetType() const;
    bool isWindowType() const;
    
    // Timer handling
    int startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer);
    void killTimer(int id);
    
    // Thread handling
    QThread *thread() const;
    bool moveToThread(QThread *targetThread);
    
    // Handler access for metaObject
    // Note: Don't override metaObject() as Q_OBJECT already provides it

    // Signal callbacks
    void setDestroyedCallback(ObjectDestroyedCallback callback);
    void setObjectNameChangedCallback(ObjectNameChangedCallback callback);
    void setEventCallback(EventCallback callback);

private slots:
    void onDestroyed();
    void onObjectNameChanged(const QString &objectName);

private:
    ObjectDestroyedCallback destroyedCallback;
    ObjectNameChangedCallback objectNameChangedCallback;
    EventCallback eventCallback;
};

#endif // BIND_Q_OBJECT_H
