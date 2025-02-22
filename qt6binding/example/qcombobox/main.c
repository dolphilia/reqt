#include "qt6binding.h"
#include <stdio.h>

void onCurrentIndexChanged(void* widget, int index) {
    void* comboBox = widget;
    const char* text = QComboBox_itemText(comboBox, index);
    printf("Selected index: %d, text: %s\n", index, text);
}

void onCurrentTextChanged(void* widget, const char* text) {
    printf("Text changed: %s\n", text);
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QComboBox Example");
    QWidget_resize(window, 300, 200);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 10, 10, 10, 10);
    
    // ラベルの追加
    void* label = QLabel_create("Select or enter a color:", window);
    QVBoxLayout_addWidget(layout, label);
    
    // コンボボックスの作成
    void* comboBox = QComboBox_create(window);
    QComboBox_addItem(comboBox, "Red");
    QComboBox_addItem(comboBox, "Green");
    QComboBox_addItem(comboBox, "Blue");
    QComboBox_setEditable(comboBox, true);
    QVBoxLayout_addWidget(layout, comboBox);
    
    // コールバックの設定
    QComboBox_setCurrentIndexChangedCallback(comboBox, onCurrentIndexChanged);
    QComboBox_setCurrentTextChangedCallback(comboBox, onCurrentTextChanged);
    
    // 現在の選択項目を設定
    QComboBox_setCurrentIndex(comboBox, 1);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
