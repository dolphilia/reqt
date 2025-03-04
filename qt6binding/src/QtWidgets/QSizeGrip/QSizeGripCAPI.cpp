#include "QSizeGripBind.h"

extern "C" {

void* QSizeGrip_create(void* parent) {
    return new QSizeGripBind(static_cast<QWidget*>(parent));
}

void QSizeGrip_delete(void* sizeGrip) {
    delete static_cast<QSizeGripBind*>(sizeGrip);
}

void QSizeGrip_setVisible(void* sizeGrip, bool visible) {
    static_cast<QSizeGripBind*>(sizeGrip)->setVisible(visible);
}

bool QSizeGrip_isVisible(void* sizeGrip) {
    return static_cast<QSizeGripBind*>(sizeGrip)->isVisible();
}

void QSizeGrip_setEnabled(void* sizeGrip, bool enabled) {
    static_cast<QSizeGripBind*>(sizeGrip)->setEnabled(enabled);
}

bool QSizeGrip_isEnabled(void* sizeGrip) {
    return static_cast<QSizeGripBind*>(sizeGrip)->isEnabled();
}

// QSizeGripには特定のシグナルがないため、コールバック関数は追加していません
// 必要に応じて、以下のようなコールバック関数を追加できます
/*
typedef void (*QSizeGrip_SomeSignalCallback)(void*, SomeType);

void QSizeGrip_setSomeSignalCallback(void* sizeGrip, QSizeGrip_SomeSignalCallback callback) {
    static_cast<QSizeGripBind*>(sizeGrip)->setSomeSignalCallback(callback);
}
*/

}
