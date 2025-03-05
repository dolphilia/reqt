#ifndef QVARIANT_HANDLER_H
#define QVARIANT_HANDLER_H

#include <QObject>
#include <QVariant>

class QVariantHandler : public QObject {
    Q_OBJECT
    typedef void (*QVariant_ValueChangedCallback)(void*, const void*);
public:
    explicit QVariantHandler(QObject* parent = nullptr);
    ~QVariantHandler();

    // アクセサ
    QVariant *getVariant() const;
    
    // コールバック設定
    void setValueChangedCallback(QVariant_ValueChangedCallback callback);
    bool hasValueChangedCallback() const { return valueChangedCallback != nullptr; }

public slots:
    void onValueChanged(const QVariant& value) const;

private:
    QVariant *variant;
    QVariant_ValueChangedCallback valueChangedCallback;
};

#endif // QVARIANT_HANDLER_H
