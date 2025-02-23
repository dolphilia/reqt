#ifndef QWIDGET_C_H
#define QWIDGET_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QWidget creation/deletion
void* QWidget_create(void* parent);
void QWidget_delete(void* widget);

// Geometry
void QWidget_resize(void* widget, int w, int h);
void QWidget_move(void* widget, int x, int y);
int QWidget_x(void* widget);
int QWidget_y(void* widget);
int QWidget_width(void* widget);
int QWidget_height(void* widget);
void QWidget_setFixedSize(void* widget, int w, int h);
void QWidget_setFixedHeight(void* widget, int height);
void QWidget_setFixedWidth(void* widget, int width);

// Visibility
void QWidget_show(void* widget);
void QWidget_hide(void* widget);
bool QWidget_isVisible(void* widget);
void QWidget_setVisible(void* widget, bool visible);

// Window properties
void QWidget_setWindowTitle(void* widget, const char* title);
const char* QWidget_windowTitle(void* widget);

// Style sheet
void QWidget_setStyleSheet(void* widget, const char* styleSheet);
const char* QWidget_styleSheet(void* widget);

// Cursor
void QWidget_setCursor(void* widget, void* cursor);

// Background
void QWidget_setAutoFillBackground(void* widget, bool enabled);
bool QWidget_autoFillBackground(void* widget);

// Palette
void QWidget_setBackgroundRole(void* widget, int role);
int QWidget_backgroundRole(void* widget);
void QWidget_setForegroundRole(void* widget, int role);
int QWidget_foregroundRole(void* widget);

// Color roles
#define QWIDGET_BACKGROUND 10
#define QWIDGET_FOREGROUND 9
#define QWIDGET_WINDOW 0
#define QWIDGET_WINDOWTEXT 1
#define QWIDGET_BASE 9
#define QWIDGET_ALTERNATEBASE 16
#define QWIDGET_TOOLTIBASE 17
#define QWIDGET_TOOLTIPTEXT 18
#define QWIDGET_TEXT 6
#define QWIDGET_BUTTON 1
#define QWIDGET_BUTTONTEXT 8
#define QWIDGET_BRIGHTTEXT 7

#ifdef __cplusplus
}
#endif

#endif // QWIDGET_C_H
