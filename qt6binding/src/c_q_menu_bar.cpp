#include "c_q_menu_bar.h"
#include "bind_q_menu_bar.h"
#include "handler_menu_bar.h"
#include <QString>

extern "C" {

void* QMenuBar_create(void* parent)
{
    return new BindQMenuBar(reinterpret_cast<QWidget*>(parent));
}

void QMenuBar_delete(void* menu_bar)
{
    delete static_cast<BindQMenuBar*>(menu_bar);
}

void* QMenuBar_addMenu(void* menu_bar, const char* title)
{
    return static_cast<BindQMenuBar*>(menu_bar)->addMenu(QString::fromUtf8(title));
}

void* QMenuBar_addMenu2(void* menu_bar, void* menu)
{
    return static_cast<BindQMenuBar*>(menu_bar)->addMenu(static_cast<QMenu*>(menu));
}

void QMenuBar_clear(void* menu_bar)
{
    static_cast<BindQMenuBar*>(menu_bar)->clear();
}

void* QMenuBar_addAction(void* menu_bar, const char* text)
{
    return static_cast<BindQMenuBar*>(menu_bar)->addAction(QString::fromUtf8(text));
}

void QMenuBar_removeAction(void* menu_bar, void* action)
{
    static_cast<BindQMenuBar*>(menu_bar)->removeAction(static_cast<QAction*>(action));
}

void* QMenuBar_addSeparator(void* menu_bar)
{
    return static_cast<BindQMenuBar*>(menu_bar)->addSeparator();
}

void QMenuBar_setVisible(void* menu_bar, bool visible)
{
    static_cast<BindQMenuBar*>(menu_bar)->setVisible(visible);
}

bool QMenuBar_isVisible(void* menu_bar)
{
    return static_cast<BindQMenuBar*>(menu_bar)->isVisible();
}

void QMenuBar_setEnabled(void* menu_bar, bool enabled)
{
    static_cast<BindQMenuBar*>(menu_bar)->setEnabled(enabled);
}

bool QMenuBar_isEnabled(void* menu_bar)
{
    return static_cast<BindQMenuBar*>(menu_bar)->isEnabled();
}

int QMenuBar_height(void* menu_bar)
{
    return static_cast<BindQMenuBar*>(menu_bar)->height();
}

void QMenuBar_setNativeMenuBar(void* menu_bar, bool native)
{
    static_cast<BindQMenuBar*>(menu_bar)->setNativeMenuBar(native);
}

bool QMenuBar_isNativeMenuBar(void* menu_bar)
{
    return static_cast<BindQMenuBar*>(menu_bar)->isNativeMenuBar();
}

void QMenuBar_setCornerWidget(void* menu_bar, void* widget, int corner)
{
    static_cast<BindQMenuBar*>(menu_bar)->setCornerWidget(
        static_cast<QWidget*>(widget),
        static_cast<Qt::Corner>(corner)
    );
}

void* QMenuBar_cornerWidget(void* menu_bar, int corner)
{
    return static_cast<BindQMenuBar*>(menu_bar)->cornerWidget(static_cast<Qt::Corner>(corner));
}

void QMenuBar_setActionEnabled(void* menu_bar, void* action, bool enabled)
{
    static_cast<QAction*>(action)->setEnabled(enabled);
}

bool QMenuBar_isActionEnabled(void* menu_bar, void* action)
{
    return static_cast<QAction*>(action)->isEnabled();
}

void QMenuBar_setActionVisible(void* menu_bar, void* action, bool visible)
{
    static_cast<QAction*>(action)->setVisible(visible);
}

bool QMenuBar_isActionVisible(void* menu_bar, void* action)
{
    return static_cast<QAction*>(action)->isVisible();
}

void QMenuBar_setActionText(void* menu_bar, void* action, const char* text)
{
    static_cast<QAction*>(action)->setText(QString::fromUtf8(text));
}

const char* QMenuBar_actionText(void* menu_bar, void* action)
{
    QString text = static_cast<QAction*>(action)->text();
    return qstrdup(text.toUtf8().constData());
}

void QMenuBar_setTriggeredCallback(void* menu_bar, QMenuBarTriggeredCallback callback)
{
    BindQMenuBar* qmenubar = static_cast<BindQMenuBar*>(menu_bar);
    MenuBarHandler* handler = qmenubar->handler();
    if (!handler) {
        handler = new MenuBarHandler(qmenubar);
        qmenubar->setMenuBarHandler(handler);
    }
    handler->setTriggeredCallback(callback);
}

void QMenuBar_setHoveredCallback(void* menu_bar, QMenuBarHoveredCallback callback)
{
    BindQMenuBar* qmenubar = static_cast<BindQMenuBar*>(menu_bar);
    MenuBarHandler* handler = qmenubar->handler();
    if (!handler) {
        handler = new MenuBarHandler(qmenubar);
        qmenubar->setMenuBarHandler(handler);
    }
    handler->setHoveredCallback(callback);
}

}
