#include "qpoint.h"
#include "qpointf.h"
#include "qt6.h"
#include <stdio.h>
#include <math.h>

// QPointFの情報を表示する関数
void printPointFInfo(void* pointF, const char* label) {
    if (!pointF) {
        printf("%s: NULL\n", label);
        return;
    }
    
    double x = QPointF_x(pointF);
    double y = QPointF_y(pointF);
    double manhattan = QPointF_manhattanLength(pointF);
    bool isNull = QPointF_isNull(pointF);
    
    printf("%s: (%.2f, %.2f)\n", label, x, y);
    printf("  isNull: %s\n", isNull ? "true" : "false");
    printf("  Manhattan Length: %.2f\n", manhattan);
}

// QPointの情報を表示する関数
void printPointInfo(void* point, const char* label) {
    if (!point) {
        printf("%s: NULL\n", label);
        return;
    }
    
    int x = QPoint_x(point);
    int y = QPoint_y(point);
    
    printf("%s: (%d, %d)\n", label, x, y);
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    printf("=== QPointF Example ===\n\n");
    
    // 1. デフォルトコンストラクタでQPointFを作成
    void* pointF1 = QPointF_create();
    printPointFInfo(pointF1, "Default PointF");
    
    // 2. 座標を指定してQPointFを作成
    void* pointF2 = QPointF_createWithXY(10.5, 20.75);
    printPointFInfo(pointF2, "PointF(10.5, 20.75)");
    
    // 3. QPointからQPointFを作成
    void* point = QPoint_createWithXY(15, 25);
    void* pointF3 = QPointF_createWithPoint(point);
    printPointFInfo(pointF3, "PointF from Point(15, 25)");
    
    // 4. 座標の設定
    QPointF_setX(pointF1, 5.25);
    QPointF_setY(pointF1, 15.75);
    printPointFInfo(pointF1, "After setX/setY");
    
    // 5. 点の加算
    void* pointF4 = QPointF_operatorAddAssign(pointF1, pointF2);
    printPointFInfo(pointF4, "pointF1 + pointF2");
    
    // 6. 点の減算
    void* pointF5 = QPointF_operatorSubAssign(pointF2, pointF1);
    printPointFInfo(pointF5, "pointF2 - pointF1");
    
    // 7. スカラー倍
    void* pointF6 = QPointF_operatorMulAssign(pointF1, 2.5);
    printPointFInfo(pointF6, "pointF1 * 2.5");
    
    // 8. スカラー除算
    void* pointF7 = QPointF_operatorDivAssign(pointF2, 2.0);
    printPointFInfo(pointF7, "pointF2 / 2.0");
    
    // 9. 座標の入れ替え
    void* pointF8 = QPointF_transposed(pointF2);
    printPointFInfo(pointF8, "pointF2 transposed");
    
    // 10. QPointへの変換
    void* point2 = QPointF_toPoint(pointF2);
    printPointInfo(point2, "pointF2 as QPoint");
    
    // 11. 内積の計算
    double dotProduct = QPointF_dotProduct(pointF1, pointF2);
    printf("Dot product of pointF1 and pointF2: %.2f\n", dotProduct);
    
    // クリーンアップ
    QPointF_delete(pointF1);
    QPointF_delete(pointF2);
    QPointF_delete(pointF3);
    QPointF_delete(pointF4);
    QPointF_delete(pointF5);
    QPointF_delete(pointF6);
    QPointF_delete(pointF7);
    QPointF_delete(pointF8);
    QPoint_delete(point);
    QPoint_delete(point2);
    
    QApplication_delete(app);
    
    return 0;
}
