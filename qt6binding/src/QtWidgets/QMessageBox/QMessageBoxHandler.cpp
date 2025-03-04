#include "QMessageBoxHandler.h"

QMessageBoxHandler::QMessageBoxHandler(QObject* parent)
    : QObject(parent)
    , buttonClickedCallback(nullptr) {
}

void QMessageBoxHandler::setButtonClickedCallback(QMessageBox_ButtonClickedCallback callback) {
    buttonClickedCallback = callback;
}

void QMessageBoxHandler::onButtonClicked(QAbstractButton* button) const {
    if (buttonClickedCallback) {
        buttonClickedCallback(parent(), button);
    }
}
