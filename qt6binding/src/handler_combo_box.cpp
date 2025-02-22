#include "handler_combo_box.h"

ComboBoxHandler::ComboBoxHandler(void (*indexCallback)(void*, int),
                               void (*textCallback)(void*, const char*))
    : QObject(nullptr)
    , indexCallback(indexCallback)
    , textCallback(textCallback)
{
}

void ComboBoxHandler::onCurrentIndexChanged(int index)
{
    if (indexCallback) {
        indexCallback(parent(), index);
    }
}

void ComboBoxHandler::onCurrentTextChanged(const QString& text)
{
    if (textCallback) {
        textCallback(parent(), text.toUtf8().constData());
    }
}
