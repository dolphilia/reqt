#ifndef QSTACKEDWIDGET_H
#define QSTACKEDWIDGET_H

#ifdef __cplusplus
extern "C" {
#endif

void* QStackedWidget_create(void* parent);
void QStackedWidget_delete(void* stackedWidget);
int QStackedWidget_addWidget(void* stackedWidget, void* widget);
int QStackedWidget_insertWidget(void* stackedWidget, int index, void* widget);
void QStackedWidget_removeWidget(void* stackedWidget, void* widget);
int QStackedWidget_count(void* stackedWidget);
int QStackedWidget_currentIndex(void* stackedWidget);
void* QStackedWidget_currentWidget(void* stackedWidget);
void* QStackedWidget_widget(void* stackedWidget, int index);
int QStackedWidget_indexOf(void* stackedWidget, void* widget);
void QStackedWidget_setCurrentIndex(void* stackedWidget, int index);
void QStackedWidget_setCurrentWidget(void* stackedWidget, void* widget);
void QStackedWidget_setCurrentChangedCallback(void* stackedWidget, void (*callback)(void*, int));
void QStackedWidget_setWidgetRemovedCallback(void* stackedWidget, void (*callback)(void*, int));

#ifdef __cplusplus
}
#endif

#endif // QSTACKEDWIDGET_H
