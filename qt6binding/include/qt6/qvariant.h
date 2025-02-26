#ifndef QT_QVARIANT_H
#define QT_QVARIANT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QVariant作成関数
void *QVariant_create_empty();
void *QVariant_create_string(const char *value);
void *QVariant_create_int(int value);
void *QVariant_create_double(double value);
void *QVariant_create_bool(bool value);
void *QVariant_create_date(int year, int month, int day);
void *QVariant_create_time(int hour, int minute, int second, int msec);
void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec);
void *QVariant_create_point(int x, int y);
void *QVariant_create_rect(int x, int y, int width, int height);
void *QVariant_create_size(int width, int height);

// QVariant削除関数
void QVariant_delete(void *variant);

// 型チェック関数
bool QVariant_isNull(void *variant);
bool QVariant_isValid(void *variant);
bool QVariant_canConvert(void *variant, int targetTypeId);

// 変換関数
char *QVariant_toString(void *variant);
int QVariant_toInt(void *variant, bool *ok);
double QVariant_toDouble(void *variant, bool *ok);
bool QVariant_toBool(void *variant);

// 日付・時間関数
void QVariant_toDate(void *variant, int *year, int *month, int *day);
void QVariant_toTime(void *variant, int *hour, int *minute, int *second, int *msec);
void QVariant_toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec);

// 幾何学関数
void QVariant_toPoint(void *variant, int *x, int *y);
void QVariant_toRect(void *variant, int *x, int *y, int *width, int *height);
void QVariant_toSize(void *variant, int *width, int *height);

#ifdef __cplusplus
}
#endif

#endif // QT_QVARIANT_H
