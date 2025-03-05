#ifndef QVARIANT_HANDLER_H
#define QVARIANT_HANDLER_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QPoint>
#include <QRect>
#include <QSize>

class QVariantHandler : public QObject {
    Q_OBJECT
public:
    explicit QVariantHandler(QObject* parent = nullptr);
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

#endif // QVARIANT_HANDLER_H
