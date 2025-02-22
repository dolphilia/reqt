#include "bind_q_tab_widget.h"

BindQTabWidget::BindQTabWidget(QWidget *parent)
    : QTabWidget(parent)
    , m_handler(nullptr)
{
}

BindQTabWidget::~BindQTabWidget()
{
    delete m_handler;
}

void BindQTabWidget::setTabWidgetHandler(TabWidgetHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QTabWidget::currentChanged, m_handler, &TabWidgetHandler::onCurrentChanged);
        disconnect(this, &QTabWidget::tabCloseRequested, m_handler, &TabWidgetHandler::onTabCloseRequested);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QTabWidget::currentChanged, m_handler, &TabWidgetHandler::onCurrentChanged);
        connect(this, &QTabWidget::tabCloseRequested, m_handler, &TabWidgetHandler::onTabCloseRequested);
    }
}

TabWidgetHandler *BindQTabWidget::handler() const
{
    return m_handler;
}
