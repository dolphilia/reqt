#include "c_q_tab_bar.h"
#include "bind_q_tab_bar.h"
#include "handler_tab_bar.h"
#include <QString>

extern "C" {

void* QTabBar_create(void* parent)
{
    return new BindQTabBar(reinterpret_cast<QWidget*>(parent));
}

void QTabBar_delete(void* tab_bar)
{
    delete static_cast<BindQTabBar*>(tab_bar);
}

int QTabBar_addTab(void* tab_bar, const char* text)
{
    return static_cast<BindQTabBar*>(tab_bar)->addTab(QString::fromUtf8(text));
}

int QTabBar_insertTab(void* tab_bar, int index, const char* text)
{
    return static_cast<BindQTabBar*>(tab_bar)->insertTab(index, QString::fromUtf8(text));
}

void QTabBar_removeTab(void* tab_bar, int index)
{
    static_cast<BindQTabBar*>(tab_bar)->removeTab(index);
}

void QTabBar_setCurrentIndex(void* tab_bar, int index)
{
    static_cast<BindQTabBar*>(tab_bar)->setCurrentIndex(index);
}

int QTabBar_currentIndex(void* tab_bar)
{
    return static_cast<BindQTabBar*>(tab_bar)->currentIndex();
}

int QTabBar_count(void* tab_bar)
{
    return static_cast<BindQTabBar*>(tab_bar)->count();
}

const char* QTabBar_tabText(void* tab_bar, int index)
{
    QString text = static_cast<BindQTabBar*>(tab_bar)->tabText(index);
    return qstrdup(text.toUtf8().constData());
}

void QTabBar_setTabText(void* tab_bar, int index, const char* text)
{
    static_cast<BindQTabBar*>(tab_bar)->setTabText(index, QString::fromUtf8(text));
}

void QTabBar_setTabsClosable(void* tab_bar, bool closable)
{
    static_cast<BindQTabBar*>(tab_bar)->setTabsClosable(closable);
}

bool QTabBar_tabsClosable(void* tab_bar)
{
    return static_cast<BindQTabBar*>(tab_bar)->tabsClosable();
}

void QTabBar_setTabEnabled(void* tab_bar, int index, bool enabled)
{
    static_cast<BindQTabBar*>(tab_bar)->setTabEnabled(index, enabled);
}

bool QTabBar_isTabEnabled(void* tab_bar, int index)
{
    return static_cast<BindQTabBar*>(tab_bar)->isTabEnabled(index);
}

void QTabBar_setTabToolTip(void* tab_bar, int index, const char* tooltip)
{
    static_cast<BindQTabBar*>(tab_bar)->setTabToolTip(index, QString::fromUtf8(tooltip));
}

void QTabBar_setCurrentChangedCallback(void* tab_bar, QTabBarCurrentChangedCallback callback)
{
    BindQTabBar* qtab_bar = static_cast<BindQTabBar*>(tab_bar);
    TabBarHandler* handler = qtab_bar->handler();
    if (!handler) {
        handler = new TabBarHandler(qtab_bar);
        qtab_bar->setTabBarHandler(handler);
    }
    handler->setCurrentChangedCallback(callback);
}

void QTabBar_setTabCloseRequestedCallback(void* tab_bar, QTabBarTabCloseRequestedCallback callback)
{
    BindQTabBar* qtab_bar = static_cast<BindQTabBar*>(tab_bar);
    TabBarHandler* handler = qtab_bar->handler();
    if (!handler) {
        handler = new TabBarHandler(qtab_bar);
        qtab_bar->setTabBarHandler(handler);
    }
    handler->setTabCloseRequestedCallback(callback);
}

}
