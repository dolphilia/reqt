#ifndef QPOINT_C_H
#define QPOINT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QPoint_delete(void* point);
void* QPoint_create(); // QPoint()
void* QPoint_createWithXY(int x, int y); // QPoint(int xpos, int ypos)
bool QPoint_isNull(void* point); // bool isNull() const
int QPoint_manhattanLength(void* point); // int manhattanLength() const
void* QPoint_rx(void* point); // int & rx()
void* QPoint_ry(void* point); // int & ry()
void QPoint_setX(void* point, int x); // void setX(int x)
void QPoint_setY(void* point, int y); // void setY(int y)
// CGPoint toCGPoint() const
void* QPoint_toPointF(void* point); // (since 6.4) QPointF toPointF() const
void* QPoint_transposed(void* point); // QPoint transposed() const
int QPoint_x(void* point); // int x() const
int QPoint_y(void* point); // int y() const
void* QPoint_operatorMulAssignDouble(void* point, double factor); // QPoint & operator*=(double factor)
void* QPoint_operatorMulAssignFloat(void* point, float factor); // QPoint & operator*=(float factor)
void* QPoint_operatorMulAssignInt(void* point, int factor); // QPoint & operator*=(int factor)
void* QPoint_operatorAddAssign(void* point1, void* point2); // QPoint & operator+=(const QPoint &point)
void* QPoint_operatorSubAssign(void* point1, void* point2); // QPoint & operator-=(const QPoint &point)
void* QPoint_operatorDivAssign(void* point, double divisor); // QPoint & operator/=(qreal divisor)
//-- Static Public Members
int QPoint_dotProduct(void* point1, void* point2);

#ifdef __cplusplus
}
#endif

#endif // QPOINT_C_H
