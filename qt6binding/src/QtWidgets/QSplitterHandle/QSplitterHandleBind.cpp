#include "QSplitterHandleBind.h"
#include "QSplitterHandleHandler.h"
#include <QMouseEvent>

QSplitterHandleBind::QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent)
    : QSplitterHandle(orientation, parent)
    , handler(new QSplitterHandleHandler(this)) {
    // QSplitterHandleには、mouse、pressed、releasedというシグナルが存在しないため、
    // 代わりにmouseMoveEvent、mousePressEvent、mouseReleaseEventをオーバーライドする
}

QSplitterHandleBind::~QSplitterHandleBind() {
    delete handler;
}

void QSplitterHandleBind::setMovedCallback(QSplitterHandle_MovedCallback callback) const {
    handler->setMovedCallback(callback);
}

void QSplitterHandleBind::setPressedCallback(QSplitterHandle_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QSplitterHandleBind::setReleasedCallback(QSplitterHandle_ReleasedCallback callback) const {
    handler->setReleasedCallback(callback);
}

bool QSplitterHandleBind::opaqueResize() const {
    return splitter() ? splitter()->opaqueResize() : false;
}

void QSplitterHandleBind::setOpaqueResize(bool opaque) {
    // QSplitterHandleの親であるQSplitterのopaqueResizeを設定する
    if (splitter()) {
        splitter()->setOpaqueResize(opaque);
    }
}

void QSplitterHandleBind::mouseMoveEvent(QMouseEvent *e) {
    // 親クラスのイベントハンドラを呼び出す
    QSplitterHandle::mouseMoveEvent(e);
    // ハンドラのコールバックを呼び出す
    handler->onMoved();
}

void QSplitterHandleBind::mousePressEvent(QMouseEvent *e) {
    // 親クラスのイベントハンドラを呼び出す
    QSplitterHandle::mousePressEvent(e);
    // ハンドラのコールバックを呼び出す
    handler->onPressed();
}

void QSplitterHandleBind::mouseReleaseEvent(QMouseEvent *e) {
    // 親クラスのイベントハンドラを呼び出す
    QSplitterHandle::mouseReleaseEvent(e);
    // ハンドラのコールバックを呼び出す
    handler->onReleased();
}
