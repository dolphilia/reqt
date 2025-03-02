#include "QObjectBind.h"
#include "qobject.h"
#include <QString>

// オブジェクト作成・削除
void *QObject_create(void *parent)
{
    return new BindQObject(static_cast<QObject*>(parent));
}

void QObject_delete(void *object)
{
    delete static_cast<BindQObject*>(object);
}

// オブジェクト名
void QObject_setObjectName(void *object, const char *name)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->setObjectName(QString::fromUtf8(name));
}

char *QObject_objectName(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return qstrdup(obj->objectName().toUtf8().constData());
}

// 親オブジェクト
void *QObject_parent(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->parent();
}

void QObject_setParent(void *object, void *parent)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->setParent(static_cast<QObject*>(parent));
}

// プロパティ
bool QObject_setProperty(void *object, const char *name, void *value)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->setProperty(name, *static_cast<QVariant*>(value));
}

void *QObject_property(void *object, const char *name)
{
    auto obj = static_cast<BindQObject*>(object);
    auto *variant = new QVariant(obj->property(name));
    return variant;
}

// 動的プロパティの名前リスト
char **QObject_dynamicPropertyNames(void *object, int *count)
{
    auto obj = static_cast<BindQObject*>(object);
    QList<QByteArray> names = obj->dynamicPropertyNames();
    *count = names.size();
    
    char **result = new char*[names.size()];
    for (int i = 0; i < names.size(); i++) {
        result[i] = qstrdup(names[i].constData());
    }
    
    return result;
}

// オブジェクト管理
void QObject_deleteLater(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->deleteLater();
}

bool QObject_blockSignals(void *object, bool block)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->blockSignals(block);
}

bool QObject_signalsBlocked(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->signalsBlocked();
}

// オブジェクト情報
char *QObject_className(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return qstrdup(obj->className().toUtf8().constData());
}

bool QObject_inherits(void *object, const char *className)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->inherits(className);
}

// オブジェクト情報表示
void QObject_dumpObjectInfo(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->dumpObjectInfo();
}

void QObject_dumpObjectTree(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->dumpObjectTree();
}

// 子オブジェクト
void **QObject_children(void *object, int *count)
{
    auto obj = static_cast<BindQObject*>(object);
    QList<QObject*> children = obj->children();
    *count = children.size();
    
    void **result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    
    return result;
}

// イベント処理
bool QObject_event(void *object, void *event)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->event(static_cast<QEvent*>(event));
}

bool QObject_eventFilter(void *object, void *watched, void *event)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void QObject_installEventFilter(void *object, void *filterObj)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->installEventFilter(static_cast<QObject*>(filterObj));
}

void QObject_removeEventFilter(void *object, void *obj)
{
    auto obj_instance = static_cast<BindQObject*>(object);
    obj_instance->removeEventFilter(static_cast<QObject*>(obj));
}

// タイプチェック
bool QObject_isWidgetType(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->isWidgetType();
}

bool QObject_isWindowType(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->isWindowType();
}

// タイマー
int QObject_startTimer(void *object, int interval, int timerType)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->startTimer(interval, static_cast<Qt::TimerType>(timerType));
}

void QObject_killTimer(void *object, int id)
{
    auto obj = static_cast<BindQObject*>(object);
    obj->killTimer(id);
}

// スレッド
void *QObject_thread(void *object)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->thread();
}

bool QObject_moveToThread(void *object, void *thread)
{
    auto obj = static_cast<BindQObject*>(object);
    return obj->moveToThread(static_cast<QThread*>(thread));
}

// シグナルコールバック
void QObject_setDestroyedCallback(void *object, void (*callback)(void*))
{
    auto obj = static_cast<BindQObject*>(object);
    obj->setDestroyedCallback(callback);
}

// CallbackContextクラスの静的メンバ変数の定義
namespace {
    struct CallbackContext {
        static void (*current_callback)(void*, const char*);
        
        static void wrapper(void* obj, const QString* name) {
            if (current_callback) {
                current_callback(obj, name->toUtf8().constData());
            }
        }
    };
    
    // 静的メンバ変数の定義
    void (*CallbackContext::current_callback)(void*, const char*) = nullptr;
    
    // イベントコールバック用
    struct EventCallbackContext {
        static void (*current_callback)(void*, void*);
        
        static void wrapper(void* obj, QEvent* event) {
            if (current_callback) {
                current_callback(obj, event);
            }
        }
    };
    
    // 静的メンバ変数の定義
    void (*EventCallbackContext::current_callback)(void*, void*) = nullptr;
}

void QObject_setObjectNameChangedCallback(void *object, void (*callback)(void*, const char*))
{
    auto obj = static_cast<BindQObject*>(object);
    CallbackContext::current_callback = callback;
    obj->setObjectNameChangedCallback(CallbackContext::wrapper);
}

void QObject_setEventCallback(void *object, void (*callback)(void*, void*))
{
    auto obj = static_cast<BindQObject*>(object);
    EventCallbackContext::current_callback = callback;
    obj->setEventCallback(EventCallbackContext::wrapper);
}
