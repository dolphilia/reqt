#include "qt6.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Qt初期化
    void *app = QApplication_create(argc, argv);
    
    printf("QVariantのテスト\n");
    printf("================\n\n");
    
    // 基本型のテスト
    printf("基本型のテスト:\n");
    
    // 空のQVariant
    void *emptyVariant = QVariant_create_empty();
    printf("空のQVariant - isNull: %s, isValid: %s\n", 
           QVariant_isNull(emptyVariant) ? "true" : "false",
           QVariant_isValid(emptyVariant) ? "true" : "false");
    QVariant_delete(emptyVariant);
    
    // 文字列
    void *stringVariant = QVariant_create_string("Hello, Qt!");
    char *stringValue = QVariant_toString(stringVariant);
    printf("文字列: %s\n", stringValue);
    free(stringValue);
    QVariant_delete(stringVariant);
    
    // 整数
    void *intVariant = QVariant_create_int(42);
    bool ok = false;
    int intValue = QVariant_toInt(intVariant, &ok);
    printf("整数: %d (変換成功: %s)\n", intValue, ok ? "true" : "false");
    QVariant_delete(intVariant);
    
    // 浮動小数点数
    void *doubleVariant = QVariant_create_double(3.14159);
    ok = false;
    double doubleValue = QVariant_toDouble(doubleVariant, &ok);
    printf("浮動小数点数: %f (変換成功: %s)\n", doubleValue, ok ? "true" : "false");
    QVariant_delete(doubleVariant);
    
    // 真偽値
    void *boolVariant = QVariant_create_bool(true);
    bool boolValue = QVariant_toBool(boolVariant);
    printf("真偽値: %s\n", boolValue ? "true" : "false");
    QVariant_delete(boolVariant);
    
    printf("\n");
    
    // 日付と時間のテスト
    printf("日付と時間のテスト:\n");
    
    // 日付
    void *dateVariant = QVariant_create_date(2025, 2, 26);
    int year, month, day;
    QVariant_toDate(dateVariant, &year, &month, &day);
    printf("日付: %d年%d月%d日\n", year, month, day);
    QVariant_delete(dateVariant);
    
    // 時刻
    void *timeVariant = QVariant_create_time(13, 45, 30, 500);
    int hour, minute, second, msec;
    QVariant_toTime(timeVariant, &hour, &minute, &second, &msec);
    printf("時刻: %02d:%02d:%02d.%03d\n", hour, minute, second, msec);
    QVariant_delete(timeVariant);
    
    // 日時
    void *dateTimeVariant = QVariant_create_datetime(2025, 2, 26, 13, 45, 30, 500);
    QVariant_toDateTime(dateTimeVariant, &year, &month, &day, &hour, &minute, &second, &msec);
    printf("日時: %d年%d月%d日 %02d:%02d:%02d.%03d\n", year, month, day, hour, minute, second, msec);
    QVariant_delete(dateTimeVariant);
    
    printf("\n");
    
    // 幾何学的型のテスト
    printf("幾何学的型のテスト:\n");
    
    // 点
    void *pointVariant = QVariant_create_point(10, 20);
    int x, y;
    QVariant_toPoint(pointVariant, &x, &y);
    printf("点: (%d, %d)\n", x, y);
    QVariant_delete(pointVariant);
    
    // 矩形
    void *rectVariant = QVariant_create_rect(10, 20, 100, 50);
    int width, height;
    QVariant_toRect(rectVariant, &x, &y, &width, &height);
    printf("矩形: (%d, %d, %d, %d)\n", x, y, width, height);
    QVariant_delete(rectVariant);
    
    // サイズ
    void *sizeVariant = QVariant_create_size(800, 600);
    QVariant_toSize(sizeVariant, &width, &height);
    printf("サイズ: %d x %d\n", width, height);
    QVariant_delete(sizeVariant);
    
    printf("\n");
    
    // 型変換のテスト
    printf("型変換のテスト:\n");
    
    // 整数から文字列への変換
    void *intToStringVariant = QVariant_create_int(123);
    char *intAsString = QVariant_toString(intToStringVariant);
    printf("整数から文字列: %s\n", intAsString);
    free(intAsString);
    QVariant_delete(intToStringVariant);
    
    // 文字列から整数への変換
    void *stringToIntVariant = QVariant_create_string("456");
    ok = false;
    int stringAsInt = QVariant_toInt(stringToIntVariant, &ok);
    printf("文字列から整数: %d (変換成功: %s)\n", stringAsInt, ok ? "true" : "false");
    QVariant_delete(stringToIntVariant);
    
    // 文字列から浮動小数点数への変換
    void *stringToDoubleVariant = QVariant_create_string("3.14");
    ok = false;
    double stringAsDouble = QVariant_toDouble(stringToDoubleVariant, &ok);
    printf("文字列から浮動小数点数: %f (変換成功: %s)\n", stringAsDouble, ok ? "true" : "false");
    QVariant_delete(stringToDoubleVariant);
    
    // 文字列から真偽値への変換
    void *stringToBoolVariant = QVariant_create_string("true");
    bool stringAsBool = QVariant_toBool(stringToBoolVariant);
    printf("文字列から真偽値: %s\n", stringAsBool ? "true" : "false");
    QVariant_delete(stringToBoolVariant);
    
    // クリーンアップ
    QApplication_delete(app);
    
    return 0;
}
