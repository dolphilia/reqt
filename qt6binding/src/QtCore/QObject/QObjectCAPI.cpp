#include "QObjectBind.h"
#include "QVariant/QVariantBind.h"

extern "C" {

void* QObject_create(void* parent) {
    return new QObjectBind(static_cast<QObject*>(parent));
}

void QObject_delete(void* object) {
    delete static_cast<QObjectBind*>(object);
}

// Public Functions

void QObject_setObjectName(void* object, const char* name) {
    const QString qstr = QString::fromUtf8(name);
    static_cast<QObjectBind*>(object)->setObjectName(qstr);
}

const char* QObject_objectName(void* object) {
    const QString qstr = static_cast<QObjectBind*>(object)->objectName();
    return qstr.toUtf8().constData();
}

void* QObject_parent(void* object) {
    return static_cast<QObjectBind*>(object)->parent();
}

void QObject_setParent(void* object, void* parent) {
    static_cast<QObjectBind*>(object)->setParent(static_cast<QObject*>(parent));
}

bool QObject_setProperty(void* object, const char* name, void* value) {
    return static_cast<QObjectBind*>(object)->setProperty(name, *static_cast<QVariant*>(value));
}

void* QObject_property(void* object, const char* name) {
    auto* variant = new QVariant(static_cast<QObjectBind*>(object)->property(name));
    return variant;
}

char** QObject_dynamicPropertyNames(void* object, int* count) {
    QList<QByteArray> names = static_cast<QObjectBind*>(object)->dynamicPropertyNames();
    *count = names.size();
    
    char** result = new char*[names.size()];
    for (int i = 0; i < names.size(); i++) {
        result[i] = qstrdup(names[i].constData());
    }
    
    return result;
}

void QObject_deleteLater(void* object) {
    static_cast<QObjectBind*>(object)->deleteLater();
}

bool QObject_blockSignals(void* object, bool block) {
    return static_cast<QObjectBind*>(object)->blockSignals(block);
}

bool QObject_signalsBlocked(void* object) {
    return static_cast<QObjectBind*>(object)->signalsBlocked();
}

char* QObject_className(void* object) {
    return qstrdup(static_cast<QObjectBind*>(object)->metaObject()->className());
}

bool QObject_inherits(void* object, const char* className) {
    return static_cast<QObjectBind*>(object)->inherits(className);
}

void QObject_dumpObjectInfo(void* object) {
    static_cast<QObjectBind*>(object)->dumpObjectInfo();
}

void QObject_dumpObjectTree(void* object) {
    static_cast<QObjectBind*>(object)->dumpObjectTree();
}

void** QObject_children(void* object, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->children();
    *count = children.size();
    
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    
    return result;
}

bool QObject_event(void* object, void* event) {
    return static_cast<QObjectBind*>(object)->event(static_cast<QEvent*>(event));
}

bool QObject_eventFilter(void* object, void* watched, void* event) {
    return static_cast<QObjectBind*>(object)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void QObject_installEventFilter(void* object, void* filterObj) {
    static_cast<QObjectBind*>(object)->installEventFilter(static_cast<QObject*>(filterObj));
}

void QObject_removeEventFilter(void* object, void* obj) {
    static_cast<QObjectBind*>(object)->removeEventFilter(static_cast<QObject*>(obj));
}

bool QObject_isWidgetType(void* object) {
    return static_cast<QObjectBind*>(object)->isWidgetType();
}

bool QObject_isWindowType(void* object) {
    return static_cast<QObjectBind*>(object)->isWindowType();
}

int QObject_startTimer(void* object, int interval, int timerType) {
    return static_cast<QObjectBind*>(object)->startTimer(interval, static_cast<Qt::TimerType>(timerType));
}

void QObject_killTimer(void* object, int id) {
    static_cast<QObjectBind*>(object)->killTimer(id);
}

void* QObject_thread(void* object) {
    return static_cast<QObjectBind*>(object)->thread();
}

bool QObject_moveToThread(void* object, void* thread) {
    return static_cast<QObjectBind*>(object)->moveToThread(static_cast<QThread*>(thread));
}

typedef void (*QObject_DestroyedCallback)(void*);
typedef void (*QObject_ObjectNameChangedCallback)(void*, const QString*);
typedef void (*QObject_EventCallback)(void*, QEvent*);

void QObject_setDestroyedCallback(void* object, QObject_DestroyedCallback callback) {
    static_cast<QObjectBind*>(object)->setDestroyedCallback(callback);
}

void QObject_setObjectNameChangedCallback(void* object, QObject_ObjectNameChangedCallback callback) {
    static_cast<QObjectBind*>(object)->setObjectNameChangedCallback(callback);
}

void QObject_setEventCallback(void* object, QObject_EventCallback callback) {
    static_cast<QObjectBind*>(object)->setEventCallback(callback);
}

}
