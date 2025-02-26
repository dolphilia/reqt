#include "QObjectBind.h"

BindQObject::BindQObject(QObject *parent)
    : QObject(parent)
    , handler(new QObjectHandler(parent))
    , destroyedCallback(nullptr)
    , objectNameChangedCallback(nullptr)
    , eventCallback(nullptr)
{
    connect(this, &QObject::destroyed, this, &BindQObject::onDestroyed);
    connect(this, &QObject::objectNameChanged, this, &BindQObject::onObjectNameChanged);
}

BindQObject::~BindQObject()
{
    delete handler;
}

void BindQObject::setObjectName(const QString &name)
{
    handler->setObjectName(name);
}

QString BindQObject::objectName() const
{
    return handler->objectName();
}

QObject *BindQObject::parent() const
{
    return handler->parent();
}

void BindQObject::setParent(QObject *parent)
{
    handler->setParent(parent);
}

bool BindQObject::setProperty(const char *name, const QVariant &value)
{
    return handler->setProperty(name, value);
}

QVariant BindQObject::property(const char *name) const
{
    return handler->property(name);
}

QList<QByteArray> BindQObject::dynamicPropertyNames() const
{
    return handler->dynamicPropertyNames();
}

void BindQObject::deleteLater()
{
    handler->deleteLater();
}

bool BindQObject::blockSignals(bool block)
{
    return handler->blockSignals(block);
}

bool BindQObject::signalsBlocked() const
{
    return handler->signalsBlocked();
}

QString BindQObject::className() const
{
    return handler->className();
}

bool BindQObject::inherits(const char *className) const
{
    return handler->inherits(className);
}

void BindQObject::dumpObjectInfo() const
{
    handler->dumpObjectInfo();
}

void BindQObject::dumpObjectTree() const
{
    handler->dumpObjectTree();
}

QList<QObject*> BindQObject::children() const
{
    return handler->children();
}

bool BindQObject::event(QEvent *e)
{
    if (eventCallback) {
        eventCallback(this, e);
    }
    return handler->event(e);
}

bool BindQObject::eventFilter(QObject *watched, QEvent *event)
{
    return handler->eventFilter(watched, event);
}

void BindQObject::installEventFilter(QObject *filterObj)
{
    handler->installEventFilter(filterObj);
}

void BindQObject::removeEventFilter(QObject *obj)
{
    handler->removeEventFilter(obj);
}

bool BindQObject::isWidgetType() const
{
    return handler->isWidgetType();
}

bool BindQObject::isWindowType() const
{
    return handler->isWindowType();
}

int BindQObject::startTimer(int interval, Qt::TimerType timerType)
{
    return handler->startTimer(interval, timerType);
}

void BindQObject::killTimer(int id)
{
    handler->killTimer(id);
}

QThread *BindQObject::thread() const
{
    return handler->thread();
}

bool BindQObject::moveToThread(QThread *targetThread)
{
    return handler->moveToThread(targetThread);
}


void BindQObject::setDestroyedCallback(ObjectDestroyedCallback callback)
{
    destroyedCallback = callback;
}

void BindQObject::setObjectNameChangedCallback(ObjectNameChangedCallback callback)
{
    objectNameChangedCallback = callback;
}

void BindQObject::setEventCallback(EventCallback callback)
{
    eventCallback = callback;
}

void BindQObject::onDestroyed()
{
    if (destroyedCallback) {
        destroyedCallback(this);
    }
}

void BindQObject::onObjectNameChanged(const QString &objectName)
{
    if (objectNameChangedCallback) {
        objectNameChangedCallback(this, &objectName);
    }
}
