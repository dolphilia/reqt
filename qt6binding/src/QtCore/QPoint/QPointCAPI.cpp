#include "QPointBind.h"

extern "C" {

//-- Public Functions

void QPoint_delete(void* point) {
    delete static_cast<QPointBind*>(point);
}

// QPoint()

void* QPoint_create() {
    return new QPointBind();
}

// QPoint(int xpos, int ypos)

void* QPoint_createWithXY(int x, int y) {
    return new QPointBind(x, y);
}

// bool isNull() const

bool QPoint_isNull(void* point) {
    return static_cast<QPointBind*>(point)->isNull();
}

// int manhattanLength() const

int QPoint_manhattanLength(void* point) {
    return static_cast<QPointBind*>(point)->manhattanLength();
}

// int & rx()

void* QPoint_rx(void* point) {
    return &static_cast<QPointBind*>(point)->rx();
}

// int & ry()

void* QPoint_ry(void* point) {
    return &static_cast<QPointBind*>(point)->ry();
}

// void setX(int x)

void QPoint_setX(void* point, int x) {
    static_cast<QPointBind*>(point)->setX(x);
}

// void setY(int y)

void QPoint_setY(void* point, int y) {
    static_cast<QPointBind*>(point)->setY(y);
}

// CGPoint toCGPoint() const
// (since 6.4) QPointF toPointF() const

void* QPoint_toPointF(void* point) {
    return new QPointF(static_cast<QPointBind*>(point)->toPointF());
}

// QPoint transposed() const

void* QPoint_transposed(void* point) {
    return new QPoint(static_cast<QPointBind*>(point)->transposed());
}

// int x() const

int QPoint_x(void* point) {
    return static_cast<QPointBind*>(point)->x();
}

// int y() const

int QPoint_y(void* point) {
    return static_cast<QPointBind*>(point)->y();
}

// QPoint & operator*=(double factor)

void* QPoint_operatorMulAssignDouble(void* point, double factor) {
    QPoint result = static_cast<QPointBind*>(point)->operator*=(factor);
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

// QPoint & operator*=(float factor)

void* QPoint_operatorMulAssignFloat(void* point, float factor) {
    QPoint result = static_cast<QPointBind*>(point)->operator*=(factor);
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

// QPoint & operator*=(int factor)

void* QPoint_operatorMulAssignInt(void* point, int factor) {
    QPoint result = static_cast<QPointBind*>(point)->operator*=(factor);
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

// QPoint & operator+=(const QPoint &point)

void* QPoint_operatorAddAssign(void* point1, void* point2) {
    QPoint result = static_cast<QPointBind*>(point1)->operator+=(*static_cast<QPointBind*>(point2));
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

// QPoint & operator-=(const QPoint &point)

void* QPoint_operatorSubAssign(void* point1, void* point2) {
    QPoint result = static_cast<QPointBind*>(point1)->operator-=(*static_cast<QPointBind*>(point2));
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

// QPoint & operator/=(qreal divisor)

void* QPoint_operatorDivAssign(void* point, double divisor) {
    QPoint result = static_cast<QPointBind*>(point)->operator/=(divisor);
    QPointBind* newPoint = new QPointBind(result.x(), result.y());
    return newPoint;
}

//-- Static Public Members

int QPoint_dotProduct(void* point1, void* point2) {
    return QPointBind::dotProduct(*static_cast<QPointBind*>(point1), *static_cast<QPointBind*>(point2));
}

}