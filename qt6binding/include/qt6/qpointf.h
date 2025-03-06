#ifndef QPOINTF_C_H
#define QPOINTF_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QPointF_delete(void* point);
void* QPointF_create(); // QPointF()
void* QPointF_createWithPoint(void* point); // QPointF(const QPoint &point)
void* QPointF_createWithXY(double x, double y); // QPointF(qreal xpos, qreal ypos)
bool QPointF_isNull(void* point); // bool isNull() const
double QPointF_manhattanLength(void* point); // qreal manhattanLength() const
double* QPointF_rx(void* point); // qreal & rx()
void* QPointF_ry(void* point); // qreal & ry()
void QPointF_setX(void* point, double x); // void setX(qreal x)
void QPointF_setY(void* point, double y); // void setY(qreal y)
// CGPoint toCGPoint() const
void* QPointF_toPoint(void* point); // QPoint toPoint() const
void* QPointF_transposed(void* point); // QPointF transposed() const
double QPointF_x(void* point); // qreal x() const
double QPointF_y(void* point); // qreal y() const
void* QPointF_operatorMulAssign(void* point, double factor); // QPointF & operator*=(qreal factor)
void* QPointF_operatorAddAssign(void* point1, void* point2); // QPointF & operator+=(const QPointF &point)
void* QPointF_operatorSubAssign(void* point1, void* point2); // QPointF & operator-=(const QPointF &point)
void* QPointF_operatorDivAssign(void* point, double divisor); // QPointF & operator/=(qreal divisor)
//-- Static Public Members
double QPointF_dotProduct(void* point1, void* point2); // qreal dotProduct(const QPointF &p1, const QPointF &p2)
// QPointF fromCGPoint(CGPoint point)

#ifdef __cplusplus
}
#endif

#endif // QPOINTF_C_H
