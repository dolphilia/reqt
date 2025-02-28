#ifndef QABSTRACTBUTTON_HANDLER_H
#define QABSTRACTBUTTON_HANDLER_H

#include <QObject>
#include <QAbstractButton>

class QAbstractButtonHandler : public QObject {
    Q_OBJECT

public:
    QAbstractButtonHandler(QAbstractButton* button, QObject* parent = nullptr);
    ~QAbstractButtonHandler();

    // シグナルコールバック関数ポインタ
    void (*clickedCallback)(void* data, bool checked);
    void (*pressedCallback)(void* data);
    void (*releasedCallback)(void* data);
    void (*toggledCallback)(void* data, bool checked);

    // コールバックデータ
    void* clickedData;
    void* pressedData;
    void* releasedData;
    void* toggledData;

public slots:
    void onClicked(bool checked);
    void onPressed();
    void onReleased();
    void onToggled(bool checked);
};

#endif // QABSTRACTBUTTON_HANDLER_H
