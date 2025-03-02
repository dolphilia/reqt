#include "QVariantBind.h"
#include "../../include/qt6/qvariant.h"

// QVariant作成関数
void *QVariant_create_empty()
{
    return QVariantBind::create_empty();
}

void *QVariant_create_string(const char *value)
{
    return QVariantBind::create_string(value);
}

void *QVariant_create_int(int value)
{
    return QVariantBind::create_int(value);
}

void *QVariant_create_double(double value)
{
    return QVariantBind::create_double(value);
}

void *QVariant_create_bool(bool value)
{
    return QVariantBind::create_bool(value);
}

void *QVariant_create_date(int year, int month, int day)
{
    return QVariantBind::create_date(year, month, day);
}

void *QVariant_create_time(int hour, int minute, int second, int msec)
{
    return QVariantBind::create_time(hour, minute, second, msec);
}

void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec)
{
    return QVariantBind::create_datetime(year, month, day, hour, minute, second, msec);
}

void *QVariant_create_point(int x, int y)
{
    return QVariantBind::create_point(x, y);
}

void *QVariant_create_rect(int x, int y, int width, int height)
{
    return QVariantBind::create_rect(x, y, width, height);
}

void *QVariant_create_size(int width, int height)
{
    return QVariantBind::create_size(width, height);
}

// QVariant削除関数
void QVariant_delete(void *variant)
{
    QVariantBind::delete_variant(variant);
}

// 型チェック関数
bool QVariant_isNull(void *variant)
{
    return QVariantBind::isNull(variant);
}

bool QVariant_isValid(void *variant)
{
    return QVariantBind::isValid(variant);
}

bool QVariant_canConvert(void *variant, int targetTypeId)
{
    return QVariantBind::canConvert(variant, targetTypeId);
}

// 変換関数
char *QVariant_toString(void *variant)
{
    return QVariantBind::toString(variant);
}

int QVariant_toInt(void *variant, bool *ok)
{
    return QVariantBind::toInt(variant, ok);
}

double QVariant_toDouble(void *variant, bool *ok)
{
    return QVariantBind::toDouble(variant, ok);
}

bool QVariant_toBool(void *variant)
{
    return QVariantBind::toBool(variant);
}

// 日付・時間関数
void QVariant_toDate(void *variant, int *year, int *month, int *day)
{
    QVariantBind::toDate(variant, year, month, day);
}

void QVariant_toTime(void *variant, int *hour, int *minute, int *second, int *msec)
{
    QVariantBind::toTime(variant, hour, minute, second, msec);
}

void QVariant_toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec)
{
    QVariantBind::toDateTime(variant, year, month, day, hour, minute, second, msec);
}

// 幾何学関数
void QVariant_toPoint(void *variant, int *x, int *y)
{
    QVariantBind::toPoint(variant, x, y);
}

void QVariant_toRect(void *variant, int *x, int *y, int *width, int *height)
{
    QVariantBind::toRect(variant, x, y, width, height);
}

void QVariant_toSize(void *variant, int *width, int *height)
{
    QVariantBind::toSize(variant, width, height);
}
