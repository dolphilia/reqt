#ifndef QT_QVARIANTBIND_H
#define QT_QVARIANTBIND_H

#include "QVariantHandler.h"
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QPoint>
#include <QRect>
#include <QSize>

class QVariantBind {
public:
    // 作成関数
    static void *create_empty();
    static void *create_string(const char *value);
    static void *create_int(int value);
    static void *create_double(double value);
    static void *create_bool(bool value);
    static void *create_date(int year, int month, int day);
    static void *create_time(int hour, int minute, int second, int msec = 0);
    static void *create_datetime(int year, int month, int day, int hour, int minute, int second, int msec = 0);
    static void *create_point(int x, int y);
    static void *create_rect(int x, int y, int width, int height);
    static void *create_size(int width, int height);
    
    // 削除関数
    static void delete_variant(void *variant);
    
    // 型チェック関数
    static bool isNull(void *variant);
    static bool isValid(void *variant);
    static bool canConvert(void *variant, int targetTypeId);
    
    // 変換関数
    static char *toString(void *variant);
    static int toInt(void *variant, bool *ok);
    static double toDouble(void *variant, bool *ok);
    static bool toBool(void *variant);
    
    // 日付・時間関数
    static void toDate(void *variant, int *year, int *month, int *day);
    static void toTime(void *variant, int *hour, int *minute, int *second, int *msec);
    static void toDateTime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec);
    
    // 幾何学関数
    static void toPoint(void *variant, int *x, int *y);
    static void toRect(void *variant, int *x, int *y, int *width, int *height);
    static void toSize(void *variant, int *width, int *height);

private:
    static QVariantHandler *handler(void *variant);
};

#endif // QT_QVARIANTBIND_H
