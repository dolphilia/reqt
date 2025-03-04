#include "QComboBoxHandler.h"

QComboBoxHandler::QComboBoxHandler(QObject* parent)
    : QObject(parent)
    , indexCallback(nullptr)
    , textCallback(nullptr) {
}

void QComboBoxHandler::setCurrentIndexCallback(QComboBox_CurrentIndexChangedCallback callback) {
    indexCallback = callback;
}

void QComboBoxHandler::setCurrentTextCallback(QComboBox_CurrentTextChangedCallback callback) {
    textCallback = callback;
}

void QComboBoxHandler::onCurrentIndexChanged(int index) const {
    if (indexCallback) {
        indexCallback(parent(), index);
    }
}

void QComboBoxHandler::onCurrentTextChanged(const QString& text) const {
    if (textCallback) {
        textCallback(parent(), text.toUtf8().constData());
    }
}
