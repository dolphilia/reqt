#include "bind_q_menu.h"

BindQMenu::BindQMenu(QWidget *parent)
    : QMenu(parent)
    , m_handler(nullptr)
{
}

BindQMenu::BindQMenu(const QString &title, QWidget *parent)
    : QMenu(title, parent)
    , m_handler(nullptr)
{
}

BindQMenu::~BindQMenu()
{
    delete m_handler;
}

void BindQMenu::setMenuHandler(MenuHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QMenu::aboutToShow, m_handler, &MenuHandler::onAboutToShow);
        disconnect(this, &QMenu::aboutToHide, m_handler, &MenuHandler::onAboutToHide);
        disconnect(this, &QMenu::triggered, m_handler, &MenuHandler::onTriggered);
        disconnect(this, &QMenu::hovered, m_handler, &MenuHandler::onHovered);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QMenu::aboutToShow, m_handler, &MenuHandler::onAboutToShow);
        connect(this, &QMenu::aboutToHide, m_handler, &MenuHandler::onAboutToHide);
        connect(this, &QMenu::triggered, m_handler, &MenuHandler::onTriggered);
        connect(this, &QMenu::hovered, m_handler, &MenuHandler::onHovered);
    }
}

MenuHandler *BindQMenu::handler() const
{
    return m_handler;
}
