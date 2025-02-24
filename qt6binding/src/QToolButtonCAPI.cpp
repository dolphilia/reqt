#include "qtoolbutton.h"
#include "QToolButtonBind.h"
#include <QIcon>
#include <QMenu>
#include <QAction>

extern "C" {

void* QToolButton_create(void* parent)
{
    return new BindQToolButton(reinterpret_cast<QWidget*>(parent));
}

void QToolButton_delete(void* tool_button)
{
    delete static_cast<BindQToolButton*>(tool_button);
}

void QToolButton_setText(void* tool_button, const char* text)
{
    static_cast<BindQToolButton*>(tool_button)->setText(QString::fromUtf8(text));
}

const char* QToolButton_text(void* tool_button)
{
    return static_cast<BindQToolButton*>(tool_button)->text().toUtf8().constData();
}

void QToolButton_setIcon(void* tool_button, const char* icon_path)
{
    static_cast<BindQToolButton*>(tool_button)->setIcon(QIcon(QString::fromUtf8(icon_path)));
}

void QToolButton_setIconSize(void* tool_button, int w, int h)
{
    static_cast<BindQToolButton*>(tool_button)->setIconSize(QSize(w, h));
}

void QToolButton_setToolButtonStyle(void* tool_button, int style)
{
    static_cast<BindQToolButton*>(tool_button)->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
}

int QToolButton_toolButtonStyle(void* tool_button)
{
    return static_cast<int>(static_cast<BindQToolButton*>(tool_button)->toolButtonStyle());
}

void QToolButton_setAutoRaise(void* tool_button, bool enable)
{
    static_cast<BindQToolButton*>(tool_button)->setAutoRaise(enable);
}

bool QToolButton_autoRaise(void* tool_button)
{
    return static_cast<BindQToolButton*>(tool_button)->autoRaise();
}

void QToolButton_setCheckable(void* tool_button, bool checkable)
{
    static_cast<BindQToolButton*>(tool_button)->setCheckable(checkable);
}

bool QToolButton_isCheckable(void* tool_button)
{
    return static_cast<BindQToolButton*>(tool_button)->isCheckable();
}

void QToolButton_setPopupMode(void* tool_button, int mode)
{
    static_cast<BindQToolButton*>(tool_button)->setPopupMode(static_cast<QToolButton::ToolButtonPopupMode>(mode));
}

int QToolButton_popupMode(void* tool_button)
{
    return static_cast<int>(static_cast<BindQToolButton*>(tool_button)->popupMode());
}

void QToolButton_setArrowType(void* tool_button, int type)
{
    static_cast<BindQToolButton*>(tool_button)->setArrowType(static_cast<Qt::ArrowType>(type));
}

int QToolButton_arrowType(void* tool_button)
{
    return static_cast<int>(static_cast<BindQToolButton*>(tool_button)->arrowType());
}

void QToolButton_setMenu(void* tool_button, void* menu)
{
    static_cast<BindQToolButton*>(tool_button)->setMenu(static_cast<QMenu*>(menu));
}

void* QToolButton_menu(void* tool_button)
{
    return static_cast<BindQToolButton*>(tool_button)->menu();
}

void QToolButton_setDefaultAction(void* tool_button, void* action)
{
    static_cast<BindQToolButton*>(tool_button)->setDefaultAction(static_cast<QAction*>(action));
}

void* QToolButton_defaultAction(void* tool_button)
{
    return static_cast<BindQToolButton*>(tool_button)->defaultAction();
}

void QToolButton_setClickedCallback(void* tool_button, QToolButtonClickedCallback callback)
{
    BindQToolButton* button = static_cast<BindQToolButton*>(tool_button);
    ToolButtonHandler* handler = button->handler();
    if (!handler) {
        handler = new ToolButtonHandler(button);
        button->setToolButtonHandler(handler);
    }
    handler->setClickedCallback(callback);
}

void QToolButton_setToggledCallback(void* tool_button, QToolButtonToggledCallback callback)
{
    BindQToolButton* button = static_cast<BindQToolButton*>(tool_button);
    ToolButtonHandler* handler = button->handler();
    if (!handler) {
        handler = new ToolButtonHandler(button);
        button->setToolButtonHandler(handler);
    }
    handler->setToggledCallback(callback);
}

void QToolButton_setTriggeredCallback(void* tool_button, QToolButtonTriggeredCallback callback)
{
    BindQToolButton* button = static_cast<BindQToolButton*>(tool_button);
    ToolButtonHandler* handler = button->handler();
    if (!handler) {
        handler = new ToolButtonHandler(button);
        button->setToolButtonHandler(handler);
    }
    handler->setTriggeredCallback(callback);
}

}
