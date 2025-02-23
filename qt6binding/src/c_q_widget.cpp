#include "c_q_widget.h"
#include "bind_q_widget.h"
#include <QWidget>

extern "C" {

void* QWidget_create(void* parent)
{
    return new BindQWidget(reinterpret_cast<QWidget*>(parent));
}

void QWidget_delete(void* widget)
{
    delete static_cast<BindQWidget*>(widget);
}

void QWidget_resize(void* widget, int w, int h)
{
    static_cast<BindQWidget*>(widget)->resize(w, h);
}

void QWidget_move(void* widget, int x, int y)
{
    static_cast<BindQWidget*>(widget)->move(x, y);
}

int QWidget_x(void* widget)
{
    return static_cast<BindQWidget*>(widget)->x();
}

int QWidget_y(void* widget)
{
    return static_cast<BindQWidget*>(widget)->y();
}

int QWidget_width(void* widget)
{
    return static_cast<BindQWidget*>(widget)->width();
}

int QWidget_height(void* widget)
{
    return static_cast<BindQWidget*>(widget)->height();
}

void QWidget_show(void* widget)
{
    static_cast<BindQWidget*>(widget)->show();
}

void QWidget_hide(void* widget)
{
    static_cast<BindQWidget*>(widget)->hide();
}

bool QWidget_isVisible(void* widget)
{
    return static_cast<BindQWidget*>(widget)->isVisible();
}

void QWidget_setVisible(void* widget, bool visible)
{
    static_cast<BindQWidget*>(widget)->setVisible(visible);
}

void QWidget_setWindowTitle(void* widget, const char* title)
{
    static_cast<BindQWidget*>(widget)->setWindowTitle(QString::fromUtf8(title));
}

const char* QWidget_windowTitle(void* widget)
{
    return static_cast<BindQWidget*>(widget)->windowTitle().toUtf8().constData();
}

void QWidget_setStyleSheet(void* widget, const char* styleSheet)
{
    static_cast<BindQWidget*>(widget)->setStyleSheet(QString::fromUtf8(styleSheet));
}

const char* QWidget_styleSheet(void* widget)
{
    return static_cast<BindQWidget*>(widget)->styleSheet().toUtf8().constData();
}

void QWidget_setAutoFillBackground(void* widget, bool enabled)
{
    static_cast<BindQWidget*>(widget)->setAutoFillBackground(enabled);
}

bool QWidget_autoFillBackground(void* widget)
{
    return static_cast<BindQWidget*>(widget)->autoFillBackground();
}

void QWidget_setBackgroundRole(void* widget, int role)
{
    static_cast<BindQWidget*>(widget)->setBackgroundRole(static_cast<QPalette::ColorRole>(role));
}

int QWidget_backgroundRole(void* widget)
{
    return static_cast<int>(static_cast<BindQWidget*>(widget)->backgroundRole());
}

void QWidget_setForegroundRole(void* widget, int role)
{
    static_cast<BindQWidget*>(widget)->setForegroundRole(static_cast<QPalette::ColorRole>(role));
}

int QWidget_foregroundRole(void* widget)
{
    return static_cast<int>(static_cast<BindQWidget*>(widget)->foregroundRole());
}

}
