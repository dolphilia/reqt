#include "QLineEditHandler.h"
#include <QString>

QLineEditHandler::QLineEditHandler(QObject* parent)
    : QObject(parent)
    , textChangedCallback(nullptr)
    , textEditedCallback(nullptr)
    , returnPressedCallback(nullptr) {
}

void QLineEditHandler::setTextChangedCallback(TextChangedCallback callback) {
    textChangedCallback = callback;
}

void QLineEditHandler::setTextEditedCallback(TextEditedCallback callback) {
    textEditedCallback = callback;
}

void QLineEditHandler::setReturnPressedCallback(ReturnPressedCallback callback) {
    returnPressedCallback = callback;
}

void QLineEditHandler::onTextChanged(const QString& text) const {
    if (textChangedCallback) {
        textChangedCallback(parent(), text.toUtf8().constData());
    }
}

void QLineEditHandler::onTextEdited(const QString& text) const {
    if (textEditedCallback) {
        textEditedCallback(parent(), text.toUtf8().constData());
    }
}

void QLineEditHandler::onReturnPressed() const {
    if (returnPressedCallback) {
        returnPressedCallback(parent(), "");
    }
}
