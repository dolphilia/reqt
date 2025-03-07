#ifndef QT_QSTRINGHANDLER_H
#define QT_QSTRINGHANDLER_H

#include <QString>
#include <QObject>

class QStringHandler : public QObject {
    Q_OBJECT
    typedef void (*QStringChangedCallback)(void*, const char*);
public:
    // コンストラクタ
    explicit QStringHandler(QObject* parent = nullptr);
    ~QStringHandler();

    // コールバック設定
    void setChangedCallback(QStringChangedCallback callback);

    // 文字列操作
    void setText(const QString &text);
    QString text() const;

public slots:
    void onTextChanged(const QString &text) const;

private:
    QStringChangedCallback changedCallback;
    QString m_text;
};

#endif // QT_QSTRINGHANDLER_H
