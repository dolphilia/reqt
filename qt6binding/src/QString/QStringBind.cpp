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

void QStringBind::delete_string(void *str)
{
    delete handler(str);
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

void QStringBind::prepend(void *str, const char *text)
{
    handler(str)->prepend(text);
}

void QStringBind::insert(void *str, int position, const char *text)
{
    handler(str)->insert(position, text);
}

void QStringBind::remove(void *str, int position, int n)
{
    handler(str)->remove(position, n);
}

void QStringBind::replace(void *str, int position, int n, const char *after)
{
    handler(str)->replace(position, n, after);
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

// 検索
int QStringBind::indexOf(void *str, const char *substr, int from)
{
    return handler(str)->indexOf(substr, from);
}

int QStringBind::lastIndexOf(void *str, const char *substr, int from)
{
    return handler(str)->lastIndexOf(substr, from);
}

bool QStringBind::contains(void *str, const char *substr)
{
    return handler(str)->contains(substr);
}

bool QStringBind::startsWith(void *str, const char *prefix)
{
    return handler(str)->startsWith(prefix);
}

bool QStringBind::endsWith(void *str, const char *suffix)
{
    return handler(str)->endsWith(suffix);
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

// 比較
bool QStringBind::equals(void *str, const char *other)
{
    return handler(str)->equals(other);
}

QStringHandler *QStringBind::handler(void *str)
{
    return static_cast<QStringHandler *>(str);
}
