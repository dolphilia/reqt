#include "QSplitterHandleBind.h"
#include "QSplitterHandleHandler.h"
#include <QPainter>
#include <QStyleOption>

QSplitterHandleBind::QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent)
    : QSplitterHandle(orientation, parent)
    , handler(new QSplitterHandleHandler(this)) {
    // QSplitterHandleには、mouse、pressed、releasedというシグナルが存在しないため、
    // 代わりにmouseMoveEvent、mousePressEvent、mouseReleaseEventをオーバーライドする
}

QSplitterHandleBind::~QSplitterHandleBind() {
    delete handler;
}

// Reimplemented Public Functions

QSize QSplitterHandleBind::sizeHint() const {
    return QSplitterHandle::sizeHint();
}

// Protected Functions

int QSplitterHandleBind::closestLegalPosition(int pos) {
    return QSplitterHandle::closestLegalPosition(pos);
}

void QSplitterHandleBind::moveSplitter(int pos) {
    QSplitterHandle::moveSplitter(pos);
}

// Callback

void QSplitterHandleBind::setMovedCallback(QSplitterHandle_MovedCallback callback) const {
    handler->setMovedCallback(callback);
}

void QSplitterHandleBind::setPressedCallback(QSplitterHandle_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QSplitterHandleBind::setReleasedCallback(QSplitterHandle_ReleasedCallback callback) const {
    handler->setReleasedCallback(callback);
}

void QSplitterHandleBind::setEventCallback(QSplitterHandle_EventCallback callback) const {
    handler->setEventCallback(callback);
}

void QSplitterHandleBind::setPaintCallback(QSplitterHandle_PaintCallback callback) const {
    handler->setPaintCallback(callback);
}

void QSplitterHandleBind::setResizeCallback(QSplitterHandle_ResizeCallback callback) const {
    handler->setResizeCallback(callback);
}

//  Reimplemented Protected Functions

bool QSplitterHandleBind::event(QEvent *event) {
    bool result = QSplitterHandle::event(event);
    return handler->onEvent(event) ? true : result;
}

void QSplitterHandleBind::paintEvent(QPaintEvent *event) {
    QSplitterHandle::paintEvent(event);
    handler->onPaint();
}

void QSplitterHandleBind::resizeEvent(QResizeEvent *event) {
    QSplitterHandle::resizeEvent(event);
    handler->onResize(event);
}

void QSplitterHandleBind::mouseMoveEvent(QMouseEvent *e) {
    QSplitterHandle::mouseMoveEvent(e);
    handler->onMoved();
}

void QSplitterHandleBind::mousePressEvent(QMouseEvent *e) {
    QSplitterHandle::mousePressEvent(e);
    handler->onPressed();
}

void QSplitterHandleBind::mouseReleaseEvent(QMouseEvent *e) {
    QSplitterHandle::mouseReleaseEvent(e);
    handler->onReleased();
}
