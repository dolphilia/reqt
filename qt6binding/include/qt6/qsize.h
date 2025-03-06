#ifndef QSIZE_H
#define QSIZE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QSize_delete(void* size);
void* QSize_create(); // QSize()
void* QSize_createWithWH(int width, int height); // QSize(int width, int height)
void* QSize_boundedTo(void* size, void* otherSize); // QSize boundedTo(const QSize &otherSize) const
void* QSize_expandedTo(void* size, void* otherSize); // QSize expandedTo(const QSize &otherSize) const
void* QSize_grownBy(void* size, void* margins); // QSize grownBy(QMargins margins) const
int QSize_height(void* size); // int height() const
bool QSize_isEmpty(void* size); // bool isEmpty() const
bool QSize_isNull(void* size); // bool isNull() const
bool QSize_isValid(void* size); // bool isValid() const
void* QSize_rheight(void* size); // int & rheight()
void* QSize_rwidth(void* size); // int & rwidth()
void QSize_scaleByWH(void* size, int width, int height, int mode); // void scale(int width, int height, Qt::AspectRatioMode mode)
void QSize_scaleWithSize(void* size, void* otherSize, int mode); // void scale(const QSize &size, Qt::AspectRatioMode mode)
void* QSize_scaledByWH(void* size, int width, int height, int mode); // QSize scaled(int width, int height, Qt::AspectRatioMode mode) const
void* QSize_scaledWithSize(void* size, void* s, int mode); // QSize scaled(const QSize &s, Qt::AspectRatioMode mode) const
void QSize_setHeight(void* size, int height); // void setHeight(int height)
void QSize_setWidth(void* size, int width); // void setWidth(int width)
void* QSize_shrunkBy(void* size, void* margins); // QSize shrunkBy(QMargins margins) const
// CGSize toCGSize() const
void* QSize_toSizeF(void* size); // (since 6.4) QSizeF toSizeF() const
void QSize_transpose(void* size); // void transpose()
void* QSize_transposed(void* size); // QSize transposed() const
int QSize_width(void* size); // int width() const
void* QSize_operatorMulAssign(void* size, double factor); // QSize & operator*=(qreal factor)
void* QSize_operatorAddAssign(void* size1, void* size2); // QSize & operator+=(const QSize &size)
void* QSize_operatorSubAssign(void* size1, void* size2); // QSize & operator-=(const QSize &size)
void* QSize_operatorDivAssign(void* size, double divisor); // QSize & operator/=(qreal divisor)

#ifdef __cplusplus
}
#endif

#endif // QSIZE_H