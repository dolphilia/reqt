#include "QStringBind.h"
#include "../../include/qt6/qstring.h"

// 作成・削除
void *QString_create_empty()
{
    return QStringBind::create_empty();
}

void *QString_create_from_utf8(const char *str)
{
    return QStringBind::create_from_utf8(str);
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

// 文字列操作
char QString_at(void *str, int position)
{
    return QStringBind::at(str, position);
}

void QString_append(void *str, const char *text)
{
    QStringBind::append(str, text);
}

void QString_prepend(void *str, const char *text)
{
    QStringBind::prepend(str, text);
}

void QString_insert(void *str, int position, const char *text)
{
    QStringBind::insert(str, position, text);
}

void QString_remove(void *str, int position, int n)
{
    QStringBind::remove(str, position, n);
}

void QString_replace(void *str, int position, int n, const char *after)
{
    QStringBind::replace(str, position, n, after);
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

// 検索
int QString_indexOf(void *str, const char *substr, int from)
{
    return QStringBind::indexOf(str, substr, from);
}

int QString_lastIndexOf(void *str, const char *substr, int from)
{
    return QStringBind::lastIndexOf(str, substr, from);
}

bool QString_contains(void *str, const char *substr)
{
    return QStringBind::contains(str, substr);
}

bool QString_startsWith(void *str, const char *prefix)
{
    return QStringBind::startsWith(str, prefix);
}

bool QString_endsWith(void *str, const char *suffix)
{
    return QStringBind::endsWith(str, suffix);
}

// 分割
char **QString_split(void *str, const char *sep, int *count)
{
    return QStringBind::split(str, sep, count);
}

// 比較
bool QString_equals(void *str, const char *other)
{
    return QStringBind::equals(str, other);
}
