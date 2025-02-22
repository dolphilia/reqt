#include "bind_q_spin_box.h"

BindQSpinBox::BindQSpinBox(QWidget *parent)
    : QSpinBox(parent)
    , m_handler(nullptr)
{
}

BindQSpinBox::~BindQSpinBox()
{
    delete m_handler;
}

void BindQSpinBox::setSpinBoxHandler(SpinBoxHandler *handler)
{
    if (m_handler) {
        disconnect(this, QOverload<int>::of(&QSpinBox::valueChanged),
                  m_handler, &SpinBoxHandler::onValueChanged);
        disconnect(this, &QSpinBox::textChanged,
                  m_handler, &SpinBoxHandler::onTextChanged);
        disconnect(this, &QSpinBox::editingFinished,
                  m_handler, &SpinBoxHandler::onEditingFinished);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, QOverload<int>::of(&QSpinBox::valueChanged),
                m_handler, &SpinBoxHandler::onValueChanged);
        connect(this, &QSpinBox::textChanged,
                m_handler, &SpinBoxHandler::onTextChanged);
        connect(this, &QSpinBox::editingFinished,
                m_handler, &SpinBoxHandler::onEditingFinished);
    }
}

SpinBoxHandler *BindQSpinBox::handler() const
{
    return m_handler;
}
