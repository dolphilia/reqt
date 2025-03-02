#include "QSplitterBind.h"
#include <QList>

extern "C" {

void* QSplitter_create(void* parent) {
    return new QSplitterBind(static_cast<QWidget*>(parent));
}

void* QSplitter_createWithOrientation(int orientation, void* parent) {
    return new QSplitterBind(static_cast<Qt::Orientation>(orientation), static_cast<QWidget*>(parent));
}

void QSplitter_delete(void* splitter) {
    delete static_cast<QSplitterBind*>(splitter);
}

void QSplitter_addWidget(void* splitter, void* widget) {
    static_cast<QSplitterBind*>(splitter)->addWidget(static_cast<QWidget*>(widget));
}

void QSplitter_insertWidget(void* splitter, int index, void* widget) {
    static_cast<QSplitterBind*>(splitter)->insertWidget(index, static_cast<QWidget*>(widget));
}

int QSplitter_count(void* splitter) {
    return static_cast<QSplitterBind*>(splitter)->count();
}

void* QSplitter_widget(void* splitter, int index) {
    return static_cast<QSplitterBind*>(splitter)->widget(index);
}

void QSplitter_setOrientation(void* splitter, int orientation) {
    static_cast<QSplitterBind*>(splitter)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QSplitter_orientation(void* splitter) {
    return static_cast<int>(static_cast<QSplitterBind*>(splitter)->orientation());
}

void QSplitter_setSizes(void* splitter, const int* sizes, int count) {
    QList<int> sizeList;
    for (int i = 0; i < count; ++i) {
        sizeList.append(sizes[i]);
    }
    static_cast<QSplitterBind*>(splitter)->setSizes(sizeList);
}

void QSplitter_getSizes(void* splitter, int* sizes, int* count) {
    QList<int> sizeList = static_cast<QSplitterBind*>(splitter)->sizes();
    *count = sizeList.size();
    for (int i = 0; i < *count; ++i) {
        sizes[i] = sizeList[i];
    }
}

void QSplitter_setHandleWidth(void* splitter, int width) {
    static_cast<QSplitterBind*>(splitter)->setHandleWidth(width);
}

int QSplitter_handleWidth(void* splitter) {
    return static_cast<QSplitterBind*>(splitter)->handleWidth();
}

void QSplitter_setCollapsible(void* splitter, int index, bool collapse) {
    static_cast<QSplitterBind*>(splitter)->setCollapsible(index, collapse);
}

bool QSplitter_isCollapsible(void* splitter, int index) {
    return static_cast<QSplitterBind*>(splitter)->isCollapsible(index);
}

void QSplitter_setSplitterMovedCallback(void* splitter, void (*callback)(void*, int, int)) {
    static_cast<QSplitterBind*>(splitter)->setSplitterMovedCallback(callback);
}

}
