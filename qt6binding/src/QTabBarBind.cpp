#include "QTabBarBind.h"

BindQTabBar::BindQTabBar(QWidget *parent)
    : QTabBar(parent)
    , m_handler(nullptr)
{
}

BindQTabBar::~BindQTabBar()
{
    delete m_handler;
}

void BindQTabBar::setTabBarHandler(TabBarHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QTabBar::currentChanged, m_handler, &TabBarHandler::onCurrentChanged);
        disconnect(this, &QTabBar::tabCloseRequested, m_handler, &TabBarHandler::onTabCloseRequested);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QTabBar::currentChanged, m_handler, &TabBarHandler::onCurrentChanged);
        connect(this, &QTabBar::tabCloseRequested, m_handler, &TabBarHandler::onTabCloseRequested);
    }
}

TabBarHandler *BindQTabBar::handler() const
{
    return m_handler;
}
