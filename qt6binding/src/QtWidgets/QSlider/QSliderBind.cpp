#include "QSliderBind.h"
#include "QSliderHandler.h"

QSliderBind::QSliderBind(QWidget* parent)
    : QSlider(parent)
    , handler(new QSliderHandler(this)) {
    connect(this, &QSlider::valueChanged, handler, &QSliderHandler::onValueChanged);
    connect(this, &QSlider::sliderMoved, handler, &QSliderHandler::onSliderMoved);
    connect(this, &QSlider::sliderPressed, handler, &QSliderHandler::onSliderPressed);
    connect(this, &QSlider::sliderReleased, handler, &QSliderHandler::onSliderReleased);
    connect(this, &QSlider::rangeChanged, handler, &QSliderHandler::onRangeChanged);
    connect(this, &QSlider::actionTriggered, handler, &QSliderHandler::onActionTriggered);
}

QSliderBind::QSliderBind(Qt::Orientation orientation, QWidget* parent)
    : QSlider(orientation, parent)
    , handler(new QSliderHandler(this)) {
    connect(this, &QSlider::valueChanged, handler, &QSliderHandler::onValueChanged);
    connect(this, &QSlider::sliderMoved, handler, &QSliderHandler::onSliderMoved);
    connect(this, &QSlider::sliderPressed, handler, &QSliderHandler::onSliderPressed);
    connect(this, &QSlider::sliderReleased, handler, &QSliderHandler::onSliderReleased);
    connect(this, &QSlider::rangeChanged, handler, &QSliderHandler::onRangeChanged);
    connect(this, &QSlider::actionTriggered, handler, &QSliderHandler::onActionTriggered);
}

QSliderBind::~QSliderBind() {
    delete handler;
}

void QSliderBind::setValueChangedCallback(QSlider_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QSliderBind::setSliderMovedCallback(QSlider_SliderMovedCallback callback) const {
    handler->setSliderMovedCallback(callback);
}

void QSliderBind::setSliderPressedCallback(QSlider_SliderPressedCallback callback) const {
    handler->setSliderPressedCallback(callback);
}

void QSliderBind::setSliderReleasedCallback(QSlider_SliderReleasedCallback callback) const {
    handler->setSliderReleasedCallback(callback);
}

void QSliderBind::setRangeChangedCallback(QSlider_RangeChangedCallback callback) const {
    handler->setRangeChangedCallback(callback);
}

void QSliderBind::setActionTriggeredCallback(QSlider_ActionTriggeredCallback callback) const {
    handler->setActionTriggeredCallback(callback);
}
