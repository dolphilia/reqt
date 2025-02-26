#include "QVariantHandler.h"

// コンストラクタ
QVariantHandler::QVariantHandler()
{
    m_variant = new QVariant();
}

QVariantHandler::QVariantHandler(const QString &value)
{
    m_variant = new QVariant(QString(value));
}

QVariantHandler::QVariantHandler(const char *value)
{
    m_variant = new QVariant(QString::fromUtf8(value));
}

QVariantHandler::QVariantHandler(int value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(double value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(bool value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QDate &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QTime &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QDateTime &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QPoint &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QRect &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::QVariantHandler(const QSize &value)
{
    m_variant = new QVariant(value);
}

QVariantHandler::~QVariantHandler()
{
    delete m_variant;
}

// アクセサ
QVariant *QVariantHandler::variant() const
{
    return m_variant;
}

// 型チェック
bool QVariantHandler::isNull() const
{
    return m_variant->isNull();
}

bool QVariantHandler::isValid() const
{
    return m_variant->isValid();
}

bool QVariantHandler::canConvert(int targetTypeId) const
{
    return m_variant->canConvert(QMetaType(targetTypeId));
}

// 変換関数
QString QVariantHandler::toString() const
{
    if (m_variant->canConvert<QString>()) {
        return m_variant->toString();
    }
    return QString();
}

int QVariantHandler::toInt(bool *ok) const
{
    return m_variant->toInt(ok);
}

double QVariantHandler::toDouble(bool *ok) const
{
    return m_variant->toDouble(ok);
}

bool QVariantHandler::toBool() const
{
    return m_variant->toBool();
}

QDate QVariantHandler::toDate() const
{
    return m_variant->toDate();
}

QTime QVariantHandler::toTime() const
{
    return m_variant->toTime();
}

QDateTime QVariantHandler::toDateTime() const
{
    return m_variant->toDateTime();
}

QPoint QVariantHandler::toPoint() const
{
    return m_variant->toPoint();
}

QRect QVariantHandler::toRect() const
{
    return m_variant->toRect();
}

QSize QVariantHandler::toSize() const
{
    return m_variant->toSize();
}
