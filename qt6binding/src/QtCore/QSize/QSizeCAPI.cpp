#include "QSizeBind.h"

extern "C" {

//-- Public Functions

void QSize_delete(void* size) {
    delete static_cast<QSizeBind*>(size);
}

// QSize()

void* QSize_create() {
    return new QSizeBind();
}

// QSize(int width, int height)

void* QSize_createWithWH(int width, int height) {
    return new QSizeBind(width, height);
}

// QSize boundedTo(const QSize &otherSize) const

void* QSize_boundedTo(void* size, void* otherSize) {
    QSize result = static_cast<QSizeBind*>(size)->boundedTo(*static_cast<QSize*>(otherSize));
    return new QSize(result);
}

// QSize expandedTo(const QSize &otherSize) const

void* QSize_expandedTo(void* size, void* otherSize) {
    QSize result = static_cast<QSizeBind*>(size)->expandedTo(*static_cast<QSize*>(otherSize));
    return new QSize(result);
}

// QSize grownBy(QMargins margins) const

void* QSize_grownBy(void* size, void* margins) {
    QSize result = static_cast<QSizeBind*>(size)->grownBy(*static_cast<QMargins*>(margins));
    return new QSize(result);
}

// int height() const

int QSize_height(void* size) {
    return static_cast<QSizeBind*>(size)->height();
}

// bool isEmpty() const

bool QSize_isEmpty(void* size) {
    return static_cast<QSizeBind*>(size)->isEmpty();
}

// bool isNull() const

bool QSize_isNull(void* size) {
    return static_cast<QSizeBind*>(size)->isNull();
}

// bool isValid() const

bool QSize_isValid(void* size) {
    return static_cast<QSizeBind*>(size)->isValid();
}

// int & rheight()

void* QSize_rheight(void* size) {
    return &static_cast<QSizeBind*>(size)->rheight();
}

// int & rwidth()

void* QSize_rwidth(void* size) {
    return &static_cast<QSizeBind*>(size)->rwidth();
}

// void scale(int width, int height, Qt::AspectRatioMode mode)

void QSize_scaleByWH(void* size, int width, int height, int mode) {
    static_cast<QSizeBind*>(size)->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
}

// void scale(const QSize &size, Qt::AspectRatioMode mode)

void QSize_scaleWithSize(void* size, void* otherSize, int mode) {
    static_cast<QSizeBind*>(size)->scale(*static_cast<QSize*>(otherSize), static_cast<Qt::AspectRatioMode>(mode));
}

// QSize scaled(int width, int height, Qt::AspectRatioMode mode) const

void* QSize_scaledByWH(void* size, int width, int height, int mode) {
    QSize result = static_cast<QSizeBind*>(size)->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode));
    return new QSize(result);
}

// QSize scaled(const QSize &s, Qt::AspectRatioMode mode) const

void* QSize_scaledWithSize(void* size, void* s, int mode) {
    QSize result = static_cast<QSizeBind*>(size)->scaled(*static_cast<QSize*>(s), static_cast<Qt::AspectRatioMode>(mode));
    return new QSize(result);
}

// void setHeight(int height)

void QSize_setHeight(void* size, int height) {
    static_cast<QSizeBind*>(size)->setHeight(height);
}

// void setWidth(int width)

void QSize_setWidth(void* size, int width) {
    static_cast<QSizeBind*>(size)->setWidth(width);
}

// QSize shrunkBy(QMargins margins) const

void* QSize_shrunkBy(void* size, void* margins) {
    QSize result = static_cast<QSizeBind*>(size)->shrunkBy(*static_cast<QMargins*>(margins));
    return new QSize(result);
}

// CGSize toCGSize() const
// (since 6.4) QSizeF toSizeF() const

void* QSize_toSizeF(void* size) {
    return new QSizeF(static_cast<QSizeBind*>(size)->toSizeF());
}

// void transpose()

void QSize_transpose(void* size) {
    static_cast<QSizeBind*>(size)->transpose();
}

// QSize transposed() const
    
void* QSize_transposed(void* size) {
    QSize result = static_cast<QSizeBind*>(size)->transposed();
    return new QSize(result);
}

// int width() const

int QSize_width(void* size) {
    return static_cast<QSizeBind*>(size)->width();
}

// QSize & operator*=(qreal factor)

void* QSize_operatorMulAssign(void* size, double factor) {
    QSize result = static_cast<QSizeBind*>(size)->operator*=(factor);
    QSizeBind* newSize = new QSizeBind(result.width(), result.height());
    return newSize;
}

// QSize & operator+=(const QSize &size)

void* QSize_operatorAddAssign(void* size1, void* size2) {
    QSize result = static_cast<QSizeBind*>(size1)->operator+=(*static_cast<QSize*>(size2));
    QSizeBind* newSize = new QSizeBind(result.width(), result.height());
    return newSize;
}

// QSize & operator-=(const QSize &size)

void* QSize_operatorSubAssign(void* size1, void* size2) {
    QSize result = static_cast<QSizeBind*>(size1)->operator-=(*static_cast<QSize*>(size2));
    QSizeBind* newSize = new QSizeBind(result.width(), result.height());
    return newSize;
}

// QSize & operator/=(qreal divisor)

void* QSize_operatorDivAssign(void* size, double divisor) {
    QSize result = static_cast<QSizeBind*>(size)->operator/=(divisor);
    QSizeBind* newSize = new QSizeBind(result.width(), result.height());
    return newSize;
}

}