#include "QToolButtonBind.h"
#include <QIcon>
#include <QMenu>
#include <QAction>

extern "C" {

void* QToolButton_create(void* parent) {
    return new QToolButtonBind(static_cast<QWidget*>(parent));
}

void QToolButton_delete(void* tool_button) {
    delete static_cast<QToolButtonBind*>(tool_button);
}

void QToolButton_setText(void* tool_button, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QToolButtonBind*>(tool_button)->setText(qstr);
}

const char* QToolButton_text(void* tool_button) {
    const QString qstr = static_cast<QToolButtonBind*>(tool_button)->text();
    return qstr.toUtf8().constData();
}

void QToolButton_setIcon(void* tool_button, const char* icon_path) {
    static_cast<QToolButtonBind*>(tool_button)->setIcon(QIcon(QString::fromUtf8(icon_path)));
}

void QToolButton_setIconSize(void* tool_button, int w, int h) {
    static_cast<QToolButtonBind*>(tool_button)->setIconSize(QSize(w, h));
}

void QToolButton_setToolButtonStyle(void* tool_button, int style) {
    static_cast<QToolButtonBind*>(tool_button)->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
}

int QToolButton_toolButtonStyle(void* tool_button) {
    return static_cast<int>(static_cast<QToolButtonBind*>(tool_button)->toolButtonStyle());
}

void QToolButton_setAutoRaise(void* tool_button, bool enable) {
    static_cast<QToolButtonBind*>(tool_button)->setAutoRaise(enable);
}

bool QToolButton_autoRaise(void* tool_button) {
    return static_cast<QToolButtonBind*>(tool_button)->autoRaise();
}

void QToolButton_setCheckable(void* tool_button, bool checkable) {
    static_cast<QToolButtonBind*>(tool_button)->setCheckable(checkable);
}

bool QToolButton_isCheckable(void* tool_button) {
    return static_cast<QToolButtonBind*>(tool_button)->isCheckable();
}

void QToolButton_setPopupMode(void* tool_button, int mode) {
    static_cast<QToolButtonBind*>(tool_button)->setPopupMode(static_cast<QToolButton::ToolButtonPopupMode>(mode));
}

int QToolButton_popupMode(void* tool_button) {
    return static_cast<int>(static_cast<QToolButtonBind*>(tool_button)->popupMode());
}

void QToolButton_setArrowType(void* tool_button, int type) {
    static_cast<QToolButtonBind*>(tool_button)->setArrowType(static_cast<Qt::ArrowType>(type));
}

int QToolButton_arrowType(void* tool_button) {
    return static_cast<int>(static_cast<QToolButtonBind*>(tool_button)->arrowType());
}

void QToolButton_setMenu(void* tool_button, void* menu) {
    static_cast<QToolButtonBind*>(tool_button)->setMenu(static_cast<QMenu*>(menu));
}

void* QToolButton_menu(void* tool_button) {
    return static_cast<QToolButtonBind*>(tool_button)->menu();
}

void QToolButton_setDefaultAction(void* tool_button, void* action) {
    static_cast<QToolButtonBind*>(tool_button)->setDefaultAction(static_cast<QAction*>(action));
}

void* QToolButton_defaultAction(void* tool_button) {
    return static_cast<QToolButtonBind*>(tool_button)->defaultAction();
}

typedef void (*QToolButton_ClickedCallback)(void*);
typedef void (*QToolButton_ToggledCallback)(void*, bool);
typedef void (*QToolButton_TriggeredCallback)(void*);

void QToolButton_setClickedCallback(void* tool_button, QToolButton_ClickedCallback callback) {
    static_cast<QToolButtonBind*>(tool_button)->setClickedCallback(callback);
}

void QToolButton_setToggledCallback(void* tool_button, QToolButton_ToggledCallback callback) {
    static_cast<QToolButtonBind*>(tool_button)->setToggledCallback(callback);
}

void QToolButton_setTriggeredCallback(void* tool_button, QToolButton_TriggeredCallback callback) {
    static_cast<QToolButtonBind*>(tool_button)->setTriggeredCallback(callback);
}

}
