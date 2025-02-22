#ifndef QWIDGET_C_H
#define QWIDGET_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QWidget
void* QWidget_create(void* parent);
void QWidget_delete(void* widget);
void QWidget_show(void* widget);
void QWidget_hide(void* widget);
void QWidget_setMinimumSize(void* widget, int width, int height);
void QWidget_setMaximumSize(void* widget, int width, int height);
void QWidget_move(void* widget, int x, int y);
void QWidget_setWindowTitle(void* widget, const char* title);
void QWidget_resize(void* widget, int width, int height);

#ifdef __cplusplus
}
#endif

#endif // QWIDGET_C_H
