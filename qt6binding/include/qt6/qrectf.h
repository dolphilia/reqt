//
// Created by dolphilia on 25/04/18.
//

#ifndef QRECTF_H
#define QRECTF_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    //-- Public Functions
    void QRectF_adjust(void* rect, double dx1, double dy1, double dx2, double dy2); // void	adjust(qreal dx1, qreal dy1, qreal dx2, qreal dy2)
    void* QRectF_adjusted(void* rect, double dx1, double dy1, double dx2, double dy2); // QRectF	adjusted(qreal dx1, qreal dy1, qreal dx2, qreal dy2) const
    double QRectF_bottom(void* rect); // qreal	bottom() const
    void* QRectF_bottomLeft(void* rect); // QPointF	bottomLeft() const
    void* QRectF_bottomRight(void* rect); // QPointF	bottomRight() const
    void* QRectF_center(void* rect); // QPointF	center() const
    bool QRectF_containsByPoint(void* rect, void* point); // bool	contains(const QPointF &point) const
    bool QRectF_containsByRectangle(void* rect, void* rectangle); // bool	contains(const QRectF &rectangle) const
    bool QRectF_containsByXY(void* rect, double x, double y); // bool	contains(qreal x, qreal y) const
    void QRectF_getCoords(void* rect, double* x1, double* y1, double* x2, double* y2); // void	getCoords(qreal *x1, qreal *y1, qreal *x2, qreal *y2) const
    void QRectF_getRect(void* rect, double* x, double* y, double* width, double* height); // void	getRect(qreal *x, qreal *y, qreal *width, qreal *height) const
    double QRectF_height(void* rect); // qreal	height() const
    void* QRectF_intersected(void* rect, void* rectangle); // QRectF	intersected(const QRectF &rectangle) const
    bool QRectF_intersects(void* rect, void* rectangle); // bool	intersects(const QRectF &rectangle) const
    bool QRectF_isEmpty(void* rect); // bool	isEmpty() const
    bool QRectF_isNull(void* rect); // bool	isNull() const
    bool QRectF_isValid(void* rect); // bool	isValid() const
    double QRectF_left(void* rect); // qreal	left() const
    void* QRectF_marginsAdded(void* rect, void* margins); // QRectF	marginsAdded(const QMarginsF &margins) const
    void* QRectF_marginsRemoved(void* rect, void* margins); // QRectF	marginsRemoved(const QMarginsF &margins) const
    void QRectF_moveBottom(void* rect, double y); // void	moveBottom(qreal y)
    void QRectF_moveBottomLeft(void* rect, void* position); // void	moveBottomLeft(const QPointF &position)
    void QRectF_moveBottomRight(void* rect, void* position); // void	moveBottomRight(const QPointF &position)
    void QRectF_moveCenter(void* rect, void* position); // void	moveCenter(const QPointF &position)
    void QRectF_moveLeft(void* rect, double x); // void	moveLeft(qreal x)
    void QRectF_moveRight(void* rect, double x); // void	moveRight(qreal x)
    void QRectF_moveTo(void* rect, double x, double y); // void	moveTo(qreal x, qreal y)
    void QRectF_moveToPosition(void* rect, void* position); // void	moveTo(const QPointF &position)
    void QRectF_moveTop(void* rect, double y); // void	moveTop(qreal y)
    void QRectF_moveTopLeft(void* rect, void* position); // void	moveTopLeft(const QPointF &position)
    void QRectF_moveTopRight(void* rect, void* position); // void	moveTopRight(const QPointF &position)
    void* QRectF_normalized(void* rect); // QRectF	normalized() const
    double QRectF_right(void* rect); // qreal	right() const
    void QRectF_setBottom(void* rect, double y); // void	setBottom(qreal y)
    void QRectF_setBottomLeft(void* rect, void* position); // void	setBottomLeft(const QPointF &position)
    void QRectF_setBottomRight(void* rect, void* position); // void	setBottomRight(const QPointF &position)
    void QRectF_setCoords(void* rect, double x1, double y1, double x2, double y2); // void	setCoords(qreal x1, qreal y1, qreal x2, qreal y2)
    void QRectF_setHeight(void* rect, double height); // void	setHeight(qreal height)
    void QRectF_setLeft(void* rect, double x); // void	setLeft(qreal x)
    void QRectF_setRect(void* rect, double x, double y, double width, double height); // void	setRect(qreal x, qreal y, qreal width, qreal height)
    void QRectF_setRight(void* rect, double x); // void	setRight(qreal x)
    void QRectF_setSize(void* rect, void* size); // void	setSize(const QSizeF &size)
    void QRectF_setTop(void* rect, double y); // void	setTop(qreal y)
    void QRectF_setTopLeft(void* rect, void* position); // void	setTopLeft(const QPointF &position)
    void QRectF_setTopRight(void* rect, void* position); // void	setTopRight(const QPointF &position)
    void QRectF_setWidth(void* rect, double width); // void	setWidth(qreal width)
    void QRectF_setX(void* rect, double x); // void	setX(qreal x)
    void QRectF_setY(void* rect, double y); // void	setY(qreal y)
    void* QRectF_size(void* rect); // QSizeF	size() const
    void* QRectF_toAlignedRect(void* rect); // QRect	toAlignedRect() const
    // CGRect	toCGRect() const
    // (since 6.5) emscripten::val	toDOMRect() const
    void* QRectF_toRect(void* rect); // QRect	toRect() const
    double QRectF_top(void* rect); // qreal	top() const
    void* QRectF_topLeft(void* rect); // QPointF	topLeft() const
    void* QRectF_topRight(void* rect); // QPointF	topRight() const
    void QRectF_translateByXY(void* rect, double dx, double dy); // void	translate(qreal dx, qreal dy)
    void QRectF_translateByOffset(void* rect, void* offset); // void	translate(const QPointF &offset)
    void* QRectF_translatedByXY(void* rect, double dx, double dy); // QRectF	translated(qreal dx, qreal dy) const
    void* QRectF_translatedByOffset(void* rect, void* offset); // QRectF	translated(const QPointF &offset) const
    void* QRectF_transposed(void* rect); // QRectF	transposed() const
    void* QRectF_united(void* rect, void* rectangle); // QRectF	united(const QRectF &rectangle) const
    double QRectF_width(void* rect); // qreal	width() const
    double QRectF_x(void* rect); // qreal	x() const
    double QRectF_y(void* rect); // qreal	y() const
    void* QRectF_operatorAnd(void* rect, void* rectangle); // QRectF	operator&(const QRectF &rectangle) const
    void* QRectF_operatorAndAssign(void* rect, void* rectangle); // QRectF &	operator&=(const QRectF &rectangle)
    void* QRectF_operatorAddAssign(void* rect, void* margins); // QRectF &	operator+=(const QMarginsF &margins)
    void* QRectF_operatorSubAssign(void* rect, void* margins); // QRectF &	operator-=(const QMarginsF &margins)
    void* QRectF_operatorOr(void* rect, void* rectangle); // QRectF	operator|(const QRectF &rectangle) const
    void* QRectF_operatorOrAssign(void* rect, void* rectangle); // QRectF &	operator|=(const QRectF &rectangle)
    //-- Static Public Members
    // QRectF	fromCGRect(CGRect rect)
    // (since 6.5) QRectF	fromDOMRect(emscripten::val domRect)

#ifdef __cplusplus
}
#endif

#endif //QRECTF_H
