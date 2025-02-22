#ifndef QWIDGET_BIND_H
#define QWIDGET_BIND_H

#include <QWidget>

class QWidgetBind {
public:
    static QWidget* create(QWidget* parent = nullptr);
    static void destroy(QWidget* widget);
    static void show(QWidget* widget);
    static void hide(QWidget* widget);
    static void setWindowTitle(QWidget* widget, const char* title);
    static void resize(QWidget* widget, int width, int height);
    static void setMinimumSize(QWidget* widget, int width, int height);
    static void setMaximumSize(QWidget* widget, int width, int height);
    static void move(QWidget* widget, int x, int y);
};

#endif // QWIDGET_BIND_H
