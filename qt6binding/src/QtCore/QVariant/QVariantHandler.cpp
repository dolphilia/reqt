#include "QVariantHandler.h"

QVariantHandler::QVariantHandler(QObject* parent)
    : QObject(parent)
    , variant(new QVariant())
    , valueChangedCallback(nullptr) {
}

QVariantHandler::~QVariantHandler() {
    delete variant;
}

// アクセサ
QVariant *QVariantHandler::getVariant() const {
    return variant;
}

// コールバック設定
void QVariantHandler::setValueChangedCallback(QVariant_ValueChangedCallback callback) {
    valueChangedCallback = callback;
}

// スロット
void QVariantHandler::onValueChanged(const QVariant& value) const {
    if (valueChangedCallback) {
        valueChangedCallback(parent(), &value);
    }
}
