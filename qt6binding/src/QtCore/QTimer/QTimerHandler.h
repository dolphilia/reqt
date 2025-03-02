#ifndef QT_QTIMERHANDLER_H
#define QT_QTIMERHANDLER_H

#include <QTimer>
#include <QObject>
#include <functional>

// タイマーのコールバック関数の型定義
typedef void (*QTimerCallback)(void *userData);

class QTimerHandler : public QObject {
    Q_OBJECT

public:
    // コンストラクタ
    QTimerHandler();
    ~QTimerHandler();

    // アクセサ
    QTimer *timer() const;

    // タイマー操作
    void start(int msec);
    void startSingleShot(int msec);
    void stop();
    bool isActive() const;
    int interval() const;
    void setInterval(int msec);
    int remainingTime() const;
    int timerId() const;
    
    // 追加機能
    bool isSingleShot() const;
    void setSingleShot(bool singleShot);
    int timerType() const;
    void setTimerType(int type);
    int id() const; // Qt 6.8以降

    // コールバック設定
    void setCallback(QTimerCallback callback, void *userData);

private slots:
    void handleTimeout();

private:
    QTimer *m_timer;
    QTimerCallback m_callback;
    void *m_userData;
};

#endif // QT_QTIMERHANDLER_H
