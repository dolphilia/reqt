#include "qt6.h"
#include <stdio.h>

void onGroupBoxToggled(void* groupBox, bool checked) {
    printf("GroupBox toggled: %s\n", checked ? "checked" : "unchecked");
}

int main(int argc, char* argv[]) {
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QGroupBox Example");
    QWidget_resize(window, 300, 200);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    
    // チェック可能なグループボックスの作成
    void* checkableGroup = QGroupBox_create_with_title("Checkable Group", window);
    QGroupBox_setCheckable(checkableGroup, true);
    QGroupBox_setChecked(checkableGroup, true);
    QGroupBox_setAlignment(checkableGroup, QGROUPBOX_ALIGN_CENTER);
    
    // チェック可能なグループボックスの内部レイアウト
    void* checkableLayout = QVBoxLayout_create(NULL);
    void* button1 = QPushButton_create("Button 1", checkableGroup);
    void* button2 = QPushButton_create("Button 2", checkableGroup);
    QVBoxLayout_addWidget(checkableLayout, button1);
    QVBoxLayout_addWidget(checkableLayout, button2);
    QWidget_setLayout(checkableGroup, checkableLayout);
    
    // フラットなグループボックスの作成
    void* flatGroup = QGroupBox_create_with_title("Flat Group", window);
    QGroupBox_setFlat(flatGroup, true);
    QGroupBox_setAlignment(flatGroup, QGROUPBOX_ALIGN_LEFT);
    
    // フラットなグループボックスの内部レイアウト
    void* flatLayout = QVBoxLayout_create(NULL);
    void* button3 = QPushButton_create("Button 3", flatGroup);
    void* button4 = QPushButton_create("Button 4", flatGroup);
    QVBoxLayout_addWidget(flatLayout, button3);
    QVBoxLayout_addWidget(flatLayout, button4);
    QWidget_setLayout(flatGroup, flatLayout);
    
    // メインレイアウトにグループボックスを追加
    QVBoxLayout_addWidget(layout, checkableGroup);
    QVBoxLayout_addWidget(layout, flatGroup);
    
    // トグルコールバックの設定
    QGroupBox_setToggledCallback(checkableGroup, onGroupBoxToggled);
    
    // ウィンドウの表示
    QWidget_show(window);
    QApplication_exec();
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return 0;
}
