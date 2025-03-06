#include "QRectBind.h"

extern "C" {
//-- Public Functions
void QRect_delete(void* rect) {
    delete static_cast<QRectBind*>(rect);
}
// QRect()
void* QRect_create() {
    return new QRectBind();
}
// QRect(const QPoint &topLeft, const QPoint &bottomRight)
void* QRect_createWithTLBR(void* topLeft, void* bottomRight) {
    return new QRectBind(*static_cast<QPoint*>(topLeft), *static_cast<QPoint*>(bottomRight));
}
// QRect(const QPoint &topLeft, const QSize &size)
void* QRect_createWithTLSize(void* topLeft, void* size) {
    return new QRectBind(*static_cast<QPoint*>(topLeft), *static_cast<QSize*>(size));
}
// QRect(int x, int y, int width, int height)
void* QRect_createWithXYWH(int x, int y, int width, int height) {
    return new QRectBind(x, y, width, height);
}
// void adjust(int dx1, int dy1, int dx2, int dy2)

void QRect_adjust(void* rect, int dx1, int dy1, int dx2, int dy2) {
    static_cast<QRectBind*>(rect)->adjust(dx1, dy1, dx2, dy2);
}
// QRect adjusted(int dx1, int dy1, int dx2, int dy2) const

void* QRect_adjusted(void* rect, int dx1, int dy1, int dx2, int dy2) {
    return new QRect(static_cast<QRectBind*>(rect)->adjusted(dx1, dy1, dx2, dy2));
}
// int bottom() const

int QRect_bottom(void* rect) {
    return static_cast<QRectBind*>(rect)->bottom();
}
// QPoint bottomLeft() const

void* QRect_bottomLeft(void* rect) {
    return new QPoint(static_cast<QRectBind*>(rect)->bottomLeft());
}
// QPoint bottomRight() const

void* QRect_bottomRight(void* rect) {
    return new QPoint(static_cast<QRectBind*>(rect)->bottomRight());
}
// QPoint center() const

void* QRect_center(void* rect) {
    return new QPoint(static_cast<QRectBind*>(rect)->center());
}
// bool contains(const QPoint &point, bool proper = false) const

bool QRect_contains(void* rect, void* point, bool proper) {
    return static_cast<QRectBind*>(rect)->contains(*static_cast<QPoint*>(point), proper);
}
// bool contains(const QRect &rectangle, bool proper = false) const

bool QRect_containsRect(void* rect, void* rectangle, bool proper) {
    return static_cast<QRectBind*>(rect)->contains(*static_cast<QRect*>(rectangle), proper);
}
// bool contains(int x, int y) const

bool QRect_containsCoords(void* rect, int x, int y) {
    return static_cast<QRectBind*>(rect)->contains(x, y);
}
// bool contains(int x, int y, bool proper) const

bool QRect_containsCoordsProper(void* rect, int x, int y, bool proper) {
    return static_cast<QRectBind*>(rect)->contains(x, y, proper);
}
// void getCoords(int *x1, int *y1, int *x2, int *y2) const

void QRect_getCoords(void* rect, int* x1, int* y1, int* x2, int* y2) {
    static_cast<QRectBind*>(rect)->getCoords(x1, y1, x2, y2);
}
// void getRect(int *x, int *y, int *width, int *height) const

void QRect_getRect(void* rect, int* x, int* y, int* width, int* height) {
    static_cast<QRectBind*>(rect)->getRect(x, y, width, height);
}
// int height() const

int QRect_height(void* rect) {
    return static_cast<QRectBind*>(rect)->height();
}
// QRect intersected(const QRect &rectangle) const

void* QRect_intersected(void* rect, void* rectangle) {
    return new QRect(static_cast<QRectBind*>(rect)->intersected(*static_cast<QRect*>(rectangle)));
}
// bool intersects(const QRect &rectangle) const

bool QRect_intersects(void* rect, void* rectangle) {
    return static_cast<QRectBind*>(rect)->intersects(*static_cast<QRect*>(rectangle));
}
// bool isEmpty() const

bool QRect_isEmpty(void* rect) {
    return static_cast<QRectBind*>(rect)->isEmpty();
}
// bool isNull() const

bool QRect_isNull(void* rect) {
    return static_cast<QRectBind*>(rect)->isNull();
}
// bool isValid() const

bool QRect_isValid(void* rect) {
    return static_cast<QRectBind*>(rect)->isValid();
}
// int left() const

int QRect_left(void* rect) {
    return static_cast<QRectBind*>(rect)->left();
}
// QRect marginsAdded(const QMargins &margins) const

void* QRect_marginsAdded(void* rect, void* margins) {
    return new QRect(static_cast<QRectBind*>(rect)->marginsAdded(*static_cast<QMargins*>(margins)));
}
// QRect marginsRemoved(const QMargins &margins) const

void* QRect_marginsRemoved(void* rect, void* margins) {
    return new QRect(static_cast<QRectBind*>(rect)->marginsRemoved(*static_cast<QMargins*>(margins)));
}
// void moveBottom(int y)

void QRect_moveBottom(void* rect, int y) {
    static_cast<QRectBind*>(rect)->moveBottom(y);
}
// void moveBottomLeft(const QPoint &position)

void QRect_moveBottomLeft(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveBottomLeft(*static_cast<QPoint*>(position));
}
// void moveBottomRight(const QPoint &position)

void QRect_moveBottomRight(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveBottomRight(*static_cast<QPoint*>(position));
}
// void moveCenter(const QPoint &position)

void QRect_moveCenter(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveCenter(*static_cast<QPoint*>(position));
}
// void moveLeft(int x)

void QRect_moveLeft(void* rect, int x) {
    static_cast<QRectBind*>(rect)->moveLeft(x);
}
// void moveRight(int x)

void QRect_moveRight(void* rect, int x) {
    static_cast<QRectBind*>(rect)->moveRight(x);
}
// void moveTo(const QPoint &position)

void QRect_moveTo(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveTo(*static_cast<QPoint*>(position));
}
// void moveTo(int x, int y)

void QRect_moveToCoords(void* rect, int x, int y) {
    static_cast<QRectBind*>(rect)->moveTo(x, y);
}
// void moveTop(int y)

void QRect_moveTop(void* rect, int y) {
    static_cast<QRectBind*>(rect)->moveTop(y);
}
// void moveTopLeft(const QPoint &position)

void QRect_moveTopLeft(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveTopLeft(*static_cast<QPoint*>(position));
}
// void moveTopRight(const QPoint &position)

void QRect_moveTopRight(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->moveTopRight(*static_cast<QPoint*>(position));
}
// QRect normalized() const

void* QRect_normalized(void* rect) {
    return new QRect(static_cast<QRectBind*>(rect)->normalized());
}
// int right() const

int QRect_right(void* rect) {
    return static_cast<QRectBind*>(rect)->right();
}
// void setBottom(int y)

void QRect_setBottom(void* rect, int y) {
    static_cast<QRectBind*>(rect)->setBottom(y);
}
// void setBottomLeft(const QPoint &position)

void QRect_setBottomLeft(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->setBottomLeft(*static_cast<QPoint*>(position));
}
// void setBottomRight(const QPoint &position)

void QRect_setBottomRight(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->setBottomRight(*static_cast<QPoint*>(position));
}
// void setCoords(int x1, int y1, int x2, int y2)

void QRect_setCoords(void* rect, int x1, int y1, int x2, int y2) {
    static_cast<QRectBind*>(rect)->setCoords(x1, y1, x2, y2);
}
// void setHeight(int height)

void QRect_setHeight(void* rect, int height) {
    static_cast<QRectBind*>(rect)->setHeight(height);
}
// void setLeft(int x)

void QRect_setLeft(void* rect, int x) {
    static_cast<QRectBind*>(rect)->setLeft(x);
}
// void setRect(int x, int y, int width, int height)

void QRect_setRect(void* rect, int x, int y, int width, int height) {
    static_cast<QRectBind*>(rect)->setRect(x, y, width, height);
}
// void setRight(int x)

void QRect_setRight(void* rect, int x) {
    static_cast<QRectBind*>(rect)->setRight(x);
}
// void setSize(const QSize &size)

void QRect_setSize(void* rect, void* size) {
    static_cast<QRectBind*>(rect)->setSize(*static_cast<QSize*>(size));
}
// void setTop(int y)

void QRect_setTop(void* rect, int y) {
    static_cast<QRectBind*>(rect)->setTop(y);
}
// void setTopLeft(const QPoint &position)

void QRect_setTopLeft(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->setTopLeft(*static_cast<QPoint*>(position));
}
// void setTopRight(const QPoint &position)

void QRect_setTopRight(void* rect, void* position) {
    static_cast<QRectBind*>(rect)->setTopRight(*static_cast<QPoint*>(position));
}
// void setWidth(int width)

void QRect_setWidth(void* rect, int width) {
    static_cast<QRectBind*>(rect)->setWidth(width);
}
// void setX(int x)

void QRect_setX(void* rect, int x) {
    static_cast<QRectBind*>(rect)->setX(x);
}
// void setY(int y)

void QRect_setY(void* rect, int y) {
    static_cast<QRectBind*>(rect)->setY(y);
}
// QSize size() const

void* QRect_size(void* rect) {
    return new QSize(static_cast<QRectBind*>(rect)->size());
}
// CGRect toCGRect() const
// (since 6.4) QRectF toRectF() const

void* QRect_toRectF(void* rect) {
    return new QRectF(static_cast<QRectBind*>(rect)->toRectF());
}
// int top() const

int QRect_top(void* rect) {
    return static_cast<QRectBind*>(rect)->top();
}
// QPoint topLeft() const

void* QRect_topLeft(void* rect) {
    return new QPoint(static_cast<QRectBind*>(rect)->topLeft());
}
// QPoint topRight() const

void* QRect_topRight(void* rect) {
    return new QPoint(static_cast<QRectBind*>(rect)->topRight());
}
// void translate(int dx, int dy)

void QRect_translateByXY(void* rect, int dx, int dy) {
    static_cast<QRectBind*>(rect)->translate(dx, dy);
}
// void translate(const QPoint &offset)

void QRect_translateWithOffset(void* rect, void* offset) {
    static_cast<QRectBind*>(rect)->translate(*static_cast<QPoint*>(offset));
}
// QRect translated(int dx, int dy) const

void* QRect_translatedByXY(void* rect, int dx, int dy) {
    return new QRect(static_cast<QRectBind*>(rect)->translated(dx, dy));
}
// QRect translated(const QPoint &offset) const

void* QRect_translatedWithOffset(void* rect, void* offset) {
    return new QRect(static_cast<QRectBind*>(rect)->translated(*static_cast<QPoint*>(offset)));
}
// QRect transposed() const

void* QRect_transposed(void* rect) {
    return new QRect(static_cast<QRectBind*>(rect)->transposed());
}
// QRect united(const QRect &rectangle) const

void* QRect_united(void* rect, void* rectangle) {
    return new QRect(static_cast<QRectBind*>(rect)->united(*static_cast<QRect*>(rectangle)));
}
// int width() const

int QRect_width(void* rect) {
    return static_cast<QRectBind*>(rect)->width();
}
// int x() const

int QRect_x(void* rect) {
    return static_cast<QRectBind*>(rect)->x();
}
// int y() const

int QRect_y(void* rect) {
    return static_cast<QRectBind*>(rect)->y();
}
// QRect operator&(const QRect &rectangle) const

void* QRect_operatorAnd(void* rect, void* rectangle) {
    QRect result = static_cast<QRectBind*>(rect)->operator&(*static_cast<QRect*>(rectangle));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
// QRect & operator&=(const QRect &rectangle)

void* QRect_operatorAndAssign(void* rect, void* rectangle) {
    QRect result = static_cast<QRectBind*>(rect)->operator&=(*static_cast<QRect*>(rectangle));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
// QRect & operator+=(const QMargins &margins)

void* QRect_operatorAddAssign(void* rect, void* margins) {
    QRect result = static_cast<QRectBind*>(rect)->operator+=(*static_cast<QMargins*>(margins));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
// QRect & operator-=(const QMargins &margins)

void* QRect_operatorSubAssign(void* rect, void* margins) {
    QRect result = static_cast<QRectBind*>(rect)->operator-=(*static_cast<QMargins*>(margins));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
// QRect operator|(const QRect &rectangle) const

void* QRect_operatorOr(void* rect, void* rectangle) {
    QRect result = static_cast<QRectBind*>(rect)->operator|(*static_cast<QRect*>(rectangle));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
// QRect & operator|=(const QRect &rectangle)

void* QRect_operatorOrAssign(void* rect, void* rectangle) {
    QRect result = static_cast<QRectBind*>(rect)->operator|=(*static_cast<QRect*>(rectangle));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
//-- Static Public Members
// (since 6.0) QRect span(const QPoint &p1, const QPoint &p2)

void* QRect_span(void* p1, void* p2) {
    QRect result = QRectBind::span(*static_cast<QPoint*>(p1), *static_cast<QPoint*>(p2));
    QRectBind* newRect = new QRectBind(result.topLeft(), result.bottomRight());
    return newRect;
}
}