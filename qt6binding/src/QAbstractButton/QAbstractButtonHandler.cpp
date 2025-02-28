#include "QAbstractButtonHandler.h"

QAbstractButtonHandler::QAbstractButtonHandler(QAbstractButton* button, QObject* parent)
    : QObject(parent),
      clickedCallback(nullptr),
      pressedCallback(nullptr),
      releasedCallback(nullptr),
      toggledCallback(nullptr),
      clickedData(nullptr),
      pressedData(nullptr),
      releasedData(nullptr),
      toggledData(nullptr)
{
    // シグナルとスロットを接続
    connect(button, &QAbstractButton::clicked, this, &QAbstractButtonHandler::onClicked);
    connect(button, &QAbstractButton::pressed, this, &QAbstractButtonHandler::onPressed);
    connect(button, &QAbstractButton::released, this, &QAbstractButtonHandler::onReleased);
    connect(button, &QAbstractButton::toggled, this, &QAbstractButtonHandler::onToggled);
}

QAbstractButtonHandler::~QAbstractButtonHandler()
{
    // 特に何もする必要はない
}

void QAbstractButtonHandler::onClicked(bool checked)
{
    if (clickedCallback) {
        clickedCallback(clickedData, checked);
    }
}

void QAbstractButtonHandler::onPressed()
{
    if (pressedCallback) {
        pressedCallback(pressedData);
    }
}

void QAbstractButtonHandler::onReleased()
{
    if (releasedCallback) {
        releasedCallback(releasedData);
    }
}

void QAbstractButtonHandler::onToggled(bool checked)
{
    if (toggledCallback) {
        toggledCallback(toggledData, checked);
    }
}
