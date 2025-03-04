#include "QSplitterHandleBind.h"

extern "C" {

void* QSplitterHandle_create(int orientation, void* parent) {
    return new QSplitterHandleBind(static_cast<Qt::Orientation>(orientation), static_cast<QSplitter*>(parent));
}

void QSplitterHandle_delete(void* splitterHandle) {
    delete static_cast<QSplitterHandleBind*>(splitterHandle);
}

int QSplitterHandle_opaqueResize(void* splitterHandle) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->opaqueResize();
}

void QSplitterHandle_setOpaqueResize(void* splitterHandle, bool opaque) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setOpaqueResize(opaque);
}

int QSplitterHandle_orientation(void* splitterHandle) {
    return static_cast<int>(static_cast<QSplitterHandleBind*>(splitterHandle)->orientation());
}

void QSplitterHandle_setOrientation(void* splitterHandle, int orientation) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

void* QSplitterHandle_splitter(void* splitterHandle) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->splitter();
}

typedef void (*QSplitterHandle_MovedCallback)(void*);
typedef void (*QSplitterHandle_PressedCallback)(void*);
typedef void (*QSplitterHandle_ReleasedCallback)(void*);

void QSplitterHandle_setMovedCallback(void* splitterHandle, QSplitterHandle_MovedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setMovedCallback(callback);
}

void QSplitterHandle_setPressedCallback(void* splitterHandle, QSplitterHandle_PressedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setPressedCallback(callback);
}

void QSplitterHandle_setReleasedCallback(void* splitterHandle, QSplitterHandle_ReleasedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setReleasedCallback(callback);
}

}
