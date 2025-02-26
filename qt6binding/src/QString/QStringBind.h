#ifndef QT_QSTRINGBIND_H
#define QT_QSTRINGBIND_H

#include "QStringHandler.h"
#include <QString>
#include <QStringList>

class QStringBind {
public:
    // 作成・削除
    static void *create_empty();
    static void *create_from_utf8(const char *str);
    static void delete_string(void *str);
    
    // 基本操作
    static int length(void *str);
    static bool isEmpty(void *str);
    static void clear(void *str);
    static char *toString(void *str);
    
    // 文字列操作
    static char at(void *str, int position);
    static void append(void *str, const char *text);
    static void prepend(void *str, const char *text);
    static void insert(void *str, int position, const char *text);
    static void remove(void *str, int position, int n);
    static void replace(void *str, int position, int n, const char *after);
    
    // 変換
    static char *toLower(void *str);
    static char *toUpper(void *str);
    static char *trimmed(void *str);
    static char *simplified(void *str);
    
    // 検索
    static int indexOf(void *str, const char *substr, int from);
    static int lastIndexOf(void *str, const char *substr, int from);
    static bool contains(void *str, const char *substr);
    static bool startsWith(void *str, const char *prefix);
    static bool endsWith(void *str, const char *suffix);
    
    // 分割
    static char **split(void *str, const char *sep, int *count);
    
    // 比較
    static bool equals(void *str, const char *other);
    
private:
    static QStringHandler *handler(void *str);
};

#endif // QT_QSTRINGBIND_H
