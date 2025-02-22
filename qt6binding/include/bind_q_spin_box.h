#ifndef BIND_Q_SPIN_BOX_H
#define BIND_Q_SPIN_BOX_H

#include <QSpinBox>
#include "handler_spin_box.h"

class BindQSpinBox : public QSpinBox {
    Q_OBJECT
public:
    explicit BindQSpinBox(QWidget *parent = nullptr);
    ~BindQSpinBox();

    void setSpinBoxHandler(SpinBoxHandler *handler);
    SpinBoxHandler *handler() const;

private:
    SpinBoxHandler *m_handler;
};

#endif // BIND_Q_SPIN_BOX_H
