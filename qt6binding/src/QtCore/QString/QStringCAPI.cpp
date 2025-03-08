#include "QStringBind.h"
#include <QString>

extern "C" {

// QString()

void *QString_create() {
    return new QStringBind();
}

// QString(QChar ch)

void *QString_createFromQChar(void *ch) {
    QChar c = *static_cast<QChar*>(ch);
    return new QStringBind(c);
}

// QString(QLatin1StringView str)

void *QString_createFromLatin1View(void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView *>(latin1StringView);
    return new QStringBind(*view);
}

// QString(const QByteArray &ba)

void *QString_createFromByteArray(void *byteArray) {
    QByteArray *ba = static_cast<QByteArray *>(byteArray);
    return new QStringBind(*ba);
}

// QString(const char *str)

void *QString_createFromCString(const char *cString) {
    return new QStringBind(cString);
}

// (since 6.1) QString(const char8_t *str)
// QString(const QChar *unicode, qsizetype size = -1)

void *QString_createFromUnicode(const void *unicode, long long size) {
    const QChar *chars = reinterpret_cast<const QChar*>(unicode);
    return new QStringBind(chars, size);
}

// QString(qsizetype size, QChar ch)

void *QString_createWithSize(long long size, void* c) {
    QChar qchar = *static_cast<QChar*>(c);
    return new QStringBind(size, qchar);
}

// QString(const QString &other)

void *QString_createFromQString(void *qString) {
    QString *string = static_cast<QString*>(qString);
    return new QStringBind(*string);
}

// QString(QString &&other)

void *QString_createFromQStringMove(void *qString) {
    QString *string = static_cast<QString*>(qString);
    return new QStringBind(std::move(*string));
}

// ~QString()

void QString_delete(void *str){
    delete static_cast<QStringBind*>(str);
}

// QString & append(const QString &str)

void* QString_appendWithQString(void *str, void *qString) {
    QString *string = static_cast<QString *>(qString);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*string));
}

// QString & append(QChar ch)

void* QString_appendByQChar(void *str, void *qChar) {
    QChar c = *static_cast<QChar*>(qChar);
    return new QStringBind(static_cast<QStringBind*>(str)->append(c));
}

void* QString_appendByChar(void *str, char c) {
    return new QStringBind(static_cast<QStringBind*>(str)->append(QChar(c)));
}

// QString & append(QLatin1StringView str)

void* QString_appendFromLatin1View(void *str, void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView *>(latin1StringView);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*view));
}

// (since 6.0) QString & append(QStringView v)

void* QString_appendFromStringView(void *str, void *stringView) {
    QStringView *view = static_cast<QStringView *>(stringView);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*view));
}

// (since 6.5) QString & append(QUtf8StringView str)

void* QString_appendFromUtf8View(void *str, void *utf8StringView) {
    QUtf8StringView *view = static_cast<QUtf8StringView *>(utf8StringView);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*view));
}

// QString & append(const QByteArray &ba)

void* QString_appendFromByteArray(void *str, void *byteArray) {
    QByteArray *ba = static_cast<QByteArray *>(byteArray);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*ba));
}

// QString & append(const char *str)

void* QString_appendFromCString(void *str, void *cString) {
    QString *string = static_cast<QString *>(cString);
    return new QStringBind(static_cast<QStringBind*>(str)->append(*string));
}

// QString & append(const QChar *str, qsizetype len)

void* QString_appendWithCharArray(void *str, void *unicode, long long size) {
    QChar *chars = static_cast<QChar*>(unicode);
    return new QStringBind(static_cast<QStringBind*>(str)->append(chars, size));
}

// QString arg(Args &&... args) const
void *QString_argVa(void *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int bufSize = strlen(format) + 1;
    char *buffer = new char[bufSize];
    vsnprintf(buffer, bufSize, format, args);
    va_end(args);
    QString result = static_cast<QStringBind*>(str)->arg(QString::fromUtf8(buffer));
    delete[] buffer;
    return new QStringBind(result);
}


// QString arg(const QString &a, int fieldWidth = 0, QChar fillChar = u' ') const

void *QString_argWithQString(void *str, void *qString, int fieldWidth, void* fillChar) {
    QString *string = static_cast<QString*>(qString);
    QString result = static_cast<QStringBind*>(str)->arg(*string, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

void *QString_argWithCString(void *str, const char *cString, int fieldWidth, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(QString::fromUtf8(cString), fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(QChar a, int fieldWidth = 0, QChar fillChar = u' ') const

void *QString_argWithQChar(void *str, void *qChar, int fieldWidth, void* fillChar) {
    QChar c = *static_cast<QChar*>(qChar);
    QString result = static_cast<QStringBind*>(str)->arg(c, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(QLatin1StringView a, int fieldWidth = 0, QChar fillChar = u' ') const

void *QString_argWithLatin1View(void *str, void *latin1StringView, int fieldWidth, void* fillChar) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    QString result = static_cast<QStringBind*>(str)->arg(*view, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(QStringView a, int fieldWidth = 0, QChar fillChar = u' ') const

void *QString_argWithStringView(void *str, void *stringView, int fieldWidth, void* fillChar) {
    QStringView *view = static_cast<QStringView*>(stringView);
    QString result = static_cast<QStringBind*>(str)->arg(*view, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(char a, int fieldWidth = 0, QChar fillChar = u' ') const

void *QString_argWithChar(void *str, char c, int fieldWidth, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(c, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(int a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithInt(void *str, int a, int fieldWidth, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(long a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithLong(void *str, long a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(qlonglong a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithLongLong(void *str, long long a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(static_cast<qlonglong>(a), fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(qulonglong a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithULongLong(void *str, unsigned long long a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(static_cast<qulonglong>(a), fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(short a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithShort(void *str, short a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(uint a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithUInt(void *str, unsigned int a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(ulong a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argWithULong(void *str, unsigned long a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(ushort a, int fieldWidth = 0, int base = 10, QChar fillChar = u' ') const

void *QString_argUShort(void *str, unsigned short a, int fieldWidth, int base, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, base, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// QString arg(double a, int fieldWidth = 0, char format = 'g', int precision = -1, QChar fillChar = u' ') const

void *QString_argWithDouble(void *str, double a, int fieldWidth, char format, int precision, void* fillChar) {
    QString result = static_cast<QStringBind*>(str)->arg(a, fieldWidth, format, precision, *static_cast<QChar*>(fillChar));
    return new QStringBind(result);
}

// (since 6.6) QString & assign(QAnyStringView v)
// (since 6.6) QString & assign(InputIterator first, InputIterator last)
// (since 6.6) QString & assign(qsizetype n, QChar c)
// const QChar at(qsizetype position) const

void* QString_at(void *str, long long position) {
    QChar ch = static_cast<QStringBind*>(str)->at(position);
    return new QChar(ch);
}

// QChar & back()
// QChar back() const

void* QString_back(void *str) {
    QChar ch = static_cast<QStringBind*>(str)->back();
    return new QChar(ch);
}

// QString::iterator begin()
// QString::const_iterator begin() const
// qsizetype capacity() const

long long QString_capacity(void *str) {
    return static_cast<QStringBind*>(str)->capacity();
}

// QString::const_iterator cbegin() const
// QString::const_iterator cend() const
// void chop(qsizetype n)

void QString_chop(void *str, long long n) {
    static_cast<QStringBind*>(str)->chop(n);
}

// QString chopped(qsizetype len) &&
// QString chopped(qsizetype len) const &

void *QString_choppedMove(void *str, long long len) {
    QString result = static_cast<QStringBind*>(str)->chopped(len);
    return new QStringBind(result);
}

// void clear()

void QString_clear(void *str) {
    static_cast<QStringBind*>(str)->clear();
}

// int compare(QChar ch, Qt::CaseSensitivity cs);

int QString_compareWithQChar(void *str, void *qChar, int cs) {
    QChar c = *static_cast<QChar*>(qChar);
    return static_cast<QStringBind*>(str)->compare(c, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QLatin1StringView other, Qt::CaseSensitivity cs);

int QString_compareWithLatin1(void *str, void *other, int cs) {
    QLatin1StringView* latin1View = static_cast<QLatin1StringView*>(other);
    return static_cast<QStringBind*>(str)->compare(*latin1View, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QStringView s, Qt::CaseSensitivity cs);

int QString_compareWithQStringView(void *str, void *stringView, int cs) {
    QStringView* view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->compare(*view, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(const QString &other, Qt::CaseSensitivity cs);


int QString_compareWithQString(void *str, void *other, int cs) {
    QString *string = static_cast<QString*>(other);
    return static_cast<QStringBind*>(str)->compare(*string, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

int QString_compareWithChar(void *str, void *qChar, int cs) {
    QChar ch = *static_cast<QChar*>(qChar);
    return static_cast<QStringBind*>(str)->compare(ch, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QLatin1StringView other, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

int QString_compareWithLatin1View(void *str, void *other, int cs) {
    QLatin1StringView* latin1View = static_cast<QLatin1StringView*>(other);
    return static_cast<QStringBind*>(str)->compare(*latin1View, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QStringView s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

int QString_compareWithStringView(void *str, void *stringView, int cs) {
    QStringView* view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->compare(*view, static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(const QString &other, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

int QString_compareWithCString(void *str, const char *other, int cs) {
    return static_cast<QStringBind*>(str)->compare(QString::fromUtf8(other), static_cast<Qt::CaseSensitivity>(cs));
}

// QString::const_iterator constBegin() const
// const QChar * constData() const

const void *QString_constData(void *str) {
    const QChar *data = static_cast<QStringBind*>(str)->constData();
    return const_cast<QChar*>(data);
}
// QString::const_iterator constEnd() const
// bool contains(const QRegularExpression &re, QRegularExpressionMatch *rmatch = nullptr) const

bool QString_containsRegex(void *str, void *re, void *rmatch) {
    QRegularExpression *regex = static_cast<QRegularExpression*>(re);
    QRegularExpressionMatch *match = static_cast<QRegularExpressionMatch*>(rmatch);
    return static_cast<QStringBind*>(str)->contains(*regex, match);
}

// bool contains(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_containsQString(void *str, void *substr) {
    QString *string = static_cast<QString*>(substr);
    return static_cast<QStringBind*>(str)->contains(*string);
}

// bool contains(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_containsQChar(void *str, void *qChar) {
    QChar c = *static_cast<QChar*>(qChar);
    return static_cast<QStringBind*>(str)->contains(c);
}

// bool contains(QLatin1StringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_containsLatin1(void *str, void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    return static_cast<QStringBind*>(str)->contains(*view);
}

// bool contains(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_containsQStringView(void *str, void *stringView) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->contains(*view);
}

// qsizetype count(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_countWithQString(void *str, void *substr, int cs) {
    QString *string = static_cast<QString*>(substr);
    return static_cast<QStringBind*>(str)->count(*string, static_cast<Qt::CaseSensitivity>(cs));
}

long long QString_countWithCString(void *str, const char *substr, int cs) {
    return static_cast<QStringBind*>(str)->count(QString::fromUtf8(substr), static_cast<Qt::CaseSensitivity>(cs));
}
// qsizetype count(const QRegularExpression &re) const

long long QString_countUsingRegex(void *str, void *regex) {
    QRegularExpression *re = static_cast<QRegularExpression*>(regex);
    return static_cast<QStringBind*>(str)->count(*re);
}

// qsizetype count(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_countByChar(void *str, void* ch, int cs) {
    QChar character = *static_cast<QChar*>(ch);
    return static_cast<QStringBind*>(str)->count(character, static_cast<Qt::CaseSensitivity>(cs));
}

// (since 6.0) qsizetype count(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    
long long QString_countFromStringView(void *str, void *stringView, int cs) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->count(*view, static_cast<Qt::CaseSensitivity>(cs));
}

// QString::const_reverse_iterator crbegin() const
// QString::const_reverse_iterator crend() const
// QChar * data()
// const QChar * data() const

void *QString_data(void *str) {
    return static_cast<QStringBind*>(str)->data();
}

// QString::iterator end()
// QString::const_iterator end() const
// bool endsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_endsWithWString(void *str, void *suffix) {
    QString *string = static_cast<QString*>(suffix);
    return static_cast<QStringBind*>(str)->endsWith(*string);
}

// bool endsWith(QChar c, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_endsWithQChar(void *str, void* qChar) {
    QChar c = *static_cast<QChar*>(qChar);
    return static_cast<QStringBind*>(str)->endsWith(c);
}

// bool endsWith(QLatin1StringView s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_endsWithLatin1(void *str, void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    return static_cast<QStringBind*>(str)->endsWith(*view);
}

// bool endsWith(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_endsWithStringView(void *str, void *stringView) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->endsWith(*view);
}

// (since 6.1) QString::iterator erase(QString::const_iterator first, QString::const_iterator last)
// (since 6.5) QString::iterator erase(QString::const_iterator it)
// QString & fill(QChar ch, qsizetype size = -1)

void *QString_fill(void *str, void* qChar, long long size) {
    QChar c = *static_cast<QChar*>(qChar);
    static_cast<QStringBind*>(str)->fill(c, size);
    return str;
}

// (since 6.0) QString first(qsizetype n) &&
// (since 6.0) QString first(qsizetype n) const &

void *QString_first(void *str, long long n) {
    QString result = static_cast<QStringBind*>(str)->first(n);
    return new QStringBind(result);
}

// QChar & front()
// QChar front() const

void* QString_front(void *str) {
    return new QChar(static_cast<QStringBind*>(str)->front());
}

// qsizetype indexOf(QLatin1StringView str, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_indexOfLatin1(void *str, void *latin1StringView, long long from, int cs) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    return static_cast<QStringBind*>(str)->indexOf(*view, from, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype indexOf(const QRegularExpression &re, qsizetype from = 0, QRegularExpressionMatch *rmatch = nullptr) const

long long QString_indexOfRegex(void *str, void *regex, long long from, void *rmatch) {
    QRegularExpression *re = static_cast<QRegularExpression*>(regex);
    QRegularExpressionMatch *match = static_cast<QRegularExpressionMatch*>(rmatch);
    return static_cast<QStringBind*>(str)->indexOf(*re, from, match);
}

// qsizetype indexOf(const QString &str, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_indexOfQString(void *str, void *substr, long long from, int cs) {
    QString *string = static_cast<QString*>(substr);
    return static_cast<QStringBind*>(str)->indexOf(*string, from, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype indexOf(QChar ch, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_indexOfQChar(void *str, void* qChar, long long from, int cs) {
    QChar c = *static_cast<QChar*>(qChar);
    return static_cast<QStringBind*>(str)->indexOf(c, from, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype indexOf(QStringView str, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_indexOfStringView(void *str, void *stringView, long long from, int cs) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->indexOf(*view, from, static_cast<Qt::CaseSensitivity>(cs));
}

// QString & insert(qsizetype position, const QString &str)

void* QString_insertWithQString(void *str, long long position, void *qString) {
    QString *string = static_cast<QString *>(qString);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, *string));
}

// QString & insert(qsizetype position, QChar ch)

void* QString_insertWithQChar(void *str, long long position, void *qChar) {
    QChar c = *static_cast<QChar*>(qChar);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, c));
}

// QString & insert(qsizetype position, QLatin1StringView str)

void* QString_insertWithLatin1View(void *str, long long position, void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView *>(latin1StringView);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, *view));
}

// (since 6.0) QString & insert(qsizetype position, QStringView str)

void* QString_insertWithStringView(void *str, long long position, void *stringView) {
    QStringView *view = static_cast<QStringView *>(stringView);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, *view));
}

// (since 6.5) QString & insert(qsizetype position, QUtf8StringView str)

void* QString_insertWithUtf8View(void *str, long long position, void *utf8StringView) {
    QUtf8StringView *view = static_cast<QUtf8StringView *>(utf8StringView);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, *view));
}

// QString & insert(qsizetype position, const QByteArray &str)

void* QString_insertWithByteArray(void *str, long long position, void *byteArray) {
    QByteArray *ba = static_cast<QByteArray *>(byteArray);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, *ba));
}

// QString & insert(qsizetype position, const char *str)

void* QString_insertWithCString(void *str, long long position, const char *cString) {
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, QString::fromUtf8(cString)));
}

// QString & insert(qsizetype position, const QChar *unicode, qsizetype size)

void* QString_insertWithUnicode(void *str, long long position, const void *unicode, int size) {
    const QChar *chars = static_cast<const QChar*>(unicode);
    return new QStringBind(static_cast<QStringBind*>(str)->insert(position, chars, size));
}

// bool isEmpty() const

bool QString_isEmpty(void *str) {
    return static_cast<QStringBind*>(str)->isEmpty();
}

// bool isLower() const

bool QString_isLower(void *str) {
    return static_cast<QStringBind*>(str)->isLower();
}

// bool isNull() const

bool QString_isNull(void *str) {
    return static_cast<QStringBind*>(str)->isNull();
}

// bool isRightToLeft() const

bool QString_isRightToLeft(void *str) {
    return static_cast<QStringBind*>(str)->isRightToLeft();
}

// bool isUpper() const

bool QString_isUpper(void *str) {
    return static_cast<QStringBind*>(str)->isUpper();
}

// bool isValidUtf16() const

bool QString_isValidUtf16(void *str) {
    return static_cast<QStringBind*>(str)->isValidUtf16();
}

// (since 6.0) QString last(qsizetype n) &&
// (since 6.0) QString last(qsizetype n) const &

void *QString_last(void *str, long long n) {
    QString result = static_cast<QStringBind*>(str)->last(n);
    return new QStringBind(result);
}

// qsizetype lastIndexOf(const QRegularExpression &re, qsizetype from, QRegularExpressionMatch *rmatch = nullptr) const

long long QString_lastIndexOfRegex(void *str, void *regex, long long from, void *rmatch) {
    QRegularExpression *re = static_cast<QRegularExpression*>(regex);
    QRegularExpressionMatch *match = static_cast<QRegularExpressionMatch*>(rmatch);
    return static_cast<QStringBind*>(str)->lastIndexOf(*re, from, match);
}

// qsizetype lastIndexOf(const QString &str, qsizetype from, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfQString(void *str, void *substr, long long from, int cs) {
    QString *string = static_cast<QString*>(substr);
    return static_cast<QStringBind*>(str)->lastIndexOf(*string, from, static_cast<Qt::CaseSensitivity>(cs));
}

// (since 6.3) qsizetype lastIndexOf(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfQChar(void *str, void* ch, int cs) {
    QChar c = *static_cast<QChar*>(ch);
    return static_cast<QStringBind*>(str)->lastIndexOf(c, static_cast<Qt::CaseSensitivity>(cs));
}

// (since 6.2) qsizetype lastIndexOf(QLatin1StringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfLatin1(void *str, void *latin1StringView, int cs) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    return static_cast<QStringBind*>(str)->lastIndexOf(*view, static_cast<Qt::CaseSensitivity>(cs));
}

// (since 6.2) qsizetype lastIndexOf(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfStringView(void *str, void *stringView, int cs) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->lastIndexOf(*view, static_cast<Qt::CaseSensitivity>(cs));
}

// (since 6.2) qsizetype lastIndexOf(const QRegularExpression &re, QRegularExpressionMatch *rmatch = nullptr) const

long long QString_lastIndexOfRegexMatch(void *str, void *regex, void *rmatch) {
    QRegularExpression *re = static_cast<QRegularExpression*>(regex);
    QRegularExpressionMatch *match = static_cast<QRegularExpressionMatch*>(rmatch);
    return static_cast<QStringBind*>(str)->lastIndexOf(*re, match);
}

// (since 6.2) qsizetype lastIndexOf(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfQStringMatch(void *str, void *substr, int cs) {
    QString *string = static_cast<QString*>(substr);
    return static_cast<QStringBind*>(str)->lastIndexOf(*string, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype lastIndexOf(QChar ch, qsizetype from, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfQCharMatch(void *str, void* ch, long long from, int cs) {
    QChar c = *static_cast<QChar*>(ch);
    return static_cast<QStringBind*>(str)->lastIndexOf(c, from, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype lastIndexOf(QLatin1StringView str, qsizetype from, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfLatin1Match(void *str, void *latin1StringView, long long from, int cs) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    return static_cast<QStringBind*>(str)->lastIndexOf(*view, from, static_cast<Qt::CaseSensitivity>(cs));
}

// qsizetype lastIndexOf(QStringView str, qsizetype from, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

long long QString_lastIndexOfStringViewMatch(void *str, void *stringView, long long from, int cs) {
    QStringView *view = static_cast<QStringView*>(stringView);
    return static_cast<QStringBind*>(str)->lastIndexOf(*view, from, static_cast<Qt::CaseSensitivity>(cs));
}

// QString left(qsizetype n) &&
// QString left(qsizetype n) const &

void *QString_left(void *str, long long n) {
    QString result = static_cast<QStringBind*>(str)->left(n);
    return new QStringBind(result);
}

// QString leftJustified(qsizetype width, QChar fill = u' ', bool truncate = false) const

void *QString_leftJustified(void *str, long long width, void* fill, bool truncate) {
    QChar c = *static_cast<QChar*>(fill);
    QString result = static_cast<QStringBind*>(str)->leftJustified(width, c, truncate);
    return new QStringBind(result);
}

// qsizetype length() const

long long QString_length(void *str) {
    return static_cast<QStringBind*>(str)->length();
}

// (since 6.0) int localeAwareCompare(QStringView other) const

long long QString_localeAwareCompareWithStringView(void *str, void *other) {
    QStringView *view = static_cast<QStringView*>(other);
    return static_cast<QStringBind*>(str)->localeAwareCompare(*view);
}

// int localeAwareCompare(const QString &other) const

long long QString_localeAwareCompareWithQString(void *str, void *other) {
    QString *string = static_cast<QString*>(other);
    return static_cast<QStringBind*>(str)->localeAwareCompare(*string);
}

// (since 6.8) qsizetype max_size() const

long long QString_max_size(void *str) {
    return static_cast<QStringBind*>(str)->max_size();
}

// QString mid(qsizetype position, qsizetype n = -1) &&
// QString mid(qsizetype position, qsizetype n = -1) const &

void *QString_mid(void *str, long long position, long long n) {
    QString result = static_cast<QStringBind*>(str)->mid(position, n);
    return new QStringBind(result);
}

// QString normalized(QString::NormalizationForm mode, QChar::UnicodeVersion version = QChar::Unicode_Unassigned) const

void *QString_normalized(void *str, int mode, int version) {
    QString result = static_cast<QStringBind*>(str)->normalized(static_cast<QString::NormalizationForm>(mode), static_cast<QChar::UnicodeVersion>(version));
    return new QStringBind(result);
}

// QString & prepend(const QString &str)

void* QString_prependWithQString(void *str, void *qString) {
    QString qstr = *static_cast<QString*>(qString);
    QString result = static_cast<QStringBind*>(str)->prepend(qstr);
    return new QStringBind(result);
}

// QString & prepend(QLatin1StringView str)
void* QString_prependWithLatin1StringView(void *str, void *latin1StringView) {
    QLatin1StringView *view = static_cast<QLatin1StringView*>(latin1StringView);
    QString result = static_cast<QStringBind*>(str)->prepend(*view);
    return new QStringBind(result);
}

// (since 6.0) QString & prepend(QStringView str)

void* QString_prependWithStringView(void *str, void *stringView) {
    QStringView *view = static_cast<QStringView*>(stringView);
    QString result = static_cast<QStringBind*>(str)->prepend(*view);
    return new QStringBind(result);
}
// (since 6.5) QString & prepend(QUtf8StringView str)

void* QString_prependWithUtf8StringView(void *str, void *utf8StringView) {
    QUtf8StringView *view = static_cast<QUtf8StringView*>(utf8StringView);
    QString result = static_cast<QStringBind*>(str)->prepend(*view);
    return new QStringBind(result);
}

// QString & prepend(const QByteArray &ba)

void* QString_prependWithByteArray(void *str, void *byteArray) {
    QByteArray *ba = static_cast<QByteArray*>(byteArray);
    QString result = static_cast<QStringBind*>(str)->prepend(*ba);
    return new QStringBind(result);
}

// QString & prepend(const char *str)

void* QString_prependWithCString(void *str, const char *cString) {
    QString result = static_cast<QStringBind*>(str)->prepend(QString::fromUtf8(cString));
    return new QStringBind(result);
}

// QString & prepend(const QChar *str, qsizetype len)

void* QString_prependWithUnicode(void *str, const void *unicode, long long len) {
    const QChar *chars = static_cast<const QChar*>(unicode);
    QString result = static_cast<QStringBind*>(str)->prepend(chars, len);
    return new QStringBind(result);
}

// void push_back(const QString &other)

void QString_push_backWithQString(void *str, void *other) {
    static_cast<QStringBind*>(str)->push_back(*static_cast<QString*>(other));
}

// void push_back(QChar ch)

void QString_push_backWithQChar(void *str, void* ch) {
    static_cast<QStringBind*>(str)->push_back(*static_cast<QChar*>(ch));
}

// void push_front(const QString &other)

void QString_push_frontWithQString(void *str, void *other) {
    static_cast<QStringBind*>(str)->push_front(*static_cast<QString*>(other));
}

// void push_front(QChar ch)

void QString_push_frontWithQChar(void *str, void* ch) {
    static_cast<QStringBind*>(str)->push_front(*static_cast<QChar*>(ch));
}
// QString::reverse_iterator rbegin()
// QString::const_reverse_iterator rbegin() const
// QString & remove(const QRegularExpression &re)

void* QString_removeRegex(void *str, void *re) {
    QString result = static_cast<QStringBind*>(str)->remove(*static_cast<QRegularExpression*>(re));
    return new QStringBind(result);
}

// QString & remove(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_removeChar(void *str, void* ch, int cs) {
    QString result = static_cast<QStringBind*>(str)->remove(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}

// QString & remove(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_removeQString(void *str, void *substr, int cs) {
    QString result = static_cast<QStringBind*>(str)->remove(*static_cast<QString*>(substr), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}

// QString & remove(qsizetype position, qsizetype n)

void* QString_removeAtIndex(void *str, long long position, long long n) {
    QString result = static_cast<QStringBind*>(str)->remove(position, n);
    return new QStringBind(result);
}

// QString & remove(QLatin1StringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_removeLatin1(void *str, void *latin1StringView, int cs) {
    QString result = static_cast<QStringBind*>(str)->remove(*static_cast<QLatin1StringView*>(latin1StringView), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}

// (since 6.5) QString & removeAt(qsizetype pos)

void* QString_removeAt(void *str, long long pos) {
    QString result = static_cast<QStringBind*>(str)->removeAt(pos);
    return new QStringBind(result);
}

// (since 6.5) QString & removeFirst()

void* QString_removeFirst(void *str) {
    QString result = static_cast<QStringBind*>(str)->removeFirst();
    return new QStringBind(result);
}

// (since 6.1) QString & removeIf(Predicate pred)
void* QString_removeIf(void *str, void *pred) {
    typedef bool (*QCharPredicate)(QChar);
    QString result = static_cast<QStringBind*>(str)->removeIf(reinterpret_cast<QCharPredicate>(pred));
    return new QStringBind(result);
    
}

// (since 6.5) QString & removeLast()

void* QString_removeLast(void *str) {
    QString result = static_cast<QStringBind*>(str)->removeLast();
    return new QStringBind(result);
}

// QString::reverse_iterator rend()
// QString::const_reverse_iterator rend() const
// QString repeated(qsizetype times) const

void *QString_repeated(void *str, long long times) {
    QString result = static_cast<QStringBind*>(str)->repeated(times);
    return new QStringBind(result);
}

// QString & replace(qsizetype position, qsizetype n, const QString &after)

void QString_replaceAtIndex(void *str, long long position, long long n, const void *after) {
    static_cast<QStringBind*>(str)->replace(position, n, *static_cast<const QString*>(after));
}

// QString & replace(const QRegularExpression &re, const QString &after)

void* QString_replaceByRegex(void *str, void *re, const void *after) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QRegularExpression*>(re), *static_cast<const QString*>(after));
    return new QStringBind(result);
}

// QString & replace(QChar before, QChar after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceChar(void *str, void* before, void* after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QChar*>(before), *static_cast<QChar*>(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}

// QString & replace(QChar c, QLatin1StringView after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceCharToLatin1(void *str, void* c, void *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QChar*>(c), *static_cast<QLatin1StringView*>(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// QString & replace(QChar ch, const QString &after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceCharToString(void *str, void* ch, const char *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QChar*>(ch), QString::fromUtf8(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// QString & replace(QLatin1StringView before, QLatin1StringView after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceLatin1Pair(void *str, void *before, void *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QLatin1StringView*>(before), *static_cast<QLatin1StringView*>(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// QString & replace(QLatin1StringView before, const QString &after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceLatin1ToString(void *str, void *before, const char *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(*static_cast<QLatin1StringView*>(before), QString::fromUtf8(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// QString & replace(const QString &before, QLatin1StringView after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceStringToLatin1(void *str, const char *before, void *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(QString::fromUtf8(before), *static_cast<QLatin1StringView*>(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// QString & replace(const QString &before, const QString &after, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceStringPair(void *str, const char *before, const char *after, int cs) {
    QString result = static_cast<QStringBind*>(str)->replace(QString::fromUtf8(before), QString::fromUtf8(after), static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}

// QString & replace(qsizetype position, qsizetype n, QChar after)
void QString_replaceAtIndexWithChar(void *str, long long position, long long n, void* after) {
    static_cast<QStringBind*>(str)->replace(position, n, *static_cast<QChar*>(after));
}
// QString & replace(qsizetype position, qsizetype n, const QChar *after, qsizetype alen)

void* QString_replaceAtIndexArray(void *str, long long position, long long n, void *after, long long alen) {
    QChar *chars = static_cast<QChar*>(after);
    QString result = static_cast<QStringBind*>(str)->replace(position, n, chars, alen);
    return new QStringBind(result);
}
// QString & replace(const QChar *before, qsizetype blen, const QChar *after, qsizetype alen, Qt::CaseSensitivity cs = Qt::CaseSensitive)

void* QString_replaceArrayPair(void *str, void *before, long long blen, void *after, long long alen, int cs) {
    QChar *beforeChars = static_cast<QChar*>(before);
    QChar *afterChars = static_cast<QChar*>(after);
    QString result = static_cast<QStringBind*>(str)->replace(beforeChars, blen, afterChars, alen, static_cast<Qt::CaseSensitivity>(cs));
    return new QStringBind(result);
}
// void reserve(qsizetype size)

void QString_reserve(void *str, long long size) {
    static_cast<QStringBind*>(str)->reserve(size);
}

// void resize(qsizetype size)

void QString_resize(void *str, long long size) {
    static_cast<QStringBind*>(str)->resize(size);
}

// void resize(qsizetype newSize, QChar fillChar)

void QString_resizeWithChar(void *str, long long size, void* fillChar) {
    static_cast<QStringBind*>(str)->resize(size, *static_cast<QChar*>(fillChar));
}

// (since 6.8) void resizeForOverwrite(qsizetype size)

void QString_resizeForOverwrite(void *str, long long size) {
    static_cast<QStringBind*>(str)->resizeForOverwrite(size);
}

// QString right(qsizetype n) &&
// QString right(qsizetype n) const &

void *QString_right(void *str, long long n) {
    QString result = static_cast<QStringBind*>(str)->right(n);
    return new QStringBind(result);
}

// QString rightJustified(qsizetype width, QChar fill = u' ', bool truncate = false) const

void *QString_rightJustified(void *str, long long width, void* fill, bool truncate) {
    QString result = static_cast<QStringBind*>(str)->rightJustified(width, *static_cast<QChar*>(fill), truncate);
    return new QStringBind(result);
}

// QString section(QChar sep, qsizetype start, qsizetype end = -1, QString::SectionFlags flags = SectionDefault) const

void *QString_sectionWithQChar(void *str, void* sep, long long start, long long end, int flags) {
    QString result = static_cast<QStringBind*>(str)->section(*static_cast<QChar*>(sep), start, end, QFlags<QString::SectionFlag>(flags));
    return new QStringBind(result);
}

// QString section(const QRegularExpression &re, qsizetype start, qsizetype end = -1, QString::SectionFlags flags = SectionDefault) const

void *QString_sectionWithRegex(void *str, void* re, long long start, long long end, int flags) {
    QString result = static_cast<QStringBind*>(str)->section(*static_cast<QRegularExpression*>(re), start, end, QFlags<QString::SectionFlag>(flags));
    return new QStringBind(result);
}

// QString section(const QString &sep, qsizetype start, qsizetype end = -1, QString::SectionFlags flags = SectionDefault) const

void *QString_sectionWithQString(void *str, void* sep, long long start, long long end, int flags) {
    QString result = static_cast<QStringBind*>(str)->section(*static_cast<QString*>(sep), start, end, QFlags<QString::SectionFlag>(flags));
    return new QStringBind(result);
}

// QString & setNum(int n, int base = 10)

void *QString_setNumByInt(void *str, int n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(long n, int base = 10)

void *QString_setNumByLong(void *str, long n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(qlonglong n, int base = 10)

void *QString_setNumByLongLong(void *str, long long n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(qulonglong n, int base = 10)

void *QString_setNumByULongLong(void *str, unsigned long long n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(short n, int base = 10)

void *QString_setNumByShort(void *str, short n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(uint n, int base = 10)

void *QString_setNumByUInt(void *str, unsigned int n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(ulong n, int base = 10)

void *QString_setNumByULong(void *str, unsigned long n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(ushort n, int base = 10)

void *QString_setNumByUShort(void *str, unsigned short n, int base) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, base);
    return new QStringBind(result);
}

// QString & setNum(double n, char format = 'g', int precision = 6)

void *QString_setNumByDouble(void *str, double n, char format, int precision) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, format, precision);
    return new QStringBind(result);
}

// QString & setNum(float n, char format = 'g', int precision = 6)

void *QString_setNumByFloat(void *str, float n, char format, int precision) {
    QString result = static_cast<QStringBind*>(str)->setNum(n, format, precision);
    return new QStringBind(result);
}

// QString & setRawData(const QChar *unicode, qsizetype size)

void *QString_setRawData(void *str, const void *unicode, long long size) {
    const QChar *chars = static_cast<const QChar*>(unicode);
    QString result = static_cast<QStringBind*>(str)->setRawData(chars, size);
    return new QStringBind(result);
}

// QString & setUnicode(const QChar *unicode, qsizetype size)

void *QString_setUnicode(void *str, const void *unicode, long long size) {
    const QChar *chars = static_cast<const QChar*>(unicode);
    QString result = static_cast<QStringBind*>(str)->setUnicode(chars, size);
    return new QStringBind(result);
}

// QString & setUtf16(const ushort *unicode, qsizetype size)

void *QString_setUtf16(void *str, const unsigned short *unicode, long long size) {
    QString result = static_cast<QStringBind*>(str)->setUtf16(unicode, size);
    return new QStringBind(result);
}

// void shrink_to_fit()

void QString_shrink_to_fit(void *str) {
    static_cast<QStringBind*>(str)->squeeze();
}

// QString simplified() const

void *QString_simplified(void *str) {
    QString result = static_cast<QStringBind*>(str)->simplified();
    return new QStringBind(result);
}

// qsizetype size() const

long long QString_size(void *str) {
    return static_cast<QStringBind*>(str)->size();
}

// (since 6.8) QString & slice(qsizetype pos, qsizetype n)

void *QString_slice(void *str, long long pos, long long n) {
    QString result = static_cast<QStringBind*>(str)->slice(pos, n);
    return new QStringBind(result);
}

// (since 6.8) QString & slice(qsizetype pos)

void *QString_sliceFrom(void *str, long long pos) {
    QString result = static_cast<QStringBind*>(str)->slice(pos);
    return new QStringBind(result);
}

// (since 6.0) QString sliced(qsizetype pos, qsizetype n) &&

void *QString_slicedBy(void *str, long long position, long long n) {
    QString result = static_cast<QStringBind*>(str)->sliced(position, n);
    return new QStringBind(result);
}

// (since 6.0) QString sliced(qsizetype pos, qsizetype n) const &

void *QString_slicedByConst(void *str, long long position, long long n) {
    QString result = static_cast<QStringBind*>(str)->sliced(position, n);
    return new QStringBind(result);
}

// (since 6.0) QString sliced(qsizetype pos) &&
// (since 6.0) QString sliced(qsizetype pos) const &

void *QString_slicedFrom(void *str, long long position) {
    QString result = static_cast<QStringBind*>(str)->sliced(position);
    return new QStringBind(result);
}


// QStringList split(const QString &sep, Qt::SplitBehavior behavior = Qt::KeepEmptyParts, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

char **QString_splitQString(void *str, void *sep, int *count) {
    QStringList list = static_cast<QStringBind*>(str)->split(*static_cast<QString*>(sep));
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}

// QStringList split(const QRegularExpression &re, Qt::SplitBehavior behavior = Qt::KeepEmptyParts) const

char **QString_splitRegex(void *str, void *re, int *count) {
    QStringList list = static_cast<QStringBind*>(str)->split(*static_cast<QRegularExpression*>(re));
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}
// QStringList split(QChar sep, Qt::SplitBehavior behavior = Qt::KeepEmptyParts, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

char **QString_splitQChar(void *str, void* sep, int *count) {
    QStringList list = static_cast<QStringBind*>(str)->split(*static_cast<QChar*>(sep));
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}

// void squeeze()

void QString_squeeze(void *str) {
    static_cast<QStringBind*>(str)->squeeze();
}

// bool startsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_startsWith(void *str, void *prefix) {
    return static_cast<QStringBind*>(str)->startsWith(*static_cast<QString*>(prefix));
}

// bool startsWith(QChar c, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_startsWith_QChar(void *str, void *sep) {
    return static_cast<QStringBind*>(str)->startsWith(*static_cast<QChar*>(sep));
}

// bool startsWith(QLatin1StringView s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_startsWithLatin1(void *str, void *latin1StringView) {
    return static_cast<QStringBind*>(str)->startsWith(*static_cast<QLatin1StringView*>(latin1StringView));
}

// bool startsWith(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const

bool QString_startsWithStringView(void *str, void *stringView) {
    return static_cast<QStringBind*>(str)->startsWith(*static_cast<QStringView*>(stringView));
}

// void swap(QString &other)

void QString_swap(void *str, void *other) {
    static_cast<QStringBind*>(str)->swap(*static_cast<QString*>(other));
}

// CFStringRef toCFString() const
// QString toCaseFolded() const

void *QString_toCaseFolded(void *str) {
    QString result = static_cast<QStringBind*>(str)->toCaseFolded();
    return new QStringBind(result);
}

// double toDouble(bool *ok = nullptr) const

double QString_toDouble(void *str, bool *ok) {
    return static_cast<QStringBind*>(str)->toDouble(ok);
}

// (since 6.6) emscripten::val toEcmaString() const
// float toFloat(bool *ok = nullptr) const

float QString_toFloat(void *str, bool *ok) {
    return static_cast<QStringBind*>(str)->toFloat(ok);
}

// QString toHtmlEscaped() const

void *QString_toHtmlEscaped(void *str) {
    QString result = static_cast<QStringBind*>(str)->toHtmlEscaped();
    return new QStringBind(result);
}

// int toInt(bool *ok = nullptr, int base = 10) const

int QString_toInt(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toInt(ok, base);
}

// QByteArray toLatin1() const
void* QString_toLatin1(void *str) {
    QByteArray result = static_cast<QStringBind*>(str)->toLatin1();
    return new QByteArray(result);
}

// QByteArray toLocal8Bit() const

void* QString_toLocal8Bit(void *str) {
    QByteArray result = static_cast<QStringBind*>(str)->toLocal8Bit();
    return new QByteArray(result);
}
// long toLong(bool *ok = nullptr, int base = 10) const

long QString_toLong(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toLong(ok, base);
}

// qlonglong toLongLong(bool *ok = nullptr, int base = 10) const

long long QString_toLongLong(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toLongLong(ok, base);
}

// QString toLower() const

void *QString_toLower(void *str) {
    QString result = static_cast<QStringBind*>(str)->toLower();
    return new QStringBind(result);
}

// NSString * toNSString() const
// short toShort(bool *ok = nullptr, int base = 10) const

short QString_toShort(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toShort(ok, base);
}

// std::string toStdString() const
// std::u16string toStdU16String() const
// std::u32string toStdU32String() const
// std::wstring toStdWString() const
// uint toUInt(bool *ok = nullptr, int base = 10) const

unsigned int QString_toUInt(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toUInt(ok, base);
}

// ulong toULong(bool *ok = nullptr, int base = 10) const

unsigned long QString_toULong(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toULong(ok, base);
}

// qulonglong toULongLong(bool *ok = nullptr, int base = 10) const

unsigned long long QString_toULongLong(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toULongLong(ok, base);
}

// ushort toUShort(bool *ok = nullptr, int base = 10) const

unsigned short QString_toUShort(void *str, bool *ok, int base) {
    return static_cast<QStringBind*>(str)->toUShort(ok, base);
}

// QList<uint> toUcs4() const

unsigned int *QString_toUcs4(void *str, int *count) {
    QList<uint> list = static_cast<QStringBind*>(str)->toUcs4();
    *count = list.size();
    
    unsigned int *result = new unsigned int[*count];
    for (int i = 0; i < *count; i++) {
        result[i] = list.at(i);
    }
    
    return result;
}
// QString toUpper() const

void *QString_toUpper(void *str) {
    QString result = static_cast<QStringBind*>(str)->toUpper();
    return new QStringBind(result);
}

// QByteArray toUtf8() const

void* QString_toUtf8(void *str) {
    QByteArray result = static_cast<QStringBind*>(str)->toUtf8();
    return new QByteArray(result);
}
// qsizetype toWCharArray(wchar_t *array) const

long long QString_toWCharArray(void *str, wchar_t *array) {
    return static_cast<QStringBind*>(str)->toWCharArray(array);
}

// (since 6.0) auto tokenize(Needle &&sep, Flags... flags) &&
// (since 6.0) auto tokenize(Needle &&sep, Flags... flags) const &&
// (since 6.0) auto tokenize(Needle &&sep, Flags... flags) const &
// QString trimmed() const

void *QString_trimmed(void *str) {
    QString result = static_cast<QStringBind*>(str)->trimmed();
    return new QStringBind(result);
}


// void truncate(qsizetype position)

void QString_truncate(void *str, long long position) {
    static_cast<QStringBind*>(str)->truncate(position);
}


// const QChar * unicode() const

const void *QString_unicode(void *str) {
    const QChar *result = static_cast<QStringBind*>(str)->unicode();
    return result;
}

// const ushort * utf16() const

const unsigned short *QString_utf16(void *str) {
    return static_cast<QStringBind*>(str)->utf16();
}

// (since 6.7) std::u16string_view operator std::u16string_view() const
// QString & operator+=(const QString &other)

void *QString_operatorAddAssignQString(void *str, void *other) {
    QString result = *static_cast<QStringBind*>(str) + *static_cast<QString*>(other);
    return new QStringBind(result);
}
// QString & operator+=(QChar ch)
void *QString_operatorAddAssignQChar(void *str, void* ch) {
    QString result = *static_cast<QStringBind*>(str) + *static_cast<QChar*>(ch);
    return new QStringBind(result);
}

// QString & operator+=(QLatin1StringView str)
void *QString_operatorAddAssignQLatin1StringView(void *str, void *latin1) {
    QLatin1StringView view(static_cast<const char*>(latin1));
    QString result = *static_cast<QStringBind*>(str) + view;
    return new QStringBind(result);
}

// (since 6.0) QString & operator+=(QStringView str)
void *QString_operatorAddAssignQStringView(void *str, void *view) {
    QString result = *static_cast<QStringBind*>(str) + QString(*static_cast<QStringView*>(view));
    return new QStringBind(result);
}

// (since 6.5) QString & operator+=(QUtf8StringView str)
void *QString_operatorAddAssignQUtf8StringView(void *str, void *utf8) {
    QString result = *static_cast<QStringBind*>(str) + static_cast<QUtf8StringView*>(utf8)->toString();
    return new QStringBind(result);
}

// QString & operator+=(const QByteArray &ba)
void *QString_operatorAddAssignQByteArray(void *str, void *ba) {
    QByteArray *byteArray = static_cast<QByteArray*>(ba);
    QString result = *static_cast<QStringBind*>(str) + *byteArray;
    return new QStringBind(result);
}

// QString & operator+=(const char *str)
void *QString_operatorAddAssignCString(void *str, const char *cString) {
    QString result = *static_cast<QStringBind*>(str) + QString::fromUtf8(cString);
    return new QStringBind(result);
}
// QString & operator=(QString &&other)
// QString & operator=(const QString &other)
// QString & operator=(QChar ch)
// QString & operator=(QLatin1StringView str)
// QString & operator=(const QByteArray &ba)
// QString & operator=(const char *str)
// QChar & operator[](qsizetype position)
// const QChar operator[](qsizetype position) const
//-- Static Public Members
// 
// QString asprintf(const char *cformat, ...)

void *QString_asprintf_static(const char *cformat, ...) {
    va_list args;
    va_start(args, cformat);
    QString result = QStringBind::asprintf(cformat, args);
    va_end(args);
    return new QStringBind(result);
}
// int compare(const QString &s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

int QString_compareWithQStringQString_static(void *s1, void *s2, int cs) {
    return QStringBind::compare(*static_cast<QStringBind*>(s1), *static_cast<QStringBind*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QLatin1StringView s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

int QString_compareWithQLatin1StringViewQString_static(void *s1, void *s2, int cs) {
    return QStringBind::compare(*static_cast<QLatin1StringView*>(s1), *static_cast<QStringBind*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(QStringView s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

int QString_compareWithQStringViewQString_static(void *s1, void *s2, int cs) {
    return QStringBind::compare(*static_cast<QStringView*>(s1), *static_cast<QStringBind*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(const QString &s1, QLatin1StringView s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

int QString_compareWithQStringQLatin1StringView_static(void *s1, void *s2, int cs) {
    return QStringBind::compare(*static_cast<QStringBind*>(s1), *static_cast<QLatin1StringView*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

// int compare(const QString &s1, QStringView s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

int QString_compareWithQStringQStringView_static(void *s1, void *s2, int cs) {
    return QStringBind::compare(*static_cast<QStringBind*>(s1), *static_cast<QStringView*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

// QString fromCFString(CFStringRef string)
// (since 6.6) QString fromEcmaString(emscripten::val jsString)
// QString fromLatin1(const char *str, qsizetype size)

void *QString_fromLatin1WithSize_static(const char *str, long long size) {
    return new QStringBind(QStringBind::fromLatin1(str, size));
}

// (since 6.0) QString fromLatin1(QByteArrayView str)

void *QString_fromLatin1FromByteArrayView_static(const char *str) {
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLatin1(ba));
}

// QString fromLatin1(const QByteArray &str)

void *QString_fromLatin1FromByteArray_static(const char *str) {
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLatin1(ba));
}

// QString fromLocal8Bit(const char *str, qsizetype size)

void *QString_fromLocal8bitWithSize(const char *str, long long size) {
    return new QStringBind(QStringBind::fromLocal8Bit(str, size));
}

// (since 6.0) QString fromLocal8Bit(QByteArrayView str)

void *QString_fromLocal8bitFromByteArrayView(const char *str) {
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLocal8Bit(ba));
}

// QString fromLocal8Bit(const QByteArray &str)

void *QString_fromLocal8bitFromByteArray(const char *str) {
    QByteArray ba(str);
    return new QStringBind(QStringBind::fromLocal8Bit(ba));
}

// QString fromNSString(const NSString *string)
// QString fromRawData(const QChar *unicode, qsizetype size)

void *QString_fromRawData(const void *unicode, long long size) {
    return new QStringBind(QStringBind::fromRawData(static_cast<const QChar*>(unicode), size));
}

// QString fromStdString(const std::string &str)
// QString fromStdU16String(const std::u16string &str)
// QString fromStdU32String(const std::u32string &str)
// QString fromStdWString(const std::wstring &str)
// QString fromUcs4(const char32_t *unicode, qsizetype size = -1)

void *QString_fromUcs4(const char *unicode, long long size) {
    return new QStringBind(QStringBind::fromUcs4(reinterpret_cast<const char32_t*>(unicode), size));
}

// QString fromUtf8(const char *str, qsizetype size)

void *QString_fromUtf8WithSize(const char *str, long long size) {
    return new QStringBind(QStringBind::fromUtf8(str, size));
}

// (since 6.0) QString fromUtf8(QByteArrayView str)

void *QString_fromUtf8FromByteArrayView(void *str) {
    QByteArray ba(*static_cast<QByteArray*>(str));
    return new QStringBind(QStringBind::fromUtf8(ba));
}

// QString fromUtf8(const QByteArray &str)

void *QString_fromUtf8FromByteArray(const void *str) {
    QByteArray ba(*static_cast<const QByteArray*>(str));
    return new QStringBind(QStringBind::fromUtf8(ba));
}

// (since 6.1) QString fromUtf8(const char8_t *str)

void *QString_fromUtf8WithChar8(const char *str) {
    return new QStringBind(QStringBind::fromUtf8(reinterpret_cast<const char*>(str)));
}

// (since 6.0) QString fromUtf8(const char8_t *str, qsizetype size)

void *QString_fromUtf8WithChar8Size(const char *str, long long size) {
    return new QStringBind(QStringBind::fromUtf8(reinterpret_cast<const char*>(str), size));
}

// QString fromUtf16(const char16_t *unicode, qsizetype size = -1)

void *QString_fromUtf16(const char *unicode, long long size){
    return new QStringBind(QStringBind::fromUtf16(reinterpret_cast<const char16_t*>(unicode), size));
}

// QString fromWCharArray(const wchar_t *string, qsizetype size = -1)

void *QString_fromWCharArray(const wchar_t *string, long long size) {
    return new QStringBind(QStringBind::fromWCharArray(string, size));
}

// int localeAwareCompare(const QString &s1, const QString &s2)

int QString_localeAwareCompare(const void *s1, const void *s2) {
    return QStringBind::localeAwareCompare(*static_cast<const QStringBind*>(s1), *static_cast<const QStringBind*>(s2));
}

// (since 6.0) int localeAwareCompare(QStringView s1, QStringView s2)

int QString_localeAwareCompareWithView(void *s1, void *s2) {
    return QStringBind::localeAwareCompare(*static_cast<QStringView*>(s1), *static_cast<QStringView*>(s2));
}

// (since 6.8) qsizetype maxSize()

long long QString_maxSize() {
    return static_cast<int>(QString::maxSize());
}

// QString number(long n, int base = 10)

void *QString_numberByLong(long n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString number(double n, char format = 'g', int precision = 6)

void *QString_numberByDouble(double n, char format, int precision) {
    QString result = QStringBind::number(n, format, precision);
    return new QStringBind(result);
}

// QString number(int n, int base = 10)

void *QString_numberByInt(int n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString number(qlonglong n, int base = 10)

void *QString_numberByLongLong(long long n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString number(qulonglong n, int base = 10)

void *QString_numberByULongLong(unsigned long long n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString number(uint n, int base = 10)

void *QString_numberByUInt(unsigned int n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString number(ulong n, int base = 10)

void *QString_numberByULong(unsigned long n, int base) {
    QString result = QStringBind::number(n, base);
    return new QStringBind(result);
}

// QString vasprintf(const char *cformat, va_list ap)
void *QString_vasprintf(const char *cformat, va_list ap) {
    QString result = QStringBind::vasprintf(cformat, ap);
    return new QStringBind(result);
}

}