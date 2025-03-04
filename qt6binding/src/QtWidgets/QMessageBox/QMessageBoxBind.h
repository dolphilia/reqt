#ifndef QMESSAGEBOX_BIND_H
#define QMESSAGEBOX_BIND_H

#include "QMessageBoxHandler.h"
#include <QMessageBox>

class QMessageBoxBind : public QMessageBox {
    Q_OBJECT
    typedef void (*QMessageBox_ButtonClickedCallback)(void*, void*);
public:
    explicit QMessageBoxBind(QWidget* parent = nullptr);
    QMessageBoxBind(QMessageBox::Icon icon, const QString& title, const QString& text, 
                   QMessageBox::StandardButtons buttons = QMessageBox::NoButton, 
                   QWidget* parent = nullptr, 
                   Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ~QMessageBoxBind() override;
    void setButtonClickedCallback(QMessageBox_ButtonClickedCallback callback) const;
private:
    QMessageBoxHandler* handler;
};

#endif // QMESSAGEBOX_BIND_H
