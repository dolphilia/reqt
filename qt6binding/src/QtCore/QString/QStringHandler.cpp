#include "QStringHandler.h"

QStringHandler::QStringHandler(QObject* parent)
    : QObject(parent)
    , changedCallback(nullptr)
    , m_text() {
}

QStringHandler::~QStringHandler() {
}

void QStringHandler::setChangedCallback(QStringChangedCallback callback) {
    changedCallback = callback;
}

void QStringHandler::setText(const QString &text) {
    if (m_text != text) {
        m_text = text;
        onTextChanged(text);
    }
}

QString QStringHandler::text() const {
    return m_text;
}

void QStringHandler::onTextChanged(const QString &text) const {
    if (changedCallback) {
        QByteArray utf8 = text.toUtf8();
        changedCallback(parent(), utf8.constData());
    }
}
