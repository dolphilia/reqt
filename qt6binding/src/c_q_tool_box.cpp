#include "c_q_tool_box.h"
#include "bind_q_tool_box.h"
#include "handler_tool_box.h"
#include <QString>

extern "C" {

void* QToolBox_create(void* parent)
{
    return new BindQToolBox(reinterpret_cast<QWidget*>(parent));
}

void QToolBox_delete(void* tool_box)
{
    delete static_cast<BindQToolBox*>(tool_box);
}

int QToolBox_addItem(void* tool_box, void* widget, const char* text)
{
    return static_cast<BindQToolBox*>(tool_box)->addItem(
        static_cast<QWidget*>(widget),
        QString::fromUtf8(text)
    );
}

int QToolBox_insertItem(void* tool_box, int index, void* widget, const char* text)
{
    return static_cast<BindQToolBox*>(tool_box)->insertItem(
        index,
        static_cast<QWidget*>(widget),
        QString::fromUtf8(text)
    );
}

void QToolBox_removeItem(void* tool_box, int index)
{
    static_cast<BindQToolBox*>(tool_box)->removeItem(index);
}

int QToolBox_currentIndex(void* tool_box)
{
    return static_cast<BindQToolBox*>(tool_box)->currentIndex();
}

void QToolBox_setCurrentIndex(void* tool_box, int index)
{
    static_cast<BindQToolBox*>(tool_box)->setCurrentIndex(index);
}

void* QToolBox_currentWidget(void* tool_box)
{
    return static_cast<BindQToolBox*>(tool_box)->currentWidget();
}

void QToolBox_setCurrentWidget(void* tool_box, void* widget)
{
    static_cast<BindQToolBox*>(tool_box)->setCurrentWidget(static_cast<QWidget*>(widget));
}

const char* QToolBox_itemText(void* tool_box, int index)
{
    return static_cast<BindQToolBox*>(tool_box)->itemText(index).toUtf8().constData();
}

void QToolBox_setItemText(void* tool_box, int index, const char* text)
{
    static_cast<BindQToolBox*>(tool_box)->setItemText(index, QString::fromUtf8(text));
}

const char* QToolBox_itemToolTip(void* tool_box, int index)
{
    return static_cast<BindQToolBox*>(tool_box)->itemToolTip(index).toUtf8().constData();
}

void QToolBox_setItemToolTip(void* tool_box, int index, const char* toolTip)
{
    static_cast<BindQToolBox*>(tool_box)->setItemToolTip(index, QString::fromUtf8(toolTip));
}

bool QToolBox_isItemEnabled(void* tool_box, int index)
{
    return static_cast<BindQToolBox*>(tool_box)->isItemEnabled(index);
}

void QToolBox_setItemEnabled(void* tool_box, int index, bool enabled)
{
    static_cast<BindQToolBox*>(tool_box)->setItemEnabled(index, enabled);
}

int QToolBox_count(void* tool_box)
{
    return static_cast<BindQToolBox*>(tool_box)->count();
}

void* QToolBox_widget(void* tool_box, int index)
{
    return static_cast<BindQToolBox*>(tool_box)->widget(index);
}

int QToolBox_indexOf(void* tool_box, void* widget)
{
    return static_cast<BindQToolBox*>(tool_box)->indexOf(static_cast<QWidget*>(widget));
}

void QToolBox_setCurrentChangedCallback(void* tool_box, QToolBoxCurrentChangedCallback callback)
{
    BindQToolBox* toolBox = static_cast<BindQToolBox*>(tool_box);
    ToolBoxHandler* handler = toolBox->handler();
    if (!handler) {
        handler = new ToolBoxHandler(toolBox);
        toolBox->setToolBoxHandler(handler);
    }
    handler->setCurrentChangedCallback(callback);
}

}
