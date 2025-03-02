#include "QMessageBoxHandler.h"

QMessageBoxHandler::QMessageBoxHandler(QMessageBox* messageBox, QObject* parent)
    : QObject(parent)
    , buttonClickedCallback(nullptr)
    , buttonClickedData(nullptr)
{
    connect(messageBox, &QMessageBox::buttonClicked, this, &QMessageBoxHandler::onButtonClicked);
}

QMessageBoxHandler::~QMessageBoxHandler()
{
}

void QMessageBoxHandler::onButtonClicked(QAbstractButton* button)
{
    if (buttonClickedCallback) {
        buttonClickedCallback(buttonClickedData, button);
    }
}
