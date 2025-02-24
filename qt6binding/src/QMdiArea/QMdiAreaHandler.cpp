#include "QMdiAreaHandler.h"

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

void MdiAreaHandler::setSubWindowActivatedCallback(SubWindowActivatedCallback callback) {
    this->callback = callback;
}

void MdiAreaHandler::onSubWindowActivated(QMdiSubWindow* window) {
    if (callback && mdiArea) {
        callback(mdiArea, window);
    }
}
