#include "c_q_scroll_area.h"
#include "bind_q_scroll_area.h"
#include "handler_scroll_area.h"

extern "C" {

void* QScrollArea_create(void* parent)
{
    return new BindQScrollArea(reinterpret_cast<QWidget*>(parent));
}

void QScrollArea_delete(void* scroll_area)
{
    delete static_cast<BindQScrollArea*>(scroll_area);
}

void QScrollArea_setWidget(void* scroll_area, void* widget)
{
    static_cast<BindQScrollArea*>(scroll_area)->setWidget(reinterpret_cast<QWidget*>(widget));
}

void* QScrollArea_widget(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->widget();
}

void* QScrollArea_takeWidget(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->takeWidget();
}

void* QScrollArea_viewport(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->viewport();
}

void QScrollArea_setHorizontalScrollBarPolicy(void* scroll_area, int policy)
{
    static_cast<BindQScrollArea*>(scroll_area)->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

int QScrollArea_horizontalScrollBarPolicy(void* scroll_area)
{
    return static_cast<int>(static_cast<BindQScrollArea*>(scroll_area)->horizontalScrollBarPolicy());
}

void QScrollArea_setVerticalScrollBarPolicy(void* scroll_area, int policy)
{
    static_cast<BindQScrollArea*>(scroll_area)->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

int QScrollArea_verticalScrollBarPolicy(void* scroll_area)
{
    return static_cast<int>(static_cast<BindQScrollArea*>(scroll_area)->verticalScrollBarPolicy());
}

void* QScrollArea_horizontalScrollBar(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->horizontalScrollBar();
}

void* QScrollArea_verticalScrollBar(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->verticalScrollBar();
}

void QScrollArea_setWidgetResizable(void* scroll_area, bool resizable)
{
    static_cast<BindQScrollArea*>(scroll_area)->setWidgetResizable(resizable);
}

bool QScrollArea_widgetResizable(void* scroll_area)
{
    return static_cast<BindQScrollArea*>(scroll_area)->widgetResizable();
}

void QScrollArea_setSizeAdjustPolicy(void* scroll_area, int policy)
{
    static_cast<BindQScrollArea*>(scroll_area)->setSizeAdjustPolicy(static_cast<QAbstractScrollArea::SizeAdjustPolicy>(policy));
}

int QScrollArea_sizeAdjustPolicy(void* scroll_area)
{
    return static_cast<int>(static_cast<BindQScrollArea*>(scroll_area)->sizeAdjustPolicy());
}

void QScrollArea_setAlignment(void* scroll_area, int alignment)
{
    static_cast<BindQScrollArea*>(scroll_area)->setAlignment(static_cast<Qt::Alignment>(alignment));
}

int QScrollArea_alignment(void* scroll_area)
{
    return static_cast<int>(static_cast<BindQScrollArea*>(scroll_area)->alignment());
}

void QScrollArea_ensureVisible(void* scroll_area, int x, int y, int xmargin, int ymargin)
{
    static_cast<BindQScrollArea*>(scroll_area)->ensureVisible(x, y, xmargin, ymargin);
}

void QScrollArea_ensureWidgetVisible(void* scroll_area, void* child_widget, int xmargin, int ymargin)
{
    static_cast<BindQScrollArea*>(scroll_area)->ensureWidgetVisible(reinterpret_cast<QWidget*>(child_widget), xmargin, ymargin);
}

void QScrollArea_setVerticalScrollBarValueChangedCallback(void* scroll_area, QScrollAreaVerticalScrollBarValueChangedCallback callback)
{
    BindQScrollArea* qscroll_area = static_cast<BindQScrollArea*>(scroll_area);
    ScrollAreaHandler* handler = qscroll_area->handler();
    if (!handler) {
        handler = new ScrollAreaHandler(qscroll_area);
        qscroll_area->setScrollAreaHandler(handler);
    }
    handler->setVerticalScrollBarValueChangedCallback(callback);
}

void QScrollArea_setHorizontalScrollBarValueChangedCallback(void* scroll_area, QScrollAreaHorizontalScrollBarValueChangedCallback callback)
{
    BindQScrollArea* qscroll_area = static_cast<BindQScrollArea*>(scroll_area);
    ScrollAreaHandler* handler = qscroll_area->handler();
    if (!handler) {
        handler = new ScrollAreaHandler(qscroll_area);
        qscroll_area->setScrollAreaHandler(handler);
    }
    handler->setHorizontalScrollBarValueChangedCallback(callback);
}

}
