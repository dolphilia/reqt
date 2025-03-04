#include "QMenuBarBind.h"

extern "C" {

void* QMenuBar_create(void* parent) {
    return new QMenuBarBind(static_cast<QWidget*>(parent));
}

void QMenuBar_delete(void* menuBar) {
    delete static_cast<QMenuBarBind*>(menuBar);
}

void* QMenuBar_addMenu(void* menuBar, const char* title) {
    const QString qstr = QString::fromUtf8(title);
    return static_cast<QMenuBarBind*>(menuBar)->addMenu(qstr);
}

void* QMenuBar_addMenu2(void* menuBar, void* menu) {
    return static_cast<QMenuBarBind*>(menuBar)->addMenu(static_cast<QMenu*>(menu));
}

void QMenuBar_clear(void* menuBar) {
    static_cast<QMenuBarBind*>(menuBar)->clear();
}

void* QMenuBar_addAction(void* menuBar, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QMenuBarBind*>(menuBar)->addAction(qstr);
}

void QMenuBar_removeAction(void* menuBar, void* action) {
    static_cast<QMenuBarBind*>(menuBar)->removeAction(static_cast<QAction*>(action));
}

void* QMenuBar_addSeparator(void* menuBar) {
    return static_cast<QMenuBarBind*>(menuBar)->addSeparator();
}

void QMenuBar_setVisible(void* menuBar, bool visible) {
    static_cast<QMenuBarBind*>(menuBar)->setVisible(visible);
}

bool QMenuBar_isVisible(void* menuBar) {
    return static_cast<QMenuBarBind*>(menuBar)->isVisible();
}

void QMenuBar_setEnabled(void* menuBar, bool enabled) {
    static_cast<QMenuBarBind*>(menuBar)->setEnabled(enabled);
}

bool QMenuBar_isEnabled(void* menuBar) {
    return static_cast<QMenuBarBind*>(menuBar)->isEnabled();
}

int QMenuBar_height(void* menuBar) {
    return static_cast<QMenuBarBind*>(menuBar)->height();
}

void QMenuBar_setNativeMenuBar(void* menuBar, bool native) {
    static_cast<QMenuBarBind*>(menuBar)->setNativeMenuBar(native);
}

bool QMenuBar_isNativeMenuBar(void* menuBar) {
    return static_cast<QMenuBarBind*>(menuBar)->isNativeMenuBar();
}

void QMenuBar_setCornerWidget(void* menuBar, void* widget, int corner) {
    static_cast<QMenuBarBind*>(menuBar)->setCornerWidget(
        static_cast<QWidget*>(widget),
        static_cast<Qt::Corner>(corner)
    );
}

void* QMenuBar_cornerWidget(void* menuBar, int corner) {
    return static_cast<QMenuBarBind*>(menuBar)->cornerWidget(static_cast<Qt::Corner>(corner));
}

void QMenuBar_setActionEnabled(void* menuBar, void* action, bool enabled) {
    static_cast<QAction*>(action)->setEnabled(enabled);
}

bool QMenuBar_isActionEnabled(void* menuBar, void* action) {
    return static_cast<QAction*>(action)->isEnabled();
}

void QMenuBar_setActionVisible(void* menuBar, void* action, bool visible) {
    static_cast<QAction*>(action)->setVisible(visible);
}

bool QMenuBar_isActionVisible(void* menuBar, void* action) {
    return static_cast<QAction*>(action)->isVisible();
}

void QMenuBar_setActionText(void* menuBar, void* action, const char* text) {
    static_cast<QAction*>(action)->setText(QString::fromUtf8(text));
}

const char* QMenuBar_actionText(void* menuBar, void* action) {
    QString text = static_cast<QAction*>(action)->text();
    return qstrdup(text.toUtf8().constData());
}

typedef void (*QMenuBar_TriggeredCallback)(void*, void*);
typedef void (*QMenuBar_HoveredCallback)(void*, void*);

void QMenuBar_setTriggeredCallback(void* menuBar, QMenuBar_TriggeredCallback callback) {
    static_cast<QMenuBarBind*>(menuBar)->setTriggeredCallback(callback);
}

void QMenuBar_setHoveredCallback(void* menuBar, QMenuBar_HoveredCallback callback) {
    static_cast<QMenuBarBind*>(menuBar)->setHoveredCallback(callback);
}

}
