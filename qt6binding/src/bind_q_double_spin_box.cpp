#include "bind_q_double_spin_box.h"

BindQDoubleSpinBox::BindQDoubleSpinBox(QWidget *parent)
    : QDoubleSpinBox(parent)
    , m_handler(nullptr)
{
}

BindQDoubleSpinBox::~BindQDoubleSpinBox()
{
    delete m_handler;
}

void BindQDoubleSpinBox::setDoubleSpinBoxHandler(DoubleSpinBoxHandler *handler)
{
    if (m_handler) {
        disconnect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                  m_handler, &DoubleSpinBoxHandler::onValueChanged);
        disconnect(this, &QDoubleSpinBox::editingFinished,
                  m_handler, &DoubleSpinBoxHandler::onEditingFinished);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                m_handler, &DoubleSpinBoxHandler::onValueChanged);
        connect(this, &QDoubleSpinBox::editingFinished,
                m_handler, &DoubleSpinBoxHandler::onEditingFinished);
    }
}

DoubleSpinBoxHandler *BindQDoubleSpinBox::handler() const
{
    return m_handler;
}
