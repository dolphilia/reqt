#include "QPushButtonHandler.h"

ButtonClickHandler::ButtonClickHandler(void (*callback)(void*))
    : QObject(nullptr)
    , callback(callback)
{
}

ButtonClickHandler::~ButtonClickHandler()
{
}

void ButtonClickHandler::onClick()
{
    if (callback) {
        callback(parent());
    }
}
