#include <stdio.h>
#include <stdlib.h>
#include "qt6/qapplication.h"
#include "qt6/qinputdialog.h"
#include "qt6/qwidget.h"
#include "qt6/qpushbutton.h"
#include "qt6/qvboxlayout.h"

void onTextButtonClicked(void* sender) {
    bool ok = false;
    const char* text = QInputDialog_getText(NULL, "テキスト入力", "名前を入力してください:", 0, "", &ok, 0);
    if (ok && text) {
        printf("入力されたテキスト: %s\n", text);
    }
}

void onIntButtonClicked(void* sender) {
    bool ok = false;
    int value = QInputDialog_getInt(NULL, "数値入力", "年齢を入力してください:", 20, 0, 150, 1, &ok, 0);
    if (ok) {
        printf("入力された数値: %d\n", value);
    }
}

void onDoubleButtonClicked(void* sender) {
    bool ok = false;
    double value = QInputDialog_getDouble(NULL, "小数入力", "身長を入力してください(m):", 1.70, 0.0, 3.0, 2, &ok, 0);
    if (ok) {
        printf("入力された小数: %.2f\n", value);
    }
}

void onItemButtonClicked(void* sender) {
    bool ok = false;
    const char* items[] = {"赤", "青", "緑", "黄", "白", "黒"};
    const char* selected = QInputDialog_getItem(NULL, "項目選択", "色を選択してください:", items, 6, 0, true, &ok, 0);
    if (ok && selected) {
        printf("選択された項目: %s\n", selected);
    }
}

void onMultiLineButtonClicked(void* sender) {
    bool ok = false;
    const char* text = QInputDialog_getMultiLineText(NULL, "複数行テキスト", "メッセージを入力してください:", "", &ok, 0);
    if (ok && text) {
        printf("入力された複数行テキスト:\n%s\n", text);
    }
}

int main(int argc, char *argv[]) {
    void* app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_resize(window, 300, 200);
    QWidget_setWindowTitle(window, "QInputDialog サンプル");

    // レイアウトの作成
    void* layout = QVBoxLayout_create(NULL);

    // ボタンの作成
    void* textButton = QPushButton_create("テキスト入力ダイアログ", window);
    QPushButton_setClickCallback(textButton, onTextButtonClicked);
    QVBoxLayout_addWidget(layout, textButton);

    void* intButton = QPushButton_create("数値入力ダイアログ", window);
    QPushButton_setClickCallback(intButton, onIntButtonClicked);
    QVBoxLayout_addWidget(layout, intButton);

    void* doubleButton = QPushButton_create("小数入力ダイアログ", window);
    QPushButton_setClickCallback(doubleButton, onDoubleButtonClicked);
    QVBoxLayout_addWidget(layout, doubleButton);

    void* itemButton = QPushButton_create("項目選択ダイアログ", window);
    QPushButton_setClickCallback(itemButton, onItemButtonClicked);
    QVBoxLayout_addWidget(layout, itemButton);

    void* multiLineButton = QPushButton_create("複数行テキスト入力ダイアログ", window);
    QPushButton_setClickCallback(multiLineButton, onMultiLineButtonClicked);
    QVBoxLayout_addWidget(layout, multiLineButton);

    // レイアウトの設定
    QWidget_setLayout(window, (void*)layout);

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    return QApplication_exec();
}
