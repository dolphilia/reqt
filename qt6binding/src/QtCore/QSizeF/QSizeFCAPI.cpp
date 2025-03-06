#include "QSizeFBind.h"

extern "C" {

//-- Public Functions

void QSizeF_delete(void* size) {
    delete static_cast<QSizeFBind*>(size);
}

// QSizeF()

void* QSizeF_create() {
    return new QSizeFBind();
}
// QSizeF(const QSize &size)

void* QSizeF_create_2(void* size) {
    return new QSizeFBind(*static_cast<QSize*>(size));
}

// QSizeF(qreal width, qreal height)
void* QSizeF_create_3(double width, double height) {
    return new QSizeFBind(width, height);
}

// QSizeF boundedTo(const QSizeF &otherSize) const

void* QSizeF_boundedTo(void* size, void* otherSize) {
    QSizeF result = static_cast<QSizeFBind*>(size)->boundedTo(*static_cast<QSizeF*>(otherSize));
    return new QSizeF(result);
}
// QSizeF expandedTo(const QSizeF &otherSize) const

void* QSizeF_expandedTo(void* size, void* otherSize) {
    QSizeF result = static_cast<QSizeFBind*>(size)->expandedTo(*static_cast<QSizeF*>(otherSize));
    return new QSizeF(result);
}
// QSizeF grownBy(QMarginsF margins) const

void* QSizeF_grownBy(void* size, void* margins) {
    QSizeF result = static_cast<QSizeFBind*>(size)->grownBy(*static_cast<QMarginsF*>(margins));
    return new QSizeF(result);
}
// qreal height() const

double QSizeF_height(void* size) {
    return static_cast<QSizeFBind*>(size)->height();
}
// bool isEmpty() const

bool QSizeF_isEmpty(void* size) {
    return static_cast<QSizeFBind*>(size)->isEmpty();
}
// bool isNull() const

bool QSizeF_isNull(void* size) {
    return static_cast<QSizeFBind*>(size)->isNull();
}
// bool isValid() const
bool QSizeF_isValid(void* size) {
    return static_cast<QSizeFBind*>(size)->isValid();
}
// qreal & rheight()

void* QSizeF_rheight(void* size) {
    return &static_cast<QSizeFBind*>(size)->rheight();
}
// qreal & rwidth()

void* QSizeF_rwidth(void* size) {
    return &static_cast<QSizeFBind*>(size)->rwidth();
}
// void scale(qreal width, qreal height, Qt::AspectRatioMode mode)

void QSizeF_scale(void* size, double width, double height, int mode) {
    static_cast<QSizeFBind*>(size)->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
}
// void scale(const QSizeF &size, Qt::AspectRatioMode mode)

void QSizeF_scale_2(void* size, void* s, int mode) {
    static_cast<QSizeFBind*>(size)->scale(*static_cast<QSizeF*>(s), static_cast<Qt::AspectRatioMode>(mode));
}
// QSizeF scaled(qreal width, qreal height, Qt::AspectRatioMode mode) const

void* QSizeF_scaled(void* size, double width, double height, int mode) {
    QSizeF result = static_cast<QSizeFBind*>(size)->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode));
    return new QSizeF(result);
}
// QSizeF scaled(const QSizeF &s, Qt::AspectRatioMode mode) const
void* QSizeF_scaled_2(void* size, void* s, int mode) {
    QSizeF result = static_cast<QSizeFBind*>(size)->scaled(*static_cast<QSizeF*>(s), static_cast<Qt::AspectRatioMode>(mode));
    return new QSizeF(result);
}
// void setHeight(qreal height)

void QSizeF_setHeight(void* size, double height) {
    static_cast<QSizeFBind*>(size)->setHeight(height);
}
// void setWidth(qreal width)

void QSizeF_setWidth(void* size, double width) {
    static_cast<QSizeFBind*>(size)->setWidth(width);
}
// QSizeF shrunkBy(QMarginsF margins) const

void* QSizeF_shrunkBy(void* size, void* margins) {
    QSizeF result = static_cast<QSizeFBind*>(size)->shrunkBy(*static_cast<QMarginsF*>(margins));
    return new QSizeF(result);
}
// CGSize toCGSize() const
// QSize toSize() const

void* QSizeF_toSize(void* size) {
    QSize result = static_cast<QSizeFBind*>(size)->toSize();
    return new QSize(result);
}
// void transpose()

void QSizeF_transpose(void* size) {
    static_cast<QSizeFBind*>(size)->transpose();
}
// QSizeF transposed() const
void* QSizeF_transposed(void* size) {
    QSizeF result = static_cast<QSizeFBind*>(size)->transposed();
    return new QSizeF(result);
}

// qreal width() const

double QSizeF_width(void* size) {
    return static_cast<QSizeFBind*>(size)->width();
}
// QSizeF & operator*=(qreal factor)

void* QSizeF_multiplyDouble(void* size, double factor) {
    return new QSizeF(*static_cast<QSizeFBind*>(size) * factor);
}
// QSizeF & operator+=(const QSizeF &size)

void* QSizeF_add(void* size1, void* size2) {
    QSizeF result = *static_cast<QSizeFBind*>(size1) + *static_cast<QSizeFBind*>(size2);
    QSizeFBind* newSize = new QSizeFBind(result.width(), result.height());
    return newSize;
}
// QSizeF & operator-=(const QSizeF &size)

void* QSizeF_subtract(void* size1, void* size2) {
    QSizeF result = *static_cast<QSizeFBind*>(size1) - *static_cast<QSizeFBind*>(size2);
    QSizeFBind* newSize = new QSizeFBind(result.width(), result.height());
    return newSize;
}
// QSizeF & operator/=(qreal divisor)

void* QSizeF_divide(void* size, double divisor) {
    QSizeF result = *static_cast<QSizeFBind*>(size) / divisor;
    QSizeFBind* newSize = new QSizeFBind(result.width(), result.height());
    return newSize;
}

//-- Static Public Members

// QSizeF fromCGSize(CGSize size)
    
}