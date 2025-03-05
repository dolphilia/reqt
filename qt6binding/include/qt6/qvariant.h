#ifndef QT_QVARIANT_H
#define QT_QVARIANT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 基本型定義
typedef long long qlonglong;
typedef unsigned long long qulonglong;
typedef double qreal;
typedef unsigned int uint;

// QVariant作成関数
void *QVariant_create_empty();
void *QVariant_create_string(const char *value);
void *QVariant_create_int(int value);
void *QVariant_create_uint(uint value);
void *QVariant_create_longlong(qlonglong value);
void *QVariant_create_ulonglong(qulonglong value);
void *QVariant_create_double(double value);
void *QVariant_create_float(float value);
void *QVariant_create_char(char value);
void *QVariant_create_bool(bool value);
void *QVariant_create_bytearray(const char *data, int size);
void *QVariant_create_bitarray(const char *bits, int size);
void *QVariant_create_date(int year, int month, int day);
void *QVariant_create_time(int hour, int minute, int second, int msec);
void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec);
void *QVariant_create_point(int x, int y);
void *QVariant_create_pointf(qreal x, qreal y);
void *QVariant_create_line(int x1, int y1, int x2, int y2);
void *QVariant_create_linef(qreal x1, qreal y1, qreal x2, qreal y2);
void *QVariant_create_rect(int x, int y, int width, int height);
void *QVariant_create_rectf(qreal x, qreal y, qreal width, qreal height);
void *QVariant_create_size(int width, int height);
void *QVariant_create_sizef(qreal width, qreal height);
void *QVariant_create_url(const char *url);
void *QVariant_create_uuid(const char *uuid);
void *QVariant_create_stringlist(const char **strings, int count);
void *QVariant_create_with_type(int type, const void *copy);

// QVariant削除関数
void QVariant_delete(void *variant);

// 型チェック関数
bool QVariant_isNull(void *variant);
bool QVariant_isValid(void *variant);
bool QVariant_canConvert(void *variant, int targetTypeId);
bool QVariant_canView(void *variant, int targetTypeId);
int QVariant_typeId(void *variant);
const char *QVariant_typeName(void *variant);
int QVariant_userType(void *variant);
int QVariant_metaType(void *variant);
bool QVariant_convert(void *variant, int targetTypeId);
void QVariant_clear(void *variant);
void QVariant_swap(void *variant, void *other);
const void *QVariant_constData(void *variant);
void *QVariant_data(void *variant);

// 変換関数
char *QVariant_toString(void *variant);
int QVariant_toInt(void *variant, bool *ok);
uint QVariant_toUInt(void *variant, bool *ok);
qlonglong QVariant_toLongLong(void *variant, bool *ok);
qulonglong QVariant_toULongLong(void *variant, bool *ok);
double QVariant_toDouble(void *variant, bool *ok);
float QVariant_toFloat(void *variant, bool *ok);
qreal QVariant_toReal(void *variant, bool *ok);
bool QVariant_toBool(void *variant);
char QVariant_toChar(void *variant);
void *QVariant_toBitArray(void *variant);
void *QVariant_toByteArray(void *variant);
void *QVariant_toStringList(void *variant);
void *QVariant_toList(void *variant);
void *QVariant_toMap(void *variant);
void *QVariant_toHash(void *variant);
void *QVariant_toUrl(void *variant);
void *QVariant_toUuid(void *variant);
void *QVariant_toRegularExpression(void *variant);
void *QVariant_toLocale(void *variant);
void *QVariant_toEasingCurve(void *variant);
void *QVariant_toJsonArray(void *variant);
void *QVariant_toJsonDocument(void *variant);
void *QVariant_toJsonObject(void *variant);
void *QVariant_toJsonValue(void *variant);
// QModelIndexとQPersistentModelIndexは複雑なため、これらの関数は実装しない

// 日付・時間関数
void QVariant_toDate(void *variant, int *year, int *month, int *day);
void QVariant_toTime(void *variant, int *hour, int *minute, int *second, int *msec);
void QVariant_toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec);

// 幾何学関数
void QVariant_toPoint(void *variant, int *x, int *y);
void QVariant_toPointF(void *variant, qreal *x, qreal *y);
void QVariant_toLine(void *variant, int *x1, int *y1, int *x2, int *y2);
void QVariant_toLineF(void *variant, qreal *x1, qreal *y1, qreal *x2, qreal *y2);
void QVariant_toRect(void *variant, int *x, int *y, int *width, int *height);
void QVariant_toRectF(void *variant, qreal *x, qreal *y, qreal *width, qreal *height);
void QVariant_toSize(void *variant, int *width, int *height);
void QVariant_toSizeF(void *variant, qreal *width, qreal *height);

// 値の設定
void QVariant_setValue_string(void *variant, const char *value);
void QVariant_setValue_int(void *variant, int value);
void QVariant_setValue_double(void *variant, double value);
void QVariant_setValue_bool(void *variant, bool value);
void QVariant_setValue_date(void *variant, int year, int month, int day);
void QVariant_setValue_time(void *variant, int hour, int minute, int second, int msec);
void QVariant_setValue_datetime(void *variant, int year, int month, int day, int hour, int minute, int second, int msec);
void QVariant_setValue_point(void *variant, int x, int y);
void QVariant_setValue_rect(void *variant, int x, int y, int width, int height);
void QVariant_setValue_size(void *variant, int width, int height);

// コールバック関数
typedef void (*QVariant_ValueChangedCallback)(void*, const void*);
void QVariant_setValueChangedCallback(void *variant, QVariant_ValueChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QT_QVARIANT_H
