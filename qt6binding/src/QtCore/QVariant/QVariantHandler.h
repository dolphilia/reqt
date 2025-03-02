#ifndef QT_QVARIANTHANDLER_H
#define QT_QVARIANTHANDLER_H

#include <QVariant>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QPoint>
#include <QRect>
#include <QSize>

class QVariantHandler {
public:
    // コンストラクタ
    QVariantHandler(); // デフォルトコンストラクタ
    explicit QVariantHandler(const QString &value);
    explicit QVariantHandler(const char *value);
    explicit QVariantHandler(int value);
    explicit QVariantHandler(double value);
    explicit QVariantHandler(bool value);
    explicit QVariantHandler(const QDate &value);
    explicit QVariantHandler(const QTime &value);
    explicit QVariantHandler(const QDateTime &value);
    explicit QVariantHandler(const QPoint &value);
    explicit QVariantHandler(const QRect &value);
    explicit QVariantHandler(const QSize &value);
    ~QVariantHandler();

    // アクセサ
    QVariant *variant() const;
    
    // 型チェック
    bool isNull() const;
    bool isValid() const;
    bool canConvert(int targetTypeId) const;
    
    // 変換関数
    QString toString() const;
    int toInt(bool *ok = nullptr) const;
    double toDouble(bool *ok = nullptr) const;
    bool toBool() const;
    QDate toDate() const;
    QTime toTime() const;
    QDateTime toDateTime() const;
    QPoint toPoint() const;
    QRect toRect() const;
    QSize toSize() const;

private:
    QVariant *m_variant;
};

#endif // QT_QVARIANTHANDLER_H
