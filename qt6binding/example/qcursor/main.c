#include "qt6.h"
#include <stdio.h>
#include <unistd.h>

void onButtonClicked(void* button) {
    // カーソルの位置を取得
    int x, y;
    QCursor_pos(&x, &y);
    printf("Current cursor position: x=%d, y=%d\n", x, y);
}

int main(int argc, char* argv[]) {
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QCursor Example");
    QWidget_resize(window, 300, 200);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    
    // ボタンの作成
    void* button1 = QPushButton_create("Get Cursor Position", window);
    void* button2 = QPushButton_create("Set Wait Cursor", window);
    void* button3 = QPushButton_create("Set Arrow Cursor", window);
    void* button4 = QPushButton_create("Set IBeam Cursor", window);
    
    // ボタンのコールバック設定
    QPushButton_setClickCallback(button1, onButtonClicked);
    
    // レイアウトにボタンを追加
    QVBoxLayout_addWidget(layout, button1);
    QVBoxLayout_addWidget(layout, button2);
    QVBoxLayout_addWidget(layout, button3);
    QVBoxLayout_addWidget(layout, button4);
    
    // カーソルの作成と設定
    void* waitCursor = QCursor_create_with_shape(QCURSOR_WAIT);
    void* arrowCursor = QCursor_create_with_shape(QCURSOR_ARROW);
    void* ibeamCursor = QCursor_create_with_shape(QCURSOR_IBEAM);
    
    // ボタンにカーソルを設定
    QWidget_setCursor(button2, waitCursor);
    QWidget_setCursor(button3, arrowCursor);
    QWidget_setCursor(button4, ibeamCursor);
    
    // ウィンドウの表示
    QWidget_show(window);
    QApplication_exec(app);
    
    // クリーンアップ
    QCursor_delete(waitCursor);
    QCursor_delete(arrowCursor);
    QCursor_delete(ibeamCursor);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return 0;
}
