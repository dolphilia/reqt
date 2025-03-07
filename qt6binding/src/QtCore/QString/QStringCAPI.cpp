#include "QStringBind.h"
#include <QString>

extern "C" {

// 静的メソッド
char *QString_number_int(int n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_long(long n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_longlong(long long n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_ulonglong(unsigned long long n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_uint(unsigned int n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_ulong(unsigned long n, int base)
{
    QString result = QStringBind::number(n, base);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_number_double(double n, char format, int precision)
{
    QString result = QStringBind::number(n, format, precision);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

int QString_compare_strings(const char *s1, const char *s2, int cs)
{
    return QStringBind::compare(QString::fromUtf8(s1), QString::fromUtf8(s2), static_cast<Qt::CaseSensitivity>(cs));
}

int QString_locale_aware_compare(const char *s1, const char *s2)
{
    return QStringBind::localeAwareCompare(QString::fromUtf8(s1), QString::fromUtf8(s2));
}

void *QString_from_latin1(const char *str, int size)
{
    return new QStringBind(QStringBind::fromLatin1(str, size));
}

void *QString_from_latin1_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLatin1(ba));
}

void *QString_from_utf8_size(const char *str, int size)
{
    return new QStringBind(QStringBind::fromUtf8(str, size));
}

void *QString_from_utf8_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromUtf8(ba));
}

void *QString_from_local8bit(const char *str, int size)
{
    return new QStringBind(QStringBind::fromLocal8Bit(str, size));
}

void *QString_from_local8bit_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLocal8Bit(ba));
}

void *QString_from_ucs4(const char *unicode, int size)
{
    return new QStringBind(QStringBind::fromUcs4(reinterpret_cast<const char32_t*>(unicode), size));
}

void *QString_from_utf16(const char *unicode, int size)
{
    return new QStringBind(QStringBind::fromUtf16(reinterpret_cast<const char16_t*>(unicode), size));
}

void *QString_from_wchar_array(const wchar_t *string, int size)
{
    return new QStringBind(QStringBind::fromWCharArray(string, size));
}

int QString_static_max_size()
{
    return static_cast<int>(QString::maxSize());
}

// 作成・削除
void *QString_create_empty()
{
    return new QStringBind();
}

void *QString_create_from_utf8(const char *str)
{
    return new QStringBind(str);
}

void *QString_create_from_char(char ch)
{
    return new QStringBind(QChar(ch));
}

void *QString_create_from_byte_array(const char *data, int size)
{
    QByteArray ba(data, size);
    return new QStringBind(ba);
}

void *QString_create_with_size(int size, char ch)
{
    return new QStringBind(size, QChar(ch));
}

void QString_delete(void *str)
{
    delete static_cast<QStringBind*>(str);
}

// 基本操作
int QString_length(void *str)
{
    return static_cast<QStringBind*>(str)->length();
}

bool QString_isEmpty(void *str)
{
    return static_cast<QStringBind*>(str)->isEmpty();
}

void QString_clear(void *str)
{
    static_cast<QStringBind*>(str)->clear();
}

char *QString_toString(void *str)
{
    QByteArray utf8 = static_cast<QStringBind*>(str)->toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

int QString_capacity(void *str)
{
    return static_cast<QStringBind*>(str)->capacity();
}

void QString_chop(void *str, int n)
{
    static_cast<QStringBind*>(str)->chop(n);
}

char *QString_chopped(void *str, int len)
{
    QString result = static_cast<QStringBind*>(str)->chopped(len);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

void *QString_fill(void *str, char ch, int size)
{
    static_cast<QStringBind*>(str)->fill(QChar(ch), size);
    return str;
}

char *QString_first(void *str, int n)
{
    QString result = static_cast<QStringBind*>(str)->first(n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_last(void *str, int n)
{
    QString result = static_cast<QStringBind*>(str)->last(n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char QString_front(void *str)
{
    QChar ch = static_cast<QStringBind*>(str)->front();
    return ch.toLatin1();
}

char QString_back(void *str)
{
    QChar ch = static_cast<QStringBind*>(str)->back();
    return ch.toLatin1();
}

bool QString_isNull(void *str)
{
    return static_cast<QStringBind*>(str)->isNull();
}

bool QString_isLower(void *str)
{
    return static_cast<QStringBind*>(str)->isLower();
}

bool QString_isUpper(void *str)
{
    return static_cast<QStringBind*>(str)->isUpper();
}

bool QString_isRightToLeft(void *str)
{
    return static_cast<QStringBind*>(str)->isRightToLeft();
}

char *QString_left(void *str, int n)
{
    QString result = static_cast<QStringBind*>(str)->left(n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_right(void *str, int n)
{
    QString result = static_cast<QStringBind*>(str)->right(n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_mid(void *str, int position, int n)
{
    QString result = static_cast<QStringBind*>(str)->mid(position, n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

int QString_max_size(void *str)
{
    return static_cast<QStringBind*>(str)->capacity();
}

void QString_reserve(void *str, int size)
{
    static_cast<QStringBind*>(str)->reserve(size);
}

void QString_resize(void *str, int size)
{
    static_cast<QStringBind*>(str)->resize(size);
}

void QString_resize_with_char(void *str, int size, char fillChar)
{
    static_cast<QStringBind*>(str)->resize(size, QChar(fillChar));
}

char *QString_repeated(void *str, int times)
{
    QString result = static_cast<QStringBind*>(str)->repeated(times);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_sliced(void *str, int position, int n)
{
    QString result = static_cast<QStringBind*>(str)->sliced(position, n);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_sliced_from(void *str, int position)
{
    QString result = static_cast<QStringBind*>(str)->sliced(position);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

void QString_shrink_to_fit(void *str)
{
    static_cast<QStringBind*>(str)->squeeze();
}

void QString_squeeze(void *str)
{
    static_cast<QStringBind*>(str)->squeeze();
}

void QString_swap(void *str, void *other)
{
    static_cast<QStringBind*>(str)->swap(*static_cast<QStringBind*>(other));
}

// 数値変換
void *QString_setNum_int(void *str, int n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_long(void *str, long n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_longlong(void *str, long long n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_ulonglong(void *str, unsigned long long n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_short(void *str, short n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_uint(void *str, unsigned int n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_ulong(void *str, unsigned long n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_ushort(void *str, unsigned short n, int base)
{
    static_cast<QStringBind*>(str)->setNum(n, base);
    return str;
}

void *QString_setNum_double(void *str, double n, char format, int precision)
{
    static_cast<QStringBind*>(str)->setNum(n, format, precision);
    return str;
}

void *QString_setNum_float(void *str, float n, char format, int precision)
{
    static_cast<QStringBind*>(str)->setNum(n, format, precision);
    return str;
}

// 文字列操作
char QString_at(void *str, int position)
{
    QChar ch = static_cast<QStringBind*>(str)->at(position);
    return ch.toLatin1();
}

void QString_append(void *str, const char *text)
{
    static_cast<QStringBind*>(str)->append(QString::fromUtf8(text));
}

void QString_append_char(void *str, char ch)
{
    static_cast<QStringBind*>(str)->append(QChar(ch));
}

void QString_append_byte_array(void *str, const char *data, int size)
{
    QByteArray ba(data, size);
    static_cast<QStringBind*>(str)->append(QString::fromUtf8(ba));
}

void QString_prepend(void *str, const char *text)
{
    static_cast<QStringBind*>(str)->prepend(QString::fromUtf8(text));
}

void QString_prepend_char(void *str, char ch)
{
    static_cast<QStringBind*>(str)->prepend(QChar(ch));
}

void QString_prepend_byte_array(void *str, const char *data, int size)
{
    QByteArray ba(data, size);
    static_cast<QStringBind*>(str)->prepend(QString::fromUtf8(ba));
}

void QString_insert(void *str, int position, const char *text)
{
    static_cast<QStringBind*>(str)->insert(position, QString::fromUtf8(text));
}

void QString_insert_char(void *str, int position, char ch)
{
    static_cast<QStringBind*>(str)->insert(position, QChar(ch));
}

void QString_insert_byte_array(void *str, int position, const char *data, int size)
{
    QByteArray ba(data, size);
    static_cast<QStringBind*>(str)->insert(position, QString::fromUtf8(ba));
}

void QString_remove(void *str, int position, int n)
{
    static_cast<QStringBind*>(str)->remove(position, n);
}

void QString_replace(void *str, int position, int n, const char *after)
{
    static_cast<QStringBind*>(str)->replace(position, n, QString::fromUtf8(after));
}

void QString_replace_char(void *str, int position, int n, char after)
{
    static_cast<QStringBind*>(str)->replace(position, n, QChar(after));
}

void QString_replace_byte_array(void *str, int position, int n, const char *data, int size)
{
    QByteArray ba(data, size);
    static_cast<QStringBind*>(str)->replace(position, n, QString::fromUtf8(ba));
}

// 変換
char *QString_toLower(void *str)
{
    QString result = static_cast<QStringBind*>(str)->toLower();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_toUpper(void *str)
{
    QString result = static_cast<QStringBind*>(str)->toUpper();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_trimmed(void *str)
{
    QString result = static_cast<QStringBind*>(str)->trimmed();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_simplified(void *str)
{
    QString result = static_cast<QStringBind*>(str)->simplified();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_toCaseFolded(void *str)
{
    QString result = static_cast<QStringBind*>(str)->toCaseFolded();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_toHtmlEscaped(void *str)
{
    QString result = static_cast<QStringBind*>(str)->toHtmlEscaped();
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

void QString_truncate(void *str, int position)
{
    static_cast<QStringBind*>(str)->truncate(position);
}

// 数値変換
double QString_toDouble(void *str, bool *ok)
{
    return static_cast<QStringBind*>(str)->toDouble(ok);
}

float QString_toFloat(void *str, bool *ok)
{
    return static_cast<QStringBind*>(str)->toFloat(ok);
}

int QString_toInt(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toInt(ok, base);
}

long QString_toLong(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toLong(ok, base);
}

long long QString_toLongLong(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toLongLong(ok, base);
}

short QString_toShort(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toShort(ok, base);
}

unsigned int QString_toUInt(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toUInt(ok, base);
}

unsigned long QString_toULong(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toULong(ok, base);
}

unsigned long long QString_toULongLong(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toULongLong(ok, base);
}

unsigned short QString_toUShort(void *str, bool *ok, int base)
{
    return static_cast<QStringBind*>(str)->toUShort(ok, base);
}

// 検索
int QString_indexOf(void *str, const char *substr, int from)
{
    return static_cast<QStringBind*>(str)->indexOf(QString::fromUtf8(substr), from);
}

int QString_indexOf_char(void *str, char ch, int from)
{
    return static_cast<QStringBind*>(str)->indexOf(QChar(ch), from);
}

int QString_lastIndexOf(void *str, const char *substr, int from)
{
    return static_cast<QStringBind*>(str)->lastIndexOf(QString::fromUtf8(substr), from);
}

int QString_lastIndexOf_char(void *str, char ch, int from)
{
    return static_cast<QStringBind*>(str)->lastIndexOf(QChar(ch), from);
}

bool QString_contains(void *str, const char *substr)
{
    return static_cast<QStringBind*>(str)->contains(QString::fromUtf8(substr));
}

bool QString_contains_char(void *str, char ch)
{
    return static_cast<QStringBind*>(str)->contains(QChar(ch));
}

bool QString_startsWith(void *str, const char *prefix)
{
    return static_cast<QStringBind*>(str)->startsWith(QString::fromUtf8(prefix));
}

bool QString_startsWith_char(void *str, char ch)
{
    return static_cast<QStringBind*>(str)->startsWith(QChar(ch));
}

bool QString_endsWith(void *str, const char *suffix)
{
    return static_cast<QStringBind*>(str)->endsWith(QString::fromUtf8(suffix));
}

bool QString_endsWith_char(void *str, char ch)
{
    return static_cast<QStringBind*>(str)->endsWith(QChar(ch));
}

// 分割
char **QString_split(void *str, const char *sep, int *count)
{
    QStringList list = static_cast<QStringBind*>(str)->split(QString::fromUtf8(sep));
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}

char **QString_split_char(void *str, char sep, int *count)
{
    QStringList list = static_cast<QStringBind*>(str)->split(QChar(sep));
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}

// 比較
bool QString_equals(void *str, const char *other)
{
    return *static_cast<QStringBind*>(str) == QString::fromUtf8(other);
}

bool QString_equals_char(void *str, char ch)
{
    return *static_cast<QStringBind*>(str) == QString(QChar(ch));
}

int QString_compare(void *str, const char *other, int cs)
{
    return static_cast<QStringBind*>(str)->compare(QString::fromUtf8(other), static_cast<Qt::CaseSensitivity>(cs));
}

int QString_compare_char(void *str, char ch, int cs)
{
    return static_cast<QStringBind*>(str)->compare(QString(QChar(ch)), static_cast<Qt::CaseSensitivity>(cs));
}

// カウント
int QString_count(void *str, const char *substr, int cs)
{
    return static_cast<QStringBind*>(str)->count(QString::fromUtf8(substr), static_cast<Qt::CaseSensitivity>(cs));
}

int QString_count_char(void *str, char ch, int cs)
{
    return static_cast<QStringBind*>(str)->count(QChar(ch), static_cast<Qt::CaseSensitivity>(cs));
}

// セクション
char *QString_section(void *str, const char *sep, int start, int end, int flags)
{
    QString result = static_cast<QStringBind*>(str)->section(QString::fromUtf8(sep), start, end, QFlags<QString::SectionFlag>(flags));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_section_char(void *str, char sep, int start, int end, int flags)
{
    QString result = static_cast<QStringBind*>(str)->section(QChar(sep), start, end, QFlags<QString::SectionFlag>(flags));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

// 正規化
char *QString_normalized(void *str, int mode)
{
    QString result = static_cast<QStringBind*>(str)->normalized(static_cast<QString::NormalizationForm>(mode));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

// 追加の文字列操作
char *QString_arg_string(void *str, const char *a)
{
    QString result = static_cast<QStringBind*>(str)->arg(QString::fromUtf8(a));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_int(void *str, int a)
{
    QString result = static_cast<QStringBind*>(str)->arg(a);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_long(void *str, long a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_longlong(void *str, long long a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(static_cast<qlonglong>(a), fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_short(void *str, short a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_uint(void *str, unsigned int a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_ulong(void *str, unsigned long a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_ushort(void *str, unsigned short a, int fieldWidth, int base, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_double(void *str, double a, int fieldWidth, char format, int precision, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, format, precision, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_arg_char(void *str, char a, int fieldWidth, char fillChar)
{
    QString result = static_cast<QStringBind*>(str)->arg(QChar(a), fieldWidth, QChar(fillChar));
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

// パディング
char *QString_leftJustified(void *str, int width, char fill, bool truncate)
{
    QString result = static_cast<QStringBind*>(str)->leftJustified(width, QChar(fill), truncate);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

char *QString_rightJustified(void *str, int width, char fill, bool truncate)
{
    QString result = static_cast<QStringBind*>(str)->rightJustified(width, QChar(fill), truncate);
    QByteArray utf8 = result.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *resultStr = new char[size + 1];
    if (size > 0) {
        memcpy(resultStr, data, size);
    }
    resultStr[size] = '\0';
    
    return resultStr;
}

}