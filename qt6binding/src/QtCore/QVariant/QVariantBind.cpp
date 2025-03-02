#include "QVariantBind.h"
#include <cstring>

// 作成関数
void *QVariantBind::create_empty()
{
    return new QVariantHandler();
}

void *QVariantBind::create_string(const char *value)
{
    return new QVariantHandler(value);
}

void *QVariantBind::create_int(int value)
{
    return new QVariantHandler(value);
}

void *QVariantBind::create_double(double value)
{
    return new QVariantHandler(value);
}

void *QVariantBind::create_bool(bool value)
{
    return new QVariantHandler(value);
}

void *QVariantBind::create_date(int year, int month, int day)
{
    QDate date(year, month, day);
    return new QVariantHandler(date);
}

void *QVariantBind::create_time(int hour, int minute, int second, int msec)
{
    QTime time(hour, minute, second, msec);
    return new QVariantHandler(time);
}

void *QVariantBind::create_datetime(int year, int month, int day, int hour, int minute, int second, int msec)
{
    QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second, msec));
    return new QVariantHandler(dateTime);
}

void *QVariantBind::create_point(int x, int y)
{
    QPoint point(x, y);
    return new QVariantHandler(point);
}

void *QVariantBind::create_rect(int x, int y, int width, int height)
{
    QRect rect(x, y, width, height);
    return new QVariantHandler(rect);
}

void *QVariantBind::create_size(int width, int height)
{
    QSize size(width, height);
    return new QVariantHandler(size);
}

// 削除関数
void QVariantBind::delete_variant(void *variant)
{
    delete handler(variant);
}

// 型チェック関数
bool QVariantBind::isNull(void *variant)
{
    return handler(variant)->isNull();
}

bool QVariantBind::isValid(void *variant)
{
    return handler(variant)->isValid();
}

bool QVariantBind::canConvert(void *variant, int targetTypeId)
{
    return handler(variant)->canConvert(targetTypeId);
}

// 変換関数
char *QVariantBind::toString(void *variant)
{
    QString str = handler(variant)->toString();
    QByteArray utf8 = str.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();
    
    char *result = new char[size + 1];
    if (size > 0) {
        memcpy(result, data, size);
    }
    result[size] = '\0';
    
    return result;
}

int QVariantBind::toInt(void *variant, bool *ok)
{
    return handler(variant)->toInt(ok);
}

double QVariantBind::toDouble(void *variant, bool *ok)
{
    return handler(variant)->toDouble(ok);
}

bool QVariantBind::toBool(void *variant)
{
    return handler(variant)->toBool();
}

// 日付・時間関数
void QVariantBind::toDate(void *variant, int *year, int *month, int *day)
{
    QDate date = handler(variant)->toDate();
    if (date.isValid()) {
        *year = date.year();
        *month = date.month();
        *day = date.day();
    } else {
        *year = 0;
        *month = 0;
        *day = 0;
    }
}

void QVariantBind::toTime(void *variant, int *hour, int *minute, int *second, int *msec)
{
    QTime time = handler(variant)->toTime();
    if (time.isValid()) {
        *hour = time.hour();
        *minute = time.minute();
        *second = time.second();
        *msec = time.msec();
    } else {
        *hour = 0;
        *minute = 0;
        *second = 0;
        *msec = 0;
    }
}

void QVariantBind::toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec)
{
    QDateTime dateTime = handler(variant)->toDateTime();
    if (dateTime.isValid()) {
        QDate date = dateTime.date();
        QTime time = dateTime.time();
        *year = date.year();
        *month = date.month();
        *day = date.day();
        *hour = time.hour();
        *minute = time.minute();
        *second = time.second();
        *msec = time.msec();
    } else {
        *year = 0;
        *month = 0;
        *day = 0;
        *hour = 0;
        *minute = 0;
        *second = 0;
        *msec = 0;
    }
}

// 幾何学関数
void QVariantBind::toPoint(void *variant, int *x, int *y)
{
    QPoint point = handler(variant)->toPoint();
    *x = point.x();
    *y = point.y();
}

void QVariantBind::toRect(void *variant, int *x, int *y, int *width, int *height)
{
    QRect rect = handler(variant)->toRect();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariantBind::toSize(void *variant, int *width, int *height)
{
    QSize size = handler(variant)->toSize();
    *width = size.width();
    *height = size.height();
}

QVariantHandler *QVariantBind::handler(void *variant)
{
    return static_cast<QVariantHandler *>(variant);
}
