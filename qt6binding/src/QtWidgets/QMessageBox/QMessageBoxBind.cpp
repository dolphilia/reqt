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
