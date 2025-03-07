#include "QStringBind.h"

// コンストラクタ
QStringBind::QStringBind()
    : QString()
    , handler(new QStringHandler(nullptr)) {
}

QStringBind::QStringBind(QChar ch)
    : QString(ch)
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(QLatin1StringView str)
    : QString(QString::fromLatin1(str))
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(const QByteArray &ba)
    : QString(QString::fromUtf8(ba))
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(const char *str)
    : QString(QString::fromUtf8(str))
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

// QStringBind::QStringBind(const char8_t *str)
//     : QString(QString::fromUtf8(reinterpret_cast<const char*>(str)))
//     , handler(new QStringHandler(nullptr)) {
//     handler->setText(*this);
// }

QStringBind::QStringBind(const QChar *unicode, qsizetype size)
    : QString(unicode, size)
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(qsizetype size, QChar ch)
    : QString(size, ch)
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(const QString &other)
    : QString(other)
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::QStringBind(QString &&other)
    : QString(std::move(other))
    , handler(new QStringHandler(nullptr)) {
    handler->setText(*this);
}

QStringBind::~QStringBind() {
    delete handler;
}
