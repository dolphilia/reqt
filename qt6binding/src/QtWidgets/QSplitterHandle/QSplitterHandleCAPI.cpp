#include "QSplitterHandleBind.h"

extern "C" {

// Public Functions

void* QSplitterHandle_create(int orientation, void* parent) {
    return new QSplitterHandleBind(static_cast<Qt::Orientation>(orientation), static_cast<QSplitter*>(parent));
}

void QSplitterHandle_delete(void* splitterHandle) {
    delete static_cast<QSplitterHandleBind*>(splitterHandle);
}

int QSplitterHandle_opaqueResize(void* splitterHandle) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->opaqueResize();
}

int QSplitterHandle_orientation(void* splitterHandle) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->orientation();
}

void QSplitterHandle_setOrientation(void* splitterHandle, int orientation) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

void* QSplitterHandle_splitter(void* splitterHandle) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->splitter();
}

// Reimplemented Public Functions

void QSplitterHandle_sizeHint(void* splitterHandle, int* width, int* height) {
    const QSize size = static_cast<QSplitterHandleBind*>(splitterHandle)->sizeHint();
    if (width) *width = size.width();
    if (height) *height = size.height();
}

// Protected Functions

int QSplitterHandle_closestLegalPosition(void* splitterHandle, int pos) {
    return static_cast<QSplitterHandleBind*>(splitterHandle)->closestLegalPosition(pos);
}

void QSplitterHandle_moveSplitter(void* splitterHandle, int pos) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->moveSplitter(pos);
}

// Reimplemented Protected Functions

typedef void (*QSplitterHandle_MovedCallback)(void*);
typedef void (*QSplitterHandle_PressedCallback)(void*);
typedef void (*QSplitterHandle_ReleasedCallback)(void*);
typedef bool (*QSplitterHandle_EventCallback)(void*, void*);
typedef void (*QSplitterHandle_PaintCallback)(void*);
typedef void (*QSplitterHandle_ResizeCallback)(void*, void*);

void QSplitterHandle_setMovedCallback(void* splitterHandle, QSplitterHandle_MovedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setMovedCallback(callback);
}

void QSplitterHandle_setPressedCallback(void* splitterHandle, QSplitterHandle_PressedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setPressedCallback(callback);
}

void QSplitterHandle_setReleasedCallback(void* splitterHandle, QSplitterHandle_ReleasedCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setReleasedCallback(callback);
}

void QSplitterHandle_setEventCallback(void* splitterHandle, QSplitterHandle_EventCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setEventCallback(callback);
}

void QSplitterHandle_setPaintCallback(void* splitterHandle, QSplitterHandle_PaintCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setPaintCallback(callback);
}

void QSplitterHandle_setResizeCallback(void* splitterHandle, QSplitterHandle_ResizeCallback callback) {
    static_cast<QSplitterHandleBind*>(splitterHandle)->setResizeCallback(callback);
}

}
