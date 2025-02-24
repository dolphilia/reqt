#ifndef BIND_Q_DOUBLE_SPIN_BOX_H
#define BIND_Q_DOUBLE_SPIN_BOX_H

#include <QDoubleSpinBox>
#include "QDoubleSpinBoxHandler.h"

class BindQDoubleSpinBox : public QDoubleSpinBox {
    Q_OBJECT
public:
    explicit BindQDoubleSpinBox(QWidget *parent = nullptr);
    ~BindQDoubleSpinBox();

    void setDoubleSpinBoxHandler(DoubleSpinBoxHandler *handler);
    DoubleSpinBoxHandler *handler() const;

private:
    DoubleSpinBoxHandler *m_handler;
};

#endif // BIND_Q_DOUBLE_SPIN_BOX_H
