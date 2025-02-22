#include "bind_q_scroll_bar.h"

BindQScrollBar::BindQScrollBar(QWidget *parent)
    : QScrollBar(parent)
    , m_handler(nullptr)
{
}

BindQScrollBar::BindQScrollBar(Qt::Orientation orientation, QWidget *parent)
    : QScrollBar(orientation, parent)
    , m_handler(nullptr)
{
}

BindQScrollBar::~BindQScrollBar()
{
    delete m_handler;
}

void BindQScrollBar::setScrollBarHandler(ScrollBarHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QScrollBar::valueChanged,
                  m_handler, &ScrollBarHandler::onValueChanged);
        disconnect(this, &QScrollBar::sliderMoved,
                  m_handler, &ScrollBarHandler::onSliderMoved);
        disconnect(this, &QScrollBar::sliderPressed,
                  m_handler, &ScrollBarHandler::onSliderPressed);
        disconnect(this, &QScrollBar::sliderReleased,
                  m_handler, &ScrollBarHandler::onSliderReleased);
        disconnect(this, &QScrollBar::rangeChanged,
                  m_handler, &ScrollBarHandler::onRangeChanged);
        disconnect(this, &QScrollBar::actionTriggered,
                  m_handler, &ScrollBarHandler::onActionTriggered);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QScrollBar::valueChanged,
                m_handler, &ScrollBarHandler::onValueChanged);
        connect(this, &QScrollBar::sliderMoved,
                m_handler, &ScrollBarHandler::onSliderMoved);
        connect(this, &QScrollBar::sliderPressed,
                m_handler, &ScrollBarHandler::onSliderPressed);
        connect(this, &QScrollBar::sliderReleased,
                m_handler, &ScrollBarHandler::onSliderReleased);
        connect(this, &QScrollBar::rangeChanged,
                m_handler, &ScrollBarHandler::onRangeChanged);
        connect(this, &QScrollBar::actionTriggered,
                m_handler, &ScrollBarHandler::onActionTriggered);
    }
}

ScrollBarHandler *BindQScrollBar::handler() const
{
    return m_handler;
}
