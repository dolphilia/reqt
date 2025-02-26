#include "QStringHandler.h"

// コンストラクタ
QStringHandler::QStringHandler()
{
    m_string = new QString();
}

QStringHandler::QStringHandler(const char *str)
{
    m_string = new QString(QString::fromUtf8(str));
}

QStringHandler::QStringHandler(const QString &str)
{
    m_string = new QString(str);
}

QStringHandler::~QStringHandler()
{
    delete m_string;
}

// アクセサ
QString *QStringHandler::string() const
{
    return m_string;
}

// 基本操作
int QStringHandler::length() const
{
    return m_string->length();
}

bool QStringHandler::isEmpty() const
{
    return m_string->isEmpty();
}

void QStringHandler::clear()
{
    m_string->clear();
}

// 文字列操作
QString QStringHandler::at(int position) const
{
    if (position >= 0 && position < m_string->length()) {
        return QString(m_string->at(position));
    }
    return QString();
}

void QStringHandler::append(const char *str)
{
    m_string->append(QString::fromUtf8(str));
}

void QStringHandler::append(const QString &str)
{
    m_string->append(str);
}

void QStringHandler::prepend(const char *str)
{
    m_string->prepend(QString::fromUtf8(str));
}

void QStringHandler::prepend(const QString &str)
{
    m_string->prepend(str);
}

void QStringHandler::insert(int position, const char *str)
{
    m_string->insert(position, QString::fromUtf8(str));
}

void QStringHandler::insert(int position, const QString &str)
{
    m_string->insert(position, str);
}

void QStringHandler::remove(int position, int n)
{
    m_string->remove(position, n);
}

void QStringHandler::replace(int position, int n, const char *after)
{
    m_string->replace(position, n, QString::fromUtf8(after));
}

void QStringHandler::replace(int position, int n, const QString &after)
{
    m_string->replace(position, n, after);
}

// 変換
QString QStringHandler::toLower() const
{
    return m_string->toLower();
}

QString QStringHandler::toUpper() const
{
    return m_string->toUpper();
}

QString QStringHandler::trimmed() const
{
    return m_string->trimmed();
}

QString QStringHandler::simplified() const
{
    return m_string->simplified();
}

// 検索
int QStringHandler::indexOf(const char *str, int from) const
{
    return m_string->indexOf(QString::fromUtf8(str), from);
}

int QStringHandler::indexOf(const QString &str, int from) const
{
    return m_string->indexOf(str, from);
}

int QStringHandler::lastIndexOf(const char *str, int from) const
{
    return m_string->lastIndexOf(QString::fromUtf8(str), from);
}

int QStringHandler::lastIndexOf(const QString &str, int from) const
{
    return m_string->lastIndexOf(str, from);
}

bool QStringHandler::contains(const char *str) const
{
    return m_string->contains(QString::fromUtf8(str));
}

bool QStringHandler::contains(const QString &str) const
{
    return m_string->contains(str);
}

bool QStringHandler::startsWith(const char *str) const
{
    return m_string->startsWith(QString::fromUtf8(str));
}

bool QStringHandler::startsWith(const QString &str) const
{
    return m_string->startsWith(str);
}

bool QStringHandler::endsWith(const char *str) const
{
    return m_string->endsWith(QString::fromUtf8(str));
}

bool QStringHandler::endsWith(const QString &str) const
{
    return m_string->endsWith(str);
}

// 分割
QStringList QStringHandler::split(const char *sep) const
{
    return m_string->split(QString::fromUtf8(sep));
}

QStringList QStringHandler::split(const QString &sep) const
{
    return m_string->split(sep);
}

// 変換
QByteArray QStringHandler::toUtf8() const
{
    return m_string->toUtf8();
}

QByteArray QStringHandler::toLatin1() const
{
    return m_string->toLatin1();
}

QByteArray QStringHandler::toLocal8Bit() const
{
    return m_string->toLocal8Bit();
}

// 比較
bool QStringHandler::equals(const char *str) const
{
    return *m_string == QString::fromUtf8(str);
}

bool QStringHandler::equals(const QString &str) const
{
    return *m_string == str;
}
