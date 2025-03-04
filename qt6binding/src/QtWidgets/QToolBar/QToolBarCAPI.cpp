#include "qtoolbar.h"
#include "QToolBarBind.h"
#include <QAction>
#include <QIcon>

extern "C" {

void* QToolBar_create(void* parent) {
    return new QToolBarBind(static_cast<QWidget*>(parent));
}

void* QToolBar_create_with_title(const char* title, void* parent) {
    const QString qstr = QString::fromUtf8(title);
    return new QToolBarBind(qstr, static_cast<QWidget*>(parent));
}

void QToolBar_delete(void* tool_bar) {
    delete static_cast<QToolBarBind*>(tool_bar);
}

void* QToolBar_addAction(void* tool_bar, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QToolBarBind*>(tool_bar)->addAction(qstr);
}

void* QToolBar_addAction_with_icon(void* tool_bar, const char* icon, const char* text) {
    const QString iconStr = QString::fromUtf8(icon);
    const QString textStr = QString::fromUtf8(text);
    return static_cast<QToolBarBind*>(tool_bar)->addAction(QIcon(iconStr), textStr);
}

void* QToolBar_addSeparator(void* tool_bar) {
    return static_cast<QToolBarBind*>(tool_bar)->addSeparator();
}

void* QToolBar_addWidget(void* tool_bar, void* widget) {
    return static_cast<QToolBarBind*>(tool_bar)->addWidget(static_cast<QWidget*>(widget));
}

void QToolBar_clear(void* tool_bar) {
    static_cast<QToolBarBind*>(tool_bar)->clear();
}

void* QToolBar_insertAction(void* tool_bar, void* before, void* action) {
    static_cast<QToolBarBind*>(tool_bar)->insertAction(
        static_cast<QAction*>(before),
        static_cast<QAction*>(action)
    );
    return action;
}

void* QToolBar_insertSeparator(void* tool_bar, void* before) {
    return static_cast<QToolBarBind*>(tool_bar)->insertSeparator(static_cast<QAction*>(before));
}

void* QToolBar_insertWidget(void* tool_bar, void* before, void* widget) {
    return static_cast<QToolBarBind*>(tool_bar)->insertWidget(
        static_cast<QAction*>(before),
        static_cast<QWidget*>(widget)
    );
}

void QToolBar_removeAction(void* tool_bar, void* action) {
    static_cast<QToolBarBind*>(tool_bar)->removeAction(static_cast<QAction*>(action));
}

void QToolBar_setAllowedAreas(void* tool_bar, int areas) {
    static_cast<QToolBarBind*>(tool_bar)->setAllowedAreas(static_cast<Qt::ToolBarAreas>(areas));
}

int QToolBar_allowedAreas(void* tool_bar) {
    return static_cast<int>(static_cast<QToolBarBind*>(tool_bar)->allowedAreas());
}

void QToolBar_setFloatable(void* tool_bar, bool floatable) {
    static_cast<QToolBarBind*>(tool_bar)->setFloatable(floatable);
}

bool QToolBar_isFloatable(void* tool_bar) {
    return static_cast<QToolBarBind*>(tool_bar)->isFloatable();
}

void QToolBar_setMovable(void* tool_bar, bool movable) {
    static_cast<QToolBarBind*>(tool_bar)->setMovable(movable);
}

bool QToolBar_isMovable(void* tool_bar) {
    return static_cast<QToolBarBind*>(tool_bar)->isMovable();
}

void QToolBar_setOrientation(void* tool_bar, int orientation) {
    static_cast<QToolBarBind*>(tool_bar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QToolBar_orientation(void* tool_bar) {
    return static_cast<int>(static_cast<QToolBarBind*>(tool_bar)->orientation());
}

void QToolBar_setIconSize(void* tool_bar, int w, int h) {
    static_cast<QToolBarBind*>(tool_bar)->setIconSize(QSize(w, h));
}

void QToolBar_setToolButtonStyle(void* tool_bar, int style) {
    static_cast<QToolBarBind*>(tool_bar)->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
}

int QToolBar_toolButtonStyle(void* tool_bar) {
    return static_cast<int>(static_cast<QToolBarBind*>(tool_bar)->toolButtonStyle());
}

typedef void (*QToolBar_ActionTriggeredCallback)(void*, void*);
typedef void (*QToolBar_MovableChangedCallback)(void*, bool);
typedef void (*QToolBar_OrientationChangedCallback)(void*, int);
typedef void (*QToolBar_TopLevelChangedCallback)(void*, bool);
typedef void (*QToolBar_VisibilityChangedCallback)(void*, bool);
typedef void (*QToolBar_AllowedAreasChangedCallback)(void*, int);

void QToolBar_setActionTriggeredCallback(void* tool_bar, QToolBar_ActionTriggeredCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setActionTriggeredCallback(callback);
}

void QToolBar_setMovableChangedCallback(void* tool_bar, QToolBar_MovableChangedCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setMovableChangedCallback(callback);
}

void QToolBar_setOrientationChangedCallback(void* tool_bar, QToolBar_OrientationChangedCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setOrientationChangedCallback(callback);
}

void QToolBar_setTopLevelChangedCallback(void* tool_bar, QToolBar_TopLevelChangedCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setTopLevelChangedCallback(callback);
}

void QToolBar_setVisibilityChangedCallback(void* tool_bar, QToolBar_VisibilityChangedCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setVisibilityChangedCallback(callback);
}

void QToolBar_setAllowedAreasChangedCallback(void* tool_bar, QToolBar_AllowedAreasChangedCallback callback) {
    static_cast<QToolBarBind*>(tool_bar)->setAllowedAreasChangedCallback(callback);
}

}
