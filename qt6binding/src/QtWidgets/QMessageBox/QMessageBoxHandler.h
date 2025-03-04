#ifndef QMESSAGEBOX_HANDLER_H
#define QMESSAGEBOX_HANDLER_H

#include <QObject>
#include <QMessageBox>
#include <QAbstractButton>

class QMessageBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QMessageBox_ButtonClickedCallback)(void*, void*);

public:
    explicit QMessageBoxHandler(QObject* parent = nullptr);
    ~QMessageBoxHandler();

    void setButtonClickedCallback(QMessageBox_ButtonClickedCallback callback);

public slots:
    void onButtonClicked(QAbstractButton* button) const;

private:
    QMessageBox_ButtonClickedCallback buttonClickedCallback;
};

#endif // QMESSAGEBOX_HANDLER_H
