#include "qt6.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 文字列配列の解放関数
void free_string_array(char **array, int count) {
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

int main(int argc, char *argv[])
{
    // Qt初期化
    void *app = QApplication_create(argc, argv);
    
    printf("QStringのテスト\n");
    printf("==============\n\n");
    
    // 文字列の作成
    printf("文字列の作成:\n");
    void *emptyStr = QString_create_empty();
    void *helloStr = QString_create_from_utf8("Hello, Qt!");
    
    printf("空の文字列: \"%s\", 長さ: %d, 空か: %s\n", 
           QString_toString(emptyStr), 
           QString_length(emptyStr), 
           QString_isEmpty(emptyStr) ? "はい" : "いいえ");
    
    char *helloText = QString_toString(helloStr);
    printf("文字列: \"%s\", 長さ: %d, 空か: %s\n", 
           helloText, 
           QString_length(helloStr), 
           QString_isEmpty(helloStr) ? "はい" : "いいえ");
    free(helloText);
    
    printf("\n");
    
    // 文字列操作
    printf("文字列操作:\n");
    
    // 文字の取得
    char ch = QString_at(helloStr, 0);
    printf("最初の文字: %c\n", ch);
    
    // 追加
    QString_append(helloStr, " Welcome to Qt binding!");
    char *appendedText = QString_toString(helloStr);
    printf("追加後: \"%s\"\n", appendedText);
    free(appendedText);
    
    // 挿入
    QString_insert(helloStr, 7, "(C++)");
    char *insertedText = QString_toString(helloStr);
    printf("挿入後: \"%s\"\n", insertedText);
    free(insertedText);
    
    // 削除
    QString_remove(helloStr, 7, 5); // "(C++)"を削除
    char *removedText = QString_toString(helloStr);
    printf("削除後: \"%s\"\n", removedText);
    free(removedText);
    
    // 置換
    QString_replace(helloStr, 0, 5, "Konnichiwa");
    char *replacedText = QString_toString(helloStr);
    printf("置換後: \"%s\"\n", replacedText);
    free(replacedText);
    
    printf("\n");
    
    // 変換
    printf("変換:\n");
    
    // 小文字
    char *lowerText = QString_toLower(helloStr);
    printf("小文字: \"%s\"\n", lowerText);
    free(lowerText);
    
    // 大文字
    char *upperText = QString_toUpper(helloStr);
    printf("大文字: \"%s\"\n", upperText);
    free(upperText);
    
    // 空白除去
    void *spacedStr = QString_create_from_utf8("  Hello  World  ");
    char *spacedText = QString_toString(spacedStr);
    printf("元の文字列: \"%s\"\n", spacedText);
    free(spacedText);
    
    char *trimmedText = QString_trimmed(spacedStr);
    printf("空白除去: \"%s\"\n", trimmedText);
    free(trimmedText);
    
    char *simplifiedText = QString_simplified(spacedStr);
    printf("空白正規化: \"%s\"\n", simplifiedText);
    free(simplifiedText);
    
    printf("\n");
    
    // 検索
    printf("検索:\n");
    
    // indexOf
    int index = QString_indexOf(helloStr, "Qt", 0);
    printf("\"Qt\"の位置: %d\n", index);
    
    // lastIndexOf
    int lastIndex = QString_lastIndexOf(helloStr, "o", -1);
    printf("最後の\"o\"の位置: %d\n", lastIndex);
    
    // contains
    bool containsQt = QString_contains(helloStr, "Qt");
    printf("\"Qt\"を含むか: %s\n", containsQt ? "はい" : "いいえ");
    
    // startsWith
    bool startsWithK = QString_startsWith(helloStr, "Konnichiwa");
    printf("\"Konnichiwa\"で始まるか: %s\n", startsWithK ? "はい" : "いいえ");
    
    // endsWith
    bool endsWithExclamation = QString_endsWith(helloStr, "!");
    printf("\"!\"で終わるか: %s\n", endsWithExclamation ? "はい" : "いいえ");
    
    printf("\n");
    
    // 分割
    printf("分割:\n");
    
    void *csvStr = QString_create_from_utf8("apple,banana,cherry,date");
    char *csvText = QString_toString(csvStr);
    printf("CSV文字列: \"%s\"\n", csvText);
    free(csvText);
    
    int count = 0;
    char **parts = QString_split(csvStr, ",", &count);
    printf("分割結果 (%d個):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  %d: \"%s\"\n", i, parts[i]);
    }
    
    // 文字列配列の解放
    free_string_array(parts, count);
    
    printf("\n");
    
    // 比較
    printf("比較:\n");
    
    void *str1 = QString_create_from_utf8("Hello");
    void *str2 = QString_create_from_utf8("Hello");
    void *str3 = QString_create_from_utf8("World");
    
    printf("str1 == str2: %s\n", QString_equals(str1, QString_toString(str2)) ? "はい" : "いいえ");
    printf("str1 == str3: %s\n", QString_equals(str1, QString_toString(str3)) ? "はい" : "いいえ");
    
    printf("\n");
    
    // セクション
    printf("セクション:\n");
    
    void *pathStr = QString_create_from_utf8("/usr/local/bin/example");
    char *pathText = QString_toString(pathStr);
    printf("パス: \"%s\"\n", pathText);
    free(pathText);
    
    char *dirSection = QString_section(pathStr, "/", 1, 2, QString_SectionDefault);
    printf("ディレクトリセクション (1-2): \"%s\"\n", dirSection);
    free(dirSection);
    
    char *lastSection = QString_section(pathStr, "/", -1, -1, QString_SectionDefault);
    printf("最後のセクション: \"%s\"\n", lastSection);
    free(lastSection);
    
    printf("\n");
    
    // 正規化
    printf("正規化:\n");
    
    void *normalizeStr = QString_create_from_utf8("Café");
    char *normalText = QString_toString(normalizeStr);
    printf("元の文字列: \"%s\"\n", normalText);
    free(normalText);
    
    char *normalizedText = QString_normalized(normalizeStr, QString_NormalizationForm_D);
    printf("正規化 (D): \"%s\"\n", normalizedText);
    free(normalizedText);
    
    printf("\n");
    
    // 引数置換
    printf("引数置換:\n");
    
    void *templateStr = QString_create_from_utf8("Hello %1, welcome to %2!");
    char *templateText = QString_toString(templateStr);
    printf("テンプレート: \"%s\"\n", templateText);
    free(templateText);
    
    char *arg1Text = QString_arg_string(templateStr, "Alice");
    printf("引数1置換後: \"%s\"\n", arg1Text);
    
    char *arg2Text = QString_arg_string(QString_create_from_utf8(arg1Text), "Qt");
    printf("引数2置換後: \"%s\"\n", arg2Text);
    free(arg1Text);
    free(arg2Text);
    
    void *numTemplate = QString_create_from_utf8("Number: %1, Float: %2");
    char *numText = QString_arg_int(numTemplate, 42);
    char *floatText = QString_arg_double(QString_create_from_utf8(numText), 3.14159, 6, 'f', 2, ' ');
    printf("数値置換: \"%s\"\n", floatText);
    free(numText);
    free(floatText);
    
    printf("\n");
    
    // パディング
    printf("パディング:\n");
    
    void *padStr = QString_create_from_utf8("Test");
    char *padText = QString_toString(padStr);
    printf("元の文字列: \"%s\"\n", padText);
    free(padText);
    
    char *leftJustText = QString_leftJustified(padStr, 10, '-', false);
    printf("左揃え: \"%s\"\n", leftJustText);
    free(leftJustText);
    
    char *rightJustText = QString_rightJustified(padStr, 10, '-', false);
    printf("右揃え: \"%s\"\n", rightJustText);
    free(rightJustText);
    
    // クリーンアップ
    QString_delete(emptyStr);
    QString_delete(helloStr);
    QString_delete(spacedStr);
    QString_delete(csvStr);
    QString_delete(str1);
    QString_delete(str2);
    QString_delete(str3);
    QString_delete(pathStr);
    QString_delete(normalizeStr);
    QString_delete(templateStr);
    QString_delete(numTemplate);
    QString_delete(padStr);
    
    QApplication_delete(app);
    
    return 0;
}
