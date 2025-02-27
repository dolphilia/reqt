#include "QPointBind.h"

extern "C" {

// コンストラクタ
void* QPoint_create() {
    return QPointBind::create();
}

void* QPoint_createWithCoords(int x, int y) {
    return QPointBind::createWithCoords(x, y);
}

// デストラクタ
void QPoint_delete(void* point) {
    QPointBind::destroy(static_cast<QPoint*>(point));
}

// プロパティ取得
bool QPoint_isNull(void* point) {
    return QPointBind::isNull(static_cast<QPoint*>(point));
}

int QPoint_manhattanLength(void* point) {
    return QPointBind::manhattanLength(static_cast<QPoint*>(point));
}

int QPoint_x(void* point) {
    return QPointBind::x(static_cast<QPoint*>(point));
}

int QPoint_y(void* point) {
    return QPointBind::y(static_cast<QPoint*>(point));
}

// プロパティ設定
void QPoint_setX(void* point, int x) {
    QPointBind::setX(static_cast<QPoint*>(point), x);
}

void QPoint_setY(void* point, int y) {
    QPointBind::setY(static_cast<QPoint*>(point), y);
}

// 変換
void* QPoint_toPointF(void* point) {
    return QPointBind::toPointF(static_cast<QPoint*>(point));
}

void* QPoint_transposed(void* point) {
    return QPointBind::transposed(static_cast<QPoint*>(point));
}

// 演算
void* QPoint_add(void* point1, void* point2) {
    return QPointBind::add(static_cast<QPoint*>(point1), static_cast<QPoint*>(point2));
}

void* QPoint_subtract(void* point1, void* point2) {
    return QPointBind::subtract(static_cast<QPoint*>(point1), static_cast<QPoint*>(point2));
}

void* QPoint_multiplyInt(void* point, int factor) {
    return QPointBind::multiplyInt(static_cast<QPoint*>(point), factor);
}

void* QPoint_multiplyFloat(void* point, float factor) {
    return QPointBind::multiplyFloat(static_cast<QPoint*>(point), factor);
}

void* QPoint_multiplyDouble(void* point, double factor) {
    return QPointBind::multiplyDouble(static_cast<QPoint*>(point), factor);
}

void* QPoint_divideReal(void* point, double divisor) {
    return QPointBind::divideReal(static_cast<QPoint*>(point), divisor);
}


}
