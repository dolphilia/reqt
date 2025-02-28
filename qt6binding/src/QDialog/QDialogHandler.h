#ifndef QDIALOG_HANDLER_H
#define QDIALOG_HANDLER_H

#include <QObject>
#include <QDialog>

class QDialogHandler : public QObject {
    Q_OBJECT

public:
    QDialogHandler(QDialog* dialog, QObject* parent = nullptr);
    ~QDialogHandler();

    // シグナルコールバック関数ポインタ
    void (*acceptedCallback)(void* data);
    void (*finishedCallback)(void* data, int result);
    void (*rejectedCallback)(void* data);

    // コールバックデータ
    void* acceptedData;
    void* finishedData;
    void* rejectedData;

public slots:
    void onAccepted();
    void onFinished(int result);
    void onRejected();
};

#endif // QDIALOG_HANDLER_H
