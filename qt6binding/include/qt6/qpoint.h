#ifndef QPOINT_C_H
#define QPOINT_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// コンストラクタ
void* QPoint_create();
void* QPoint_createWithCoords(int x, int y);

// デストラクタ
void QPoint_delete(void* point);

// プロパティ取得
bool QPoint_isNull(void* point);
int QPoint_manhattanLength(void* point);
int QPoint_x(void* point);
int QPoint_y(void* point);

// プロパティ設定
void QPoint_setX(void* point, int x);
void QPoint_setY(void* point, int y);

// 変換
void* QPoint_toPointF(void* point);
void* QPoint_transposed(void* point);

// 演算
void* QPoint_add(void* point1, void* point2);
void* QPoint_subtract(void* point1, void* point2);
void* QPoint_multiplyInt(void* point, int factor);
void* QPoint_multiplyFloat(void* point, float factor);
void* QPoint_multiplyDouble(void* point, double factor);
void* QPoint_divideReal(void* point, double divisor);

// QPointF関連
void QPointF_delete(void* pointF);
double QPointF_x(void* pointF);
double QPointF_y(void* pointF);

#ifdef __cplusplus
}
#endif

#endif // QPOINT_C_H
