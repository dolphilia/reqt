#include "QStringBind.h"
#include "../../include/qt6/qstring.h"

// 静的メソッド
char *QString_number_int(int n, int base)
{
    return QStringBind::number_int(n, base);
}

char *QString_number_long(long n, int base)
{
    return QStringBind::number_long(n, base);
}

char *QString_number_longlong(long long n, int base)
{
    return QStringBind::number_longlong(n, base);
}

char *QString_number_ulonglong(unsigned long long n, int base)
{
    return QStringBind::number_ulonglong(n, base);
}

char *QString_number_uint(unsigned int n, int base)
{
    return QStringBind::number_uint(n, base);
}

char *QString_number_ulong(unsigned long n, int base)
{
    return QStringBind::number_ulong(n, base);
}

char *QString_number_double(double n, char format, int precision)
{
    return QStringBind::number_double(n, format, precision);
}

int QString_compare_strings(const char *s1, const char *s2, int cs)
{
    return QStringBind::compare_strings(s1, s2, cs);
}

int QString_locale_aware_compare(const char *s1, const char *s2)
{
    return QStringBind::locale_aware_compare(s1, s2);
}

void *QString_from_latin1(const char *str, int size)
{
    return QStringBind::from_latin1(str, size);
}

void *QString_from_latin1_ba(const char *str)
{
    return QStringBind::from_latin1_ba(str);
}

void *QString_from_utf8_size(const char *str, int size)
{
    return QStringBind::from_utf8_size(str, size);
}

void *QString_from_utf8_ba(const char *str)
{
    return QStringBind::from_utf8_ba(str);
}

void *QString_from_local8bit(const char *str, int size)
{
    return QStringBind::from_local8bit(str, size);
}

void *QString_from_local8bit_ba(const char *str)
{
    return QStringBind::from_local8bit_ba(str);
}

void *QString_from_ucs4(const char *unicode, int size)
{
    return QStringBind::from_ucs4(unicode, size);
}

void *QString_from_utf16(const char *unicode, int size)
{
    return QStringBind::from_utf16(unicode, size);
}

void *QString_from_wchar_array(const wchar_t *string, int size)
{
    return QStringBind::from_wchar_array(string, size);
}

int QString_static_max_size()
{
    return QStringBind::max_size();
}

// 作成・削除
void *QString_create_empty()
{
    return QStringBind::create_empty();
}

void *QString_create_from_utf8(const char *str)
{
    return QStringBind::create_from_utf8(str);
}

void *QString_create_from_char(char ch)
{
    return QStringBind::create_from_char(ch);
}

void *QString_create_from_byte_array(const char *data, int size)
{
    return QStringBind::create_from_byte_array(data, size);
}

void *QString_create_with_size(int size, char ch)
{
    return QStringBind::create_with_size(size, ch);
}

void QString_delete(void *str)
{
    QStringBind::delete_string(str);
}

// 基本操作
int QString_length(void *str)
{
    return QStringBind::length(str);
}

bool QString_isEmpty(void *str)
{
    return QStringBind::isEmpty(str);
}

void QString_clear(void *str)
{
    QStringBind::clear(str);
}

char *QString_toString(void *str)
{
    return QStringBind::toString(str);
}

int QString_capacity(void *str)
{
    return QStringBind::capacity(str);
}

void QString_chop(void *str, int n)
{
    QStringBind::chop(str, n);
}

char *QString_chopped(void *str, int len)
{
    return QStringBind::chopped(str, len);
}

void *QString_fill(void *str, char ch, int size)
{
    return QStringBind::fill(str, ch, size);
}

char *QString_first(void *str, int n)
{
    return QStringBind::first(str, n);
}

char *QString_last(void *str, int n)
{
    return QStringBind::last(str, n);
}

char QString_front(void *str)
{
    return QStringBind::front(str);
}

char QString_back(void *str)
{
    return QStringBind::back(str);
}

bool QString_isNull(void *str)
{
    return QStringBind::isNull(str);
}

bool QString_isLower(void *str)
{
    return QStringBind::isLower(str);
}

bool QString_isUpper(void *str)
{
    return QStringBind::isUpper(str);
}

bool QString_isRightToLeft(void *str)
{
    return QStringBind::isRightToLeft(str);
}

char *QString_left(void *str, int n)
{
    return QStringBind::left(str, n);
}

char *QString_right(void *str, int n)
{
    return QStringBind::right(str, n);
}

char *QString_mid(void *str, int position, int n)
{
    return QStringBind::mid(str, position, n);
}

int QString_max_size(void *str)
{
    return QStringBind::max_size(str);
}

void QString_reserve(void *str, int size)
{
    QStringBind::reserve(str, size);
}

void QString_resize(void *str, int size)
{
    QStringBind::resize(str, size);
}

void QString_resize_with_char(void *str, int size, char fillChar)
{
    QStringBind::resize_with_char(str, size, fillChar);
}

char *QString_repeated(void *str, int times)
{
    return QStringBind::repeated(str, times);
}

char *QString_sliced(void *str, int position, int n)
{
    return QStringBind::sliced(str, position, n);
}

char *QString_sliced_from(void *str, int position)
{
    return QStringBind::sliced_from(str, position);
}

void QString_shrink_to_fit(void *str)
{
    QStringBind::shrink_to_fit(str);
}

void QString_squeeze(void *str)
{
    QStringBind::squeeze(str);
}

void QString_swap(void *str, void *other)
{
    QStringBind::swap(str, other);
}

// 数値変換
void *QString_setNum_int(void *str, int n, int base)
{
    return QStringBind::setNum_int(str, n, base);
}

void *QString_setNum_long(void *str, long n, int base)
{
    return QStringBind::setNum_long(str, n, base);
}

void *QString_setNum_longlong(void *str, long long n, int base)
{
    return QStringBind::setNum_longlong(str, n, base);
}

void *QString_setNum_ulonglong(void *str, unsigned long long n, int base)
{
    return QStringBind::setNum_ulonglong(str, n, base);
}

void *QString_setNum_short(void *str, short n, int base)
{
    return QStringBind::setNum_short(str, n, base);
}

void *QString_setNum_uint(void *str, unsigned int n, int base)
{
    return QStringBind::setNum_uint(str, n, base);
}

void *QString_setNum_ulong(void *str, unsigned long n, int base)
{
    return QStringBind::setNum_ulong(str, n, base);
}

void *QString_setNum_ushort(void *str, unsigned short n, int base)
{
    return QStringBind::setNum_ushort(str, n, base);
}

void *QString_setNum_double(void *str, double n, char format, int precision)
{
    return QStringBind::setNum_double(str, n, format, precision);
}

void *QString_setNum_float(void *str, float n, char format, int precision)
{
    return QStringBind::setNum_float(str, n, format, precision);
}

// 文字列操作
char QString_at(void *str, int position)
{
    return QStringBind::at(str, position);
}

void QString_append(void *str, const char *text)
{
    QStringBind::append(str, text);
}

void QString_append_char(void *str, char ch)
{
    QStringBind::append_char(str, ch);
}

void QString_append_byte_array(void *str, const char *data, int size)
{
    QStringBind::append_byte_array(str, data, size);
}

void QString_prepend(void *str, const char *text)
{
    QStringBind::prepend(str, text);
}

void QString_prepend_char(void *str, char ch)
{
    QStringBind::prepend_char(str, ch);
}

void QString_prepend_byte_array(void *str, const char *data, int size)
{
    QStringBind::prepend_byte_array(str, data, size);
}

void QString_insert(void *str, int position, const char *text)
{
    QStringBind::insert(str, position, text);
}

void QString_insert_char(void *str, int position, char ch)
{
    QStringBind::insert_char(str, position, ch);
}

void QString_insert_byte_array(void *str, int position, const char *data, int size)
{
    QStringBind::insert_byte_array(str, position, data, size);
}

void QString_remove(void *str, int position, int n)
{
    QStringBind::remove(str, position, n);
}

void QString_replace(void *str, int position, int n, const char *after)
{
    QStringBind::replace(str, position, n, after);
}

void QString_replace_char(void *str, int position, int n, char after)
{
    QStringBind::replace_char(str, position, n, after);
}

void QString_replace_byte_array(void *str, int position, int n, const char *data, int size)
{
    QStringBind::replace_byte_array(str, position, n, data, size);
}

// 変換
char *QString_toLower(void *str)
{
    return QStringBind::toLower(str);
}

char *QString_toUpper(void *str)
{
    return QStringBind::toUpper(str);
}

char *QString_trimmed(void *str)
{
    return QStringBind::trimmed(str);
}

char *QString_simplified(void *str)
{
    return QStringBind::simplified(str);
}

char *QString_toCaseFolded(void *str)
{
    return QStringBind::toCaseFolded(str);
}

char *QString_toHtmlEscaped(void *str)
{
    return QStringBind::toHtmlEscaped(str);
}

void QString_truncate(void *str, int position)
{
    QStringBind::truncate(str, position);
}

// 数値変換
double QString_toDouble(void *str, bool *ok)
{
    return QStringBind::toDouble(str, ok);
}

float QString_toFloat(void *str, bool *ok)
{
    return QStringBind::toFloat(str, ok);
}

int QString_toInt(void *str, bool *ok, int base)
{
    return QStringBind::toInt(str, ok, base);
}

long QString_toLong(void *str, bool *ok, int base)
{
    return QStringBind::toLong(str, ok, base);
}

long long QString_toLongLong(void *str, bool *ok, int base)
{
    return QStringBind::toLongLong(str, ok, base);
}

short QString_toShort(void *str, bool *ok, int base)
{
    return QStringBind::toShort(str, ok, base);
}

unsigned int QString_toUInt(void *str, bool *ok, int base)
{
    return QStringBind::toUInt(str, ok, base);
}

unsigned long QString_toULong(void *str, bool *ok, int base)
{
    return QStringBind::toULong(str, ok, base);
}

unsigned long long QString_toULongLong(void *str, bool *ok, int base)
{
    return QStringBind::toULongLong(str, ok, base);
}

unsigned short QString_toUShort(void *str, bool *ok, int base)
{
    return QStringBind::toUShort(str, ok, base);
}

// 検索
int QString_indexOf(void *str, const char *substr, int from)
{
    return QStringBind::indexOf(str, substr, from);
}

int QString_indexOf_char(void *str, char ch, int from)
{
    return QStringBind::indexOf_char(str, ch, from);
}

int QString_lastIndexOf(void *str, const char *substr, int from)
{
    return QStringBind::lastIndexOf(str, substr, from);
}

int QString_lastIndexOf_char(void *str, char ch, int from)
{
    return QStringBind::lastIndexOf_char(str, ch, from);
}

bool QString_contains(void *str, const char *substr)
{
    return QStringBind::contains(str, substr);
}

bool QString_contains_char(void *str, char ch)
{
    return QStringBind::contains_char(str, ch);
}

bool QString_startsWith(void *str, const char *prefix)
{
    return QStringBind::startsWith(str, prefix);
}

bool QString_startsWith_char(void *str, char ch)
{
    return QStringBind::startsWith_char(str, ch);
}

bool QString_endsWith(void *str, const char *suffix)
{
    return QStringBind::endsWith(str, suffix);
}

bool QString_endsWith_char(void *str, char ch)
{
    return QStringBind::endsWith_char(str, ch);
}

// 分割
char **QString_split(void *str, const char *sep, int *count)
{
    return QStringBind::split(str, sep, count);
}

char **QString_split_char(void *str, char sep, int *count)
{
    return QStringBind::split_char(str, sep, count);
}

// 比較
bool QString_equals(void *str, const char *other)
{
    return QStringBind::equals(str, other);
}

bool QString_equals_char(void *str, char ch)
{
    return QStringBind::equals_char(str, ch);
}

int QString_compare(void *str, const char *other, int cs)
{
    return QStringBind::compare(str, other, cs);
}

int QString_compare_char(void *str, char ch, int cs)
{
    return QStringBind::compare_char(str, ch, cs);
}

// カウント
int QString_count(void *str, const char *substr, int cs)
{
    return QStringBind::count(str, substr, cs);
}

int QString_count_char(void *str, char ch, int cs)
{
    return QStringBind::count_char(str, ch, cs);
}

// セクション
char *QString_section(void *str, const char *sep, int start, int end, int flags)
{
    return QStringBind::section(str, sep, start, end, flags);
}

char *QString_section_char(void *str, char sep, int start, int end, int flags)
{
    return QStringBind::section_char(str, sep, start, end, flags);
}

// 正規化
char *QString_normalized(void *str, QString_NormalizationForm mode)
{
    return QStringBind::normalized(str, static_cast<NormalizationForm>(mode));
}

// 追加の文字列操作
char *QString_arg_string(void *str, const char *a)
{
    return QStringBind::arg_string(str, a);
}

char *QString_arg_int(void *str, int a)
{
    return QStringBind::arg_int(str, a);
}

char *QString_arg_long(void *str, long a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_long(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_longlong(void *str, long long a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_longlong(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_short(void *str, short a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_short(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_uint(void *str, unsigned int a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_uint(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_ulong(void *str, unsigned long a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_ulong(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_ushort(void *str, unsigned short a, int fieldWidth, int base, char fillChar)
{
    return QStringBind::arg_ushort(str, a, fieldWidth, base, fillChar);
}

char *QString_arg_double(void *str, double a, int fieldWidth, char format, int precision, char fillChar)
{
    return QStringBind::arg_double(str, a, fieldWidth, format, precision, fillChar);
}

char *QString_arg_char(void *str, char a, int fieldWidth, char fillChar)
{
    return QStringBind::arg_char(str, a, fieldWidth, fillChar);
}

// パディング
char *QString_leftJustified(void *str, int width, char fill, bool truncate)
{
    return QStringBind::leftJustified(str, width, fill, truncate);
}

char *QString_rightJustified(void *str, int width, char fill, bool truncate)
{
    return QStringBind::rightJustified(str, width, fill, truncate);
}
