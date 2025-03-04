#include "QScrollAreaBind.h"

extern "C" {

void* QScrollArea_create(void* parent) {
    return new QScrollAreaBind(static_cast<QWidget*>(parent));
}

void QScrollArea_delete(void* scrollArea) {
    delete static_cast<QScrollAreaBind*>(scrollArea);
}

void QScrollArea_setWidget(void* scrollArea, void* widget) {
    static_cast<QScrollAreaBind*>(scrollArea)->setWidget(static_cast<QWidget*>(widget));
}

void* QScrollArea_widget(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->widget();
}

void* QScrollArea_takeWidget(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->takeWidget();
}

void* QScrollArea_viewport(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->viewport();
}

void QScrollArea_setHorizontalScrollBarPolicy(void* scrollArea, int policy) {
    static_cast<QScrollAreaBind*>(scrollArea)->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

int QScrollArea_horizontalScrollBarPolicy(void* scrollArea) {
    return static_cast<int>(static_cast<QScrollAreaBind*>(scrollArea)->horizontalScrollBarPolicy());
}

void QScrollArea_setVerticalScrollBarPolicy(void* scrollArea, int policy) {
    static_cast<QScrollAreaBind*>(scrollArea)->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

int QScrollArea_verticalScrollBarPolicy(void* scrollArea) {
    return static_cast<int>(static_cast<QScrollAreaBind*>(scrollArea)->verticalScrollBarPolicy());
}

void* QScrollArea_horizontalScrollBar(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->horizontalScrollBar();
}

void* QScrollArea_verticalScrollBar(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->verticalScrollBar();
}

void QScrollArea_setWidgetResizable(void* scrollArea, bool resizable) {
    static_cast<QScrollAreaBind*>(scrollArea)->setWidgetResizable(resizable);
}

bool QScrollArea_widgetResizable(void* scrollArea) {
    return static_cast<QScrollAreaBind*>(scrollArea)->widgetResizable();
}

void QScrollArea_setSizeAdjustPolicy(void* scrollArea, int policy) {
    static_cast<QScrollAreaBind*>(scrollArea)->setSizeAdjustPolicy(static_cast<QAbstractScrollArea::SizeAdjustPolicy>(policy));
}

int QScrollArea_sizeAdjustPolicy(void* scrollArea) {
    return static_cast<int>(static_cast<QScrollAreaBind*>(scrollArea)->sizeAdjustPolicy());
}

void QScrollArea_setAlignment(void* scrollArea, int alignment) {
    static_cast<QScrollAreaBind*>(scrollArea)->setAlignment(static_cast<Qt::Alignment>(alignment));
}

int QScrollArea_alignment(void* scrollArea) {
    return static_cast<int>(static_cast<QScrollAreaBind*>(scrollArea)->alignment());
}

void QScrollArea_ensureVisible(void* scrollArea, int x, int y, int xmargin, int ymargin) {
    static_cast<QScrollAreaBind*>(scrollArea)->ensureVisible(x, y, xmargin, ymargin);
}

void QScrollArea_ensureWidgetVisible(void* scrollArea, void* childWidget, int xmargin, int ymargin) {
    static_cast<QScrollAreaBind*>(scrollArea)->ensureWidgetVisible(static_cast<QWidget*>(childWidget), xmargin, ymargin);
}

typedef void (*QScrollArea_VerticalScrollBarValueChangedCallback)(void*, int);
typedef void (*QScrollArea_HorizontalScrollBarValueChangedCallback)(void*, int);

void QScrollArea_setVerticalScrollBarValueChangedCallback(void* scrollArea, QScrollArea_VerticalScrollBarValueChangedCallback callback) {
    static_cast<QScrollAreaBind*>(scrollArea)->setVerticalScrollBarValueChangedCallback(callback);
}

void QScrollArea_setHorizontalScrollBarValueChangedCallback(void* scrollArea, QScrollArea_HorizontalScrollBarValueChangedCallback callback) {
    static_cast<QScrollAreaBind*>(scrollArea)->setHorizontalScrollBarValueChangedCallback(callback);
}

}
