#include "QSplitterHandleBind.h"
#include <QSplitter>

extern "C" {

void* QSplitterHandle_create(int orientation, void* parent) {
    return new QSplitterHandleBind(static_cast<Qt::Orientation>(orientation), static_cast<QSplitter*>(parent));
}

void QSplitterHandle_delete(void* handle) {
    delete static_cast<QSplitterHandleBind*>(handle);
}

int QSplitterHandle_orientation(void* handle) {
    return static_cast<int>(static_cast<QSplitterHandleBind*>(handle)->orientation());
}

void* QSplitterHandle_splitter(void* handle) {
    return static_cast<QSplitterHandleBind*>(handle)->splitter();
}

void QSplitterHandle_setDoubleClickedCallback(void* handle, void (*callback)(void*)) {
    static_cast<QSplitterHandleBind*>(handle)->setDoubleClickedCallback(callback);
}

void QSplitterHandle_setMovedCallback(void* handle, void (*callback)(void*, int)) {
    static_cast<QSplitterHandleBind*>(handle)->setMovedCallback(callback);
}

int QSplitterHandle_opaqueResize(void* handle) {
    return static_cast<QSplitterHandleBind*>(handle)->opaqueResize();
}

void QSplitterHandle_setOpaqueResize(void* handle, bool opaque) {
    static_cast<QSplitterHandleBind*>(handle)->setOpaqueResize(opaque);
}

void QSplitterHandle_moveSplitter(void* handle, int pos) {
    static_cast<QSplitterHandleBind*>(handle)->moveSplitter(pos);
}

int QSplitterHandle_closestLegalPosition(void* handle, int pos) {
    return static_cast<QSplitterHandleBind*>(handle)->closestLegalPosition(pos);
}

}
