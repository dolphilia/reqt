#include "QMessageBoxBind.h"
#include "QMessageBoxHandler.h"

QMessageBoxBind::QMessageBoxBind(QWidget* parent)
    : QMessageBox(parent)
    , handler(new QMessageBoxHandler(this)) {
    connect(this, &QMessageBox::buttonClicked, handler, &QMessageBoxHandler::onButtonClicked);
}

QMessageBoxBind::QMessageBoxBind(QMessageBox::Icon icon, const QString& title, const QString& text, 
                               QMessageBox::StandardButtons buttons, 
                               QWidget* parent, 
                               Qt::WindowFlags f)
    : QMessageBox(icon, title, text, buttons, parent, f)
    , handler(new QMessageBoxHandler(this)) {
    connect(this, &QMessageBox::buttonClicked, handler, &QMessageBoxHandler::onButtonClicked);
}

QMessageBoxBind::~QMessageBoxBind() {
    delete handler;
}

void QMessageBoxBind::setButtonClickedCallback(QMessageBox_ButtonClickedCallback callback) const {
    handler->setButtonClickedCallback(callback);
}

// スタティック関数
void QMessageBoxBind::about(QWidget* parent, const QString& title, const QString& text) {
    QMessageBox::about(parent, title, text);
}

void QMessageBoxBind::aboutQt(QWidget* parent, const QString& title) {
    QMessageBox::aboutQt(parent, title);
}

QMessageBox::StandardButton QMessageBoxBind::critical(QWidget* parent, const QString& title, const QString& text, 
                                                    QMessageBox::StandardButtons buttons, 
                                                    QMessageBox::StandardButton defaultButton) {
    return QMessageBox::critical(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::information(QWidget* parent, const QString& title, const QString& text, 
                                                       QMessageBox::StandardButtons buttons, 
                                                       QMessageBox::StandardButton defaultButton) {
    return QMessageBox::information(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::question(QWidget* parent, const QString& title, const QString& text, 
                                                    QMessageBox::StandardButtons buttons, 
                                                    QMessageBox::StandardButton defaultButton) {
    return QMessageBox::question(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::warning(QWidget* parent, const QString& title, const QString& text, 
                                                   QMessageBox::StandardButtons buttons, 
                                                   QMessageBox::StandardButton defaultButton) {
    return QMessageBox::warning(parent, title, text, buttons, defaultButton);
}
