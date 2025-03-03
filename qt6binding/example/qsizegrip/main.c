#include <qt6.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // アプリケーションの初期化
    void *app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QSizeGrip Example");

    // 中央ウィジェットの作成
    void *centralWidget = QWidget_create(NULL);
    QMainWindow_setCentralWidget(window, centralWidget);

    // サイズグリップの作成
    void *sizeGrip = QSizeGrip_create(window);
    QWidget_move(sizeGrip, 380, 280); // 右下に配置

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    int result = QApplication_exec();

    // クリーンアップ
    QSizeGrip_delete(sizeGrip);
    QWidget_delete(centralWidget);
    QWidget_delete(window);
    QApplication_delete(app);

    return result;
}
