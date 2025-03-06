#ifndef QRECT_H
#define QRECT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QRect_delete(void* rect);
void* QRect_create(); // QRect()
void* QRect_create_2(void* topLeft, void* bottomRight); // QRect(const QPoint &topLeft, const QPoint &bottomRight)
void* QRect_create_3(void* topLeft, void* size); // QRect(const QPoint &topLeft, const QSize &size)
void* QRect_create_4(int x, int y, int width, int height); // QRect(int x, int y, int width, int height)
void QRect_adjust(void* rect, int dx1, int dy1, int dx2, int dy2); // void adjust(int dx1, int dy1, int dx2, int dy2)
void* QRect_adjusted(void* rect, int dx1, int dy1, int dx2, int dy2); // QRect adjusted(int dx1, int dy1, int dx2, int dy2) const
int QRect_bottom(void* rect); // int bottom() const
void* QRect_bottomLeft(void* rect); // QPoint bottomLeft() const
void* QRect_bottomRight(void* rect); // QPoint bottomRight() const
void* QRect_center(void* rect); // QPoint center() const
bool QRect_contains(void* rect, void* point, bool proper); // bool contains(const QPoint &point, bool proper = false) const
bool QRect_containsRect(void* rect, void* rectangle, bool proper); // bool contains(const QRect &rectangle, bool proper = false) const
bool QRect_containsCoords(void* rect, int x, int y); // bool contains(int x, int y) const
bool QRect_containsCoordsProper(void* rect, int x, int y, bool proper); // bool contains(int x, int y, bool proper) const
void QRect_getCoords(void* rect, int* x1, int* y1, int* x2, int* y2); // void getCoords(int *x1, int *y1, int *x2, int *y2) const
void QRect_getRect(void* rect, int* x, int* y, int* width, int* height); // void getRect(int *x, int *y, int *width, int *height) const
int QRect_height(void* rect); // int height() const
void* QRect_intersected(void* rect, void* rectangle); // QRect intersected(const QRect &rectangle) const
bool QRect_intersects(void* rect, void* rectangle); // bool intersects(const QRect &rectangle) const
bool QRect_isEmpty(void* rect); // bool isEmpty() const
bool QRect_isNull(void* rect); // bool isNull() const
bool QRect_isValid(void* rect); // bool isValid() const
int QRect_left(void* rect); // int left() const
void* QRect_marginsAdded(void* rect, void* margins); // QRect marginsAdded(const QMargins &margins) const
void* QRect_marginsRemoved(void* rect, void* margins); // QRect marginsRemoved(const QMargins &margins) const
void QRect_moveBottom(void* rect, int y); // void moveBottom(int y)
void QRect_moveBottomLeft(void* rect, void* position); // void moveBottomLeft(const QPoint &position)
void QRect_moveBottomRight(void* rect, void* position); // void moveBottomRight(const QPoint &position)
void QRect_moveCenter(void* rect, void* position); // void moveCenter(const QPoint &position)
void QRect_moveLeft(void* rect, int x); // void moveLeft(int x)
void QRect_moveRight(void* rect, int x); // void moveRight(int x)
void QRect_moveTo(void* rect, void* position); // void moveTo(const QPoint &position)
void QRect_moveToCoords(void* rect, int x, int y); // void moveTo(int x, int y)
void QRect_moveTop(void* rect, int y); // void moveTop(int y)
void QRect_moveTopLeft(void* rect, void* position); // void moveTopLeft(const QPoint &position)
void QRect_moveTopRight(void* rect, void* position); // void moveTopRight(const QPoint &position)
void* QRect_normalized(void* rect); // QRect normalized() const
int QRect_right(void* rect); // int right() const
void QRect_setBottom(void* rect, int y); // void setBottom(int y)
void QRect_setBottomLeft(void* rect, void* position); // void setBottomLeft(const QPoint &position)
void QRect_setBottomRight(void* rect, void* position); // void setBottomRight(const QPoint &position)
void QRect_setCoords(void* rect, int x1, int y1, int x2, int y2); // void setCoords(int x1, int y1, int x2, int y2)
void QRect_setHeight(void* rect, int height); // void setHeight(int height)
void QRect_setLeft(void* rect, int x); // void setLeft(int x)
void QRect_setRect(void* rect, int x, int y, int width, int height); // void setRect(int x, int y, int width, int height)
void QRect_setRight(void* rect, int x); // void setRight(int x)
void QRect_setSize(void* rect, void* size); // void setSize(const QSize &size)
void QRect_setTop(void* rect, int y); // void setTop(int y)
void QRect_setTopLeft(void* rect, void* position); // void setTopLeft(const QPoint &position)
void QRect_setTopRight(void* rect, void* position); // void setTopRight(const QPoint &position)
void QRect_setWidth(void* rect, int width); // void setWidth(int width)
void QRect_setX(void* rect, int x); // void setX(int x)
void QRect_setY(void* rect, int y); // void setY(int y)
void* QRect_size(void* rect); // QSize size() const
// CGRect toCGRect() const
void* QRect_toRectF(void* rect); // (since 6.4) QRectF toRectF() const
int QRect_top(void* rect); // int top() const
void* QRect_topLeft(void* rect); // QPoint topLeft() const
void* QRect_topRight(void* rect); // QPoint topRight() const
void QRect_translate(void* rect, int dx, int dy); // void translate(int dx, int dy)
void QRect_translate_2(void* rect, void* offset); // void translate(const QPoint &offset)
void* QRect_translated(void* rect, int dx, int dy); // QRect translated(int dx, int dy) const
void* QRect_translated_2(void* rect, void* offset); // QRect translated(const QPoint &offset) const
void* QRect_transposed(void* rect); // QRect transposed() const
void* QRect_united(void* rect, void* rectangle); // QRect united(const QRect &rectangle) const
int QRect_width(void* rect); // int width() const
int QRect_x(void* rect); // int x() const
int QRect_y(void* rect); // int y() const
void* QRect_and(void* rect, void* rectangle); // QRect operator&(const QRect &rectangle) const
void* QRect_andAssign(void* rect, void* rectangle); // QRect & operator&=(const QRect &rectangle)
void* QRect_addAssign(void* rect, void* margins); // QRect & operator+=(const QMargins &margins)
void* QRect_subtractAssign(void* rect, void* margins); // QRect & operator-=(const QMargins &margins)
void* QRect_or(void* rect, void* rectangle); // QRect operator|(const QRect &rectangle) const
void* QRect_orAssign(void* rect, void* rectangle); // QRect & operator|=(const QRect &rectangle)
//-- Static Public Members
void* QRect_span(void* p1, void* p2); // (since 6.0) QRect span(const QPoint &p1, const QPoint &p2)

#ifdef __cplusplus
}
#endif

#endif // QRECT_H