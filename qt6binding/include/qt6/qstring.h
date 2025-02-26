#ifndef QT_QSTRING_H
#define QT_QSTRING_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 作成・削除
void *QString_create_empty();
void *QString_create_from_utf8(const char *str);
void QString_delete(void *str);

// 基本操作
int QString_length(void *str);
bool QString_isEmpty(void *str);
void QString_clear(void *str);
char *QString_toString(void *str);

// 文字列操作
char QString_at(void *str, int position);
void QString_append(void *str, const char *text);
void QString_prepend(void *str, const char *text);
void QString_insert(void *str, int position, const char *text);
void QString_remove(void *str, int position, int n);
void QString_replace(void *str, int position, int n, const char *after);

// 変換
char *QString_toLower(void *str);
char *QString_toUpper(void *str);
char *QString_trimmed(void *str);
char *QString_simplified(void *str);

// 検索
int QString_indexOf(void *str, const char *substr, int from);
int QString_lastIndexOf(void *str, const char *substr, int from);
bool QString_contains(void *str, const char *substr);
bool QString_startsWith(void *str, const char *prefix);
bool QString_endsWith(void *str, const char *suffix);

// 分割
char **QString_split(void *str, const char *sep, int *count);

// 比較
bool QString_equals(void *str, const char *other);

#ifdef __cplusplus
}
#endif

#endif // QT_QSTRING_H
