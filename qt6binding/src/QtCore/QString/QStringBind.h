#ifndef QT_QSTRINGBIND_H
#define QT_QSTRINGBIND_H

#include "QStringHandler.h"
#include <QString>
#include <QObject>

class QStringHandler;

class QStringBind : public QString {
public:
    // コンストラクタ
    QStringBind();
    explicit QStringBind(QChar ch);
    explicit QStringBind(QLatin1StringView str);
    explicit QStringBind(const QByteArray &ba);
    explicit QStringBind(const char *str);
    // explicit QStringBind(const char8_t *str);
    explicit QStringBind(const QChar *unicode, qsizetype size = -1);
    explicit QStringBind(qsizetype size, QChar ch);
    explicit QStringBind(const QString &other);
    explicit QStringBind(QString &&other);
    ~QStringBind();

private:
    QStringHandler* handler;
};

#endif // QT_QSTRINGBIND_H
