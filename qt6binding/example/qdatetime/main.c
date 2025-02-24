#include "qt6.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QDateTime Example");
    QWidget_resize(window, 400, 300);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 20);
    QVBoxLayout_setContentsMargins(layout, 20, 20, 20, 20);
    
    // ラベルの追加
    void* dateLabel = QLabel_create("Date Input:", window);
    QVBoxLayout_addWidget(layout, dateLabel);
    
    // 日付入力
    void* dateEdit = QDateEdit_create(window);
    QDateEdit_setDisplayFormat(dateEdit, "yyyy-MM-dd");
    QDateEdit_setCalendarPopup(dateEdit, true);
    QVBoxLayout_addWidget(layout, dateEdit);
    
    // 日付の最小値と最大値を設定
    QDateEdit_setMinimumDate(dateEdit, 2024, 1, 1);
    QDateEdit_setMaximumDate(dateEdit, 2025, 12, 31);
    
    // ラベルの追加
    void* dateTimeLabel = QLabel_create("Date and Time Input:", window);
    QVBoxLayout_addWidget(layout, dateTimeLabel);
    
    // 日付と時刻入力
    void* dateTimeEdit = QDateTimeEdit_create(window);
    QDateTimeEdit_setDisplayFormat(dateTimeEdit, "yyyy-MM-dd HH:mm:ss");
    QDateTimeEdit_setCalendarPopup(dateTimeEdit, true);
    QVBoxLayout_addWidget(layout, dateTimeEdit);
    
    // 現在の日時を設定
    QDateTimeEdit_setDateTime(dateTimeEdit, 2024, 2, 22, 13, 30, 0);
    
    // 日付と時刻の最小値と最大値を設定
    QDateTimeEdit_setMinimumDateTime(dateTimeEdit, 2024, 1, 1, 0, 0, 0);
    QDateTimeEdit_setMaximumDateTime(dateTimeEdit, 2025, 12, 31, 23, 59, 59);
    
    // セクション間の移動を可能にする
    QDateTimeEdit_setCurrentSectionIndex(dateTimeEdit, 0);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
