#include "QToolBarBind.h"

BindQToolBar::BindQToolBar(QWidget *parent)
    : QToolBar(parent)
    , m_handler(nullptr)
{
}

BindQToolBar::BindQToolBar(const QString &title, QWidget *parent)
    : QToolBar(title, parent)
    , m_handler(nullptr)
{
}

BindQToolBar::~BindQToolBar()
{
    delete m_handler;
}

void BindQToolBar::setToolBarHandler(ToolBarHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QToolBar::actionTriggered,
                  m_handler, &ToolBarHandler::onActionTriggered);
        disconnect(this, &QToolBar::movableChanged,
                  m_handler, &ToolBarHandler::onMovableChanged);
        disconnect(this, &QToolBar::orientationChanged,
                  m_handler, &ToolBarHandler::onOrientationChanged);
        disconnect(this, &QToolBar::topLevelChanged,
                  m_handler, &ToolBarHandler::onTopLevelChanged);
        disconnect(this, &QToolBar::visibilityChanged,
                  m_handler, &ToolBarHandler::onVisibilityChanged);
        disconnect(this, &QToolBar::allowedAreasChanged,
                  m_handler, &ToolBarHandler::onAllowedAreasChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QToolBar::actionTriggered,
                m_handler, &ToolBarHandler::onActionTriggered);
        connect(this, &QToolBar::movableChanged,
                m_handler, &ToolBarHandler::onMovableChanged);
        connect(this, &QToolBar::orientationChanged,
                m_handler, &ToolBarHandler::onOrientationChanged);
        connect(this, &QToolBar::topLevelChanged,
                m_handler, &ToolBarHandler::onTopLevelChanged);
        connect(this, &QToolBar::visibilityChanged,
                m_handler, &ToolBarHandler::onVisibilityChanged);
        connect(this, &QToolBar::allowedAreasChanged,
                m_handler, &ToolBarHandler::onAllowedAreasChanged);
    }
}

ToolBarHandler *BindQToolBar::handler() const
{
    return m_handler;
}
