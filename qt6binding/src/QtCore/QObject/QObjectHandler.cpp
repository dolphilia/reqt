#include "QObjectHandler.h"

QObjectHandler::QObjectHandler(QObject *parent)
    : m_object(new QObject(parent))
{
}

QObjectHandler::~QObjectHandler()
{
    delete m_object;
}

void QObjectHandler::setObjectName(const QString &name)
{
    m_object->setObjectName(name);
}

QString QObjectHandler::objectName() const
{
    return m_object->objectName();
}

QObject *QObjectHandler::parent() const
{
    return m_object->parent();
}

void QObjectHandler::setParent(QObject *parent)
{
    m_object->setParent(parent);
}

bool QObjectHandler::setProperty(const char *name, const QVariant &value)
{
    return m_object->setProperty(name, value);
}

QVariant QObjectHandler::property(const char *name) const
{
    return m_object->property(name);
}

QList<QByteArray> QObjectHandler::dynamicPropertyNames() const
{
    return m_object->dynamicPropertyNames();
}

void QObjectHandler::deleteLater()
{
    m_object->deleteLater();
}

bool QObjectHandler::blockSignals(bool block)
{
    return m_object->blockSignals(block);
}

bool QObjectHandler::signalsBlocked() const
{
    return m_object->signalsBlocked();
}

QString QObjectHandler::className() const
{
    return QString(m_object->metaObject()->className());
}

bool QObjectHandler::inherits(const char *className) const
{
    return m_object->inherits(className);
}

void QObjectHandler::dumpObjectInfo() const
{
    m_object->dumpObjectInfo();
}

void QObjectHandler::dumpObjectTree() const
{
    m_object->dumpObjectTree();
}

QList<QObject*> QObjectHandler::children() const
{
    return m_object->children();
}

bool QObjectHandler::event(QEvent *e)
{
    return m_object->event(e);
}

bool QObjectHandler::eventFilter(QObject *watched, QEvent *event)
{
    return m_object->eventFilter(watched, event);
}

void QObjectHandler::installEventFilter(QObject *filterObj)
{
    m_object->installEventFilter(filterObj);
}

void QObjectHandler::removeEventFilter(QObject *obj)
{
    m_object->removeEventFilter(obj);
}

bool QObjectHandler::isWidgetType() const
{
    return m_object->isWidgetType();
}

bool QObjectHandler::isWindowType() const
{
    return m_object->isWindowType();
}

int QObjectHandler::startTimer(int interval, Qt::TimerType timerType)
{
    return m_object->startTimer(interval, timerType);
}

void QObjectHandler::killTimer(int id)
{
    m_object->killTimer(id);
}

QThread *QObjectHandler::thread() const
{
    return m_object->thread();
}

bool QObjectHandler::moveToThread(QThread *targetThread)
{
    return m_object->moveToThread(targetThread);
}

const QMetaObject *QObjectHandler::metaObject() const
{
    return m_object->metaObject();
}

QObject *QObjectHandler::get() const
{
    return m_object;
}
