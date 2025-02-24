#include "QMenuBarBind.h"

BindQMenuBar::BindQMenuBar(QWidget *parent)
    : QMenuBar(parent)
    , m_handler(nullptr)
{
}

BindQMenuBar::~BindQMenuBar()
{
    delete m_handler;
}

void BindQMenuBar::setMenuBarHandler(MenuBarHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QMenuBar::triggered, m_handler, &MenuBarHandler::onTriggered);
        disconnect(this, &QMenuBar::hovered, m_handler, &MenuBarHandler::onHovered);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QMenuBar::triggered, m_handler, &MenuBarHandler::onTriggered);
        connect(this, &QMenuBar::hovered, m_handler, &MenuBarHandler::onHovered);
    }
}

MenuBarHandler *BindQMenuBar::handler() const
{
    return m_handler;
}
