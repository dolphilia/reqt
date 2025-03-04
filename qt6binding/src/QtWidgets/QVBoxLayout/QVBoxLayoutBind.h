#ifndef QVBOXLAYOUT_BIND_H
#define QVBOXLAYOUT_BIND_H

#include <QVBoxLayout>

#include "QVBoxLayoutHandler.h"

class QVBoxLayoutHandler;

class QVBoxLayoutBind : public QVBoxLayout {
    Q_OBJECT
public:
    explicit QVBoxLayoutBind(QWidget* parent = nullptr);
    ~QVBoxLayoutBind() override;

private:
    QVBoxLayoutHandler* handler;
};

#endif // QVBOXLAYOUT_BIND_H
