#ifndef QMESSAGEBOX_BIND_H
#define QMESSAGEBOX_BIND_H

#include "QMessageBoxHandler.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QPushButton>
#include <QPixmap>

class QMessageBoxBind : public QMessageBox {
    Q_OBJECT
    typedef void (*ButtonClickedCallback)(void*, QAbstractButton*);
public:
    explicit QMessageBoxBind(QWidget* parent = nullptr);
    QMessageBoxBind(QMessageBox::Icon icon, const QString& title, const QString& text, 
                   QMessageBox::StandardButtons buttons = QMessageBox::NoButton, 
                   QWidget* parent = nullptr, 
                   Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ~QMessageBoxBind() override;
    void setButtonClickedCallback(ButtonClickedCallback callback) const;

    // スタティック関数
    static void about(QWidget* parent, const QString& title, const QString& text);
    static void aboutQt(QWidget* parent, const QString& title = QString());
    static QMessageBox::StandardButton critical(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton information(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton question(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No), QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton warning(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

private:
    QMessageBoxHandler* handler;
};

#endif // QMESSAGEBOX_BIND_H
