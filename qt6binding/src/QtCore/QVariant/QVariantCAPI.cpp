#include "QVariantBind.h"
#include "../../include/qt6/qvariant.h"

extern "C" {

// QVariant作成関数
void *QVariant_create_empty() {
    return new QVariantBind();
}

void *QVariant_create_string(const char *value) {
    return new QVariantBind(value);
}

void *QVariant_create_int(int value) {
    return new QVariantBind(value);
}

void *QVariant_create_double(double value) {
    return new QVariantBind(value);
}

void *QVariant_create_bool(bool value) {
    return new QVariantBind(value);
}

void *QVariant_create_date(int year, int month, int day) {
    QDate date(year, month, day);
    return new QVariantBind(date);
}

void *QVariant_create_time(int hour, int minute, int second, int msec) {
    QTime time(hour, minute, second, msec);
    return new QVariantBind(time);
}

void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec) {
    QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second, msec));
    return new QVariantBind(dateTime);
}

void *QVariant_create_point(int x, int y) {
    QPoint point(x, y);
    return new QVariantBind(point);
}

void *QVariant_create_rect(int x, int y, int width, int height) {
    QRect rect(x, y, width, height);
    return new QVariantBind(rect);
}

void *QVariant_create_size(int width, int height) {
    QSize size(width, height);
    return new QVariantBind(size);
}

// QVariant削除関数
void QVariant_delete(void *variant) {
    delete static_cast<QVariantBind*>(variant);
}

// 型チェック関数
bool QVariant_isNull(void *variant) {
    return static_cast<QVariantBind*>(variant)->isNull();
}

bool QVariant_isValid(void *variant) {
    return static_cast<QVariantBind*>(variant)->isValid();
}

bool QVariant_canConvert(void *variant, int targetTypeId) {
    return static_cast<QVariantBind*>(variant)->canConvert(targetTypeId);
}

// 変換関数
char *QVariant_toString(void *variant) {
    QString str = static_cast<QVariantBind*>(variant)->toString();
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

int QVariant_toInt(void *variant, bool *ok) {
    return static_cast<QVariantBind*>(variant)->toInt(ok);
}

double QVariant_toDouble(void *variant, bool *ok) {
    return static_cast<QVariantBind*>(variant)->toDouble(ok);
}

bool QVariant_toBool(void *variant) {
    return static_cast<QVariantBind*>(variant)->toBool();
}

// 日付・時間関数
void QVariant_toDate(void *variant, int *year, int *month, int *day) {
    QDate date = static_cast<QVariantBind*>(variant)->toDate();
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

void QVariant_toTime(void *variant, int *hour, int *minute, int *second, int *msec) {
    QTime time = static_cast<QVariantBind*>(variant)->toTime();
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

void QVariant_toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec) {
    QDateTime dateTime = static_cast<QVariantBind*>(variant)->toDateTime();
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
void QVariant_toPoint(void *variant, int *x, int *y) {
    QPoint point = static_cast<QVariantBind*>(variant)->toPoint();
    *x = point.x();
    *y = point.y();
}

void QVariant_toRect(void *variant, int *x, int *y, int *width, int *height) {
    QRect rect = static_cast<QVariantBind*>(variant)->toRect();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariant_toSize(void *variant, int *width, int *height) {
    QSize size = static_cast<QVariantBind*>(variant)->toSize();
    *width = size.width();
    *height = size.height();
}

}
