#include "qt6.h"
#include <stdio.h>

void onClicked(void* widget, int row, int column) {
    printf("Clicked: row=%d, column=%d\n", row, column);
}

void onDoubleClicked(void* widget, int row, int column) {
    printf("Double clicked: row=%d, column=%d\n", row, column);
}

void onSelectionChanged(void* widget) {
    printf("Selection changed\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QListView Example");
    QWidget_resize(window, 300, 400);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 10, 10, 10, 10);
    
    // QListViewの作成
    void* listView = QListView_create(window);
    QListView_setSelectionMode(listView, QLISTVIEW_SINGLE_SELECTION);
    QListView_setViewMode(listView, QLISTVIEW_LIST_MODE);
    QVBoxLayout_addWidget(layout, listView);
    
    // モデルの作成とデータの設定
    void* model = QStringListModel_create(NULL);
    QStringListModel_addItem(model, "Item 1");
    QStringListModel_addItem(model, "Item 2");
    QStringListModel_addItem(model, "Item 3");
    QStringListModel_addItem(model, "Item 4");
    QStringListModel_addItem(model, "Item 5");
    QListView_setModel(listView, model);
    
    // コールバックの設定
    QListView_setClickedCallback(listView, onClicked);
    QListView_setDoubleClickedCallback(listView, onDoubleClicked);
    QListView_setSelectionChangedCallback(listView, onSelectionChanged);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QStringListModel_delete(model);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
