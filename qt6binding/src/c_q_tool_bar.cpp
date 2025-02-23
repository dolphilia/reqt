#include "c_q_tool_bar.h"
#include "bind_q_tool_bar.h"
#include <QAction>
#include <QIcon>

extern "C" {

void* QToolBar_create(void* parent)
{
    return new BindQToolBar(reinterpret_cast<QWidget*>(parent));
}

void* QToolBar_create_with_title(const char* title, void* parent)
{
    return new BindQToolBar(QString::fromUtf8(title), reinterpret_cast<QWidget*>(parent));
}

void QToolBar_delete(void* tool_bar)
{
    delete static_cast<BindQToolBar*>(tool_bar);
}

void* QToolBar_addAction(void* tool_bar, const char* text)
{
    return static_cast<BindQToolBar*>(tool_bar)->addAction(QString::fromUtf8(text));
}

void* QToolBar_addAction_with_icon(void* tool_bar, const char* icon, const char* text)
{
    return static_cast<BindQToolBar*>(tool_bar)->addAction(
        QIcon(QString::fromUtf8(icon)),
        QString::fromUtf8(text)
    );
}

void* QToolBar_addSeparator(void* tool_bar)
{
    return static_cast<BindQToolBar*>(tool_bar)->addSeparator();
}

void* QToolBar_addWidget(void* tool_bar, void* widget)
{
    return static_cast<BindQToolBar*>(tool_bar)->addWidget(static_cast<QWidget*>(widget));
}

void QToolBar_clear(void* tool_bar)
{
    static_cast<BindQToolBar*>(tool_bar)->clear();
}

void* QToolBar_insertAction(void* tool_bar, void* before, void* action)
{
    static_cast<BindQToolBar*>(tool_bar)->insertAction(
        static_cast<QAction*>(before),
        static_cast<QAction*>(action)
    );
    return action;
}

void* QToolBar_insertSeparator(void* tool_bar, void* before)
{
    return static_cast<BindQToolBar*>(tool_bar)->insertSeparator(static_cast<QAction*>(before));
}

void* QToolBar_insertWidget(void* tool_bar, void* before, void* widget)
{
    return static_cast<BindQToolBar*>(tool_bar)->insertWidget(
        static_cast<QAction*>(before),
        static_cast<QWidget*>(widget)
    );
}

void QToolBar_removeAction(void* tool_bar, void* action)
{
    static_cast<BindQToolBar*>(tool_bar)->removeAction(static_cast<QAction*>(action));
}

void QToolBar_setAllowedAreas(void* tool_bar, int areas)
{
    static_cast<BindQToolBar*>(tool_bar)->setAllowedAreas(static_cast<Qt::ToolBarAreas>(areas));
}

int QToolBar_allowedAreas(void* tool_bar)
{
    return static_cast<int>(static_cast<BindQToolBar*>(tool_bar)->allowedAreas());
}

void QToolBar_setFloatable(void* tool_bar, bool floatable)
{
    static_cast<BindQToolBar*>(tool_bar)->setFloatable(floatable);
}

bool QToolBar_isFloatable(void* tool_bar)
{
    return static_cast<BindQToolBar*>(tool_bar)->isFloatable();
}

void QToolBar_setMovable(void* tool_bar, bool movable)
{
    static_cast<BindQToolBar*>(tool_bar)->setMovable(movable);
}

bool QToolBar_isMovable(void* tool_bar)
{
    return static_cast<BindQToolBar*>(tool_bar)->isMovable();
}

void QToolBar_setOrientation(void* tool_bar, int orientation)
{
    static_cast<BindQToolBar*>(tool_bar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QToolBar_orientation(void* tool_bar)
{
    return static_cast<int>(static_cast<BindQToolBar*>(tool_bar)->orientation());
}

void QToolBar_setIconSize(void* tool_bar, int w, int h)
{
    static_cast<BindQToolBar*>(tool_bar)->setIconSize(QSize(w, h));
}

void QToolBar_setToolButtonStyle(void* tool_bar, int style)
{
    static_cast<BindQToolBar*>(tool_bar)->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
}

int QToolBar_toolButtonStyle(void* tool_bar)
{
    return static_cast<int>(static_cast<BindQToolBar*>(tool_bar)->toolButtonStyle());
}

void QToolBar_setActionTriggeredCallback(void* tool_bar, QToolBarActionTriggeredCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setActionTriggeredCallback(callback);
}

void QToolBar_setMovableChangedCallback(void* tool_bar, QToolBarMovableChangedCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setMovableChangedCallback(callback);
}

void QToolBar_setOrientationChangedCallback(void* tool_bar, QToolBarOrientationChangedCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setOrientationChangedCallback(callback);
}

void QToolBar_setTopLevelChangedCallback(void* tool_bar, QToolBarTopLevelChangedCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setTopLevelChangedCallback(callback);
}

void QToolBar_setVisibilityChangedCallback(void* tool_bar, QToolBarVisibilityChangedCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setVisibilityChangedCallback(callback);
}

void QToolBar_setAllowedAreasChangedCallback(void* tool_bar, QToolBarAllowedAreasChangedCallback callback)
{
    BindQToolBar* toolbar = static_cast<BindQToolBar*>(tool_bar);
    ToolBarHandler* handler = toolbar->handler();
    if (!handler) {
        handler = new ToolBarHandler(toolbar);
        toolbar->setToolBarHandler(handler);
    }
    handler->setAllowedAreasChangedCallback(callback);
}

}
