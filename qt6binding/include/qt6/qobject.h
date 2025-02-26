#ifndef QT_QOBJECT_H
#define QT_QOBJECT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// オブジェクト作成・削除
void *QObject_create(void *parent);
void QObject_delete(void *object);

// オブジェクト名
void QObject_setObjectName(void *object, const char *name);
char *QObject_objectName(void *object);

// 親オブジェクト
void *QObject_parent(void *object);
void QObject_setParent(void *object, void *parent);

// プロパティ
bool QObject_setProperty(void *object, const char *name, void *value);
void *QObject_property(void *object, const char *name);
char **QObject_dynamicPropertyNames(void *object, int *count);

// オブジェクト管理
void QObject_deleteLater(void *object);
bool QObject_blockSignals(void *object, bool block);
bool QObject_signalsBlocked(void *object);

// オブジェクト情報
char *QObject_className(void *object);
bool QObject_inherits(void *object, const char *className);
void QObject_dumpObjectInfo(void *object);
void QObject_dumpObjectTree(void *object);

// 子オブジェクト
void **QObject_children(void *object, int *count);

// イベント処理
bool QObject_event(void *object, void *event);
bool QObject_eventFilter(void *object, void *watched, void *event);
void QObject_installEventFilter(void *object, void *filterObj);
void QObject_removeEventFilter(void *object, void *obj);

// タイプチェック
bool QObject_isWidgetType(void *object);
bool QObject_isWindowType(void *object);

// タイマー
int QObject_startTimer(void *object, int interval, int timerType);
void QObject_killTimer(void *object, int id);

// スレッド
void *QObject_thread(void *object);
bool QObject_moveToThread(void *object, void *thread);

// シグナルコールバック
void QObject_setDestroyedCallback(void *object, void (*callback)(void*));
void QObject_setObjectNameChangedCallback(void *object, void (*callback)(void*, const char*));
void QObject_setEventCallback(void *object, void (*callback)(void*, void*));

#ifdef __cplusplus
}
#endif

#endif // QT_QOBJECT_H
