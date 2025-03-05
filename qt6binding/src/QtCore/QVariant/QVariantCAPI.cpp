#include "QVariantBind.h"
#include "../../include/qt6/qvariant.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QPoint>
#include <QPointF>
#include <QLine>
#include <QLineF>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QSizeF>
#include <QUrl>
#include <QUuid>
#include <QBitArray>
#include <QByteArray>
#include <QEasingCurve>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QLocale>
#include <QRegularExpression>
#include <QStringList>

extern "C" {

// QVariant作成関数
void *QVariant_create_empty() {
    return new QVariantBind();
}

void *QVariant_create_string(const char *value) {
    return new QVariantBind(QVariant(QString::fromUtf8(value)));
}

void *QVariant_create_int(int value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_uint(uint value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_longlong(qlonglong value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_ulonglong(qulonglong value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_double(double value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_float(float value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_char(char value) {
    return new QVariantBind(QVariant(QChar(value)));
}

void *QVariant_create_bool(bool value) {
    return new QVariantBind(QVariant(value));
}

void *QVariant_create_bytearray(const char *data, int size) {
    QByteArray byteArray(data, size);
    return new QVariantBind(QVariant(byteArray));
}

void *QVariant_create_bitarray(const char *bits, int size) {
    QBitArray bitArray(size);
    for (int i = 0; i < size; ++i) {
        bitArray.setBit(i, bits[i] != 0);
    }
    return new QVariantBind(QVariant(bitArray));
}

void *QVariant_create_date(int year, int month, int day) {
    QDate date(year, month, day);
    return new QVariantBind(QVariant(date));
}

void *QVariant_create_time(int hour, int minute, int second, int msec) {
    QTime time(hour, minute, second, msec);
    return new QVariantBind(QVariant(time));
}

void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec) {
    QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second, msec));
    return new QVariantBind(QVariant(dateTime));
}

void *QVariant_create_point(int x, int y) {
    QPoint point(x, y);
    return new QVariantBind(QVariant(point));
}

void *QVariant_create_pointf(qreal x, qreal y) {
    QPointF point(x, y);
    return new QVariantBind(QVariant(point));
}

void *QVariant_create_line(int x1, int y1, int x2, int y2) {
    QLine line(x1, y1, x2, y2);
    return new QVariantBind(QVariant(line));
}

void *QVariant_create_linef(qreal x1, qreal y1, qreal x2, qreal y2) {
    QLineF line(x1, y1, x2, y2);
    return new QVariantBind(QVariant(line));
}

void *QVariant_create_rect(int x, int y, int width, int height) {
    QRect rect(x, y, width, height);
    return new QVariantBind(QVariant(rect));
}

void *QVariant_create_rectf(qreal x, qreal y, qreal width, qreal height) {
    QRectF rect(x, y, width, height);
    return new QVariantBind(QVariant(rect));
}

void *QVariant_create_size(int width, int height) {
    QSize size(width, height);
    return new QVariantBind(QVariant(size));
}

void *QVariant_create_sizef(qreal width, qreal height) {
    QSizeF size(width, height);
    return new QVariantBind(QVariant(size));
}

void *QVariant_create_url(const char *url) {
    QUrl qurl(QString::fromUtf8(url));
    return new QVariantBind(QVariant(qurl));
}

void *QVariant_create_uuid(const char *uuid) {
    QUuid quuid(QString::fromUtf8(uuid));
    return new QVariantBind(QVariant(quuid));
}

void *QVariant_create_stringlist(const char **strings, int count) {
    QStringList list;
    for (int i = 0; i < count; ++i) {
        list.append(QString::fromUtf8(strings[i]));
    }
    return new QVariantBind(QVariant(list));
}

void *QVariant_create_with_type(int type, const void *copy) {
    return new QVariantBind(QVariant(QMetaType(type), copy));
}

// QVariant削除関数
void QVariant_delete(void *variant) {
    delete static_cast<QVariantBind*>(variant);
}

// 型チェック関数
bool QVariant_isNull(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->isNull();
}

bool QVariant_isValid(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->isValid();
}

bool QVariant_canConvert(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->canConvert(QMetaType(targetTypeId));
}

bool QVariant_canView(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->canView(QMetaType(targetTypeId));
}

int QVariant_typeId(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->typeId();
}

const char *QVariant_typeName(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->typeName();
}

int QVariant_userType(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->userType();
}

int QVariant_metaType(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->metaType().id();
}

bool QVariant_convert(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->convert(QMetaType(targetTypeId));
}

void QVariant_clear(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->clear();
}

void QVariant_swap(void *variant, void *other) {
    QVariant* var1 = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QVariant* var2 = static_cast<QVariantBind*>(other)->getHandler()->getVariant();
    var1->swap(*var2);
}

const void *QVariant_constData(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->constData();
}

void *QVariant_data(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->data();
}

// 変換関数
char *QVariant_toString(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QString str = var->toString();
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
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toInt(ok);
}

uint QVariant_toUInt(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toUInt(ok);
}

qlonglong QVariant_toLongLong(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toLongLong(ok);
}

qulonglong QVariant_toULongLong(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toULongLong(ok);
}

double QVariant_toDouble(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toDouble(ok);
}

float QVariant_toFloat(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toFloat(ok);
}

qreal QVariant_toReal(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toReal(ok);
}

bool QVariant_toBool(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toBool();
}

char QVariant_toChar(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toChar().toLatin1();
}

void *QVariant_toBitArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QBitArray bitArray = var->toBitArray();
    return new QVariantBind(QVariant(bitArray));
}

void *QVariant_toByteArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QByteArray byteArray = var->toByteArray();
    return new QVariantBind(QVariant(byteArray));
}

void *QVariant_toStringList(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QStringList stringList = var->toStringList();
    return new QVariantBind(QVariant(stringList));
}

void *QVariant_toList(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QList<QVariant> list = var->toList();
    return new QVariantBind(QVariant(list));
}

void *QVariant_toMap(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QMap<QString, QVariant> map = var->toMap();
    return new QVariantBind(QVariant(map));
}

void *QVariant_toHash(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QHash<QString, QVariant> hash = var->toHash();
    return new QVariantBind(QVariant(hash));
}

void *QVariant_toUrl(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QUrl url = var->toUrl();
    return new QVariantBind(QVariant(url));
}

void *QVariant_toUuid(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QUuid uuid = var->toUuid();
    return new QVariantBind(QVariant(uuid));
}

void *QVariant_toRegularExpression(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRegularExpression regex = var->toRegularExpression();
    return new QVariantBind(QVariant(regex));
}

void *QVariant_toLocale(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLocale locale = var->toLocale();
    return new QVariantBind(QVariant(locale));
}

void *QVariant_toEasingCurve(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QEasingCurve curve = var->toEasingCurve();
    return new QVariantBind(QVariant(curve));
}

void *QVariant_toJsonArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonArray array = var->toJsonArray();
    return new QVariantBind(QVariant(array));
}

void *QVariant_toJsonDocument(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonDocument doc = var->toJsonDocument();
    return new QVariantBind(QVariant(doc));
}

void *QVariant_toJsonObject(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonObject obj = var->toJsonObject();
    return new QVariantBind(QVariant(obj));
}

void *QVariant_toJsonValue(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonValue value = var->toJsonValue();
    return new QVariantBind(QVariant(value));
}

// QModelIndexとQPersistentModelIndexは複雑なため、これらの関数は実装しない

// 日付・時間関数
void QVariant_toDate(void *variant, int *year, int *month, int *day) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDate date = var->toDate();
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
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QTime time = var->toTime();
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
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDateTime dateTime = var->toDateTime();
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
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPoint point = var->toPoint();
    *x = point.x();
    *y = point.y();
}

void QVariant_toPointF(void *variant, qreal *x, qreal *y) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPointF point = var->toPointF();
    *x = point.x();
    *y = point.y();
}

void QVariant_toLine(void *variant, int *x1, int *y1, int *x2, int *y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLine line = var->toLine();
    *x1 = line.x1();
    *y1 = line.y1();
    *x2 = line.x2();
    *y2 = line.y2();
}

void QVariant_toLineF(void *variant, qreal *x1, qreal *y1, qreal *x2, qreal *y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLineF line = var->toLineF();
    *x1 = line.x1();
    *y1 = line.y1();
    *x2 = line.x2();
    *y2 = line.y2();
}

void QVariant_toRect(void *variant, int *x, int *y, int *width, int *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRect rect = var->toRect();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariant_toRectF(void *variant, qreal *x, qreal *y, qreal *width, qreal *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRectF rect = var->toRectF();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariant_toSize(void *variant, int *width, int *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSize size = var->toSize();
    *width = size.width();
    *height = size.height();
}

void QVariant_toSizeF(void *variant, qreal *width, qreal *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSizeF size = var->toSizeF();
    *width = size.width();
    *height = size.height();
}

// 値の設定
void QVariant_setValue_string(void *variant, const char *value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QString::fromUtf8(value));
}

void QVariant_setValue_int(void *variant, int value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_double(void *variant, double value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_bool(void *variant, bool value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_date(void *variant, int year, int month, int day) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QDate(year, month, day));
}

void QVariant_setValue_time(void *variant, int hour, int minute, int second, int msec) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QTime(hour, minute, second, msec));
}

void QVariant_setValue_datetime(void *variant, int year, int month, int day, int hour, int minute, int second, int msec) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QDateTime(QDate(year, month, day), QTime(hour, minute, second, msec)));
}

void QVariant_setValue_point(void *variant, int x, int y) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QPoint(x, y));
}

void QVariant_setValue_rect(void *variant, int x, int y, int width, int height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QRect(x, y, width, height));
}

void QVariant_setValue_size(void *variant, int width, int height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QSize(width, height));
}

// コールバック関数
void QVariant_setValueChangedCallback(void *variant, void (*callback)(void*, const void*)) {
    static_cast<QVariantBind*>(variant)->setValueChangedCallback(callback);
}

}
