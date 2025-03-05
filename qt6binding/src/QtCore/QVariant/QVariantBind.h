#ifndef QVARIANT_BIND_H
#define QVARIANT_BIND_H

#include <QObject>
#include <QVariant>

#include "QVariantHandler.h"

class QVariantHandler;

class QVariantBind : public QObject {
    Q_OBJECT
    typedef void (*QVariant_ValueChangedCallback)(void*, const void*);
public:
    // コンストラクタ
    explicit QVariantBind(QObject *parent = nullptr);
    explicit QVariantBind(const QVariant &value, QObject *parent = nullptr);
    ~QVariantBind() override;

    // コールバック設定
    void setValueChangedCallback(QVariant_ValueChangedCallback callback) const;
    
    // ハンドラーアクセサ
    QVariantHandler* getHandler() const { return handler; }

private:
    QVariantHandler* handler;
};

#endif // QVARIANT_BIND_H
