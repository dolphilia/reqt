#include "QComboBoxHandler.h"

ComboBoxHandler::ComboBoxHandler(QObject* parent)
    : QObject(parent)
    , indexCallback(nullptr)
    , textCallback(nullptr) {
}

void ComboBoxHandler::setCurrentIndexCallback(CurrentIndexChangedCallback callback) {
    indexCallback = callback;
}

void ComboBoxHandler::setCurrentTextCallback(CurrentTextChangedCallback callback) {
    textCallback = callback;
}

void ComboBoxHandler::onCurrentIndexChanged(int index) const {
    if (indexCallback) {
        indexCallback(parent(), index);
    }
}

void ComboBoxHandler::onCurrentTextChanged(const QString& text) const {
    if (textCallback) {
        textCallback(parent(), text.toUtf8().constData());
    }
}
