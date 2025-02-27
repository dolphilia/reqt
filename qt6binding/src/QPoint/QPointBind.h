#ifndef QPOINT_BIND_H
#define QPOINT_BIND_H

#include <QPoint>
#include <QPointF>

class QPointBind {
public:
    // コンストラクタ
    static QPoint* create();
    static QPoint* createWithCoords(int x, int y);
    
    // デストラクタ
    static void destroy(QPoint* point);
    
    // プロパティ取得
    static bool isNull(QPoint* point);
    static int manhattanLength(QPoint* point);
    static int x(QPoint* point);
    static int y(QPoint* point);
    
    // プロパティ設定
    static void setX(QPoint* point, int x);
    static void setY(QPoint* point, int y);
    
    // 変換
    static QPointF* toPointF(QPoint* point);
    static QPoint* transposed(QPoint* point);
    
    // 演算
    static QPoint* add(QPoint* point1, QPoint* point2);
    static QPoint* subtract(QPoint* point1, QPoint* point2);
    static QPoint* multiplyInt(QPoint* point, int factor);
    static QPoint* multiplyFloat(QPoint* point, float factor);
    static QPoint* multiplyDouble(QPoint* point, double factor);
    static QPoint* divideReal(QPoint* point, double divisor);
};

#endif // QPOINT_BIND_H
