#include "qt6binding.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // ウィジェットの作成
    void* widget = QWidget_create(NULL);
    
    // ウィンドウタイトルの設定
    QWidget_setWindowTitle(widget, "QWidget Example");
    
    // ウィンドウサイズの設定
    QWidget_resize(widget, 300, 200);
    
    // ウィンドウの最小サイズと最大サイズの設定
    QWidget_setMinimumSize(widget, 200, 150);
    QWidget_setMaximumSize(widget, 400, 300);
    
    // ウィンドウの位置を画面中央に設定
    QWidget_move(widget, 100, 100);
    
    // ウィジェットの表示
    QWidget_show(widget);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(widget);
    QApplication_delete(app);
    
    return result;
}
