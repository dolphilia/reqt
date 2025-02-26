#ifndef QT_QSTRING_H
#define QT_QSTRING_H

#include <stdbool.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

// 静的メソッド
char *QString_number_int(int n, int base);
char *QString_number_long(long n, int base);
char *QString_number_longlong(long long n, int base);
char *QString_number_ulonglong(unsigned long long n, int base);
char *QString_number_uint(unsigned int n, int base);
char *QString_number_ulong(unsigned long n, int base);
char *QString_number_double(double n, char format, int precision);

int QString_compare_strings(const char *s1, const char *s2, int cs);
int QString_locale_aware_compare(const char *s1, const char *s2);

void *QString_from_latin1(const char *str, int size);
void *QString_from_latin1_ba(const char *str);
void *QString_from_utf8_size(const char *str, int size);
void *QString_from_utf8_ba(const char *str);
void *QString_from_local8bit(const char *str, int size);
void *QString_from_local8bit_ba(const char *str);
void *QString_from_ucs4(const char *unicode, int size);
void *QString_from_utf16(const char *unicode, int size);
void *QString_from_wchar_array(const wchar_t *string, int size);

int QString_static_max_size();

// 正規化形式の列挙型
typedef enum {
    QString_NormalizationForm_D,  // 正準分解
    QString_NormalizationForm_C,  // 正準合成
    QString_NormalizationForm_KD, // 互換分解
    QString_NormalizationForm_KC  // 互換合成
} QString_NormalizationForm;

// セクションフラグの列挙型
typedef enum {
    QString_SectionDefault = 0x00,           // デフォルト
    QString_SectionSkipEmpty = 0x01,         // 空のセクションをスキップ
    QString_SectionIncludeLeadingSep = 0x02, // 先頭の区切り文字を含む
    QString_SectionIncludeTrailingSep = 0x04, // 末尾の区切り文字を含む
    QString_SectionCaseInsensitiveSeps = 0x08 // 大文字小文字を区別しない
} QString_SectionFlag;

// 作成・削除
void *QString_create_empty();
void *QString_create_from_utf8(const char *str);
void *QString_create_from_char(char ch);
void *QString_create_from_byte_array(const char *data, int size);
void *QString_create_with_size(int size, char ch);
void QString_delete(void *str);

// 基本操作
int QString_length(void *str);
bool QString_isEmpty(void *str);
void QString_clear(void *str);
char *QString_toString(void *str);
int QString_capacity(void *str);
void QString_chop(void *str, int n);
char *QString_chopped(void *str, int len);
void *QString_fill(void *str, char ch, int size);
char *QString_first(void *str, int n);
char *QString_last(void *str, int n);
char QString_front(void *str);
char QString_back(void *str);
bool QString_isNull(void *str);
bool QString_isLower(void *str);
bool QString_isUpper(void *str);
bool QString_isRightToLeft(void *str);
char *QString_left(void *str, int n);
char *QString_right(void *str, int n);
char *QString_mid(void *str, int position, int n);
int QString_max_size(void *str);
void QString_reserve(void *str, int size);
void QString_resize(void *str, int size);
void QString_resize_with_char(void *str, int size, char fillChar);
char *QString_repeated(void *str, int times);
char *QString_sliced(void *str, int position, int n);
char *QString_sliced_from(void *str, int position);
void QString_shrink_to_fit(void *str);
void QString_squeeze(void *str);
void QString_swap(void *str, void *other);

// 数値変換
void *QString_setNum_int(void *str, int n, int base);
void *QString_setNum_long(void *str, long n, int base);
void *QString_setNum_longlong(void *str, long long n, int base);
void *QString_setNum_ulonglong(void *str, unsigned long long n, int base);
void *QString_setNum_short(void *str, short n, int base);
void *QString_setNum_uint(void *str, unsigned int n, int base);
void *QString_setNum_ulong(void *str, unsigned long n, int base);
void *QString_setNum_ushort(void *str, unsigned short n, int base);
void *QString_setNum_double(void *str, double n, char format, int precision);
void *QString_setNum_float(void *str, float n, char format, int precision);

// 文字列操作
char QString_at(void *str, int position);
void QString_append(void *str, const char *text);
void QString_append_char(void *str, char ch);
void QString_append_byte_array(void *str, const char *data, int size);
void QString_prepend(void *str, const char *text);
void QString_prepend_char(void *str, char ch);
void QString_prepend_byte_array(void *str, const char *data, int size);
void QString_insert(void *str, int position, const char *text);
void QString_insert_char(void *str, int position, char ch);
void QString_insert_byte_array(void *str, int position, const char *data, int size);
void QString_remove(void *str, int position, int n);
void QString_replace(void *str, int position, int n, const char *after);
void QString_replace_char(void *str, int position, int n, char after);
void QString_replace_byte_array(void *str, int position, int n, const char *data, int size);

// 変換
char *QString_toLower(void *str);
char *QString_toUpper(void *str);
char *QString_trimmed(void *str);
char *QString_simplified(void *str);
char *QString_toCaseFolded(void *str);
char *QString_toHtmlEscaped(void *str);
void QString_truncate(void *str, int position);

// 数値変換
double QString_toDouble(void *str, bool *ok);
float QString_toFloat(void *str, bool *ok);
int QString_toInt(void *str, bool *ok, int base);
long QString_toLong(void *str, bool *ok, int base);
long long QString_toLongLong(void *str, bool *ok, int base);
short QString_toShort(void *str, bool *ok, int base);
unsigned int QString_toUInt(void *str, bool *ok, int base);
unsigned long QString_toULong(void *str, bool *ok, int base);
unsigned long long QString_toULongLong(void *str, bool *ok, int base);
unsigned short QString_toUShort(void *str, bool *ok, int base);

// 検索
int QString_indexOf(void *str, const char *substr, int from);
int QString_indexOf_char(void *str, char ch, int from);
int QString_lastIndexOf(void *str, const char *substr, int from);
int QString_lastIndexOf_char(void *str, char ch, int from);
bool QString_contains(void *str, const char *substr);
bool QString_contains_char(void *str, char ch);
bool QString_startsWith(void *str, const char *prefix);
bool QString_startsWith_char(void *str, char ch);
bool QString_endsWith(void *str, const char *suffix);
bool QString_endsWith_char(void *str, char ch);

// 分割
char **QString_split(void *str, const char *sep, int *count);
char **QString_split_char(void *str, char sep, int *count);

// 比較
bool QString_equals(void *str, const char *other);
bool QString_equals_char(void *str, char ch);
int QString_compare(void *str, const char *other, int cs);
int QString_compare_char(void *str, char ch, int cs);

// カウント
int QString_count(void *str, const char *substr, int cs);
int QString_count_char(void *str, char ch, int cs);

// セクション
char *QString_section(void *str, const char *sep, int start, int end, int flags);
char *QString_section_char(void *str, char sep, int start, int end, int flags);

// 正規化
char *QString_normalized(void *str, QString_NormalizationForm mode);

// 追加の文字列操作
char *QString_arg_string(void *str, const char *a);
char *QString_arg_int(void *str, int a);
char *QString_arg_long(void *str, long a, int fieldWidth, int base, char fillChar);
char *QString_arg_longlong(void *str, long long a, int fieldWidth, int base, char fillChar);
char *QString_arg_short(void *str, short a, int fieldWidth, int base, char fillChar);
char *QString_arg_uint(void *str, unsigned int a, int fieldWidth, int base, char fillChar);
char *QString_arg_ulong(void *str, unsigned long a, int fieldWidth, int base, char fillChar);
char *QString_arg_ushort(void *str, unsigned short a, int fieldWidth, int base, char fillChar);
char *QString_arg_double(void *str, double a, int fieldWidth, char format, int precision, char fillChar);
char *QString_arg_char(void *str, char a, int fieldWidth, char fillChar);

// パディング
char *QString_leftJustified(void *str, int width, char fill, bool truncate);
char *QString_rightJustified(void *str, int width, char fill, bool truncate);

#ifdef __cplusplus
}
#endif

#endif // QT_QSTRING_H
