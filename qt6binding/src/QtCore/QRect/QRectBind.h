#ifndef QRECT_BIND_H
#define QRECT_BIND_H

#include <QRect>
#include <QPoint>
#include <QSize>

class QRectBind : public QRect {
public:
    explicit QRectBind();
    explicit QRectBind(const QPoint &topLeft, const QPoint &bottomRight);
    explicit QRectBind(const QPoint &topLeft, const QSize &size);
    explicit QRectBind(int x, int y, int width, int height);
    ~QRectBind();
};

#endif // QRECT_BIND_H