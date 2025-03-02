#ifndef QT_QSTRINGHANDLER_H
#define QT_QSTRINGHANDLER_H

#include <QString>
#include <QStringList>
#include <QChar>
#include <QByteArray>

// 正規化形式の列挙型
enum NormalizationForm {
    NormalizationForm_D,  // 正準分解
    NormalizationForm_C,  // 正準合成
    NormalizationForm_KD, // 互換分解
    NormalizationForm_KC  // 互換合成
};

// セクションフラグの列挙型
enum SectionFlag {
    SectionDefault = 0x00,           // デフォルト
    SectionSkipEmpty = 0x01,         // 空のセクションをスキップ
    SectionIncludeLeadingSep = 0x02, // 先頭の区切り文字を含む
    SectionIncludeTrailingSep = 0x04, // 末尾の区切り文字を含む
    SectionCaseInsensitiveSeps = 0x08 // 大文字小文字を区別しない
};

class QStringHandler {
public:
    // コンストラクタ
    QStringHandler();
    explicit QStringHandler(const char *str);
    explicit QStringHandler(const QString &str);
    explicit QStringHandler(QChar ch);
    explicit QStringHandler(const QByteArray &ba);
    explicit QStringHandler(const QChar *unicode, qsizetype size = -1);
    explicit QStringHandler(qsizetype size, QChar ch);
    ~QStringHandler();

    // アクセサ
    QString *string() const;
    
    // 基本操作
    int length() const;
    bool isEmpty() const;
    void clear();
    int capacity() const;
    const QChar *constData() const;
    const QChar *data() const;
    void chop(int n);
    QString chopped(int len) const;
    QString &fill(QChar ch, int size = -1);
    QString first(int n) const;
    QString last(int n) const;
    QChar front() const;
    QChar back() const;
    bool isNull() const;
    bool isLower() const;
    bool isUpper() const;
    bool isRightToLeft() const;
    QString left(int n) const;
    QString right(int n) const;
    QString mid(int position, int n = -1) const;
    int max_size() const;
    void reserve(int size);
    void resize(int size);
    void resize(int size, QChar fillChar);
    QString repeated(int times) const;
    QString sliced(int position, int n) const;
    QString sliced(int position) const;
    void shrink_to_fit();
    void squeeze();
    void swap(QString &other);
    
    // 数値変換
    QString &setNum(int n, int base = 10);
    QString &setNum(long n, int base = 10);
    QString &setNum(long long n, int base = 10);
    QString &setNum(unsigned long long n, int base = 10);
    QString &setNum(short n, int base = 10);
    QString &setNum(unsigned int n, int base = 10);
    QString &setNum(unsigned long n, int base = 10);
    QString &setNum(unsigned short n, int base = 10);
    QString &setNum(double n, char format = 'g', int precision = 6);
    QString &setNum(float n, char format = 'g', int precision = 6);
    
    // 文字列操作
    QString at(int position) const;
    void append(const char *str);
    void append(const QString &str);
    void append(QChar ch);
    void append(const QByteArray &ba);
    void append(const QChar *str, qsizetype len);
    void prepend(const char *str);
    void prepend(const QString &str);
    void prepend(QChar ch);
    void prepend(const QByteArray &ba);
    void insert(int position, const char *str);
    void insert(int position, const QString &str);
    void insert(int position, QChar ch);
    void insert(int position, const QByteArray &ba);
    void remove(int position, int n);
    void replace(int position, int n, const char *after);
    void replace(int position, int n, const QString &after);
    void replace(int position, int n, QChar after);
    void replace(int position, int n, const QByteArray &after);
    
    // 変換
    QString toLower() const;
    QString toUpper() const;
    QString trimmed() const;
    QString simplified() const;
    QString toCaseFolded() const;
    QString toHtmlEscaped() const;
    void truncate(int position);
    
    // 数値変換
    double toDouble(bool *ok = nullptr) const;
    float toFloat(bool *ok = nullptr) const;
    int toInt(bool *ok = nullptr, int base = 10) const;
    long toLong(bool *ok = nullptr, int base = 10) const;
    long long toLongLong(bool *ok = nullptr, int base = 10) const;
    short toShort(bool *ok = nullptr, int base = 10) const;
    unsigned int toUInt(bool *ok = nullptr, int base = 10) const;
    unsigned long toULong(bool *ok = nullptr, int base = 10) const;
    unsigned long long toULongLong(bool *ok = nullptr, int base = 10) const;
    unsigned short toUShort(bool *ok = nullptr, int base = 10) const;
    
    // 検索
    int indexOf(const char *str, int from = 0) const;
    int indexOf(const QString &str, int from = 0) const;
    int indexOf(QChar ch, int from = 0) const;
    int lastIndexOf(const char *str, int from = -1) const;
    int lastIndexOf(const QString &str, int from = -1) const;
    int lastIndexOf(QChar ch, int from = -1) const;
    bool contains(const char *str) const;
    bool contains(const QString &str) const;
    bool contains(QChar ch) const;
    bool startsWith(const char *str) const;
    bool startsWith(const QString &str) const;
    bool startsWith(QChar ch) const;
    bool endsWith(const char *str) const;
    bool endsWith(const QString &str) const;
    bool endsWith(QChar ch) const;
    
    // 分割
    QStringList split(const char *sep) const;
    QStringList split(const QString &sep) const;
    QStringList split(QChar sep) const;
    
    // 変換
    QByteArray toUtf8() const;
    QByteArray toLatin1() const;
    QByteArray toLocal8Bit() const;
    
    // 比較
    bool equals(const char *str) const;
    bool equals(const QString &str) const;
    bool equals(QChar ch) const;
    int compare(const QString &other, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    int compare(const char *other, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    int compare(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    
    // カウント
    int count(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    int count(const char *str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    int count(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    
    // セクション
    QString section(const char *sep, int start, int end = -1, int flags = SectionDefault) const;
    QString section(const QString &sep, int start, int end = -1, int flags = SectionDefault) const;
    QString section(QChar sep, int start, int end = -1, int flags = SectionDefault) const;
    
    // 正規化
    QString normalized(NormalizationForm mode) const;
    
    // 追加の文字列操作
    QString arg(const char *a) const;
    QString arg(int a) const;
    QString arg(long a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(qlonglong a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(short a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(uint a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(ulong a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(ushort a, int fieldWidth = 0, int base = 10, QChar fillChar = ' ') const;
    QString arg(double a, int fieldWidth = 0, char format = 'g', int precision = -1, QChar fillChar = ' ') const;
    QString arg(QChar a, int fieldWidth = 0, QChar fillChar = ' ') const;
    
    // パディング
    QString leftJustified(int width, QChar fill = ' ', bool truncate = false) const;
    QString rightJustified(int width, QChar fill = ' ', bool truncate = false) const;
    
private:
    QString *m_string;
};

#endif // QT_QSTRINGHANDLER_H
