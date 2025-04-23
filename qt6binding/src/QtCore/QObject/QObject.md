# QObject Class

## Public Functions

- QObject(QObject *parent = nullptr)
- virtual ~QObject()
- QBindable<QString> bindableObjectName()
- bool blockSignals(bool block)
- const QObjectList & children() const
- QMetaObject::Connection connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const
- bool disconnect(const QObject *receiver, const char *method = nullptr) const
- bool disconnect(const char *signal = nullptr, const QObject *receiver = nullptr, const char *method = nullptr) const
- void dumpObjectInfo() const
- void dumpObjectTree() const
- QList<QByteArray> dynamicPropertyNames() const
- virtual bool event(QEvent *e)
- virtual bool eventFilter(QObject *watched, QEvent *event)
- T findChild(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
- (since 6.7) T findChild(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
- QList<T> findChildren(QAnyStringView name, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
- (since 6.3) QList<T> findChildren(Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
- QList<T> findChildren(const QRegularExpression &re, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
- bool inherits(const char *className) const
- void installEventFilter(QObject *filterObj)
- (since 6.4) bool isQuickItemType() const
- bool isWidgetType() const
- bool isWindowType() const
- void killTimer(int id)
- (since 6.8) void killTimer(Qt::TimerId id)
- virtual const QMetaObject * metaObject() const
- bool moveToThread(QThread *targetThread)
- QString objectName() const
- QObject * parent() const
- QVariant property(const char *name) const
- void removeEventFilter(QObject *obj)
- void setObjectName(const QString &name)
- (since 6.4) void setObjectName(QAnyStringView name)
- void setParent(QObject *parent)
- bool setProperty(const char *name, const QVariant &value)
- (since 6.6) bool setProperty(const char *name, QVariant &&value)
- bool signalsBlocked() const
- int startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
- int startTimer(std::chrono::nanoseconds interval, Qt::TimerType timerType = Qt::CoarseTimer)
- QThread * thread() const

## Public Slots

- void deleteLater()

## Signals

- void destroyed(QObject *obj = nullptr)
- void objectNameChanged(const QString &objectName)

## Static Public Members

- QMetaObject::Connection connect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method, Qt::ConnectionType type = Qt::AutoConnection)
- QMetaObject::Connection connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
- QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
- QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *context, Functor functor, Qt::ConnectionType type = Qt::AutoConnection)
- QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method, Qt::ConnectionType type = Qt::AutoConnection)
- bool disconnect(const QMetaObject::Connection &connection)
- bool disconnect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method)
- bool disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *method)
- bool disconnect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method)
- const QMetaObject staticMetaObject
- QString tr(const char *sourceText, const char *disambiguation = nullptr, int n = -1)

## Protected Functions

- virtual void childEvent(QChildEvent *event)
- virtual void connectNotify(const QMetaMethod &signal)
- virtual void customEvent(QEvent *event)
- virtual void disconnectNotify(const QMetaMethod &signal)
- bool isSignalConnected(const QMetaMethod &signal) const
- int receivers(const char *signal) const
- QObject * sender() const
- int senderSignalIndex() const
- virtual void timerEvent(QTimerEvent *event)

## Related Non-Members

- QObjectList
- (since 6.8) enum class TimerId { Invalid }
- T qobject_cast(QObject *object)
- T qobject_cast(const QObject *object)

## Macros

- (since 6.7) QT_NO_CONTEXTLESS_CONNECT
- QT_NO_NARROWING_CONVERSIONS_IN_CONNECT
- Q_CLASSINFO(Name, Value)
- Q_EMIT
- Q_ENUM(...)
- Q_ENUM_NS(...)
- Q_FLAG(...)
- Q_FLAG_NS(...)
- Q_GADGET
- (since 6.3) Q_GADGET_EXPORT(EXPORT_MACRO)
- Q_INTERFACES(...)
- Q_INVOKABLE
- (since 6.0) Q_MOC_INCLUDE
- Q_NAMESPACE
- Q_NAMESPACE_EXPORT(EXPORT_MACRO)
- Q_OBJECT
- Q_PROPERTY(...)
- Q_REVISION
- Q_SET_OBJECT_NAME(Object)
- Q_SIGNAL
- Q_SIGNALS
- Q_SLOT
- Q_SLOTS
