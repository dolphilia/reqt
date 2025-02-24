#include "QToolButtonBind.h"

BindQToolButton::BindQToolButton(QWidget *parent)
    : QToolButton(parent)
    , m_handler(nullptr)
{
}

BindQToolButton::~BindQToolButton()
{
    delete m_handler;
}

void BindQToolButton::setToolButtonHandler(ToolButtonHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QToolButton::clicked,
                  m_handler, &ToolButtonHandler::onClicked);
        disconnect(this, &QToolButton::toggled,
                  m_handler, &ToolButtonHandler::onToggled);
        disconnect(this, &QToolButton::triggered,
                  m_handler, &ToolButtonHandler::onTriggered);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QToolButton::clicked,
                m_handler, &ToolButtonHandler::onClicked);
        connect(this, &QToolButton::toggled,
                m_handler, &ToolButtonHandler::onToggled);
        connect(this, &QToolButton::triggered,
                m_handler, &ToolButtonHandler::onTriggered);
    }
}

ToolButtonHandler *BindQToolButton::handler() const
{
    return m_handler;
}
