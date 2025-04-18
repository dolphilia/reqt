#ifndef QRECTF_BIND_H
#define QRECTF_BIND_H

#include <QRectF>
#include <QPointF>
#include <QSize>

class QRectFBind : public QRectF {
public:
    explicit QRectFBind();
    explicit QRectFBind(const QRect &rectangle);
    explicit QRectFBind(const QPointF &topLeft, const QPointF &bottomRight);
    explicit QRectFBind(const QPointF &topLeft, const QSize &size);
    explicit QRectFBind(qreal x, qreal y, qreal width, qreal height);
    ~QRectFBind();
};

#endif // QRECTF_BIND_H