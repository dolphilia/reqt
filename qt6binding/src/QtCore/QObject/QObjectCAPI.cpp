#include "QObjectBind.h"
#include "QVariant/QVariantBind.h"
#include <QtCore/qproperty.h>
#include <QRegularExpression>

extern "C" {

//-- Properties
//-- Public Functions

// QObject(QObject *parent = nullptr)

void* QObject_create(void* parent) {
    return new QObjectBind(static_cast<QObject*>(parent));
}

// virtual ~QObject()

void QObject_delete(void* object) {
    delete static_cast<QObjectBind*>(object);
}

// QBindable<QString> bindableObjectName()

void * QObject_bindableObjectName(void* object) {
    QBindable<QString>* bindable = new QBindable<QString>(static_cast<QObjectBind*>(object)->bindableObjectName());
    return static_cast<void*>(bindable);
}

// bool blockSignals(bool block)

bool QObject_blockSignals(void* object, bool block) {
    return static_cast<QObjectBind*>(object)->blockSignals(block);
}

// const QObjectList & children() const

void** QObject_children(void* object, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->children();
    *count = children.size();
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    return result;
}

// QMetaObject::Connection connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const

void* QObject_connect(void* object, void* sender, const char* signal, const char* method, int type) {
    return new QMetaObject::Connection(static_cast<QObjectBind*>(object)->connect(static_cast<QObject*>(sender), signal, method, static_cast<Qt::ConnectionType>(type)));
}

// bool disconnect(const QObject *receiver, const char *method = nullptr) const

bool QObject_disconnect(void* object, void* receiver, const char* method) {
    return static_cast<QObjectBind*>(object)->disconnect(static_cast<QObject*>(receiver), method);
}

// bool disconnect(const char *signal = nullptr, const QObject *receiver = nullptr, const char *method = nullptr) const

bool QObject_disconnect_2(void* object, const char* signal, void* receiver, const char* method) {
    return static_cast<QObjectBind*>(object)->disconnect(signal, static_cast<QObject*>(receiver), method);
}

// void dumpObjectInfo() const

void QObject_dumpObjectInfo(void* object) {
    static_cast<QObjectBind*>(object)->dumpObjectInfo();
}

// void dumpObjectTree() const

void QObject_dumpObjectTree(void* object) {
    static_cast<QObjectBind*>(object)->dumpObjectTree();
}

// QList<QByteArray> dynamicPropertyNames() const

char** QObject_dynamicPropertyNames(void* object, int* count) {
    QList<QByteArray> names = static_cast<QObjectBind*>(object)->dynamicPropertyNames();
    *count = names.size();
    char** result = new char*[names.size()];
    for (int i = 0; i < names.size(); i++) {
        result[i] = qstrdup(names[i].constData());
    }
    return result;
}

// virtual bool event(QEvent *e)
// Note: event() is protected in QObject, so we can't call it directly from C API
// Instead, use the event callback mechanism

bool QObject_event(void* object, void* event) {
    // Forward the event to QObject's default implementation
    return QObject::staticMetaObject.cast(static_cast<QObjectBind*>(object))->QObject::event(static_cast<QEvent*>(event));
}

// virtual bool eventFilter(QObject *watched, QEvent *event)

bool QObject_eventFilter(void* object, void* watched, void* event) {
    return static_cast<QObjectBind*>(object)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

// T findChild(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const

void * QObject_findChild(void* object, const char* name) {
    return static_cast<QObjectBind*>(object)->findChild<QObject*>(name);
}

// (since 6.7) T findChild(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const

void * QObject_findChildWithOptions(void* object, int options) {
    return static_cast<QObjectBind*>(object)->findChild<QObject*>(static_cast<Qt::FindChildOptions>(options));
}

// QList<T>	findChildren(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const

void** QObject_findChildren(void* object, const char* name, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->findChildren<QObject*>(name);
    *count = children.size();
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    return result;
}

// (since 6.3) QList<T>	findChildren(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const

void** QObject_findChildrenWithOptions(void* object, int options, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->findChildren<QObject*>(static_cast<Qt::FindChildOptions>(options));
    *count = children.size();
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    return result;
}

// QList<T>	findChildren(const QRegularExpression &re, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const

void** QObject_findChildrenWithRegex(void* object, const char* re, int options, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->findChildren<QObject*>(QRegularExpression(re), static_cast<Qt::FindChildOptions>(options));
    *count = children.size();
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    return result;
}

// bool inherits(const char *className) const

bool QObject_inherits(void* object, const char* className) {
    return static_cast<QObjectBind*>(object)->inherits(className);
}

// void installEventFilter(QObject *filterObj)

void QObject_installEventFilter(void* object, void* filterObj) {
    static_cast<QObjectBind*>(object)->installEventFilter(static_cast<QObject*>(filterObj));
}

// (since 6.4) bool isQuickItemType() const

bool QObject_isQuickItemType(void* object) {
    return static_cast<QObjectBind*>(object)->isQuickItemType();
}

// bool isWidgetType() const

bool QObject_isWidgetType(void* object) {
    return static_cast<QObjectBind*>(object)->isWidgetType();
}

// bool isWindowType() const

bool QObject_isWindowType(void* object) {
    return static_cast<QObjectBind*>(object)->isWindowType();
}

// void killTimer(int id)

void QObject_killTimer(void* object, int id) {
    static_cast<QObjectBind*>(object)->killTimer(id);
}

// (since 6.8) void killTimer(Qt::TimerId id)

void QObject_killTimer_2(void* object, int id) {
    static_cast<QObjectBind*>(object)->killTimer(static_cast<Qt::TimerId>(id));
}

// virtual const QMetaObject * metaObject() const

void* QObject_metaObject(void* object) {
    const QMetaObject* metaObject = static_cast<QObjectBind*>(object)->metaObject();
    return const_cast<void*>(static_cast<const void*>(metaObject));
}

// bool moveToThread(QThread *targetThread)

bool QObject_moveToThread(void* object, void* thread) {
    return static_cast<QObjectBind*>(object)->moveToThread(static_cast<QThread*>(thread));
}

// QString objectName() const

const char* QObject_objectName(void* object) {
    const QString qstr = static_cast<QObjectBind*>(object)->objectName();
    return qstr.toUtf8().constData();
}

// QObject * parent() const

void* QObject_parent(void* object) {
    return static_cast<QObjectBind*>(object)->parent();
}

// QVariant property(const char *name) const

void* QObject_property(void* object, const char* name) {
    auto* variant = new QVariant(static_cast<QObjectBind*>(object)->property(name));
    return variant;
}

// void removeEventFilter(QObject *obj)

void QObject_removeEventFilter(void* object, void* obj) {
    static_cast<QObjectBind*>(object)->removeEventFilter(static_cast<QObject*>(obj));
}

// void setObjectName(const QString &name)
// (since 6.4) void setObjectName(QAnyStringView name)

void QObject_setObjectName(void* object, const char* name) {
    const QString qstr = QString::fromUtf8(name);
    static_cast<QObjectBind*>(object)->setObjectName(qstr);
}

// void setParent(QObject *parent)

void QObject_setParent(void* object, void* parent) {
    static_cast<QObjectBind*>(object)->setParent(static_cast<QObject*>(parent));
}

// bool setProperty(const char *name, const QVariant &value)
// (since 6.6) bool setProperty(const char *name, QVariant &&value)

bool QObject_setProperty(void* object, const char* name, void* value) {
    return static_cast<QObjectBind*>(object)->setProperty(name, *static_cast<QVariant*>(value));
}


// bool signalsBlocked() const

bool QObject_signalsBlocked(void* object) {
    return static_cast<QObjectBind*>(object)->signalsBlocked();
}

// int startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
// int startTimer(std::chrono::nanoseconds interval, Qt::TimerType timerType = Qt::CoarseTimer)

int QObject_startTimer(void* object, int interval, int timerType) {
    return static_cast<QObjectBind*>(object)->startTimer(interval, static_cast<Qt::TimerType>(timerType));
}

// QThread * thread() const

void* QObject_thread(void* object) {
    return static_cast<QObjectBind*>(object)->thread();
}

//-- Protected Functions made public

bool QObject_isSignalConnected(void* object, void* signal) {
    return static_cast<QObjectBind*>(object)->isSignalConnected(*static_cast<QMetaMethod*>(signal));
}

int QObject_receivers(void* object, const char* signal) {
    return static_cast<QObjectBind*>(object)->receivers(signal);
}

void* QObject_sender(void* object) {
    return static_cast<QObjectBind*>(object)->sender();
}

int QObject_senderSignalIndex(void* object) {
    return static_cast<QObjectBind*>(object)->senderSignalIndex();
}

//-- Static Public Members

// QMetaObject::Connection connect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method, Qt::ConnectionType type = Qt::AutoConnection)

void* QObject_connect_2(void* sender, void* signal, void* receiver, void* method, int type) {
    return new QMetaObject::Connection(QObject::connect(static_cast<QObject*>(sender), *static_cast<QMetaMethod*>(signal), static_cast<QObject*>(receiver), *static_cast<QMetaMethod*>(method), static_cast<Qt::ConnectionType>(type)));
}

// QMetaObject::Connection connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)

void* QObject_connect_3(void* sender, const char* signal, void* receiver, const char* method, int type) {
    return new QMetaObject::Connection(QObject::connect(static_cast<QObject*>(sender), signal, static_cast<QObject*>(receiver), method, static_cast<Qt::ConnectionType>(type)));
}

// QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
// QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *context, Functor functor, Qt::ConnectionType type = Qt::AutoConnection)
// QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method, Qt::ConnectionType type = Qt::AutoConnection)

void* QObject_connect_6(void* sender, void* signal, void* receiver, void* method, int type) {
    return new QMetaObject::Connection(QObject::connect(static_cast<QObject*>(sender), *static_cast<QMetaMethod*>(signal), static_cast<QObject*>(receiver), *static_cast<QMetaMethod*>(method), static_cast<Qt::ConnectionType>(type)));
}

// bool disconnect(const QMetaObject::Connection &connection)

bool QObject_disconnect_3(void* connection) {
    return QObject::disconnect(*static_cast<QMetaObject::Connection*>(connection));
}

// bool disconnect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method)

bool QObject_disconnect_4(void* sender, void* signal, void* receiver, void* method) {
    return QObject::disconnect(static_cast<QObject*>(sender), *static_cast<QMetaMethod*>(signal), static_cast<QObject*>(receiver), *static_cast<QMetaMethod*>(method));
}

// bool disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *method)

bool disconnect_5(void* sender, const char* signal, void* receiver, const char* method) {
    return QObject::disconnect(static_cast<QObject*>(sender), signal, static_cast<QObject*>(receiver), method);
}

// bool disconnect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method)

bool disconnect_6(void* sender, void* signal, void* receiver, void* method) {
    return QObject::disconnect(static_cast<QObject*>(sender), *static_cast<QMetaMethod*>(signal), static_cast<QObject*>(receiver), *static_cast<QMetaMethod*>(method));
}

// const QMetaObject staticMetaObject

void * QObject_staticMetaObject() {
    return const_cast<void*>(static_cast<const void*>(&QObject::staticMetaObject));
}

// QString tr(const char *sourceText, const char *disambiguation = nullptr, int n = -1)

const char * QObject_tr(const char * sourceText, const char * disambiguation, int n) {
    return QObject::tr(sourceText, disambiguation, n).toUtf8().constData();
}

//-- Callback

typedef void (*QObject_DestroyedCallback)(void*);
typedef void (*QObject_ObjectNameChangedCallback)(void*, const char *);
typedef void (*QObject_EventCallback)(void*, void*);

void QObject_setDestroyedCallback(void* object, QObject_DestroyedCallback callback) {
    static_cast<QObjectBind*>(object)->setDestroyedCallback(callback);
}

void QObject_setObjectNameChangedCallback(void* object, QObject_ObjectNameChangedCallback callback) {
    typedef void (*QObject_ObjectNameChangedCallback_Cast)(void*, const QString*);
    static_cast<QObjectBind*>(object)->setObjectNameChangedCallback(reinterpret_cast<QObject_ObjectNameChangedCallback_Cast>(callback));
}

void QObject_setEventCallback(void* object, QObject_EventCallback callback) {
    typedef void (*QObject_EventCallback_Cast)(void*, QEvent*);
    static_cast<QObjectBind*>(object)->setEventCallback(reinterpret_cast<QObject_EventCallback_Cast>(callback));
}

//-- Protected Callback

typedef void (*QObject_ChildEventCallback)(void*, void*);
typedef void (*QObject_ConnectNotifyCallback)(void*, const void*);
typedef void (*QObject_CustomEventCallback)(void*, void*);
typedef void (*QObject_DisconnectNotifyCallback)(void*, const void*);
typedef void (*QObject_TimerEventCallback)(void*, void*);

// virtual void childEvent(QChildEvent *event)

void QObject_setChildEventCallback(void* object, QObject_ChildEventCallback callback) {
    typedef void (*QObject_ChildEventCallback_Cast)(void*, QChildEvent*);
    static_cast<QObjectBind*>(object)->setChildEventCallback(reinterpret_cast<QObject_ChildEventCallback_Cast>(callback));
}

// virtual void connectNotify(const QMetaMethod &signal)

void QObject_setConnectNotifyCallback(void* object, QObject_ConnectNotifyCallback callback) {
    typedef void (*QObject_ConnectNotifyCallback_Cast)(void*, const QMetaMethod*);
    static_cast<QObjectBind*>(object)->setConnectNotifyCallback(reinterpret_cast<QObject_ConnectNotifyCallback_Cast>(callback));
}

// virtual void customEvent(QEvent *event)

void QObject_setCustomEventCallback(void* object, QObject_CustomEventCallback callback) {
    typedef void (*QObject_CustomEventCallback_Cast)(void*, QEvent*);
    static_cast<QObjectBind*>(object)->setCustomEventCallback(reinterpret_cast<QObject_CustomEventCallback_Cast>(callback));
}

// virtual void disconnectNotify(const QMetaMethod &signal)

void QObject_setDisconnectNotifyCallback(void* object, QObject_DisconnectNotifyCallback callback) {
    typedef void (*QObject_DisconnectNotifyCallback_Cast)(void*, const QMetaMethod*);
    static_cast<QObjectBind*>(object)->setDisconnectNotifyCallback(reinterpret_cast<QObject_DisconnectNotifyCallback_Cast>(callback));
}

// virtual void timerEvent(QTimerEvent *event)

void QObject_setTimerEventCallback(void* object, QObject_TimerEventCallback callback) {
    typedef void (*QObject_TimerEventCallback_Cast)(void*, QTimerEvent*);
    static_cast<QObjectBind*>(object)->setTimerEventCallback(reinterpret_cast<QObject_TimerEventCallback_Cast>(callback));
}

}
