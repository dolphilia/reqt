#include "qt6.h"
#include <stdio.h>

// QPointの情報を表示する関数
void printPointInfo(void* point, const char* label) {
    if (!point) {
        printf("%s: NULL\n", label);
        return;
    }
    
    int x = QPoint_x(point);
    int y = QPoint_y(point);
    int manhattan = QPoint_manhattanLength(point);
    bool isNull = QPoint_isNull(point);
    
    printf("%s: (%d, %d)\n", label, x, y);
    printf("  isNull: %s\n", isNull ? "true" : "false");
    printf("  Manhattan Length: %d\n", manhattan);
}

// QPointFの情報を表示する関数
void printPointFInfo(void* pointF, const char* label) {
    if (!pointF) {
        printf("%s: NULL\n", label);
        return;
    }
    
    double x = QPointF_x(pointF);
    double y = QPointF_y(pointF);
    
    printf("%s: (%.2f, %.2f)\n", label, x, y);
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    printf("=== QPoint Example ===\n\n");
    
    // 1. デフォルトコンストラクタでQPointを作成
    void* point1 = QPoint_create();
    printPointInfo(point1, "Default Point");
    
    // 2. 座標を指定してQPointを作成
    void* point2 = QPoint_create_2(10, 20);
    printPointInfo(point2, "Point(10, 20)");
    
    // 3. 座標の設定
    QPoint_setX(point1, 5);
    QPoint_setY(point1, 15);
    printPointInfo(point1, "After setX/setY");
    
    // 4. 点の加算
    void* point3 = QPoint_add(point1, point2);
    printPointInfo(point3, "point1 + point2");
    
    // 5. 点の減算
    void* point4 = QPoint_subtract(point2, point1);
    printPointInfo(point4, "point2 - point1");
    
    // 6. スカラー倍
    void* point5 = QPoint_multiplyInt(point1, 2);
    printPointInfo(point5, "point1 * 2");
    
    // 7. 浮動小数点数倍
    void* point6 = QPoint_multiplyDouble(point2, 1.5);
    printPointInfo(point6, "point2 * 1.5");
    
    // 8. スカラー除算
    void* point7 = QPoint_divideReal(point2, 2.0);
    printPointInfo(point7, "point2 / 2.0");
    
    // 9. 座標の入れ替え
    void* point8 = QPoint_transposed(point2);
    printPointInfo(point8, "point2 transposed");
    
    // 10. QPointFへの変換
    void* pointF = QPoint_toPointF(point2);
    printPointFInfo(pointF, "point2 as QPointF");
    
    // クリーンアップ
    QPoint_delete(point1);
    QPoint_delete(point2);
    QPoint_delete(point3);
    QPoint_delete(point4);
    QPoint_delete(point5);
    QPoint_delete(point6);
    QPoint_delete(point7);
    QPoint_delete(point8);
    QPointF_delete(pointF);
    
    QApplication_delete(app);
    
    return 0;
}
