#ifndef QHBOXLAYOUT_BIND_H
#define QHBOXLAYOUT_BIND_H

#include "QHBoxLayoutHandler.h"
#include <QHBoxLayout>

class QHBoxLayoutBind : public QHBoxLayout {
    Q_OBJECT
public:
    explicit QHBoxLayoutBind(QWidget* parent = nullptr);
    ~QHBoxLayoutBind() override;
private:
    HBoxLayoutHandler* handler;
};

#endif // QHBOXLAYOUT_BIND_H
