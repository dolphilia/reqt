#include "QSplitterHandleHandler.h"
#include <QMouseEvent>

QSplitterHandleHandler::QSplitterHandleHandler(QObject* parent)
    : QObject(parent)
    , handle(nullptr)
    , doubleClickedCallback(nullptr)
    , movedCallback(nullptr)
{
}

void QSplitterHandleHandler::setSplitterHandle(QSplitterHandle* handle) {
    if (this->handle) {
        this->handle->removeEventFilter(this);
    }
    
    this->handle = handle;
    
    if (handle) {
        handle->installEventFilter(this);
    }
}

void QSplitterHandleHandler::setDoubleClickedCallback(SplitterHandleDoubleClickedCallback callback) {
    doubleClickedCallback = callback;
}

void QSplitterHandleHandler::setMovedCallback(SplitterHandleMovedCallback callback) {
    movedCallback = callback;
}

bool QSplitterHandleHandler::eventFilter(QObject* watched, QEvent* event) {
    if (watched == handle) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            if (doubleClickedCallback) {
                doubleClickedCallback(handle);
            }
            return true;
        } else if (event->type() == QEvent::MouseMove) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (movedCallback && (mouseEvent->buttons() & Qt::LeftButton)) {
                int pos = handle->orientation() == Qt::Horizontal ? 
                          mouseEvent->position().x() : mouseEvent->position().y();
                movedCallback(handle, pos);
            }
        }
    }
    return QObject::eventFilter(watched, event);
}
