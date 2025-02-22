#ifndef QLISTVIEW_C_H
#define QLISTVIEW_C_H

#include <stdbool.h>

typedef void (*ListViewClickedCallback)(void* widget, int row, int column);
typedef void (*ListViewDoubleClickedCallback)(void* widget, int row, int column);
typedef void (*ListViewSelectionChangedCallback)(void* widget);

#ifdef __cplusplus
extern "C" {
#endif

// QListView
void* QListView_create(void* parent);
void QListView_delete(void* listView);
void QListView_setModel(void* listView, void* model);
void* QListView_model(void* listView);
void QListView_setSelectionMode(void* listView, int mode);
int QListView_selectionMode(void* listView);
void QListView_setFlow(void* listView, int flow);
int QListView_flow(void* listView);
void QListView_setWrapping(void* listView, bool wrap);
bool QListView_isWrapping(void* listView);
void QListView_setResizeMode(void* listView, int mode);
int QListView_resizeMode(void* listView);
void QListView_setSpacing(void* listView, int space);
int QListView_spacing(void* listView);
void QListView_setBatchSize(void* listView, int batchSize);
int QListView_batchSize(void* listView);
void QListView_setGridSize(void* listView, int width, int height);
void QListView_gridSize(void* listView, int* width, int* height);
void QListView_setViewMode(void* listView, int mode);
int QListView_viewMode(void* listView);
void QListView_setUniformItemSizes(void* listView, bool enable);
bool QListView_uniformItemSizes(void* listView);
void QListView_setWordWrap(void* listView, bool on);
bool QListView_wordWrap(void* listView);
void QListView_setSelectionRectVisible(void* listView, bool show);
bool QListView_isSelectionRectVisible(void* listView);
void QListView_setItemAlignment(void* listView, int alignment);
int QListView_itemAlignment(void* listView);
void QListView_setModelColumn(void* listView, int column);
int QListView_modelColumn(void* listView);

// Event handlers
void QListView_setClickedCallback(void* listView, ListViewClickedCallback callback);
void QListView_setDoubleClickedCallback(void* listView, ListViewDoubleClickedCallback callback);
void QListView_setSelectionChangedCallback(void* listView, ListViewSelectionChangedCallback callback);

// Constants
#define QLISTVIEW_STATIC 0
#define QLISTVIEW_FREE 1
#define QLISTVIEW_SNAP 2

#define QLISTVIEW_LEFT_TO_RIGHT 0
#define QLISTVIEW_TOP_TO_BOTTOM 1

#define QLISTVIEW_ICON_MODE 0
#define QLISTVIEW_LIST_MODE 1

#define QLISTVIEW_SINGLE_SELECTION 1
#define QLISTVIEW_MULTI_SELECTION 2
#define QLISTVIEW_EXTENDED_SELECTION 3
#define QLISTVIEW_CONTIGUOUS_SELECTION 4
#define QLISTVIEW_NO_SELECTION 0

#ifdef __cplusplus
}
#endif

#endif // QLISTVIEW_C_H
