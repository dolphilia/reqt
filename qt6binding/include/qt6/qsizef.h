#ifndef QSIZEF_H
#define QSIZEF_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QSizeF_delete(void* size);
void* QSizeF_create(); // QSizeF()
void* QSizeF_createWithSize(void* size); // QSizeF(const QSize &size)
void* QSizeF_createWithWH(double width, double height); // QSizeF(qreal width, qreal height)
void* QSizeF_boundedTo(void* size, void* otherSize); // QSizeF boundedTo(const QSizeF &otherSize) const
void* QSizeF_expandedTo(void* size, void* otherSize); // QSizeF expandedTo(const QSizeF &otherSize) const
void* QSizeF_grownBy(void* size, void* margins); // QSizeF grownBy(QMarginsF margins) const
double QSizeF_height(void* size); // qreal height() const
bool QSizeF_isEmpty(void* size); // bool isEmpty() const
bool QSizeF_isNull(void* size); // bool isNull() const
bool QSizeF_isValid(void* size); // bool isValid() const
void* QSizeF_rheight(void* size); // qreal & rheight()
void* QSizeF_rwidth(void* size); // qreal & rwidth()
void QSizeF_scaleByWH(void* size, double width, double height, int mode); // void scale(qreal width, qreal height, Qt::AspectRatioMode mode)
void QSizeF_scaleWithSize(void* size, void* s, int mode); // void scale(const QSizeF &size, Qt::AspectRatioMode mode)
void* QSizeF_scaledByWH(void* size, double width, double height, int mode); // QSizeF scaled(qreal width, qreal height, Qt::AspectRatioMode mode) const
void* QSizeF_scaledWithSize(void* size, void* s, int mode); // QSizeF scaled(const QSizeF &s, Qt::AspectRatioMode mode) const
void QSizeF_setHeight(void* size, double height); // void setHeight(qreal height)
void QSizeF_setWidth(void* size, double width); // void setWidth(qreal width)
void* QSizeF_shrunkBy(void* size, void* margins); // QSizeF shrunkBy(QMarginsF margins) const
// CGSize toCGSize() const
void* QSizeF_toSize(void* size); // QSize toSize() const
void QSizeF_transpose(void* size); // void transpose()
void* QSizeF_transposed(void* size); // QSizeF transposed() const
double QSizeF_width(void* size); // qreal width() const
void* QSizeF_operatorMulAssign(void* size, double factor); // QSizeF & operator*=(qreal factor)
void* QSizeF_operatorAddAssign(void* size1, void* size2); // QSizeF & operator+=(const QSizeF &size)
void* QSizeF_operatorSubAssign(void* size1, void* size2); // QSizeF & operator-=(const QSizeF &size)
void* QSizeF_operatorDivAssign(void* size, double divisor); // QSizeF & operator/=(qreal divisor)
//-- Static Public Members
// QSizeF fromCGSize(CGSize size)

#ifdef __cplusplus
}
#endif

#endif // QSIZEF_H