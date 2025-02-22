#include "bind_q_mdi_area.h"
#include "c_q_mdi_area.h"
#include <QBrush>

QMdiAreaBind::QMdiAreaBind(QWidget* parent)
    : QMdiArea(parent)
    , handler(new MdiAreaHandler(this))
{
    connect(this, &QMdiArea::subWindowActivated, handler, &MdiAreaHandler::onSubWindowActivated);
    handler->setMdiArea(this);
}

QMdiAreaBind::~QMdiAreaBind() {
    delete handler;
}

void QMdiAreaBind::setSubWindowActivatedCallback(void (*callback)(void*, void*)) {
    handler->setSubWindowActivatedCallback(callback);
}

extern "C" {

void* QMdiArea_create(void* parent) {
    return new QMdiAreaBind(static_cast<QWidget*>(parent));
}

void QMdiArea_delete(void* mdiArea) {
    delete static_cast<QMdiAreaBind*>(mdiArea);
}

void* QMdiArea_addSubWindow(void* mdiArea, void* widget) {
    return static_cast<QMdiAreaBind*>(mdiArea)->addSubWindow(static_cast<QWidget*>(widget));
}

void QMdiArea_removeSubWindow(void* mdiArea, void* widget) {
    static_cast<QMdiAreaBind*>(mdiArea)->removeSubWindow(static_cast<QWidget*>(widget));
}

void* QMdiArea_activeSubWindow(void* mdiArea) {
    return static_cast<QMdiAreaBind*>(mdiArea)->activeSubWindow();
}

void** QMdiArea_subWindowList(void* mdiArea, int* count) {
    QList<QMdiSubWindow*> list = static_cast<QMdiAreaBind*>(mdiArea)->subWindowList();
    *count = list.size();
    if (*count == 0) return nullptr;
    
    void** result = new void*[*count];
    for (int i = 0; i < *count; ++i) {
        result[i] = list[i];
    }
    return result;
}

void QMdiArea_freeSubWindowList(void** list) {
    delete[] list;
}

void QMdiArea_setViewMode(void* mdiArea, int mode) {
    static_cast<QMdiAreaBind*>(mdiArea)->setViewMode(static_cast<QMdiArea::ViewMode>(mode));
}

int QMdiArea_viewMode(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->viewMode());
}

void QMdiArea_tileSubWindows(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->tileSubWindows();
}

void QMdiArea_cascadeSubWindows(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->cascadeSubWindows();
}

void QMdiArea_closeActiveSubWindow(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->closeActiveSubWindow();
}

void QMdiArea_closeAllSubWindows(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->closeAllSubWindows();
}

void QMdiArea_activateNextSubWindow(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->activateNextSubWindow();
}

void QMdiArea_activatePreviousSubWindow(void* mdiArea) {
    static_cast<QMdiAreaBind*>(mdiArea)->activatePreviousSubWindow();
}

void QMdiArea_setHorizontalScrollBarPolicy(void* mdiArea, int policy) {
    static_cast<QMdiAreaBind*>(mdiArea)->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

void QMdiArea_setVerticalScrollBarPolicy(void* mdiArea, int policy) {
    static_cast<QMdiAreaBind*>(mdiArea)->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
}

int QMdiArea_horizontalScrollBarPolicy(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->horizontalScrollBarPolicy());
}

int QMdiArea_verticalScrollBarPolicy(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->verticalScrollBarPolicy());
}

void QMdiArea_setBackground(void* mdiArea, void* brush) {
    static_cast<QMdiAreaBind*>(mdiArea)->setBackground(*static_cast<QBrush*>(brush));
}

void QMdiArea_setActivationOrder(void* mdiArea, int order) {
    static_cast<QMdiAreaBind*>(mdiArea)->setActivationOrder(static_cast<QMdiArea::WindowOrder>(order));
}

int QMdiArea_activationOrder(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->activationOrder());
}

void QMdiArea_setTabsClosable(void* mdiArea, bool closable) {
    static_cast<QMdiAreaBind*>(mdiArea)->setTabsClosable(closable);
}

bool QMdiArea_tabsClosable(void* mdiArea) {
    return static_cast<QMdiAreaBind*>(mdiArea)->tabsClosable();
}

void QMdiArea_setTabsMovable(void* mdiArea, bool movable) {
    static_cast<QMdiAreaBind*>(mdiArea)->setTabsMovable(movable);
}

bool QMdiArea_tabsMovable(void* mdiArea) {
    return static_cast<QMdiAreaBind*>(mdiArea)->tabsMovable();
}

void QMdiArea_setTabShape(void* mdiArea, int shape) {
    static_cast<QMdiAreaBind*>(mdiArea)->setTabShape(static_cast<QTabWidget::TabShape>(shape));
}

int QMdiArea_tabShape(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->tabShape());
}

void QMdiArea_setTabPosition(void* mdiArea, int position) {
    static_cast<QMdiAreaBind*>(mdiArea)->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
}

int QMdiArea_tabPosition(void* mdiArea) {
    return static_cast<int>(static_cast<QMdiAreaBind*>(mdiArea)->tabPosition());
}

void QMdiArea_setSubWindowActivatedCallback(void* mdiArea, QMdiAreaSubWindowActivatedCallback callback) {
    static_cast<QMdiAreaBind*>(mdiArea)->setSubWindowActivatedCallback(callback);
}

}
