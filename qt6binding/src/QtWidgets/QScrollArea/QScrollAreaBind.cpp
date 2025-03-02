#include "QScrollAreaBind.h"
#include <QScrollBar>

BindQScrollArea::BindQScrollArea(QWidget *parent)
    : QScrollArea(parent)
    , m_handler(nullptr)
{
}

BindQScrollArea::~BindQScrollArea()
{
    delete m_handler;
}

void BindQScrollArea::setScrollAreaHandler(ScrollAreaHandler *handler)
{
    if (m_handler) {
        disconnect(verticalScrollBar(), &QScrollBar::valueChanged,
                  m_handler, &ScrollAreaHandler::onVerticalScrollBarValueChanged);
        disconnect(horizontalScrollBar(), &QScrollBar::valueChanged,
                  m_handler, &ScrollAreaHandler::onHorizontalScrollBarValueChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(verticalScrollBar(), &QScrollBar::valueChanged,
                m_handler, &ScrollAreaHandler::onVerticalScrollBarValueChanged);
        connect(horizontalScrollBar(), &QScrollBar::valueChanged,
                m_handler, &ScrollAreaHandler::onHorizontalScrollBarValueChanged);
    }
}

ScrollAreaHandler *BindQScrollArea::handler() const
{
    return m_handler;
}
