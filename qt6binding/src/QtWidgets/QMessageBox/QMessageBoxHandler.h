#ifndef QMESSAGEBOX_HANDLER_H
#define QMESSAGEBOX_HANDLER_H

#include <QObject>
#include <QMessageBox>
#include <QAbstractButton>

class QMessageBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*ButtonClickedCallback)(void*, QAbstractButton*);

public:
    explicit QMessageBoxHandler(QObject* parent = nullptr);
    ~QMessageBoxHandler();

    void setButtonClickedCallback(ButtonClickedCallback callback);

public slots:
    void onButtonClicked(QAbstractButton* button) const;

private:
    ButtonClickedCallback buttonClickedCallback;
};

#endif // QMESSAGEBOX_HANDLER_H
