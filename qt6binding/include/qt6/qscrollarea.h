#ifndef QSCROLLAREA_C_H
#define QSCROLLAREA_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QScrollArea creation/deletion
void* QScrollArea_create(void* parent);
void QScrollArea_delete(void* scroll_area);

// Widget management
void QScrollArea_setWidget(void* scroll_area, void* widget);
void* QScrollArea_widget(void* scroll_area);
void* QScrollArea_takeWidget(void* scroll_area);

// Viewport
void* QScrollArea_viewport(void* scroll_area);

// Scroll bar policy
void QScrollArea_setHorizontalScrollBarPolicy(void* scroll_area, int policy);
int QScrollArea_horizontalScrollBarPolicy(void* scroll_area);
void QScrollArea_setVerticalScrollBarPolicy(void* scroll_area, int policy);
int QScrollArea_verticalScrollBarPolicy(void* scroll_area);

// Scroll bars
void* QScrollArea_horizontalScrollBar(void* scroll_area);
void* QScrollArea_verticalScrollBar(void* scroll_area);

// Widget size
void QScrollArea_setWidgetResizable(void* scroll_area, bool resizable);
bool QScrollArea_widgetResizable(void* scroll_area);
void QScrollArea_setSizeAdjustPolicy(void* scroll_area, int policy);
int QScrollArea_sizeAdjustPolicy(void* scroll_area);

// Alignment
void QScrollArea_setAlignment(void* scroll_area, int alignment);
int QScrollArea_alignment(void* scroll_area);

// Ensurevisible
void QScrollArea_ensureVisible(void* scroll_area, int x, int y, int xmargin, int ymargin);
void QScrollArea_ensureWidgetVisible(void* scroll_area, void* child_widget, int xmargin, int ymargin);

// Signal handlers
    typedef void (*VerticalScrollBarValueChangedCallback)(void*, int);
    typedef void (*HorizontalScrollBarValueChangedCallback)(void*, int);

void QScrollArea_setVerticalScrollBarValueChangedCallback(void* scroll_area, VerticalScrollBarValueChangedCallback callback);
void QScrollArea_setHorizontalScrollBarValueChangedCallback(void* scroll_area, HorizontalScrollBarValueChangedCallback callback);

// Constants
#define QSCROLLAREA_SCROLLBARPOLICY_ASNEEDED 0
#define QSCROLLAREA_SCROLLBARPOLICY_ALWAYSON 1
#define QSCROLLAREA_SCROLLBARPOLICY_ALWAYSOFF 2

#define QSCROLLAREA_SIZEADJUSTPOLICY_NONE 0
#define QSCROLLAREA_SIZEADJUSTPOLICY_ADJUSTTOCONTENTS 1
#define QSCROLLAREA_SIZEADJUSTPOLICY_ADJUSTIGNORED 2

#define QSCROLLAREA_ALIGNLEFT 0x0001
#define QSCROLLAREA_ALIGNRIGHT 0x0002
#define QSCROLLAREA_ALIGNHCENTER 0x0004
#define QSCROLLAREA_ALIGNJUSTIFY 0x0008
#define QSCROLLAREA_ALIGNTOP 0x0020
#define QSCROLLAREA_ALIGNBOTTOM 0x0040
#define QSCROLLAREA_ALIGNVCENTER 0x0080
#define QSCROLLAREA_ALIGNCENTER 0x0084

#ifdef __cplusplus
}
#endif

#endif // QSCROLLAREA_C_H
