#include "QRectFBind.h"

extern "C" {
    //-- Public Functions
    // void	adjust(qreal dx1, qreal dy1, qreal dx2, qreal dy2)
    void QRectF_adjust(void* rect, double dx1, double dy1, double dx2, double dy2) {
        QRectFBind* rectBind = static_cast<QRectFBind*>(rect);
        rectBind->adjust(dx1, dy1, dx2, dy2);
    }
    // QRectF	adjusted(qreal dx1, qreal dy1, qreal dx2, qreal dy2) const
    void* QRectF_adjusted(void* rect, double dx1, double dy1, double dx2, double dy2) {
        const QRectF result = static_cast<QRectFBind*>(rect)->adjusted(dx1, dy1, dx2, dy2);
        return new QRectF(result);
    }
    // qreal	bottom() const
    double QRectF_bottom(void* rect) {
        return static_cast<QRectFBind*>(rect)->bottom();
    }
    // QPointF	bottomLeft() const
    void* QRectF_bottomLeft(void* rect) {
        const QPointF result = static_cast<QRectFBind*>(rect)->bottomLeft();
        return new QPointF(result);
    }
    // QPointF	bottomRight() const
    void* QRectF_bottomRight(void* rect) {
        const QPointF result = static_cast<QRectFBind*>(rect)->bottomRight();
        return new QPointF(result);
    }
    // QPointF	center() const
    void* QRectF_center(void* rect) {
        const QPointF result = static_cast<QRectFBind*>(rect)->center();
        return new QPointF(result);
    }
    // bool	contains(const QPointF &point) const
    bool QRectF_containsByPoint(void* rect, void* point) {
        return static_cast<QRectFBind*>(rect)->contains(*static_cast<QPointF*>(point));
    }
    // bool	contains(const QRectF &rectangle) const
    bool QRectF_containsByRectangle(void* rect, void* rectangle) {
        return static_cast<QRectFBind*>(rect)->contains(*static_cast<QRectF*>(rectangle));
    }
    // bool	contains(qreal x, qreal y) const
    bool QRectF_containsByXY(void* rect, double x, double y) {
        return static_cast<QRectFBind*>(rect)->contains(x, y);
    }
    // void	getCoords(qreal *x1, qreal *y1, qreal *x2, qreal *y2) const
    void QRectF_getCoords(void* rect, double* x1, double* y1, double* x2, double* y2) {
        static_cast<QRectFBind*>(rect)->getCoords(x1, y1, x2, y2);
    }
    // void	getRect(qreal *x, qreal *y, qreal *width, qreal *height) const
    void QRectF_getRect(void* rect, double* x, double* y, double* width, double* height) {
        static_cast<QRectFBind*>(rect)->getRect(x, y, width, height);
    }
    // qreal	height() const
    double QRectF_height(void* rect) {
        return static_cast<QRectFBind*>(rect)->height();
    }
    // QRectF	intersected(const QRectF &rectangle) const
    void* QRectF_intersected(void* rect, void* rectangle) {
        const QRectF result = static_cast<QRectFBind*>(rect)->intersected(*static_cast<QRectF*>(rectangle));
        return new QRectF(result);
    }
    // bool	intersects(const QRectF &rectangle) const
    bool QRectF_intersects(void* rect, void* rectangle) {
        return static_cast<QRectFBind*>(rect)->intersects(*static_cast<QRectF*>(rectangle));
    }
    // bool	isEmpty() const
    bool QRectF_isEmpty(void* rect) {
        return static_cast<QRectFBind*>(rect)->isEmpty();
    }
    // bool	isNull() const
    bool QRectF_isNull(void* rect) {
        return static_cast<QRectFBind*>(rect)->isNull();
    }
    // bool	isValid() const
    bool QRectF_isValid(void* rect) {
        return static_cast<QRectFBind*>(rect)->isValid();
    }
    // qreal	left() const
    double QRectF_left(void* rect) {
        return static_cast<QRectFBind*>(rect)->left();
    }
    // QRectF	marginsAdded(const QMarginsF &margins) const
    void* QRectF_marginsAdded(void* rect, void* margins) {
        const QRectF result = static_cast<QRectFBind*>(rect)->marginsAdded(*static_cast<QMarginsF*>(margins));
        return new QRectF(result);
    }
    // QRectF	marginsRemoved(const QMarginsF &margins) const
    void* QRectF_marginsRemoved(void* rect, void* margins) {
        const QRectF result = static_cast<QRectFBind*>(rect)->marginsRemoved(*static_cast<QMarginsF*>(margins));
        return new QRectF(result);
    }
    // void	moveBottom(qreal y)
    void QRectF_moveBottom(void* rect, double y) {
        static_cast<QRectFBind*>(rect)->moveBottom(y);
    }
    // void	moveBottomLeft(const QPointF &position)
    void QRectF_moveBottomLeft(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveBottomLeft(*static_cast<QPointF*>(position));
    }
    // void	moveBottomRight(const QPointF &position)
    void QRectF_moveBottomRight(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveBottomRight(*static_cast<QPointF*>(position));
    }
    // void	moveCenter(const QPointF &position)
    void QRectF_moveCenter(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveCenter(*static_cast<QPointF*>(position));
    }
    // void	moveLeft(qreal x)
    void QRectF_moveLeft(void* rect, double x) {
        static_cast<QRectFBind*>(rect)->moveLeft(x);
    }
    // void	moveRight(qreal x)
    void QRectF_moveRight(void* rect, double x) {
        static_cast<QRectFBind*>(rect)->moveRight(x);
    }
    // void	moveTo(qreal x, qreal y)
    void QRectF_moveTo(void* rect, double x, double y) {
        static_cast<QRectFBind*>(rect)->moveTo(x, y);
    }
    // void	moveTo(const QPointF &position)
    void QRectF_moveToPosition(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveTo(*static_cast<QPointF*>(position));
    }
    // void	moveTop(qreal y)
    void QRectF_moveTop(void* rect, double y) {
        static_cast<QRectFBind*>(rect)->moveTop(y);
    }
    // void	moveTopLeft(const QPointF &position)
    void QRectF_moveTopLeft(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveTopLeft(*static_cast<QPointF*>(position));
    }
    // void	moveTopRight(const QPointF &position)
    void QRectF_moveTopRight(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->moveTopRight(*static_cast<QPointF*>(position));
    }
    // QRectF	normalized() const
    void* QRectF_normalized(void* rect) {
        const QRectF result = static_cast<QRectFBind*>(rect)->normalized();
        return new QRectF(result);
    }
    // qreal	right() const
    double QRectF_right(void* rect) {
        return static_cast<QRectFBind*>(rect)->right();
    }
    // void	setBottom(qreal y)
    void QRectF_setBottom(void* rect, double y) {
        static_cast<QRectFBind*>(rect)->setBottom(y);
    }
    // void	setBottomLeft(const QPointF &position)
    void QRectF_setBottomLeft(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->setBottomLeft(*static_cast<QPointF*>(position));
    }
    // void	setBottomRight(const QPointF &position)
    void QRectF_setBottomRight(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->setBottomRight(*static_cast<QPointF*>(position));
    }
    // void	setCoords(qreal x1, qreal y1, qreal x2, qreal y2)
    void QRectF_setCoords(void* rect, double x1, double y1, double x2, double y2) {
        static_cast<QRectFBind*>(rect)->setCoords(x1, y1, x2, y2);
    }
    // void	setHeight(qreal height)
    void QRectF_setHeight(void* rect, double height) {
        static_cast<QRectFBind*>(rect)->setHeight(height);
    }
    // void	setLeft(qreal x)
    void QRectF_setLeft(void* rect, double x) {
        static_cast<QRectFBind*>(rect)->setLeft(x);
    }
    // void	setRect(qreal x, qreal y, qreal width, qreal height)
    void QRectF_setRect(void* rect, double x, double y, double width, double height) {
        static_cast<QRectFBind*>(rect)->setRect(x, y, width, height);
    }
    // void	setRight(qreal x)
    void QRectF_setRight(void* rect, double x) {
        static_cast<QRectFBind*>(rect)->setRight(x);
    }
    // void	setSize(const QSizeF &size)
    void QRectF_setSize(void* rect, void* size) {
        static_cast<QRectFBind*>(rect)->setSize(*static_cast<QSizeF*>(size));
    }
    // void	setTop(qreal y)
    void QRectF_setTop(void* rect, double y) {
        static_cast<QRectFBind*>(rect)->setTop(y);
    }
    // void	setTopLeft(const QPointF &position)
    void QRectF_setTopLeft(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->setTopLeft(*static_cast<QPointF*>(position));
    }
    // void	setTopRight(const QPointF &position)
    void QRectF_setTopRight(void* rect, void* position) {
        static_cast<QRectFBind*>(rect)->setTopRight(*static_cast<QPointF*>(position));
    }
    // void	setWidth(qreal width)
    void QRectF_setWidth(void* rect, double width) {
        static_cast<QRectFBind*>(rect)->setWidth(width);
    }
    // void	setX(qreal x)
    void QRectF_setX(void* rect, double x) {
        static_cast<QRectFBind*>(rect)->setX(x);
    }
    // void	setY(qreal y)
    void QRectF_setY(void* rect, double y) {
        static_cast<QRectFBind*>(rect)->setY(y);
    }
    // QSizeF	size() const
    void* QRectF_size(void* rect) {
        const QSizeF result = static_cast<QRectFBind*>(rect)->size();
        return new QSizeF(result);
    }
    // QRect	toAlignedRect() const
    void* QRectF_toAlignedRect(void* rect) {
        const QRect result = static_cast<QRectFBind*>(rect)->toAlignedRect();
        return new QRect(result);
    }
    // CGRect	toCGRect() const
    // (since 6.5) emscripten::val	toDOMRect() const
    // QRect	toRect() const
    void* QRectF_toRect(void* rect) {
        const QRect result = static_cast<QRectFBind*>(rect)->toRect();
        return new QRect(result);
    }
    // qreal	top() const
    double QRectF_top(void* rect) {
        return static_cast<QRectFBind*>(rect)->top();
    }
    // QPointF	topLeft() const
    void* QRectF_topLeft(void* rect) {
        const QPointF result = static_cast<QRectFBind*>(rect)->topLeft();
        return new QPointF(result);
    }
    // QPointF	topRight() const
    void* QRectF_topRight(void* rect) {
        const QPointF result = static_cast<QRectFBind*>(rect)->topRight();
        return new QPointF(result);
    }
    // void	translate(qreal dx, qreal dy)
    void QRectF_translateByXY(void* rect, double dx, double dy) {
        static_cast<QRectFBind*>(rect)->translate(dx, dy);
    }
    // void	translate(const QPointF &offset)
    void QRectF_translateByOffset(void* rect, void* offset) {
        static_cast<QRectFBind*>(rect)->translate(*static_cast<QPointF*>(offset));
    }
    // QRectF	translated(qreal dx, qreal dy) const
    void* QRectF_translatedByXY(void* rect, double dx, double dy) {
        const QRectF result = static_cast<QRectFBind*>(rect)->translated(dx, dy);
        return new QRectF(result);
    }
    // QRectF	translated(const QPointF &offset) const
    void* QRectF_translatedByOffset(void* rect, void* offset) {
        const QRectF result = static_cast<QRectFBind*>(rect)->translated(*static_cast<QPointF*>(offset));
        return new QRectF(result);
    }
    // QRectF	transposed() const
    void* QRectF_transposed(void* rect) {
        const QRectF result = static_cast<QRectFBind*>(rect)->transposed();
        return new QRectF(result);
    }
    // QRectF	united(const QRectF &rectangle) const
    void* QRectF_united(void* rect, void* rectangle) {
        const QRectF result = static_cast<QRectFBind*>(rect)->united(*static_cast<QRectF*>(rectangle));
        return new QRectF(result);
    }
    // qreal	width() const
    double QRectF_width(void* rect) {
        return static_cast<QRectFBind*>(rect)->width();
    }
    // qreal	x() const
    double QRectF_x(void* rect) {
        return static_cast<QRectFBind*>(rect)->x();
    }
    // qreal	y() const
    double QRectF_y(void* rect) {
        return static_cast<QRectFBind*>(rect)->y();
    }
    // QRectF	operator&(const QRectF &rectangle) const
    void* QRectF_operatorAnd(void* rect, void* rectangle) {
        const QRectF result = static_cast<QRectFBind*>(rect)->operator&(*static_cast<QRectF*>(rectangle));
        return new QRectF(result);
    }
    // QRectF &	operator&=(const QRectF &rectangle)
    void* QRectF_operatorAndAssign(void* rect, void* rectangle) {
        return &static_cast<QRectFBind*>(rect)->operator&=(*static_cast<QRectF*>(rectangle));
    }
    // QRectF &	operator+=(const QMarginsF &margins)
    void* QRectF_operatorAddAssign(void* rect, void* margins) {
        return &static_cast<QRectFBind*>(rect)->operator+=(*static_cast<QMarginsF*>(margins));
    }
    // QRectF &	operator-=(const QMarginsF &margins)
    void* QRectF_operatorSubAssign(void* rect, void* margins) {
        return &static_cast<QRectFBind*>(rect)->operator-=(*static_cast<QMarginsF*>(margins));
    }
    // QRectF	operator|(const QRectF &rectangle) const
    void* QRectF_operatorOr(void* rect, void* rectangle) {
        const QRectF result = static_cast<QRectFBind*>(rect)->operator|(*static_cast<QRectF*>(rectangle));
        return new QRectF(result);
    }
    // QRectF &	operator|=(const QRectF &rectangle)
    void* QRectF_operatorOrAssign(void* rect, void* rectangle) {
        return &static_cast<QRectFBind*>(rect)->operator|=(*static_cast<QRectF*>(rectangle));
    }
    //-- Static Public Members
    // QRectF	fromCGRect(CGRect rect)
    // (since 6.5) QRectF	fromDOMRect(emscripten::val domRect)
}