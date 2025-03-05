#include "QVariantBind.h"
#include "QVariantHandler.h"

// コンストラクタ
QVariantBind::QVariantBind(QObject* parent)
    : QObject(parent)
    , QVariant()
    , handler(new QVariantHandler(this)) {
}

QVariantBind::QVariantBind(const QString &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const char *value, QObject* parent)
    : QObject(parent)
    , QVariant(QString::fromUtf8(value))
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(int value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(double value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(bool value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QDate &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QTime &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QDateTime &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QPoint &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QRect &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::QVariantBind(const QSize &value, QObject* parent)
    : QObject(parent)
    , QVariant(value)
    , handler(new QVariantHandler(this)) {
    *handler->variant() = *this;
}

QVariantBind::~QVariantBind() {
    delete handler;
}

// 型チェック
bool QVariantBind::isNull() const {
    return QVariant::isNull();
}

bool QVariantBind::isValid() const {
    return QVariant::isValid();
}

bool QVariantBind::canConvert(int targetTypeId) const {
    return QVariant::canConvert(QMetaType(targetTypeId));
}

// 変換関数
QString QVariantBind::toString() const {
    return QVariant::toString();
}

int QVariantBind::toInt(bool *ok) const {
    return QVariant::toInt(ok);
}

double QVariantBind::toDouble(bool *ok) const {
    return QVariant::toDouble(ok);
}

bool QVariantBind::toBool() const {
    return QVariant::toBool();
}

QDate QVariantBind::toDate() const {
    return QVariant::toDate();
}

QTime QVariantBind::toTime() const {
    return QVariant::toTime();
}

QDateTime QVariantBind::toDateTime() const {
    return QVariant::toDateTime();
}

QPoint QVariantBind::toPoint() const {
    return QVariant::toPoint();
}

QRect QVariantBind::toRect() const {
    return QVariant::toRect();
}

QSize QVariantBind::toSize() const {
    return QVariant::toSize();
}
