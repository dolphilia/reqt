#ifndef QMESSAGEBOX_HANDLER_H
#define QMESSAGEBOX_HANDLER_H

#include <QObject>
#include <QMessageBox>
#include <QAbstractButton>

class QMessageBoxHandler : public QObject {
    Q_OBJECT

public:
    QMessageBoxHandler(QMessageBox* messageBox, QObject* parent = nullptr);
    ~QMessageBoxHandler();

    // シグナルコールバック関数ポインタ
    void (*buttonClickedCallback)(void* data, QAbstractButton* button);

    // コールバックデータ
    void* buttonClickedData;

public slots:
    void onButtonClicked(QAbstractButton* button);
};

#endif // QMESSAGEBOX_HANDLER_H
