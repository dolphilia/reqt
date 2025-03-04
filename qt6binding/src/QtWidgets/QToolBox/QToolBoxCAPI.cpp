#include "QToolBoxBind.h"

extern "C" {

void* QToolBox_create(void* parent) {
    return new QToolBoxBind(static_cast<QWidget*>(parent));
}

void QToolBox_delete(void* toolbox) {
    delete static_cast<QToolBoxBind*>(toolbox);
}

int QToolBox_addItem(void* toolbox, void* widget, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QToolBoxBind*>(toolbox)->addItem(static_cast<QWidget*>(widget), qstr);
}

int QToolBox_insertItem(void* toolbox, int index, void* widget, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    return static_cast<QToolBoxBind*>(toolbox)->insertItem(index, static_cast<QWidget*>(widget), qstr);
}

void QToolBox_removeItem(void* toolbox, int index) {
    static_cast<QToolBoxBind*>(toolbox)->removeItem(index);
}

int QToolBox_currentIndex(void* toolbox) {
    return static_cast<QToolBoxBind*>(toolbox)->currentIndex();
}

void QToolBox_setCurrentIndex(void* toolbox, int index) {
    static_cast<QToolBoxBind*>(toolbox)->setCurrentIndex(index);
}

void* QToolBox_currentWidget(void* toolbox) {
    return static_cast<QToolBoxBind*>(toolbox)->currentWidget();
}

void QToolBox_setCurrentWidget(void* toolbox, void* widget) {
    static_cast<QToolBoxBind*>(toolbox)->setCurrentWidget(static_cast<QWidget*>(widget));
}

const char* QToolBox_itemText(void* toolbox, int index) {
    return static_cast<QToolBoxBind*>(toolbox)->itemText(index).toUtf8().constData();
}

void QToolBox_setItemText(void* toolbox, int index, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QToolBoxBind*>(toolbox)->setItemText(index, qstr);
}

const char* QToolBox_itemToolTip(void* toolbox, int index) {
    return static_cast<QToolBoxBind*>(toolbox)->itemToolTip(index).toUtf8().constData();
}

void QToolBox_setItemToolTip(void* toolbox, int index, const char* toolTip) {
    const QString qstr = QString::fromUtf8(toolTip);
    static_cast<QToolBoxBind*>(toolbox)->setItemToolTip(index, qstr);
}

bool QToolBox_isItemEnabled(void* toolbox, int index) {
    return static_cast<QToolBoxBind*>(toolbox)->isItemEnabled(index);
}

void QToolBox_setItemEnabled(void* toolbox, int index, bool enabled) {
    static_cast<QToolBoxBind*>(toolbox)->setItemEnabled(index, enabled);
}

int QToolBox_count(void* toolbox) {
    return static_cast<QToolBoxBind*>(toolbox)->count();
}

void* QToolBox_widget(void* toolbox, int index) {
    return static_cast<QToolBoxBind*>(toolbox)->widget(index);
}

int QToolBox_indexOf(void* toolbox, void* widget) {
    return static_cast<QToolBoxBind*>(toolbox)->indexOf(static_cast<QWidget*>(widget));
}

typedef void (*QToolBox_CurrentChangedCallback)(void*, int);

void QToolBox_setCurrentChangedCallback(void* toolbox, QToolBox_CurrentChangedCallback callback) {
    static_cast<QToolBoxBind*>(toolbox)->setCurrentChangedCallback(callback);
}

}
