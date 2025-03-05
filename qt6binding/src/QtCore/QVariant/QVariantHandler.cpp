#include "QVariantHandler.h"

QVariantHandler::QVariantHandler(QObject* parent)
    : QObject(parent)
    , m_variant(new QVariant()) {
}

QVariantHandler::~QVariantHandler() {
    delete m_variant;
}

// アクセサ
QVariant *QVariantHandler::variant() const {
    return m_variant;
}

// 型チェック
bool QVariantHandler::isNull() const {
    return m_variant->isNull();
}

bool QVariantHandler::isValid() const {
    return m_variant->isValid();
}

bool QVariantHandler::canConvert(int targetTypeId) const {
    return m_variant->canConvert(QMetaType(targetTypeId));
}

// 変換関数
QString QVariantHandler::toString() const {
    if (m_variant->canConvert<QString>()) {
        return m_variant->toString();
    }
    return QString();
}

int QVariantHandler::toInt(bool *ok) const {
    return m_variant->toInt(ok);
}

double QVariantHandler::toDouble(bool *ok) const {
    return m_variant->toDouble(ok);
}

bool QVariantHandler::toBool() const {
    return m_variant->toBool();
}

QDate QVariantHandler::toDate() const {
    return m_variant->toDate();
}

QTime QVariantHandler::toTime() const {
    return m_variant->toTime();
}

QDateTime QVariantHandler::toDateTime() const {
    return m_variant->toDateTime();
}

QPoint QVariantHandler::toPoint() const {
    return m_variant->toPoint();
}

QRect QVariantHandler::toRect() const {
    return m_variant->toRect();
}

QSize QVariantHandler::toSize() const {
    return m_variant->toSize();
}
