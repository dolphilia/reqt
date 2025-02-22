#include "handler_mdi_area.h"

MdiAreaHandler::MdiAreaHandler(QObject* parent)
    : QObject(parent)
    , mdiArea(nullptr)
    , callback(nullptr)
{
}

void MdiAreaHandler::setMdiArea(QMdiArea* mdiArea) {
    this->mdiArea = mdiArea;
    connect(mdiArea, &QMdiArea::subWindowActivated, this, &MdiAreaHandler::onSubWindowActivated);
}

void MdiAreaHandler::setSubWindowActivatedCallback(void (*callback)(void*, void*)) {
    this->callback = callback;
}

void MdiAreaHandler::onSubWindowActivated(QMdiSubWindow* window) {
    if (callback && mdiArea) {
        callback(mdiArea, window);
    }
}
