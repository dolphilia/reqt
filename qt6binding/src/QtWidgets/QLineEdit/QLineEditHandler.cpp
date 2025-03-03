#include "QLineEditHandler.h"
#include <QString>

LineEditHandler::LineEditHandler(QObject* parent)
    : QObject(parent)
    , textChangedCallback(nullptr)
    , textEditedCallback(nullptr)
    , returnPressedCallback(nullptr)
{
}

void LineEditHandler::setTextChangedCallback(TextChangedCallback callback) {
    textChangedCallback = callback;
}

void LineEditHandler::setTextEditedCallback(TextChangedCallback callback) {
    textEditedCallback = callback;
}

void LineEditHandler::setReturnPressedCallback(TextChangedCallback callback) {
    returnPressedCallback = callback;
}

void LineEditHandler::onTextChanged(const QString& text) const {
    if (textChangedCallback) {
        textChangedCallback(const_cast<void*>(static_cast<const void*>(parent())), text.toUtf8().constData());
    }
}

void LineEditHandler::onTextEdited(const QString& text) const {
    if (textEditedCallback) {
        textEditedCallback(const_cast<void*>(static_cast<const void*>(parent())), text.toUtf8().constData());
    }
}

void LineEditHandler::onReturnPressed() const {
    if (returnPressedCallback) {
        returnPressedCallback(const_cast<void*>(static_cast<const void*>(parent())), "");
    }
}
