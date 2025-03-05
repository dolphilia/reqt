#ifndef QT_QOBJECT_H
#define QT_QOBJECT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Properties
//-- Public Functions
void* QObject_create(void* parent); // QObject(QObject *parent = nullptr)
void QObject_delete(void* object); // virtual ~QObject()
void * QObject_bindableObjectName(void* object); // QBindable<QString> bindableObjectName()
bool QObject_blockSignals(void* object, bool block); // bool blockSignals(bool block)
void** QObject_children(void* object, int* count); // const QObjectList & children() const
void* QObject_connect(void* object, void* sender, const char* signal, const char* method, int type); // QMetaObject::Connection connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const
bool QObject_disconnect(void* object, void* receiver, const char* method); // bool disconnect(const QObject *receiver, const char *method = nullptr) const
bool QObject_disconnect_2(void* object, const char* signal, void* receiver, const char* method); // bool disconnect(const char *signal = nullptr, const QObject *receiver = nullptr, const char *method = nullptr) const
void QObject_dumpObjectInfo(void* object); // void dumpObjectInfo() const
void QObject_dumpObjectTree(void* object); // void dumpObjectTree() const
char** QObject_dynamicPropertyNames(void* object, int* count); // QList<QByteArray> dynamicPropertyNames() const
bool QObject_event(void* object, void* event); // virtual bool event(QEvent *e)
bool QObject_eventFilter(void* object, void* watched, void* event); // virtual bool eventFilter(QObject *watched, QEvent *event)
void * QObject_findChild(void* object, const char* name); // T findChild(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
void * QObject_findChildWithOptions(void* object, int options); // (since 6.7) T findChild(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
void** QObject_findChildren(void* object, const char* name, int* count); // QList<T>	findChildren(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
void** QObject_findChildrenWithOptions(void* object, int options, int* count); // (since 6.3) QList<T>	findChildren(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
void** QObject_findChildrenWithRegex(void* object, const char* re, int options, int* count); // QList<T>	findChildren(const QRegularExpression &re, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
bool QObject_inherits(void* object, const char* className); // bool inherits(const char *className) const
void QObject_installEventFilter(void* object, void* filterObj); // void installEventFilter(QObject *filterObj)
bool QObject_isQuickItemType(void* object); // (since 6.4) bool isQuickItemType() const
bool QObject_isWidgetType(void* object); // bool isWidgetType() const
bool QObject_isWindowType(void* object); // bool isWindowType() const
void QObject_killTimer(void* object, int id); // void killTimer(int id)
void QObject_killTimer_2(void* object, int id); // (since 6.8) void killTimer(Qt::TimerId id)
void* QObject_metaObject(void* object); // virtual const QMetaObject * metaObject() const
bool QObject_moveToThread(void* object, void* thread); // bool moveToThread(QThread *targetThread)
const char* QObject_objectName(void* object); // QString objectName() const
void* QObject_parent(void* object); // QObject * parent() const
void* QObject_property(void* object, const char* name); // QVariant property(const char *name) const
void QObject_removeEventFilter(void* object, void* obj); // void removeEventFilter(QObject *obj)
void QObject_setObjectName(void* object, const char* name); // void setObjectName(const QString &name)
// (since 6.4) void setObjectName(QAnyStringView name)
void QObject_setParent(void* object, void* parent); // void setParent(QObject *parent)
bool QObject_setProperty(void* object, const char* name, void* value); // bool setProperty(const char *name, const QVariant &value)
// (since 6.6) bool setProperty(const char *name, QVariant &&value)
bool QObject_signalsBlocked(void* object); // bool signalsBlocked() const
int QObject_startTimer(void* object, int interval, int timerType); // int startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
// int startTimer(std::chrono::nanoseconds interval, Qt::TimerType timerType = Qt::CoarseTimer)
void* QObject_thread(void* object); // QThread * thread() const
//-- Protected Functions
bool QObject_isSignalConnected(void* object, void* signal); // bool isSignalConnected(const QMetaMethod &signal) const
int QObject_receivers(void* object, const char* signal); // int receivers(const char *signal) const
void* QObject_sender(void* object); // QObject * sender() const
int QObject_senderSignalIndex(void* object); // int senderSignalIndex() const
//-- Static Public Members
void* QObject_connect_2(void* sender, void* signal, void* receiver, void* method, int type); // QMetaObject::Connection connect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method, Qt::ConnectionType type = Qt::AutoConnection)
void* QObject_connect_3(void* sender, const char* signal, void* receiver, const char* method, int type); // QMetaObject::Connection connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
// QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
// QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *context, Functor functor, Qt::ConnectionType type = Qt::AutoConnection)
void* QObject_connect_6(void* sender, void* signal, void* receiver, void* method, int type); // QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method, Qt::ConnectionType type = Qt::AutoConnection)
bool QObject_disconnect_3(void* connection); // bool disconnect(const QMetaObject::Connection &connection)
bool QObject_disconnect_4(void* sender, void* signal, void* receiver, void* method); // bool disconnect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method)
bool disconnect_5(void* sender, const char* signal, void* receiver, const char* method); // bool disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *method)
bool disconnect_6(void* sender, void* signal, void* receiver, void* method); // bool disconnect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method)
void * QObject_staticMetaObject(); // const QMetaObject staticMetaObject
const char * QObject_tr(const char * sourceText, const char * disambiguation, int n); // QString tr(const char *sourceText, const char *disambiguation = nullptr, int n = -1)
//-- Public Callback
typedef void (*QObject_DestroyedCallback)(void*);
typedef void (*QObject_ObjectNameChangedCallback)(void*, const char*);
typedef void (*QObject_EventCallback)(void*, void*);
void QObject_setDestroyedCallback(void* object, QObject_DestroyedCallback callback);
void QObject_setObjectNameChangedCallback(void* object, QObject_ObjectNameChangedCallback callback);
void QObject_setEventCallback(void* object, QObject_EventCallback callback);
//-- Protected Callback
typedef void (*QObject_ChildEventCallback)(void*, void*);
typedef void (*QObject_ConnectNotifyCallback)(void*, const void*);
typedef void (*QObject_CustomEventCallback)(void*, void*);
typedef void (*QObject_DisconnectNotifyCallback)(void*, const void*);
typedef void (*QObject_TimerEventCallback)(void*, void*);
void QObject_setChildEventCallback(void* object, QObject_ChildEventCallback callback); // virtual void childEvent(QChildEvent *event)
void QObject_setConnectNotifyCallback(void* object, QObject_ConnectNotifyCallback callback); // virtual void connectNotify(const QMetaMethod &signal)
void QObject_setCustomEventCallback(void* object, QObject_CustomEventCallback callback); // virtual void customEvent(QEvent *event)
void QObject_setDisconnectNotifyCallback(void* object, QObject_DisconnectNotifyCallback callback); // virtual void disconnectNotify(const QMetaMethod &signal)
void QObject_setTimerEventCallback(void* object, QObject_TimerEventCallback callback); // virtual void timerEvent(QTimerEvent *event)

#ifdef __cplusplus
}
#endif

#endif // QT_QOBJECT_H
