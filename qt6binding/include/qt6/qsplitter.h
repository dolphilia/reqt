#ifndef QSPLITTER_H
#define QSPLITTER_H

#ifdef __cplusplus
extern "C" {
#endif

void* QSplitter_create(void* parent);
void* QSplitter_createWithOrientation(int orientation, void* parent);
void QSplitter_delete(void* splitter);
void QSplitter_addWidget(void* splitter, void* widget);
void QSplitter_insertWidget(void* splitter, int index, void* widget);
int QSplitter_count(void* splitter);
void* QSplitter_widget(void* splitter, int index);
void QSplitter_setOrientation(void* splitter, int orientation);
int QSplitter_orientation(void* splitter);
void QSplitter_setSizes(void* splitter, const int* sizes, int count);
void QSplitter_getSizes(void* splitter, int* sizes, int* count);
void QSplitter_setHandleWidth(void* splitter, int width);
int QSplitter_handleWidth(void* splitter);
void QSplitter_setCollapsible(void* splitter, int index, bool collapse);
bool QSplitter_isCollapsible(void* splitter, int index);
void QSplitter_setSplitterMovedCallback(void* splitter, void (*callback)(void*, int, int));

#ifdef __cplusplus
}
#endif

#endif // QSPLITTER_H
