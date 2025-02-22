#include "bind_q_radio_button.h"

BindQRadioButton::BindQRadioButton(QWidget *parent)
    : QRadioButton(parent)
    , m_handler(nullptr)
{
}

BindQRadioButton::BindQRadioButton(const QString &text, QWidget *parent)
    : QRadioButton(text, parent)
    , m_handler(nullptr)
{
}

BindQRadioButton::~BindQRadioButton()
{
    delete m_handler;
}

void BindQRadioButton::setRadioButtonHandler(RadioButtonHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QRadioButton::toggled, m_handler, &RadioButtonHandler::onToggled);
        disconnect(this, &QRadioButton::clicked, m_handler, &RadioButtonHandler::onClicked);
        disconnect(this, &QRadioButton::pressed, m_handler, &RadioButtonHandler::onPressed);
        disconnect(this, &QRadioButton::released, m_handler, &RadioButtonHandler::onReleased);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QRadioButton::toggled, m_handler, &RadioButtonHandler::onToggled);
        connect(this, &QRadioButton::clicked, m_handler, &RadioButtonHandler::onClicked);
        connect(this, &QRadioButton::pressed, m_handler, &RadioButtonHandler::onPressed);
        connect(this, &QRadioButton::released, m_handler, &RadioButtonHandler::onReleased);
    }
}

RadioButtonHandler *BindQRadioButton::handler() const
{
    return m_handler;
}
