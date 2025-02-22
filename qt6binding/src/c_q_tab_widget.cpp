#include "c_q_tab_widget.h"
#include "bind_q_tab_widget.h"
#include "handler_tab_widget.h"
#include <QString>

extern "C" {

void* QTabWidget_create(void* parent)
{
    return new BindQTabWidget(reinterpret_cast<QWidget*>(parent));
}

void QTabWidget_delete(void* tab_widget)
{
    delete static_cast<BindQTabWidget*>(tab_widget);
}

int QTabWidget_addTab(void* tab_widget, void* page, const char* label)
{
    return static_cast<BindQTabWidget*>(tab_widget)->addTab(
        static_cast<QWidget*>(page),
        QString::fromUtf8(label)
    );
}

int QTabWidget_insertTab(void* tab_widget, int index, void* page, const char* label)
{
    return static_cast<BindQTabWidget*>(tab_widget)->insertTab(
        index,
        static_cast<QWidget*>(page),
        QString::fromUtf8(label)
    );
}

void QTabWidget_removeTab(void* tab_widget, int index)
{
    static_cast<BindQTabWidget*>(tab_widget)->removeTab(index);
}

int QTabWidget_currentIndex(void* tab_widget)
{
    return static_cast<BindQTabWidget*>(tab_widget)->currentIndex();
}

void QTabWidget_setCurrentIndex(void* tab_widget, int index)
{
    static_cast<BindQTabWidget*>(tab_widget)->setCurrentIndex(index);
}

int QTabWidget_count(void* tab_widget)
{
    return static_cast<BindQTabWidget*>(tab_widget)->count();
}

void* QTabWidget_currentWidget(void* tab_widget)
{
    return static_cast<BindQTabWidget*>(tab_widget)->currentWidget();
}

void QTabWidget_setCurrentWidget(void* tab_widget, void* widget)
{
    static_cast<BindQTabWidget*>(tab_widget)->setCurrentWidget(static_cast<QWidget*>(widget));
}

void QTabWidget_setTabText(void* tab_widget, int index, const char* text)
{
    static_cast<BindQTabWidget*>(tab_widget)->setTabText(index, QString::fromUtf8(text));
}

const char* QTabWidget_tabText(void* tab_widget, int index)
{
    QString text = static_cast<BindQTabWidget*>(tab_widget)->tabText(index);
    return qstrdup(text.toUtf8().constData());
}

void QTabWidget_setTabToolTip(void* tab_widget, int index, const char* tip)
{
    static_cast<BindQTabWidget*>(tab_widget)->setTabToolTip(index, QString::fromUtf8(tip));
}

void QTabWidget_setTabEnabled(void* tab_widget, int index, bool enabled)
{
    static_cast<BindQTabWidget*>(tab_widget)->setTabEnabled(index, enabled);
}

bool QTabWidget_isTabEnabled(void* tab_widget, int index)
{
    return static_cast<BindQTabWidget*>(tab_widget)->isTabEnabled(index);
}

void QTabWidget_setTabsClosable(void* tab_widget, bool closable)
{
    static_cast<BindQTabWidget*>(tab_widget)->setTabsClosable(closable);
}

bool QTabWidget_tabsClosable(void* tab_widget)
{
    return static_cast<BindQTabWidget*>(tab_widget)->tabsClosable();
}

void QTabWidget_setMovable(void* tab_widget, bool movable)
{
    static_cast<BindQTabWidget*>(tab_widget)->setMovable(movable);
}

bool QTabWidget_isMovable(void* tab_widget)
{
    return static_cast<BindQTabWidget*>(tab_widget)->isMovable();
}

void QTabWidget_setTabPosition(void* tab_widget, int position)
{
    static_cast<BindQTabWidget*>(tab_widget)->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
}

int QTabWidget_tabPosition(void* tab_widget)
{
    return static_cast<int>(static_cast<BindQTabWidget*>(tab_widget)->tabPosition());
}

void QTabWidget_setCurrentChangedCallback(void* tab_widget, QTabWidgetCurrentChangedCallback callback)
{
    BindQTabWidget* qtab_widget = static_cast<BindQTabWidget*>(tab_widget);
    TabWidgetHandler* handler = qtab_widget->handler();
    if (!handler) {
        handler = new TabWidgetHandler(qtab_widget);
        qtab_widget->setTabWidgetHandler(handler);
    }
    handler->setCurrentChangedCallback(callback);
}

void QTabWidget_setTabCloseRequestedCallback(void* tab_widget, QTabWidgetTabCloseRequestedCallback callback)
{
    BindQTabWidget* qtab_widget = static_cast<BindQTabWidget*>(tab_widget);
    TabWidgetHandler* handler = qtab_widget->handler();
    if (!handler) {
        handler = new TabWidgetHandler(qtab_widget);
        qtab_widget->setTabWidgetHandler(handler);
    }
    handler->setTabCloseRequestedCallback(callback);
}

}
