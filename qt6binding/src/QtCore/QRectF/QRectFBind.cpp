#include "QRectFBind.h"

QRectFBind::QRectFBind() : QRectF() {
}

QRectFBind::QRectFBind(const QRect &rectangle) : QRectF(rectangle) {
}

QRectFBind::QRectFBind(const QPointF &topLeft, const QPointF &bottomRight) : QRectF(topLeft, bottomRight) {
}

QRectFBind::QRectFBind(const QPointF &topLeft, const QSize &size) : QRectF(topLeft, size) {
}

QRectFBind::QRectFBind(qreal x, qreal y, qreal width, qreal height) : QRectF(x, y, width, height) {
}

QRectFBind::~QRectFBind() {
}