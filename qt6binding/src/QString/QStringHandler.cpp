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

QStringHandler::QStringHandler(QChar ch)
{
    m_string = new QString(ch);
}

QStringHandler::QStringHandler(const QByteArray &ba)
{
    m_string = new QString(QString::fromUtf8(ba));
}

QStringHandler::QStringHandler(const QChar *unicode, qsizetype size)
{
    m_string = new QString(unicode, size);
}

QStringHandler::QStringHandler(qsizetype size, QChar ch)
{
    m_string = new QString(size, ch);
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

int QStringHandler::capacity() const
{
    return m_string->capacity();
}

const QChar *QStringHandler::constData() const
{
    return m_string->constData();
}

const QChar *QStringHandler::data() const
{
    return m_string->data();
}

void QStringHandler::chop(int n)
{
    m_string->chop(n);
}

QString QStringHandler::chopped(int len) const
{
    return m_string->chopped(len);
}

QString &QStringHandler::fill(QChar ch, int size)
{
    return m_string->fill(ch, size);
}

QString QStringHandler::first(int n) const
{
    return m_string->first(n);
}

QString QStringHandler::last(int n) const
{
    return m_string->last(n);
}

QChar QStringHandler::front() const
{
    return m_string->front();
}

QChar QStringHandler::back() const
{
    return m_string->back();
}

bool QStringHandler::isNull() const
{
    return m_string->isNull();
}

bool QStringHandler::isLower() const
{
    return m_string->isLower();
}

bool QStringHandler::isUpper() const
{
    return m_string->isUpper();
}

bool QStringHandler::isRightToLeft() const
{
    return m_string->isRightToLeft();
}

QString QStringHandler::left(int n) const
{
    return m_string->left(n);
}

QString QStringHandler::right(int n) const
{
    return m_string->right(n);
}

QString QStringHandler::mid(int position, int n) const
{
    return m_string->mid(position, n);
}

int QStringHandler::max_size() const
{
    return m_string->capacity();
}

void QStringHandler::reserve(int size)
{
    m_string->reserve(size);
}

void QStringHandler::resize(int size)
{
    m_string->resize(size);
}

void QStringHandler::resize(int size, QChar fillChar)
{
    m_string->resize(size, fillChar);
}

QString QStringHandler::repeated(int times) const
{
    return m_string->repeated(times);
}

QString QStringHandler::sliced(int position, int n) const
{
    return m_string->sliced(position, n);
}

QString QStringHandler::sliced(int position) const
{
    return m_string->sliced(position);
}

void QStringHandler::shrink_to_fit()
{
    m_string->squeeze();
}

void QStringHandler::squeeze()
{
    m_string->squeeze();
}

void QStringHandler::swap(QString &other)
{
    m_string->swap(other);
}

// 数値変換
QString &QStringHandler::setNum(int n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(long n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(long long n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(unsigned long long n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(short n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(unsigned int n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(unsigned long n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(unsigned short n, int base)
{
    return m_string->setNum(n, base);
}

QString &QStringHandler::setNum(double n, char format, int precision)
{
    return m_string->setNum(n, format, precision);
}

QString &QStringHandler::setNum(float n, char format, int precision)
{
    return m_string->setNum(n, format, precision);
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

void QStringHandler::append(QChar ch)
{
    m_string->append(ch);
}

void QStringHandler::append(const QByteArray &ba)
{
    m_string->append(QString::fromUtf8(ba));
}

void QStringHandler::append(const QChar *str, qsizetype len)
{
    m_string->append(str, len);
}

void QStringHandler::prepend(const char *str)
{
    m_string->prepend(QString::fromUtf8(str));
}

void QStringHandler::prepend(const QString &str)
{
    m_string->prepend(str);
}

void QStringHandler::prepend(QChar ch)
{
    m_string->prepend(ch);
}

void QStringHandler::prepend(const QByteArray &ba)
{
    m_string->prepend(QString::fromUtf8(ba));
}

void QStringHandler::insert(int position, const char *str)
{
    m_string->insert(position, QString::fromUtf8(str));
}

void QStringHandler::insert(int position, const QString &str)
{
    m_string->insert(position, str);
}

void QStringHandler::insert(int position, QChar ch)
{
    m_string->insert(position, ch);
}

void QStringHandler::insert(int position, const QByteArray &ba)
{
    m_string->insert(position, QString::fromUtf8(ba));
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

void QStringHandler::replace(int position, int n, QChar after)
{
    m_string->replace(position, n, after);
}

void QStringHandler::replace(int position, int n, const QByteArray &after)
{
    m_string->replace(position, n, QString::fromUtf8(after));
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

QString QStringHandler::toCaseFolded() const
{
    return m_string->toCaseFolded();
}

QString QStringHandler::toHtmlEscaped() const
{
    return m_string->toHtmlEscaped();
}

void QStringHandler::truncate(int position)
{
    m_string->truncate(position);
}

// 数値変換
double QStringHandler::toDouble(bool *ok) const
{
    return m_string->toDouble(ok);
}

float QStringHandler::toFloat(bool *ok) const
{
    return m_string->toFloat(ok);
}

int QStringHandler::toInt(bool *ok, int base) const
{
    return m_string->toInt(ok, base);
}

long QStringHandler::toLong(bool *ok, int base) const
{
    return m_string->toLong(ok, base);
}

long long QStringHandler::toLongLong(bool *ok, int base) const
{
    return m_string->toLongLong(ok, base);
}

short QStringHandler::toShort(bool *ok, int base) const
{
    return m_string->toShort(ok, base);
}

unsigned int QStringHandler::toUInt(bool *ok, int base) const
{
    return m_string->toUInt(ok, base);
}

unsigned long QStringHandler::toULong(bool *ok, int base) const
{
    return m_string->toULong(ok, base);
}

unsigned long long QStringHandler::toULongLong(bool *ok, int base) const
{
    return m_string->toULongLong(ok, base);
}

unsigned short QStringHandler::toUShort(bool *ok, int base) const
{
    return m_string->toUShort(ok, base);
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

int QStringHandler::indexOf(QChar ch, int from) const
{
    return m_string->indexOf(ch, from);
}

int QStringHandler::lastIndexOf(const char *str, int from) const
{
    return m_string->lastIndexOf(QString::fromUtf8(str), from);
}

int QStringHandler::lastIndexOf(const QString &str, int from) const
{
    return m_string->lastIndexOf(str, from);
}

int QStringHandler::lastIndexOf(QChar ch, int from) const
{
    return m_string->lastIndexOf(ch, from);
}

bool QStringHandler::contains(const char *str) const
{
    return m_string->contains(QString::fromUtf8(str));
}

bool QStringHandler::contains(const QString &str) const
{
    return m_string->contains(str);
}

bool QStringHandler::contains(QChar ch) const
{
    return m_string->contains(ch);
}

bool QStringHandler::startsWith(const char *str) const
{
    return m_string->startsWith(QString::fromUtf8(str));
}

bool QStringHandler::startsWith(const QString &str) const
{
    return m_string->startsWith(str);
}

bool QStringHandler::startsWith(QChar ch) const
{
    return m_string->startsWith(ch);
}

bool QStringHandler::endsWith(const char *str) const
{
    return m_string->endsWith(QString::fromUtf8(str));
}

bool QStringHandler::endsWith(const QString &str) const
{
    return m_string->endsWith(str);
}

bool QStringHandler::endsWith(QChar ch) const
{
    return m_string->endsWith(ch);
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

QStringList QStringHandler::split(QChar sep) const
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

bool QStringHandler::equals(QChar ch) const
{
    return *m_string == QString(ch);
}

int QStringHandler::compare(const QString &other, Qt::CaseSensitivity cs) const
{
    return m_string->compare(other, cs);
}

int QStringHandler::compare(const char *other, Qt::CaseSensitivity cs) const
{
    return m_string->compare(QString::fromUtf8(other), cs);
}

int QStringHandler::compare(QChar ch, Qt::CaseSensitivity cs) const
{
    return m_string->compare(QString(ch), cs);
}

// カウント
int QStringHandler::count(const QString &str, Qt::CaseSensitivity cs) const
{
    return m_string->count(str, cs);
}

int QStringHandler::count(const char *str, Qt::CaseSensitivity cs) const
{
    return m_string->count(QString::fromUtf8(str), cs);
}

int QStringHandler::count(QChar ch, Qt::CaseSensitivity cs) const
{
    return m_string->count(ch, cs);
}

// セクション
QString QStringHandler::section(const char *sep, int start, int end, int flags) const
{
    return m_string->section(QString::fromUtf8(sep), start, end, QFlags<QString::SectionFlag>(flags));
}

QString QStringHandler::section(const QString &sep, int start, int end, int flags) const
{
    return m_string->section(sep, start, end, QFlags<QString::SectionFlag>(flags));
}

QString QStringHandler::section(QChar sep, int start, int end, int flags) const
{
    return m_string->section(sep, start, end, QFlags<QString::SectionFlag>(flags));
}

// 正規化
QString QStringHandler::normalized(NormalizationForm mode) const
{
    return m_string->normalized(static_cast<QString::NormalizationForm>(mode));
}

// 追加の文字列操作
QString QStringHandler::arg(const char *a) const
{
    return m_string->arg(QString::fromUtf8(a));
}

QString QStringHandler::arg(int a) const
{
    return m_string->arg(a);
}

QString QStringHandler::arg(long a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(qlonglong a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(short a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(uint a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(ulong a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(ushort a, int fieldWidth, int base, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, base, fillChar);
}

QString QStringHandler::arg(double a, int fieldWidth, char format, int precision, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, format, precision, fillChar);
}

QString QStringHandler::arg(QChar a, int fieldWidth, QChar fillChar) const
{
    return m_string->arg(a, fieldWidth, fillChar);
}

// パディング
QString QStringHandler::leftJustified(int width, QChar fill, bool truncate) const
{
    return m_string->leftJustified(width, fill, truncate);
}

QString QStringHandler::rightJustified(int width, QChar fill, bool truncate) const
{
    return m_string->rightJustified(width, fill, truncate);
}
