#include "qt6binding.h"
#include <stdio.h>

// コールバック関数
void onButtonClicked(void* button) {
    printf("Button clicked!\n");
}

void onButtonPressed(void* button) {
    printf("Button pressed!\n");
}

void onButtonReleased(void* button) {
    printf("Button released!\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QPushButton Example");
    QWidget_resize(window, 300, 200);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 20, 20, 20, 20);
    
    // 通常のボタン
    void* button1 = QPushButton_create("Click Me", window);
    QPushButton_setClickCallback(button1, onButtonClicked);
    QVBoxLayout_addWidget(layout, button1);
    
    // 押下状態を保持するボタン
    void* button2 = QPushButton_create("Toggle Button", window);
    QPushButton_setCheckable(button2, true);
    QPushButton_setClickCallback(button2, onButtonClicked);
    QVBoxLayout_addWidget(layout, button2);
    
    // 無効化されたボタン
    void* button3 = QPushButton_create("Disabled Button", window);
    QPushButton_setEnabled(button3, false);
    QVBoxLayout_addWidget(layout, button3);
    
    // プレス/リリースイベントを持つボタン
    void* button4 = QPushButton_create("Press and Release", window);
    QPushButton_setPressedCallback(button4, onButtonPressed);
    QPushButton_setReleasedCallback(button4, onButtonReleased);
    QVBoxLayout_addWidget(layout, button4);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
