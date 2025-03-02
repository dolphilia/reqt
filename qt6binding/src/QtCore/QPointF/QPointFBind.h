#ifndef QPOINTF_BIND_H
#define QPOINTF_BIND_H

#include <QPointF>
#include <QPoint>

class QPointFBind {
public:
    // コンストラクタ
    static QPointF* create();
    static QPointF* createFromPoint(QPoint* point);
    static QPointF* createWithCoords(double x, double y);
    
    // デストラクタ
    static void destroy(QPointF* point);
    
    // プロパティ取得
    static bool isNull(QPointF* point);
    static double manhattanLength(QPointF* point);
    static double x(QPointF* point);
    static double y(QPointF* point);
    
    // プロパティ設定
    static void setX(QPointF* point, double x);
    static void setY(QPointF* point, double y);
    
    // 変換
    static QPoint* toPoint(QPointF* point);
    static QPointF* transposed(QPointF* point);
    
    // 演算
    static QPointF* add(QPointF* point1, QPointF* point2);
    static QPointF* subtract(QPointF* point1, QPointF* point2);
    static QPointF* multiply(QPointF* point, double factor);
    static QPointF* divide(QPointF* point, double divisor);
    
    // 静的メソッド
    static double dotProduct(QPointF* point1, QPointF* point2);
};

#endif // QPOINTF_BIND_H
