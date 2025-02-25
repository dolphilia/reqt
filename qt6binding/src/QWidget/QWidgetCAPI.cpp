#include "qwidget.h"
#include "QWidgetBind.h"
#include <QWidget>
#include <QLayout>
#include <QWindow>

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

void QWidget_setFixedSize(void* widget, int w, int h)
{
    static_cast<BindQWidget*>(widget)->setFixedSizeWrapper(w, h);
}

void QWidget_setFixedHeight(void* widget, int height)
{
    static_cast<BindQWidget*>(widget)->setFixedHeightWrapper(height);
}

void QWidget_setFixedWidth(void* widget, int width)
{
    static_cast<BindQWidget*>(widget)->setFixedWidthWrapper(width);
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

void QWidget_setCursor(void* widget, void* cursor)
{
    static_cast<BindQWidget*>(widget)->setCursor(*static_cast<QCursor*>(cursor));
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

void QWidget_setLayout(void* widget, void* layout)
{
    static_cast<BindQWidget*>(widget)->setLayout(static_cast<QLayout*>(layout));
}

// Static Public Members

void* QWidget_createWindowContainer(void* window, void* parent, int flags)
{
    return QWidget::createWindowContainer(
        static_cast<QWindow*>(window),
        static_cast<QWidget*>(parent),
        static_cast<Qt::WindowFlags>(flags)
    );
}

void* QWidget_find(unsigned long id)
{
    return QWidget::find(static_cast<WId>(id));
}

void* QWidget_keyboardGrabber()
{
    return QWidget::keyboardGrabber();
}

void* QWidget_mouseGrabber()
{
    return QWidget::mouseGrabber();
}

void QWidget_setTabOrder(void* first, void* second)
{
    QWidget::setTabOrder(
        static_cast<QWidget*>(first),
        static_cast<QWidget*>(second)
    );
}

// Public Slots

bool QWidget_close(void* widget)
{
    return static_cast<BindQWidget*>(widget)->close();
}

void QWidget_lower(void* widget)
{
    static_cast<BindQWidget*>(widget)->lower();
}

void QWidget_raise(void* widget)
{
    static_cast<BindQWidget*>(widget)->raise();
}

void QWidget_repaint(void* widget)
{
    static_cast<BindQWidget*>(widget)->repaint();
}

void QWidget_setDisabled(void* widget, bool disable)
{
    static_cast<BindQWidget*>(widget)->setDisabled(disable);
}

void QWidget_setEnabled(void* widget, bool enable)
{
    static_cast<BindQWidget*>(widget)->setEnabled(enable);
}

void QWidget_setFocus(void* widget)
{
    static_cast<BindQWidget*>(widget)->setFocus();
}

void QWidget_setHidden(void* widget, bool hidden)
{
    static_cast<BindQWidget*>(widget)->setHidden(hidden);
}

void QWidget_setWindowModified(void* widget, bool modified)
{
    static_cast<BindQWidget*>(widget)->setWindowModified(modified);
}

void QWidget_showFullScreen(void* widget)
{
    static_cast<BindQWidget*>(widget)->showFullScreen();
}

void QWidget_showMaximized(void* widget)
{
    static_cast<BindQWidget*>(widget)->showMaximized();
}

void QWidget_showMinimized(void* widget)
{
    static_cast<BindQWidget*>(widget)->showMinimized();
}

void QWidget_showNormal(void* widget)
{
    static_cast<BindQWidget*>(widget)->showNormal();
}

void QWidget_update(void* widget)
{
    static_cast<BindQWidget*>(widget)->update();
}

// Signals

void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<BindQWidget*>(widget)->setCustomContextMenuRequestedCallback(
        reinterpret_cast<WidgetCustomContextMenuRequestedCallback>(callback)
    );
}

void QWidget_setWindowIconChangedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<BindQWidget*>(widget)->setWindowIconChangedCallback(
        reinterpret_cast<WidgetWindowIconChangedCallback>(callback)
    );
}

void QWidget_setWindowTitleChangedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<BindQWidget*>(widget)->setWindowTitleChangedCallback(
        reinterpret_cast<WidgetWindowTitleChangedCallback>(callback)
    );
}

}
