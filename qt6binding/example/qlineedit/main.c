#include "qt6binding.h"
#include <stdio.h>

// コールバック関数
void onTextChanged(void* lineEdit, const char* text) {
    printf("Text changed: %s\n", text);
}

void onTextEdited(void* lineEdit, const char* text) {
    printf("Text edited: %s\n", text);
}

void onReturnPressed(void* lineEdit, const char* text) {
    printf("Return pressed with text: %s\n", text);
}

void onClearButtonClicked(void* button) {
    printf("Clear button clicked\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QLineEdit Example");
    QWidget_resize(window, 400, 300);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 20, 20, 20, 20);
    
    // 通常のテキスト入力
    void* lineEdit1 = QLineEdit_create("", window);
    QLineEdit_setPlaceholderText(lineEdit1, "Enter text here...");
    QLineEdit_setClearButtonEnabled(lineEdit1, true);
    QLineEdit_setTextChangedCallback(lineEdit1, onTextChanged);
    QVBoxLayout_addWidget(layout, lineEdit1);
    
    // パスワード入力
    void* lineEdit2 = QLineEdit_create("", window);
    QLineEdit_setPlaceholderText(lineEdit2, "Enter password...");
    QLineEdit_setEchoMode(lineEdit2, QLINEEDIT_PASSWORD);
    QVBoxLayout_addWidget(layout, lineEdit2);
    
    // 最大文字数制限付き入力
    void* lineEdit3 = QLineEdit_create("", window);
    QLineEdit_setPlaceholderText(lineEdit3, "Max 10 characters");
    QLineEdit_setMaxLength(lineEdit3, 10);
    QLineEdit_setTextEditedCallback(lineEdit3, onTextEdited);
    QVBoxLayout_addWidget(layout, lineEdit3);
    
    // 読み取り専用入力
    void* lineEdit4 = QLineEdit_create("Read only text", window);
    QLineEdit_setReadOnly(lineEdit4, true);
    QVBoxLayout_addWidget(layout, lineEdit4);
    
    // リターンキー検知付き入力
    void* lineEdit5 = QLineEdit_create("", window);
    QLineEdit_setPlaceholderText(lineEdit5, "Press Enter to submit");
    QLineEdit_setReturnPressedCallback(lineEdit5, onReturnPressed);
    QVBoxLayout_addWidget(layout, lineEdit5);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
