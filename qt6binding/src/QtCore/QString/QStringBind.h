#ifndef QT_QSTRINGBIND_H
#define QT_QSTRINGBIND_H

#include "QStringHandler.h"
#include <QString>
#include <QStringList>
#include <QChar>
#include <QByteArray>

class QStringBind {
public:
    // 作成・削除
    static void *create_empty();
    static void *create_from_utf8(const char *str);
    static void *create_from_char(char ch);
    static void *create_from_byte_array(const char *data, int size);
    static void *create_with_size(int size, char ch);
    static void delete_string(void *str);
    
    // 静的メソッド
    static char *number_int(int n, int base);
    static char *number_long(long n, int base);
    static char *number_longlong(long long n, int base);
    static char *number_ulonglong(unsigned long long n, int base);
    static char *number_uint(unsigned int n, int base);
    static char *number_ulong(unsigned long n, int base);
    static char *number_double(double n, char format, int precision);
    
    static int compare_strings(const char *s1, const char *s2, int cs);
    static int locale_aware_compare(const char *s1, const char *s2);
    
    static void *from_latin1(const char *str, int size);
    static void *from_latin1_ba(const char *str);
    static void *from_utf8_size(const char *str, int size);
    static void *from_utf8_ba(const char *str);
    static void *from_local8bit(const char *str, int size);
    static void *from_local8bit_ba(const char *str);
    static void *from_ucs4(const char *unicode, int size);
    static void *from_utf16(const char *unicode, int size);
    static void *from_wchar_array(const wchar_t *string, int size);
    
    static int max_size();
    
    // 基本操作
    static int length(void *str);
    static bool isEmpty(void *str);
    static void clear(void *str);
    static char *toString(void *str);
    static int capacity(void *str);
    static void chop(void *str, int n);
    static char *chopped(void *str, int len);
    static void *fill(void *str, char ch, int size);
    static char *first(void *str, int n);
    static char *last(void *str, int n);
    static char front(void *str);
    static char back(void *str);
    static bool isNull(void *str);
    static bool isLower(void *str);
    static bool isUpper(void *str);
    static bool isRightToLeft(void *str);
    static char *left(void *str, int n);
    static char *right(void *str, int n);
    static char *mid(void *str, int position, int n);
    static int max_size(void *str);
    static void reserve(void *str, int size);
    static void resize(void *str, int size);
    static void resize_with_char(void *str, int size, char fillChar);
    static char *repeated(void *str, int times);
    static char *sliced(void *str, int position, int n);
    static char *sliced_from(void *str, int position);
    static void shrink_to_fit(void *str);
    static void squeeze(void *str);
    static void swap(void *str, void *other);
    
    // 数値変換
    static void *setNum_int(void *str, int n, int base);
    static void *setNum_long(void *str, long n, int base);
    static void *setNum_longlong(void *str, long long n, int base);
    static void *setNum_ulonglong(void *str, unsigned long long n, int base);
    static void *setNum_short(void *str, short n, int base);
    static void *setNum_uint(void *str, unsigned int n, int base);
    static void *setNum_ulong(void *str, unsigned long n, int base);
    static void *setNum_ushort(void *str, unsigned short n, int base);
    static void *setNum_double(void *str, double n, char format, int precision);
    static void *setNum_float(void *str, float n, char format, int precision);
    
    // 文字列操作
    static char at(void *str, int position);
    static void append(void *str, const char *text);
    static void append_char(void *str, char ch);
    static void append_byte_array(void *str, const char *data, int size);
    static void prepend(void *str, const char *text);
    static void prepend_char(void *str, char ch);
    static void prepend_byte_array(void *str, const char *data, int size);
    static void insert(void *str, int position, const char *text);
    static void insert_char(void *str, int position, char ch);
    static void insert_byte_array(void *str, int position, const char *data, int size);
    static void remove(void *str, int position, int n);
    static void replace(void *str, int position, int n, const char *after);
    static void replace_char(void *str, int position, int n, char after);
    static void replace_byte_array(void *str, int position, int n, const char *data, int size);
    
    // 変換
    static char *toLower(void *str);
    static char *toUpper(void *str);
    static char *trimmed(void *str);
    static char *simplified(void *str);
    static char *toCaseFolded(void *str);
    static char *toHtmlEscaped(void *str);
    static void truncate(void *str, int position);
    
    // 数値変換
    static double toDouble(void *str, bool *ok);
    static float toFloat(void *str, bool *ok);
    static int toInt(void *str, bool *ok, int base);
    static long toLong(void *str, bool *ok, int base);
    static long long toLongLong(void *str, bool *ok, int base);
    static short toShort(void *str, bool *ok, int base);
    static unsigned int toUInt(void *str, bool *ok, int base);
    static unsigned long toULong(void *str, bool *ok, int base);
    static unsigned long long toULongLong(void *str, bool *ok, int base);
    static unsigned short toUShort(void *str, bool *ok, int base);
    
    // 検索
    static int indexOf(void *str, const char *substr, int from);
    static int indexOf_char(void *str, char ch, int from);
    static int lastIndexOf(void *str, const char *substr, int from);
    static int lastIndexOf_char(void *str, char ch, int from);
    static bool contains(void *str, const char *substr);
    static bool contains_char(void *str, char ch);
    static bool startsWith(void *str, const char *prefix);
    static bool startsWith_char(void *str, char ch);
    static bool endsWith(void *str, const char *suffix);
    static bool endsWith_char(void *str, char ch);
    
    // 分割
    static char **split(void *str, const char *sep, int *count);
    static char **split_char(void *str, char sep, int *count);
    
    // 比較
    static bool equals(void *str, const char *other);
    static bool equals_char(void *str, char ch);
    static int compare(void *str, const char *other, int cs);
    static int compare_char(void *str, char ch, int cs);
    
    // カウント
    static int count(void *str, const char *substr, int cs);
    static int count_char(void *str, char ch, int cs);
    
    // セクション
    static char *section(void *str, const char *sep, int start, int end, int flags);
    static char *section_char(void *str, char sep, int start, int end, int flags);
    
    // 正規化
    static char *normalized(void *str, NormalizationForm mode);
    
    // 追加の文字列操作
    static char *arg_string(void *str, const char *a);
    static char *arg_int(void *str, int a);
    static char *arg_long(void *str, long a, int fieldWidth, int base, char fillChar);
    static char *arg_longlong(void *str, long long a, int fieldWidth, int base, char fillChar);
    static char *arg_short(void *str, short a, int fieldWidth, int base, char fillChar);
    static char *arg_uint(void *str, unsigned int a, int fieldWidth, int base, char fillChar);
    static char *arg_ulong(void *str, unsigned long a, int fieldWidth, int base, char fillChar);
    static char *arg_ushort(void *str, unsigned short a, int fieldWidth, int base, char fillChar);
    static char *arg_double(void *str, double a, int fieldWidth, char format, int precision, char fillChar);
    static char *arg_char(void *str, char a, int fieldWidth, char fillChar);
    
    // パディング
    static char *leftJustified(void *str, int width, char fill, bool truncate);
    static char *rightJustified(void *str, int width, char fill, bool truncate);
    
private:
    static QStringHandler *handler(void *str);
};

#endif // QT_QSTRINGBIND_H
