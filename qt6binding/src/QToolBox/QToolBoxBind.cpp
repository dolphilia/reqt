#include "QToolBoxBind.h"

BindQToolBox::BindQToolBox(QWidget *parent)
    : QToolBox(parent)
    , m_handler(nullptr)
{
}

BindQToolBox::~BindQToolBox()
{
    delete m_handler;
}

void BindQToolBox::setToolBoxHandler(ToolBoxHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QToolBox::currentChanged,
                  m_handler, &ToolBoxHandler::onCurrentChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QToolBox::currentChanged,
                m_handler, &ToolBoxHandler::onCurrentChanged);
    }
}

ToolBoxHandler *BindQToolBox::handler() const
{
    return m_handler;
}
