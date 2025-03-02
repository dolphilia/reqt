#include "QStringBind.h"
#include <cstring>

// 作成・削除
void *QStringBind::create_empty()
{
    return new QStringHandler();
}

void *QStringBind::create_from_utf8(const char *str)
{
    return new QStringHandler(str);
}

void *QStringBind::create_from_char(char ch)
{
    return new QStringHandler(QChar(ch));
}

void *QStringBind::create_from_byte_array(const char *data, int size)
{
    QByteArray ba(data, size);
    return new QStringHandler(ba);
}

void *QStringBind::create_with_size(int size, char ch)
{
    return new QStringHandler(size, QChar(ch));
}

void QStringBind::delete_string(void *str)
{
    delete handler(str);
}

// 静的メソッド
char *QStringBind::number_int(int n, int base)
{
    QString result = QString::number(n, base);
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

char *QStringBind::number_long(long n, int base)
{
    QString result = QString::number(n, base);
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

char *QStringBind::number_longlong(long long n, int base)
{
    QString result = QString::number(static_cast<qlonglong>(n), base);
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

char *QStringBind::number_ulonglong(unsigned long long n, int base)
{
    QString result = QString::number(static_cast<qulonglong>(n), base);
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

char *QStringBind::number_uint(unsigned int n, int base)
{
    QString result = QString::number(n, base);
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

char *QStringBind::number_ulong(unsigned long n, int base)
{
    QString result = QString::number(n, base);
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

char *QStringBind::number_double(double n, char format, int precision)
{
    QString result = QString::number(n, format, precision);
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

int QStringBind::compare_strings(const char *s1, const char *s2, int cs)
{
    return QString::compare(QString::fromUtf8(s1), QString::fromUtf8(s2), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringBind::locale_aware_compare(const char *s1, const char *s2)
{
    return QString::localeAwareCompare(QString::fromUtf8(s1), QString::fromUtf8(s2));
}

void *QStringBind::from_latin1(const char *str, int size)
{
    return new QStringHandler(QString::fromLatin1(str, size));
}

void *QStringBind::from_latin1_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringHandler(QString::fromLatin1(ba));
}

void *QStringBind::from_utf8_size(const char *str, int size)
{
    return new QStringHandler(QString::fromUtf8(str, size));
}

void *QStringBind::from_utf8_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringHandler(QString::fromUtf8(ba));
}

void *QStringBind::from_local8bit(const char *str, int size)
{
    return new QStringHandler(QString::fromLocal8Bit(str, size));
}

void *QStringBind::from_local8bit_ba(const char *str)
{
    QByteArray ba(str);
    return new QStringHandler(QString::fromLocal8Bit(ba));
}

void *QStringBind::from_ucs4(const char *unicode, int size)
{
    return new QStringHandler(QString::fromUcs4(reinterpret_cast<const char32_t*>(unicode), size));
}

void *QStringBind::from_utf16(const char *unicode, int size)
{
    return new QStringHandler(QString::fromUtf16(reinterpret_cast<const char16_t*>(unicode), size));
}

void *QStringBind::from_wchar_array(const wchar_t *string, int size)
{
    return new QStringHandler(QString::fromWCharArray(string, size));
}

int QStringBind::max_size()
{
    return QString::maxSize();
}

// 基本操作
int QStringBind::length(void *str)
{
    return handler(str)->length();
}

bool QStringBind::isEmpty(void *str)
{
    return handler(str)->isEmpty();
}

void QStringBind::clear(void *str)
{
    handler(str)->clear();
}

char *QStringBind::toString(void *str)
{
    QByteArray utf8 = handler(str)->toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

int QStringBind::capacity(void *str)
{
    return handler(str)->capacity();
}

void QStringBind::chop(void *str, int n)
{
    handler(str)->chop(n);
}

char *QStringBind::chopped(void *str, int len)
{
    QString result = handler(str)->chopped(len);
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

void *QStringBind::fill(void *str, char ch, int size)
{
    handler(str)->fill(QChar(ch), size);
    return str;
}

char *QStringBind::first(void *str, int n)
{
    QString result = handler(str)->first(n);
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

char *QStringBind::last(void *str, int n)
{
    QString result = handler(str)->last(n);
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

char QStringBind::front(void *str)
{
    QChar ch = handler(str)->front();
    return ch.toLatin1();
}

char QStringBind::back(void *str)
{
    QChar ch = handler(str)->back();
    return ch.toLatin1();
}

bool QStringBind::isNull(void *str)
{
    return handler(str)->isNull();
}

bool QStringBind::isLower(void *str)
{
    return handler(str)->isLower();
}

bool QStringBind::isUpper(void *str)
{
    return handler(str)->isUpper();
}

bool QStringBind::isRightToLeft(void *str)
{
    return handler(str)->isRightToLeft();
}

char *QStringBind::left(void *str, int n)
{
    QString result = handler(str)->left(n);
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

char *QStringBind::right(void *str, int n)
{
    QString result = handler(str)->right(n);
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

char *QStringBind::mid(void *str, int position, int n)
{
    QString result = handler(str)->mid(position, n);
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

int QStringBind::max_size(void *str)
{
    return handler(str)->max_size();
}

void QStringBind::reserve(void *str, int size)
{
    handler(str)->reserve(size);
}

void QStringBind::resize(void *str, int size)
{
    handler(str)->resize(size);
}

void QStringBind::resize_with_char(void *str, int size, char fillChar)
{
    handler(str)->resize(size, QChar(fillChar));
}

char *QStringBind::repeated(void *str, int times)
{
    QString result = handler(str)->repeated(times);
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

char *QStringBind::sliced(void *str, int position, int n)
{
    QString result = handler(str)->sliced(position, n);
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

char *QStringBind::sliced_from(void *str, int position)
{
    QString result = handler(str)->sliced(position);
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

void QStringBind::shrink_to_fit(void *str)
{
    handler(str)->shrink_to_fit();
}

void QStringBind::squeeze(void *str)
{
    handler(str)->squeeze();
}

void QStringBind::swap(void *str, void *other)
{
    QString otherStr;
    handler(str)->swap(otherStr);
    *handler(other)->string() = otherStr;
}

// 数値変換
void *QStringBind::setNum_int(void *str, int n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_long(void *str, long n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_longlong(void *str, long long n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_ulonglong(void *str, unsigned long long n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_short(void *str, short n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_uint(void *str, unsigned int n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_ulong(void *str, unsigned long n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_ushort(void *str, unsigned short n, int base)
{
    handler(str)->setNum(n, base);
    return str;
}

void *QStringBind::setNum_double(void *str, double n, char format, int precision)
{
    handler(str)->setNum(n, format, precision);
    return str;
}

void *QStringBind::setNum_float(void *str, float n, char format, int precision)
{
    handler(str)->setNum(n, format, precision);
    return str;
}

// 文字列操作
char QStringBind::at(void *str, int position)
{
    QString ch = handler(str)->at(position);
    if (ch.isEmpty()) {
        return '\0';
    }
    return ch.at(0).toLatin1();
}

void QStringBind::append(void *str, const char *text)
{
    handler(str)->append(text);
}

void QStringBind::append_char(void *str, char ch)
{
    handler(str)->append(QChar(ch));
}

void QStringBind::append_byte_array(void *str, const char *data, int size)
{
    QByteArray ba(data, size);
    handler(str)->append(ba);
}

void QStringBind::prepend(void *str, const char *text)
{
    handler(str)->prepend(text);
}

void QStringBind::prepend_char(void *str, char ch)
{
    handler(str)->prepend(QChar(ch));
}

void QStringBind::prepend_byte_array(void *str, const char *data, int size)
{
    QByteArray ba(data, size);
    handler(str)->prepend(ba);
}

void QStringBind::insert(void *str, int position, const char *text)
{
    handler(str)->insert(position, text);
}

void QStringBind::insert_char(void *str, int position, char ch)
{
    handler(str)->insert(position, QChar(ch));
}

void QStringBind::insert_byte_array(void *str, int position, const char *data, int size)
{
    QByteArray ba(data, size);
    handler(str)->insert(position, ba);
}

void QStringBind::remove(void *str, int position, int n)
{
    handler(str)->remove(position, n);
}

void QStringBind::replace(void *str, int position, int n, const char *after)
{
    handler(str)->replace(position, n, after);
}

void QStringBind::replace_char(void *str, int position, int n, char after)
{
    handler(str)->replace(position, n, QChar(after));
}

void QStringBind::replace_byte_array(void *str, int position, int n, const char *data, int size)
{
    QByteArray ba(data, size);
    handler(str)->replace(position, n, ba);
}

// 変換
char *QStringBind::toLower(void *str)
{
    QByteArray utf8 = handler(str)->toLower().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

char *QStringBind::toUpper(void *str)
{
    QByteArray utf8 = handler(str)->toUpper().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

char *QStringBind::trimmed(void *str)
{
    QByteArray utf8 = handler(str)->trimmed().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

char *QStringBind::simplified(void *str)
{
    QByteArray utf8 = handler(str)->simplified().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

char *QStringBind::toCaseFolded(void *str)
{
    QByteArray utf8 = handler(str)->toCaseFolded().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

char *QStringBind::toHtmlEscaped(void *str)
{
    QByteArray utf8 = handler(str)->toHtmlEscaped().toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

void QStringBind::truncate(void *str, int position)
{
    handler(str)->truncate(position);
}

// 数値変換
double QStringBind::toDouble(void *str, bool *ok)
{
    return handler(str)->toDouble(ok);
}

float QStringBind::toFloat(void *str, bool *ok)
{
    return handler(str)->toFloat(ok);
}

int QStringBind::toInt(void *str, bool *ok, int base)
{
    return handler(str)->toInt(ok, base);
}

long QStringBind::toLong(void *str, bool *ok, int base)
{
    return handler(str)->toLong(ok, base);
}

long long QStringBind::toLongLong(void *str, bool *ok, int base)
{
    return handler(str)->toLongLong(ok, base);
}

short QStringBind::toShort(void *str, bool *ok, int base)
{
    return handler(str)->toShort(ok, base);
}

unsigned int QStringBind::toUInt(void *str, bool *ok, int base)
{
    return handler(str)->toUInt(ok, base);
}

unsigned long QStringBind::toULong(void *str, bool *ok, int base)
{
    return handler(str)->toULong(ok, base);
}

unsigned long long QStringBind::toULongLong(void *str, bool *ok, int base)
{
    return handler(str)->toULongLong(ok, base);
}

unsigned short QStringBind::toUShort(void *str, bool *ok, int base)
{
    return handler(str)->toUShort(ok, base);
}

// 検索
int QStringBind::indexOf(void *str, const char *substr, int from)
{
    return handler(str)->indexOf(substr, from);
}

int QStringBind::indexOf_char(void *str, char ch, int from)
{
    return handler(str)->indexOf(QChar(ch), from);
}

int QStringBind::lastIndexOf(void *str, const char *substr, int from)
{
    return handler(str)->lastIndexOf(substr, from);
}

int QStringBind::lastIndexOf_char(void *str, char ch, int from)
{
    return handler(str)->lastIndexOf(QChar(ch), from);
}

bool QStringBind::contains(void *str, const char *substr)
{
    return handler(str)->contains(substr);
}

bool QStringBind::contains_char(void *str, char ch)
{
    return handler(str)->contains(QChar(ch));
}

bool QStringBind::startsWith(void *str, const char *prefix)
{
    return handler(str)->startsWith(prefix);
}

bool QStringBind::startsWith_char(void *str, char ch)
{
    return handler(str)->startsWith(QChar(ch));
}

bool QStringBind::endsWith(void *str, const char *suffix)
{
    return handler(str)->endsWith(suffix);
}

bool QStringBind::endsWith_char(void *str, char ch)
{
    return handler(str)->endsWith(QChar(ch));
}

// 分割
char **QStringBind::split(void *str, const char *sep, int *count)
{
    QStringList list = handler(str)->split(sep);
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

char **QStringBind::split_char(void *str, char sep, int *count)
{
    QStringList list = handler(str)->split(QChar(sep));
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
bool QStringBind::equals(void *str, const char *other)
{
    return handler(str)->equals(other);
}

bool QStringBind::equals_char(void *str, char ch)
{
    return handler(str)->equals(QChar(ch));
}

int QStringBind::compare(void *str, const char *other, int cs)
{
    return handler(str)->compare(other, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringBind::compare_char(void *str, char ch, int cs)
{
    return handler(str)->compare(QChar(ch), static_cast<Qt::CaseSensitivity>(cs));
}

// カウント
int QStringBind::count(void *str, const char *substr, int cs)
{
    return handler(str)->count(substr, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringBind::count_char(void *str, char ch, int cs)
{
    return handler(str)->count(QChar(ch), static_cast<Qt::CaseSensitivity>(cs));
}

// セクション
char *QStringBind::section(void *str, const char *sep, int start, int end, int flags)
{
    QString result = handler(str)->section(sep, start, end, flags);
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

char *QStringBind::section_char(void *str, char sep, int start, int end, int flags)
{
    QString result = handler(str)->section(QChar(sep), start, end, flags);
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
char *QStringBind::normalized(void *str, NormalizationForm mode)
{
    QString result = handler(str)->normalized(mode);
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
char *QStringBind::arg_string(void *str, const char *a)
{
    QString result = handler(str)->arg(a);
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

char *QStringBind::arg_int(void *str, int a)
{
    QString result = handler(str)->arg(a);
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

char *QStringBind::arg_long(void *str, long a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_longlong(void *str, long long a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(static_cast<qlonglong>(a), fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_short(void *str, short a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_uint(void *str, unsigned int a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_ulong(void *str, unsigned long a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_ushort(void *str, unsigned short a, int fieldWidth, int base, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, base, QChar(fillChar));
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

char *QStringBind::arg_double(void *str, double a, int fieldWidth, char format, int precision, char fillChar)
{
    QString result = handler(str)->arg(a, fieldWidth, format, precision, QChar(fillChar));
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

char *QStringBind::arg_char(void *str, char a, int fieldWidth, char fillChar)
{
    QString result = handler(str)->arg(QChar(a), fieldWidth, QChar(fillChar));
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
char *QStringBind::leftJustified(void *str, int width, char fill, bool truncate)
{
    QString result = handler(str)->leftJustified(width, QChar(fill), truncate);
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

char *QStringBind::rightJustified(void *str, int width, char fill, bool truncate)
{
    QString result = handler(str)->rightJustified(width, QChar(fill), truncate);
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

QStringHandler *QStringBind::handler(void *str)
{
    return static_cast<QStringHandler *>(str);
}
