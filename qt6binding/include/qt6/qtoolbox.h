#ifndef QTOOLBOX_C_H
#define QTOOLBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QToolBox_create(void* parent);
void QToolBox_delete(void* tool_box);

// Item management
int QToolBox_addItem(void* tool_box, void* widget, const char* text);
int QToolBox_insertItem(void* tool_box, int index, void* widget, const char* text);
void QToolBox_removeItem(void* tool_box, int index);

// Current item
int QToolBox_currentIndex(void* tool_box);
void QToolBox_setCurrentIndex(void* tool_box, int index);
void* QToolBox_currentWidget(void* tool_box);
void QToolBox_setCurrentWidget(void* tool_box, void* widget);

// Item properties
const char* QToolBox_itemText(void* tool_box, int index);
void QToolBox_setItemText(void* tool_box, int index, const char* text);
const char* QToolBox_itemToolTip(void* tool_box, int index);
void QToolBox_setItemToolTip(void* tool_box, int index, const char* toolTip);
bool QToolBox_isItemEnabled(void* tool_box, int index);
void QToolBox_setItemEnabled(void* tool_box, int index, bool enabled);

// Item count
int QToolBox_count(void* tool_box);

// Widget at index
void* QToolBox_widget(void* tool_box, int index);
int QToolBox_indexOf(void* tool_box, void* widget);

// Callbacks
typedef void (*QToolBoxCurrentChangedCallback)(int index);
void QToolBox_setCurrentChangedCallback(void* tool_box, QToolBoxCurrentChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QTOOLBOX_C_H
