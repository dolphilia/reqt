#include "QLineEditHandler.h"

LineEditTextHandler::LineEditTextHandler(void (*callback)(void*, const char*))
    : QObject(nullptr)
    , callback(callback)
{
}

void LineEditTextHandler::onTextChanged(const QString& text)
{
    if (callback) {
        callback(parent(), text.toUtf8().constData());
    }
}
