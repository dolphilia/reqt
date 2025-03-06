#include "QVariantBind.h"
#include "qvariant.h"
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
#include <QModelIndex>
#include <QPersistentModelIndex>

extern "C" {

// QVariant()

void *QVariant_create_empty() {
    return new QVariantBind();
}

// QVariant(QChar c)

void *QVariant_create_char(char value) {
    return new QVariantBind(QVariant(QChar(value)));
}

// QVariant(const char *val)

void *QVariant_create_string(const char *value) {
    return new QVariantBind(QVariant(QString::fromUtf8(value)));
}

// QVariant(double val)

void *QVariant_create_double(double value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(float val)

void *QVariant_create_float(float value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(int val)

void *QVariant_create_int(int value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(long long val)

void *QVariant_create_longlong(long long value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(unsigned long long val)

void *QVariant_create_ulonglong(unsigned long long value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(uint val)

void *QVariant_create_uint(uint value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(QMetaType type, const void *copy = nullptr)

void *QVariant_create_with_type(int type, const void *copy) {
    return new QVariantBind(QVariant(QMetaType(type), copy));
}

// (since 6.6)QVariant(std::in_place_type_t<T>, Args &&... args)
// (since 6.6)QVariant(std::in_place_type_t<T>, std::initializer_list<U> il, Args &&... args)
// QVariant(QDate val)

void *QVariant_create_date(int year, int month, int day) {
    QDate date(year, month, day);
    return new QVariantBind(QVariant(date));
}

// QVariant(QLatin1StringView val)
// QVariant(QLine val)

void *QVariant_create_line(int x1, int y1, int x2, int y2) {
    QLine line(x1, y1, x2, y2);
    return new QVariantBind(QVariant(line));
}

// QVariant(QLineF val)

void *QVariant_create_linef(double x1, double y1, double x2, double y2) {
    QLineF line(x1, y1, x2, y2);
    return new QVariantBind(QVariant(line));
}

// QVariant(QPoint val)

void *QVariant_create_point(int x, int y) {
    QPoint point(x, y);
    return new QVariantBind(QVariant(point));
}

// QVariant(QPointF val)

void *QVariant_create_pointf(double x, double y) {
    QPointF point(x, y);
    return new QVariantBind(QVariant(point));
}

// QVariant(QRect val)

void *QVariant_create_rect(int x, int y, int width, int height) {
    QRect rect(x, y, width, height);
    return new QVariantBind(QVariant(rect));
}

// QVariant(QRectF val)

void *QVariant_create_rectf(double x, double y, double width, double height) {
    QRectF rect(x, y, width, height);
    return new QVariantBind(QVariant(rect));
}

// QVariant(QSize val)

void *QVariant_create_size(int width, int height) {
    QSize size(width, height);
    return new QVariantBind(QVariant(size));
}

// QVariant(QSizeF val)


void *QVariant_create_sizef(double width, double height) {
    QSizeF size(width, height);
    return new QVariantBind(QVariant(size));
}

// QVariant(QTime val)

void *QVariant_create_time(int hour, int minute, int second, int msec) {
    QTime time(hour, minute, second, msec);
    return new QVariantBind(QVariant(time));
}

// QVariant(QUuid val)

void *QVariant_create_uuid(const char *uuid) {
    QUuid quuid(QString::fromUtf8(uuid));
    return new QVariantBind(QVariant(quuid));
}

// QVariant(bool val)

void *QVariant_create_bool(bool value) {
    return new QVariantBind(QVariant(value));
}

// QVariant(const QBitArray &val)

void *QVariant_create_bitarray(const char *bits, int size) {
    QBitArray bitArray(size);
    for (int i = 0; i < size; ++i) {
        bitArray.setBit(i, bits[i] != 0);
    }
    return new QVariantBind(QVariant(bitArray));
}

// QVariant(const QByteArray &val)

void *QVariant_create_bytearray(const char *data, int size) {
    QByteArray byteArray(data, size);
    return new QVariantBind(QVariant(byteArray));
}

// QVariant(const QDateTime &val)

void *QVariant_create_datetime(int year, int month, int day, int hour, int minute, int second, int msec) {
    QDateTime dateTime(QDate(year, month, day), QTime(hour, minute, second, msec));
    return new QVariantBind(QVariant(dateTime));
}

// QVariant(const QEasingCurve &val)

void *QVariant_create_easingcurve(void *curve) {
    return new QVariantBind(QVariant(*static_cast<QEasingCurve*>(curve)));
}

// QVariant(const QHash<QString, QVariant> &val)

void *QVariant_create_hash(void *hash) {
    return new QVariantBind(QVariant(*static_cast<QHash<QString, QVariant>*>(hash)));
}

// QVariant(const QJsonArray &val)

void *QVariant_create_jsonarray(void *array) {
    return new QVariantBind(QVariant(*static_cast<QJsonArray*>(array)));
}

// QVariant(const QJsonDocument &val)

void *QVariant_create_jsondocument(void *doc) {
    return new QVariantBind(QVariant(*static_cast<QJsonDocument*>(doc)));
}

// QVariant(const QJsonObject &val)

void *QVariant_create_jsonobject(void *obj) {
    return new QVariantBind(QVariant(*static_cast<QJsonObject*>(obj)));
}

// QVariant(const QJsonValue &val)

void *QVariant_create_jsonvalue(void *value) {
    return new QVariantBind(QVariant(*static_cast<QJsonValue*>(value)));
}

// QVariant(const QList<QVariant> &val)

void *QVariant_create_list(void *list) {
    return new QVariantBind(QVariant(*static_cast<QList<QVariant>*>(list)));
}

// QVariant(const QLocale &l)

void *QVariant_create_locale(void *locale) {
    return new QVariantBind(QVariant(*static_cast<QLocale*>(locale)));
}

// QVariant(const QMap<QString, QVariant> &val)

void *QVariant_create_map(void *map) {
    return new QVariantBind(QVariant(*static_cast<QMap<QString, QVariant>*>(map)));
}

// QVariant(const QModelIndex &val)

void *QVariant_create_modelindex(void *index) {
    return new QVariantBind(QVariant(*static_cast<QModelIndex*>(index)));
}

// QVariant(const QPersistentModelIndex &val)

void *QVariant_create_persistentmodelindex(void *index) {
    return new QVariantBind(QVariant(*static_cast<QPersistentModelIndex*>(index)));
}

// QVariant(const QRegularExpression &re)

void *QVariant_create_regularexpression(void *regex) {
    return new QVariantBind(QVariant(*static_cast<QRegularExpression*>(regex)));
}

// QVariant(const QString &val)

void *QVariant_create_qstring(const char *value) {
    return new QVariantBind(QVariant(QString::fromUtf8(value)));
}
// QVariant(const QStringList &val)

void *QVariant_create_stringlist(const char **strings, int count) {
    QStringList list;
    for (int i = 0; i < count; ++i) {
        list.append(QString::fromUtf8(strings[i]));
    }
    return new QVariantBind(QVariant(list));
}

// QVariant(const QUrl &val)

void *QVariant_create_url(const char *url) {
    QUrl qurl(QString::fromUtf8(url));
    return new QVariantBind(QVariant(qurl));
}

// QVariant(const QVariant &p)

void *QVariant_create_copy(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return new QVariantBind(QVariant(*var));
}

// QVariant(QVariant &&other)

void *QVariant_create_move(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return new QVariantBind(QVariant(std::move(*var)));
}
// ~QVariant()

void QVariant_delete(void *variant) {
    delete static_cast<QVariantBind*>(variant);
}

// bool canConvert() const
// (since 6.0) bool canConvert(QMetaType type) const

bool QVariant_canConvert(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->canConvert(QMetaType(targetTypeId));
}

// bool canView() const

bool QVariant_canView(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->canView(QMetaType(targetTypeId));
}

// void clear()

void QVariant_clear(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->clear();
}

// const void * constData() const

const void *QVariant_constData(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->constData();
}

// (since 6.0) bool convert(QMetaType targetType)

bool QVariant_convert(void *variant, int targetTypeId) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->convert(QMetaType(targetTypeId));
}

// void * data()

void *QVariant_data(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->data();
}

// const void * data() const
// (since 6.6) T & emplace(Args &&... args)
// (since 6.6) T & emplace(std::initializer_list<U> list, Args &&... args)
// bool isNull() const

bool QVariant_isNull(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->isNull();
}

// bool isValid() const

bool QVariant_isValid(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->isValid();
}

// (since 6.0) QMetaType metaType() const

int QVariant_metaType(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->metaType().id();
}

// void setValue(QVariant &&value)

void QVariant_setValue_move(void *variant, void *value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QVariant* val = static_cast<QVariantBind*>(value)->getHandler()->getVariant();
    var->setValue(std::move(*val));
}

// void setValue(T &&value)

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

void QVariant_setValue_float(void *variant, float value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_longlong(void *variant, long long value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_ulonglong(void *variant, unsigned long long value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_uint(void *variant, uint value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(value);
}

void QVariant_setValue_char(void *variant, char value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QChar(value));
}

void QVariant_setValue_line(void *variant, int x1, int y1, int x2, int y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QLine(x1, y1, x2, y2));
}

void QVariant_setValue_linef(void *variant, double x1, double y1, double x2, double y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QLineF(x1, y1, x2, y2));
}

void QVariant_setValue_pointf(void *variant, double x, double y) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QPointF(x, y));
}

void QVariant_setValue_rectf(void *variant, double x, double y, double width, double height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QRectF(x, y, width, height));
}

void QVariant_setValue_sizef(void *variant, double width, double height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QSizeF(width, height));
}

void QVariant_setValue_url(void *variant, const char *url) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QUrl(QString::fromUtf8(url)));
}

void QVariant_setValue_uuid(void *variant, const char *uuid) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QUuid(QString::fromUtf8(uuid)));
}

void QVariant_setValue_bitarray(void *variant, const char *bits, int size) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QBitArray bitArray(size);
    for (int i = 0; i < size; ++i) {
        bitArray.setBit(i, bits[i] != 0);
    }
    var->setValue(bitArray);
}

void QVariant_setValue_bytearray(void *variant, const char *data, int size) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    var->setValue(QByteArray(data, size));
}

void QVariant_setValue_stringlist(void *variant, const char **strings, int count) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QStringList list;
    for (int i = 0; i < count; ++i) {
        list.append(QString::fromUtf8(strings[i]));
    }
    var->setValue(list);
}

// void setValue(const QVariant &value)

void QVariant_setValue_variant(void *variant, void *value) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QVariant* val = static_cast<QVariantBind*>(value)->getHandler()->getVariant();
    var->setValue(*val);
}

// void swap(QVariant &other)

void QVariant_swap(void *variant, void *other) {
    QVariant* var1 = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QVariant* var2 = static_cast<QVariantBind*>(other)->getHandler()->getVariant();
    var1->swap(*var2);
}

// QBitArray toBitArray() const

void *QVariant_toBitArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QBitArray bitArray = var->toBitArray();
    return new QVariantBind(QVariant(bitArray));
}

// bool toBool() const

bool QVariant_toBool(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toBool();
}

// QByteArray toByteArray() const

void *QVariant_toByteArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QByteArray byteArray = var->toByteArray();
    return new QVariantBind(QVariant(byteArray));
}

// QChar toChar() const

char QVariant_toChar(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toChar().toLatin1();
}

// QDate toDate() const

void *QVariant_toDate(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDate date = var->toDate();
    return new QVariantBind(QVariant(date));
}

// QDateTime toDateTime() const

void *QVariant_toDateTime(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDateTime dateTime = var->toDateTime();
    return new QVariantBind(QVariant(dateTime));
}

// double toDouble(bool *ok = nullptr) const

double QVariant_toDouble(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toDouble(ok);
}

// QEasingCurve toEasingCurve() const

void *QVariant_toEasingCurve(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QEasingCurve curve = var->toEasingCurve();
    return new QVariantBind(QVariant(curve));
}

// float toFloat(bool *ok = nullptr) const

float QVariant_toFloat(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toFloat(ok);
}

// QHash<QString, QVariant> toHash() const

void *QVariant_toHash(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QHash<QString, QVariant> hash = var->toHash();
    return new QVariantBind(QVariant(hash));
}

// int toInt(bool *ok = nullptr) const

int QVariant_toInt(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toInt(ok);
}

// QJsonArray toJsonArray() const

void *QVariant_toJsonArray(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonArray array = var->toJsonArray();
    return new QVariantBind(QVariant(array));
}

// QJsonDocument toJsonDocument() const

void *QVariant_toJsonDocument(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonDocument doc = var->toJsonDocument();
    return new QVariantBind(QVariant(doc));
}

// QJsonObject toJsonObject() const

void *QVariant_toJsonObject(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonObject obj = var->toJsonObject();
    return new QVariantBind(QVariant(obj));
}

// QJsonValue toJsonValue() const

void *QVariant_toJsonValue(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QJsonValue value = var->toJsonValue();
    return new QVariantBind(QVariant(value));
}

// QLine toLine() const

void *QVariant_toLine(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLine line = var->toLine();
    return new QVariantBind(QVariant(line));
}

// QLineF toLineF() const

void *QVariant_toLineF(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLineF line = var->toLineF();
    return new QVariantBind(QVariant(line));
}

// QList<QVariant> toList() const

void *QVariant_toList(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QList<QVariant> list = var->toList();
    return new QVariantBind(QVariant(list));
}

// QLocale toLocale() const

void *QVariant_toLocale(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLocale locale = var->toLocale();
    return new QVariantBind(QVariant(locale));
}

// long long toLongLong(bool *ok = nullptr) const

long long QVariant_toLongLong(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toLongLong(ok);
}

// QMap<QString, QVariant> toMap() const

void *QVariant_toMap(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QMap<QString, QVariant> map = var->toMap();
    return new QVariantBind(QVariant(map));
}

// QModelIndex toModelIndex() const

void *QVariant_toModelIndex(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QModelIndex index = var->toModelIndex();
    return new QVariantBind(QVariant(index));
}

// QPersistentModelIndex toPersistentModelIndex() const

void *QVariant_toPersistentModelIndex(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPersistentModelIndex index = var->toPersistentModelIndex();
    return new QVariantBind(QVariant(index));
}

// QPoint toPoint() const

void *QVariant_toPoint(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPoint point = var->toPoint();
    return new QVariantBind(QVariant(point));
}

// QPointF toPointF() const

void *QVariant_toPointF(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPointF point = var->toPointF();
    return new QVariantBind(QVariant(point));
}

// double toReal(bool *ok = nullptr) const

double QVariant_toReal(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toReal(ok);
}

// QRect toRect() const

void *QVariant_toRect(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRect rect = var->toRect();
    return new QVariantBind(QVariant(rect));
}

// QRectF toRectF() const

void *QVariant_toRectF(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRectF rect = var->toRectF();
    return new QVariantBind(QVariant(rect));
}

// QRegularExpression toRegularExpression() const

void *QVariant_toRegularExpression(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRegularExpression regex = var->toRegularExpression();
    return new QVariantBind(QVariant(regex));
}

// QSize toSize() const


void *QVariant_toSize(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSize size = var->toSize();
    return new QVariantBind(QVariant(size));
}

// QSizeF toSizeF() const

void *QVariant_toSizeF(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSizeF size = var->toSizeF();
    return new QVariantBind(QVariant(size));
}

// QString toString() const

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

// QStringList toStringList() const

void *QVariant_toStringList(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QStringList stringList = var->toStringList();
    return new QVariantBind(QVariant(stringList));
}

// QTime toTime() const

void *QVariant_toTime(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QTime time = var->toTime();
    return new QVariantBind(QVariant(time));
}

// uint toUInt(bool *ok = nullptr) const

uint QVariant_toUInt(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toUInt(ok);
}

// unsigned long long toULongLong(bool *ok = nullptr) const

unsigned long long QVariant_toULongLong(void *variant, bool *ok) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->toULongLong(ok);
}

// QUrl toUrl() const

void *QVariant_toUrl(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QUrl url = var->toUrl();
    return new QVariantBind(QVariant(url));
}

// QUuid toUuid() const

void *QVariant_toUuid(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QUuid uuid = var->toUuid();
    return new QVariantBind(QVariant(uuid));
}

// int typeId() const

int QVariant_typeId(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->typeId();
}

// const char * typeName() const

const char *QVariant_typeName(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->typeName();
}

// int userType() const

int QVariant_userType(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->userType();
}

// T value() const &

int QVariant_value_int(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<int>();
}

bool QVariant_value_bool(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<bool>();
}

double QVariant_value_double(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<double>();
}

float QVariant_value_float(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<float>();
}

long long QVariant_value_longlong(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<long long>();
}

unsigned long long QVariant_value_ulonglong(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<unsigned long long>();
}

uint QVariant_value_uint(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<uint>();
}

char QVariant_value_char(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    return var->value<QChar>().toLatin1();
}

void QVariant_value_string(void *variant, char **result) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QString str = var->value<QString>();
    QByteArray utf8 = str.toUtf8();
    const char *data = utf8.constData();
    size_t size = utf8.size();

    *result = new char[size + 1];
    if (size > 0) {
        memcpy(*result, data, size);
    }
    (*result)[size] = '\0';
}

void QVariant_value_date(void *variant, int *year, int *month, int *day) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDate date = var->value<QDate>();
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

void QVariant_value_time(void *variant, int *hour, int *minute, int *second, int *msec) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QTime time = var->value<QTime>();
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

void QVariant_value_datetime(void *variant, int *year, int *month, int *day, int *hour, int *minute, int *second, int *msec) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QDateTime dateTime = var->value<QDateTime>();
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

void QVariant_value_point(void *variant, int *x, int *y) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPoint point = var->value<QPoint>();
    *x = point.x();
    *y = point.y();
}

void QVariant_value_pointf(void *variant, double *x, double *y) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QPointF point = var->value<QPointF>();
    *x = point.x();
    *y = point.y();
}

void QVariant_value_rect(void *variant, int *x, int *y, int *width, int *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRect rect = var->value<QRect>();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariant_value_rectf(void *variant, double *x, double *y, double *width, double *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QRectF rect = var->value<QRectF>();
    *x = rect.x();
    *y = rect.y();
    *width = rect.width();
    *height = rect.height();
}

void QVariant_value_size(void *variant, int *width, int *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSize size = var->value<QSize>();
    *width = size.width();
    *height = size.height();
}

void QVariant_value_sizef(void *variant, double *width, double *height) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QSizeF size = var->value<QSizeF>();
    *width = size.width();
    *height = size.height();
}

void QVariant_value_line(void *variant, int *x1, int *y1, int *x2, int *y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLine line = var->value<QLine>();
    *x1 = line.x1();
    *y1 = line.y1();
    *x2 = line.x2();
    *y2 = line.y2();
}

void QVariant_value_linef(void *variant, double *x1, double *y1, double *x2, double *y2) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    QLineF line = var->value<QLineF>();
    *x1 = line.x1();
    *y1 = line.y1();
    *x2 = line.x2();
    *y2 = line.y2();
}

// T view()

const int *QVariant_view_int(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static int value;
    value = var->view<int>();
    return &value;
}

const bool *QVariant_view_bool(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static bool value;
    value = var->view<bool>();
    return &value;
}

const double *QVariant_view_double(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static double value;
    value = var->view<double>();
    return &value;
}

const float *QVariant_view_float(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static float value;
    value = var->view<float>();
    return &value;
}

const long long *QVariant_view_longlong(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static long long value;
    value = var->view<long long>();
    return &value;
}

const unsigned long long *QVariant_view_ulonglong(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static unsigned long long value;
    value = var->view<unsigned long long>();
    return &value;
}

const unsigned int *QVariant_view_uint(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static unsigned int value;
    value = var->view<unsigned int>();
    return &value;
}

const char *QVariant_view_char(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    static char result;
    QChar qchar = var->view<QChar>();
    if (!qchar.isNull()) {
        result = qchar.toLatin1();
        return &result;
    }
    return nullptr;
}

const char *QVariant_view_string(void *variant) {
    QVariant* var = static_cast<QVariantBind*>(variant)->getHandler()->getVariant();
    const QString &str = var->view<QString>();
    if (!str.isEmpty()) {
        static QByteArray utf8;
        utf8 = str.toUtf8();
        return utf8.constData();
    }
    return nullptr;
}

// QVariant & operator=(QVariant &&other)
// QVariant & operator=(const QVariant &variant)

// コールバック関数
void QVariant_setValueChangedCallback(void *variant, void (*callback)(void*, const void*)) {
    static_cast<QVariantBind*>(variant)->setValueChangedCallback(callback);
}

}
