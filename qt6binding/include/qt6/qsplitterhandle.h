#ifndef QSPLITTERHANDLE_H
#define QSPLITTERHANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

void* QSplitterHandle_create(int orientation, void* parent);
void QSplitterHandle_delete(void* handle);
int QSplitterHandle_orientation(void* handle);
void* QSplitterHandle_splitter(void* handle);
void QSplitterHandle_setDoubleClickedCallback(void* handle, void (*callback)(void*));
void QSplitterHandle_setMovedCallback(void* handle, void (*callback)(void*, int));
int QSplitterHandle_opaqueResize(void* handle);
void QSplitterHandle_setOpaqueResize(void* handle, bool opaque);
void QSplitterHandle_moveSplitter(void* handle, int pos);
int QSplitterHandle_closestLegalPosition(void* handle, int pos);

#ifdef __cplusplus
}
#endif

#endif // QSPLITTERHANDLE_H
