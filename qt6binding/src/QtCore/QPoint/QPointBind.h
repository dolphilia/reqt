#ifndef QPOINT_BIND_H
#define QPOINT_BIND_H

#include <QPoint>
#include <QPointF>

class QPointBind : public QPoint {
public:
    explicit QPointBind();
    explicit QPointBind(int x, int y);
    ~QPointBind();
};

#endif // QPOINT_BIND_H
