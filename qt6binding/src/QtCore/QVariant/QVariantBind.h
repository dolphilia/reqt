#ifndef QVARIANT_BIND_H
#define QVARIANT_BIND_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QPoint>
#include <QRect>
#include <QSize>

#include "QVariantHandler.h"

class QVariantHandler;

class QVariantBind : public QObject, public QVariant {
    Q_OBJECT
public:
    // コンストラクタ
    explicit QVariantBind(QObject *parent = nullptr);
    explicit QVariantBind(const QString &value, QObject *parent = nullptr);
    explicit QVariantBind(const char *value, QObject *parent = nullptr);
    explicit QVariantBind(int value, QObject *parent = nullptr);
    explicit QVariantBind(double value, QObject *parent = nullptr);
    explicit QVariantBind(bool value, QObject *parent = nullptr);
    explicit QVariantBind(const QDate &value, QObject *parent = nullptr);
    explicit QVariantBind(const QTime &value, QObject *parent = nullptr);
    explicit QVariantBind(const QDateTime &value, QObject *parent = nullptr);
    explicit QVariantBind(const QPoint &value, QObject *parent = nullptr);
    explicit QVariantBind(const QRect &value, QObject *parent = nullptr);
    explicit QVariantBind(const QSize &value, QObject *parent = nullptr);
    ~QVariantBind() override;

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
    QVariantHandler* handler;
};

#endif // QVARIANT_BIND_H
