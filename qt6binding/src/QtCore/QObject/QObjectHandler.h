#ifndef Q_OBJECT_HANDLER_H
#define Q_OBJECT_HANDLER_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QEvent>
#include <QList>
#include <QThread>
#include <QMetaObject>
#include <QByteArray>

class QObjectHandler {
public:
    explicit QObjectHandler(QObject *parent = nullptr);
    virtual ~QObjectHandler();

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
    
    // MetaObject
    const QMetaObject *metaObject() const;

    // Access to the underlying QObject
    QObject *get() const;

private:
    QObject *m_object;
};

#endif // Q_OBJECT_HANDLER_H
