#include "QPointFBind.h"

extern "C" {

//-- Public Functions

void QPointF_delete(void* point) {
    delete static_cast<QPointF*>(point);
}

// QPointF()

void* QPointF_create() {
    return new QPointFBind();
}

// QPointF(const QPoint &point)

void* QPointF_createWithPoint(void* point) {
    return new QPointFBind(static_cast<QPoint*>(point));
}

// QPointF(qreal xpos, qreal ypos)

void* QPointF_createWithXY(double x, double y) {
    return new QPointFBind(x, y);
}

// bool isNull() const

bool QPointF_isNull(void* point) {
    return static_cast<QPointF*>(point)->isNull();
}

// qreal manhattanLength() const

double QPointF_manhattanLength(void* point) {
    return static_cast<QPointF*>(point)->manhattanLength();
}

// qreal & rx()

double* QPointF_rx(void* point) {
    return &static_cast<QPointFBind*>(point)->rx();
}

// qreal & ry()

void* QPointF_ry(void* point) {
    return &static_cast<QPointFBind*>(point)->ry();
}

// void setX(qreal x)

void QPointF_setX(void* point, double x) {
    static_cast<QPointF*>(point)->setX(x);
}

// void setY(qreal y)

void QPointF_setY(void* point, double y) {
    static_cast<QPointF*>(point)->setY(y);
}

// CGPoint toCGPoint() const
// QPoint toPoint() const

void* QPointF_toPoint(void* point) {
    return new QPoint(static_cast<QPointF*>(point)->toPoint());
}

// QPointF transposed() const

void* QPointF_transposed(void* point) {
    return new QPointF(static_cast<QPointF*>(point)->transposed());
}

// qreal x() const

double QPointF_x(void* point) {
    return static_cast<QPointF*>(point)->x();
}

// qreal y() const

double QPointF_y(void* point) {
    return static_cast<QPointF*>(point)->y();
}

// QPointF & operator*=(qreal factor)

void* QPointF_operatorMulAssign(void* point, double factor) {
    QPointF result = static_cast<QPointFBind*>(point)->operator*=(factor);
    QPointFBind* newPoint = new QPointFBind(result.x(), result.y());
    return newPoint;
}

// QPointF & operator+=(const QPointF &point)

void* QPointF_operatorAddAssign(void* point1, void* point2) {
    QPointF result = static_cast<QPointFBind*>(point1)->operator+=(*static_cast<QPointFBind*>(point2));
    QPointFBind* newPoint = new QPointFBind(result.x(), result.y());
    return newPoint;
}

// QPointF & operator-=(const QPointF &point)

void* QPointF_operatorSubAssign(void* point1, void* point2) {
    QPointF result = static_cast<QPointFBind*>(point1)->operator-=(*static_cast<QPointFBind*>(point2));
    QPointFBind* newPoint = new QPointFBind(result.x(), result.y());
    return newPoint;
}

// QPointF & operator/=(qreal divisor)

void* QPointF_operatorDivAssign(void* point, double divisor) {
    QPointF result = static_cast<QPointFBind*>(point)->operator/=(divisor);
    QPointFBind* newPoint = new QPointFBind(result.x(), result.y());
    return newPoint;
}

//-- Static Public Members

// qreal dotProduct(const QPointF &p1, const QPointF &p2)

double QPointF_dotProduct(void* point1, void* point2) {
    return QPointFBind::dotProduct(*static_cast<QPointFBind*>(point1), *static_cast<QPointFBind*>(point2));
}

// QPointF fromCGPoint(CGPoint point)


}
