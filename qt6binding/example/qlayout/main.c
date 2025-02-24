#include "qt6.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QLayout Example");
    QWidget_resize(window, 500, 400);
    
    // メインレイアウト（垂直）の作成
    void* mainLayout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(mainLayout, 10);
    QVBoxLayout_setContentsMargins(mainLayout, 20, 20, 20, 20);
    
    // 上部の水平レイアウト
    void* topLayout = QHBoxLayout_create(NULL);
    QHBoxLayout_setSpacing(topLayout, 10);
    
    void* label1 = QLabel_create("Name:", window);
    void* lineEdit = QLineEdit_create("", window);
    QHBoxLayout_addWidget(topLayout, label1);
    QHBoxLayout_addWidget(topLayout, lineEdit);
    
    // 中央の水平レイアウト（3つのボタンを均等に配置）
    void* middleLayout = QHBoxLayout_create(NULL);
    QHBoxLayout_setSpacing(middleLayout, 10);
    
    void* button1 = QPushButton_create("Button 1", window);
    void* button2 = QPushButton_create("Button 2", window);
    void* button3 = QPushButton_create("Button 3", window);
    
    QHBoxLayout_addStretch(middleLayout, 1);
    QHBoxLayout_addWidget(middleLayout, button1);
    QHBoxLayout_addWidget(middleLayout, button2);
    QHBoxLayout_addWidget(middleLayout, button3);
    QHBoxLayout_addStretch(middleLayout, 1);
    
    // 下部の2列レイアウト
    void* bottomLayout = QHBoxLayout_create(NULL);
    QHBoxLayout_setSpacing(bottomLayout, 20);
    
    // 左列（垂直レイアウト）
    void* leftColumn = QVBoxLayout_create(NULL);
    QVBoxLayout_setSpacing(leftColumn, 5);
    
    void* checkbox1 = QCheckBox_create("Option 1", window);
    void* checkbox2 = QCheckBox_create("Option 2", window);
    void* checkbox3 = QCheckBox_create("Option 3", window);
    
    QVBoxLayout_addWidget(leftColumn, checkbox1);
    QVBoxLayout_addWidget(leftColumn, checkbox2);
    QVBoxLayout_addWidget(leftColumn, checkbox3);
    QVBoxLayout_addStretch(leftColumn, 1);
    
    // 右列（垂直レイアウト）
    void* rightColumn = QVBoxLayout_create(NULL);
    QVBoxLayout_setSpacing(rightColumn, 5);
    
    void* radio1 = QCheckBox_create("Choice 1", window);
    void* radio2 = QCheckBox_create("Choice 2", window);
    void* radio3 = QCheckBox_create("Choice 3", window);
    
    QVBoxLayout_addWidget(rightColumn, radio1);
    QVBoxLayout_addWidget(rightColumn, radio2);
    QVBoxLayout_addWidget(rightColumn, radio3);
    QVBoxLayout_addStretch(rightColumn, 1);
    
    // 下部レイアウトに列を追加
    QHBoxLayout_addLayout(bottomLayout, leftColumn);
    QHBoxLayout_addLayout(bottomLayout, rightColumn);
    
    // メインレイアウトに各セクションを追加
    QVBoxLayout_addLayout(mainLayout, topLayout);
    QVBoxLayout_addSpacing(mainLayout, 20);
    QVBoxLayout_addLayout(mainLayout, middleLayout);
    QVBoxLayout_addSpacing(mainLayout, 20);
    QVBoxLayout_addLayout(mainLayout, bottomLayout);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
