// explicit QRectBind();
// explicit QRectBind(const QPoint &topLeft, const QPoint &bottomRight);
// explicit QRectBind(const QPoint &topLeft, const QSize &size);
// explicit QRectBind(int x, int y, int width, int height);

#include "QRectBind.h"

QRectBind::QRectBind() : QRect() {
}

QRectBind::QRectBind(const QPoint &topLeft, const QPoint &bottomRight) : QRect(topLeft, bottomRight) {
}

QRectBind::QRectBind(const QPoint &topLeft, const QSize &size) : QRect(topLeft, size) {
}

QRectBind::QRectBind(int x, int y, int width, int height) : QRect(x, y, width, height) {
}

QRectBind::~QRectBind() {
}