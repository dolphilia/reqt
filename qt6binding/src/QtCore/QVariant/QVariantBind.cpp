#include "QVariantBind.h"
#include "QVariantHandler.h"

// コンストラクタ
QVariantBind::QVariantBind(QObject* parent)
    : QObject(parent)
    , handler(new QVariantHandler(this)) {
}

QVariantBind::QVariantBind(const QVariant &value, QObject* parent)
    : QObject(parent)
    , handler(new QVariantHandler(this)) {
    handler->getVariant()->setValue(value);
}

// デストラクタ
QVariantBind::~QVariantBind() {
    delete handler;
}

// コールバック設定
void QVariantBind::setValueChangedCallback(QVariant_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}
