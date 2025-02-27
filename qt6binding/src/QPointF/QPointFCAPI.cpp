#include "QPointFBind.h"

extern "C" {

// コンストラクタ
void* QPointF_create() {
    return QPointFBind::create();
}

void* QPointF_createFromPoint(void* point) {
    return QPointFBind::createFromPoint(static_cast<QPoint*>(point));
}

void* QPointF_createWithCoords(double x, double y) {
    return QPointFBind::createWithCoords(x, y);
}

// デストラクタ
void QPointF_delete(void* point) {
    QPointFBind::destroy(static_cast<QPointF*>(point));
}

// プロパティ取得
bool QPointF_isNull(void* point) {
    return QPointFBind::isNull(static_cast<QPointF*>(point));
}

double QPointF_manhattanLength(void* point) {
    return QPointFBind::manhattanLength(static_cast<QPointF*>(point));
}

double QPointF_x(void* point) {
    return QPointFBind::x(static_cast<QPointF*>(point));
}

double QPointF_y(void* point) {
    return QPointFBind::y(static_cast<QPointF*>(point));
}

// プロパティ設定
void QPointF_setX(void* point, double x) {
    QPointFBind::setX(static_cast<QPointF*>(point), x);
}

void QPointF_setY(void* point, double y) {
    QPointFBind::setY(static_cast<QPointF*>(point), y);
}

// 変換
void* QPointF_toPoint(void* point) {
    return QPointFBind::toPoint(static_cast<QPointF*>(point));
}

void* QPointF_transposed(void* point) {
    return QPointFBind::transposed(static_cast<QPointF*>(point));
}

// 演算
void* QPointF_add(void* point1, void* point2) {
    return QPointFBind::add(static_cast<QPointF*>(point1), static_cast<QPointF*>(point2));
}

void* QPointF_subtract(void* point1, void* point2) {
    return QPointFBind::subtract(static_cast<QPointF*>(point1), static_cast<QPointF*>(point2));
}

void* QPointF_multiply(void* point, double factor) {
    return QPointFBind::multiply(static_cast<QPointF*>(point), factor);
}

void* QPointF_divide(void* point, double divisor) {
    return QPointFBind::divide(static_cast<QPointF*>(point), divisor);
}

// 静的メソッド
double QPointF_dotProduct(void* point1, void* point2) {
    return QPointFBind::dotProduct(static_cast<QPointF*>(point1), static_cast<QPointF*>(point2));
}

}
