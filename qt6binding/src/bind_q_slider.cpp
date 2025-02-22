#include "bind_q_slider.h"

BindQSlider::BindQSlider(QWidget *parent)
    : QSlider(parent)
    , m_handler(nullptr)
{
}

BindQSlider::BindQSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent)
    , m_handler(nullptr)
{
}

BindQSlider::~BindQSlider()
{
    delete m_handler;
}

void BindQSlider::setSliderHandler(SliderHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QSlider::valueChanged, m_handler, &SliderHandler::onValueChanged);
        disconnect(this, &QSlider::sliderMoved, m_handler, &SliderHandler::onSliderMoved);
        disconnect(this, &QSlider::sliderPressed, m_handler, &SliderHandler::onSliderPressed);
        disconnect(this, &QSlider::sliderReleased, m_handler, &SliderHandler::onSliderReleased);
        disconnect(this, &QSlider::rangeChanged, m_handler, &SliderHandler::onRangeChanged);
        disconnect(this, &QSlider::actionTriggered, m_handler, &SliderHandler::onActionTriggered);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QSlider::valueChanged, m_handler, &SliderHandler::onValueChanged);
        connect(this, &QSlider::sliderMoved, m_handler, &SliderHandler::onSliderMoved);
        connect(this, &QSlider::sliderPressed, m_handler, &SliderHandler::onSliderPressed);
        connect(this, &QSlider::sliderReleased, m_handler, &SliderHandler::onSliderReleased);
        connect(this, &QSlider::rangeChanged, m_handler, &SliderHandler::onRangeChanged);
        connect(this, &QSlider::actionTriggered, m_handler, &SliderHandler::onActionTriggered);
    }
}

SliderHandler *BindQSlider::handler() const
{
    return m_handler;
}
