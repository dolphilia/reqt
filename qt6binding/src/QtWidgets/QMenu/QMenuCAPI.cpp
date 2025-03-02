#include "qmenu.h"
#include "QMenuBind.h"
#include "QMenuHandler.h"
#include <QString>
#include <QIcon>

extern "C" {

void* QMenu_create(void* parent)
{
    return new BindQMenu(reinterpret_cast<QWidget*>(parent));
}

void* QMenu_createWithTitle(const char* title, void* parent)
{
    return new BindQMenu(QString::fromUtf8(title), reinterpret_cast<QWidget*>(parent));
}

void QMenu_delete(void* menu)
{
    delete static_cast<BindQMenu*>(menu);
}

void* QMenu_addAction(void* menu, const char* text)
{
    return static_cast<BindQMenu*>(menu)->addAction(QString::fromUtf8(text));
}

void* QMenu_addMenu(void* menu, void* submenu)
{
    return static_cast<BindQMenu*>(menu)->addMenu(static_cast<QMenu*>(submenu));
}

void* QMenu_addSeparator(void* menu)
{
    return static_cast<BindQMenu*>(menu)->addSeparator();
}

void QMenu_removeAction(void* menu, void* action)
{
    static_cast<BindQMenu*>(menu)->removeAction(static_cast<QAction*>(action));
}

void QMenu_clear(void* menu)
{
    static_cast<BindQMenu*>(menu)->clear();
}

void QMenu_setTitle(void* menu, const char* title)
{
    static_cast<BindQMenu*>(menu)->setTitle(QString::fromUtf8(title));
}

const char* QMenu_title(void* menu)
{
    QString title = static_cast<BindQMenu*>(menu)->title();
    return qstrdup(title.toUtf8().constData());
}

void QMenu_setIcon(void* menu, const char* iconPath)
{
    static_cast<BindQMenu*>(menu)->setIcon(QIcon(QString::fromUtf8(iconPath)));
}

void QMenu_setEnabled(void* menu, bool enabled)
{
    static_cast<BindQMenu*>(menu)->setEnabled(enabled);
}

bool QMenu_isEnabled(void* menu)
{
    return static_cast<BindQMenu*>(menu)->isEnabled();
}

void QMenu_setVisible(void* menu, bool visible)
{
    static_cast<BindQMenu*>(menu)->setVisible(visible);
}

bool QMenu_isVisible(void* menu)
{
    return static_cast<BindQMenu*>(menu)->isVisible();
}

void QMenu_setActionEnabled(void* menu, void* action, bool enabled)
{
    static_cast<QAction*>(action)->setEnabled(enabled);
}

bool QMenu_isActionEnabled(void* menu, void* action)
{
    return static_cast<QAction*>(action)->isEnabled();
}

void QMenu_setActionVisible(void* menu, void* action, bool visible)
{
    static_cast<QAction*>(action)->setVisible(visible);
}

bool QMenu_isActionVisible(void* menu, void* action)
{
    return static_cast<QAction*>(action)->isVisible();
}

void QMenu_setActionText(void* menu, void* action, const char* text)
{
    static_cast<QAction*>(action)->setText(QString::fromUtf8(text));
}

const char* QMenu_actionText(void* menu, void* action)
{
    QString text = static_cast<QAction*>(action)->text();
    return qstrdup(text.toUtf8().constData());
}

void QMenu_setActionIcon(void* menu, void* action, const char* iconPath)
{
    static_cast<QAction*>(action)->setIcon(QIcon(QString::fromUtf8(iconPath)));
}

void QMenu_setActionCheckable(void* menu, void* action, bool checkable)
{
    static_cast<QAction*>(action)->setCheckable(checkable);
}

bool QMenu_isActionCheckable(void* menu, void* action)
{
    return static_cast<QAction*>(action)->isCheckable();
}

void QMenu_setActionChecked(void* menu, void* action, bool checked)
{
    static_cast<QAction*>(action)->setChecked(checked);
}

bool QMenu_isActionChecked(void* menu, void* action)
{
    return static_cast<QAction*>(action)->isChecked();
}

void QMenu_popup(void* menu, int x, int y)
{
    static_cast<BindQMenu*>(menu)->popup(QPoint(x, y));
}

void QMenu_exec(void* menu)
{
    static_cast<BindQMenu*>(menu)->exec();
}

void QMenu_setAboutToShowCallback(void* menu, QMenuAboutToShowCallback callback)
{
    BindQMenu* qmenu = static_cast<BindQMenu*>(menu);
    MenuHandler* handler = qmenu->handler();
    if (!handler) {
        handler = new MenuHandler(qmenu);
        qmenu->setMenuHandler(handler);
    }
    handler->setAboutToShowCallback(callback);
}

void QMenu_setAboutToHideCallback(void* menu, QMenuAboutToHideCallback callback)
{
    BindQMenu* qmenu = static_cast<BindQMenu*>(menu);
    MenuHandler* handler = qmenu->handler();
    if (!handler) {
        handler = new MenuHandler(qmenu);
        qmenu->setMenuHandler(handler);
    }
    handler->setAboutToHideCallback(callback);
}

void QMenu_setTriggeredCallback(void* menu, QMenuTriggeredCallback callback)
{
    BindQMenu* qmenu = static_cast<BindQMenu*>(menu);
    MenuHandler* handler = qmenu->handler();
    if (!handler) {
        handler = new MenuHandler(qmenu);
        qmenu->setMenuHandler(handler);
    }
    handler->setTriggeredCallback(callback);
}

void QMenu_setHoveredCallback(void* menu, QMenuHoveredCallback callback)
{
    BindQMenu* qmenu = static_cast<BindQMenu*>(menu);
    MenuHandler* handler = qmenu->handler();
    if (!handler) {
        handler = new MenuHandler(qmenu);
        qmenu->setMenuHandler(handler);
    }
    handler->setHoveredCallback(callback);
}

}
