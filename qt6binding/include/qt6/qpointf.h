#ifndef QPOINTF_C_H
#define QPOINTF_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// コンストラクタ
void* QPointF_create();
void* QPointF_createFromPoint(void* point);
void* QPointF_createWithCoords(double x, double y);

// デストラクタ
void QPointF_delete(void* point);

// プロパティ取得
bool QPointF_isNull(void* point);
double QPointF_manhattanLength(void* point);
double QPointF_x(void* point);
double QPointF_y(void* point);

// プロパティ設定
void QPointF_setX(void* point, double x);
void QPointF_setY(void* point, double y);

// 変換
void* QPointF_toPoint(void* point);
void* QPointF_transposed(void* point);

// 演算
void* QPointF_add(void* point1, void* point2);
void* QPointF_subtract(void* point1, void* point2);
void* QPointF_multiply(void* point, double factor);
void* QPointF_divide(void* point, double divisor);

// 静的メソッド
double QPointF_dotProduct(void* point1, void* point2);

#ifdef __cplusplus
}
#endif

#endif // QPOINTF_C_H
