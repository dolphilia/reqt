#include "bind_q_widget.h"
#include <QString>

QWidget* QWidgetBind::create(QWidget* parent) {
    return new QWidget(parent);
}

void QWidgetBind::destroy(QWidget* widget) {
    if (widget) {
        delete widget;
    }
}

void QWidgetBind::show(QWidget* widget) {
    if (widget) {
        widget->show();
    }
}

void QWidgetBind::hide(QWidget* widget) {
    if (widget) {
        widget->hide();
    }
}

void QWidgetBind::setWindowTitle(QWidget* widget, const char* title) {
    if (widget && title) {
        widget->setWindowTitle(QString::fromUtf8(title));
    }
}

void QWidgetBind::resize(QWidget* widget, int width, int height) {
    if (widget) {
        widget->resize(width, height);
    }
}

void QWidgetBind::setMinimumSize(QWidget* widget, int width, int height) {
    if (widget) {
        widget->setMinimumSize(width, height);
    }
}

void QWidgetBind::setMaximumSize(QWidget* widget, int width, int height) {
    if (widget) {
        widget->setMaximumSize(width, height);
    }
}

void QWidgetBind::move(QWidget* widget, int x, int y) {
    if (widget) {
        widget->move(x, y);
    }
}

extern "C" {

void* QWidget_create(void* parent) {
    return QWidgetBind::create(static_cast<QWidget*>(parent));
}

void QWidget_delete(void* widget) {
    QWidgetBind::destroy(static_cast<QWidget*>(widget));
}

void QWidget_show(void* widget) {
    QWidgetBind::show(static_cast<QWidget*>(widget));
}

void QWidget_hide(void* widget) {
    QWidgetBind::hide(static_cast<QWidget*>(widget));
}

void QWidget_setWindowTitle(void* widget, const char* title) {
    QWidgetBind::setWindowTitle(static_cast<QWidget*>(widget), title);
}

void QWidget_resize(void* widget, int width, int height) {
    QWidgetBind::resize(static_cast<QWidget*>(widget), width, height);
}

void QWidget_setMinimumSize(void* widget, int width, int height) {
    QWidgetBind::setMinimumSize(static_cast<QWidget*>(widget), width, height);
}

void QWidget_setMaximumSize(void* widget, int width, int height) {
    QWidgetBind::setMaximumSize(static_cast<QWidget*>(widget), width, height);
}

void QWidget_move(void* widget, int x, int y) {
    QWidgetBind::move(static_cast<QWidget*>(widget), x, y);
}

}
