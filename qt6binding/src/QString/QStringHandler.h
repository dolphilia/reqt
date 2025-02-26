#ifndef QT_QSTRINGHANDLER_H
#define QT_QSTRINGHANDLER_H

#include <QString>
#include <QStringList>

class QStringHandler {
public:
    // コンストラクタ
    QStringHandler();
    explicit QStringHandler(const char *str);
    explicit QStringHandler(const QString &str);
    ~QStringHandler();

    // アクセサ
    QString *string() const;
    
    // 基本操作
    int length() const;
    bool isEmpty() const;
    void clear();
    
    // 文字列操作
    QString at(int position) const;
    void append(const char *str);
    void append(const QString &str);
    void prepend(const char *str);
    void prepend(const QString &str);
    void insert(int position, const char *str);
    void insert(int position, const QString &str);
    void remove(int position, int n);
    void replace(int position, int n, const char *after);
    void replace(int position, int n, const QString &after);
    
    // 変換
    QString toLower() const;
    QString toUpper() const;
    QString trimmed() const;
    QString simplified() const;
    
    // 検索
    int indexOf(const char *str, int from = 0) const;
    int indexOf(const QString &str, int from = 0) const;
    int lastIndexOf(const char *str, int from = -1) const;
    int lastIndexOf(const QString &str, int from = -1) const;
    bool contains(const char *str) const;
    bool contains(const QString &str) const;
    bool startsWith(const char *str) const;
    bool startsWith(const QString &str) const;
    bool endsWith(const char *str) const;
    bool endsWith(const QString &str) const;
    
    // 分割
    QStringList split(const char *sep) const;
    QStringList split(const QString &sep) const;
    
    // 変換
    QByteArray toUtf8() const;
    QByteArray toLatin1() const;
    QByteArray toLocal8Bit() const;
    
    // 比較
    bool equals(const char *str) const;
    bool equals(const QString &str) const;
    
private:
    QString *m_string;
};

#endif // QT_QSTRINGHANDLER_H
