#include "QScrollBarBind.h"
#include "QScrollBarHandler.h"

QScrollBarBind::QScrollBarBind(QWidget* parent)
    : QScrollBar(parent)
    , handler(new QScrollBarHandler(this)) {
    connect(this, &QScrollBar::valueChanged, handler, &QScrollBarHandler::onValueChanged);
    connect(this, &QScrollBar::sliderMoved, handler, &QScrollBarHandler::onSliderMoved);
    connect(this, &QScrollBar::sliderPressed, handler, &QScrollBarHandler::onSliderPressed);
    connect(this, &QScrollBar::sliderReleased, handler, &QScrollBarHandler::onSliderReleased);
    connect(this, &QScrollBar::rangeChanged, handler, &QScrollBarHandler::onRangeChanged);
    connect(this, &QScrollBar::actionTriggered, handler, &QScrollBarHandler::onActionTriggered);
}

QScrollBarBind::QScrollBarBind(Qt::Orientation orientation, QWidget* parent)
    : QScrollBar(orientation, parent)
    , handler(new QScrollBarHandler(this)) {
    connect(this, &QScrollBar::valueChanged, handler, &QScrollBarHandler::onValueChanged);
    connect(this, &QScrollBar::sliderMoved, handler, &QScrollBarHandler::onSliderMoved);
    connect(this, &QScrollBar::sliderPressed, handler, &QScrollBarHandler::onSliderPressed);
    connect(this, &QScrollBar::sliderReleased, handler, &QScrollBarHandler::onSliderReleased);
    connect(this, &QScrollBar::rangeChanged, handler, &QScrollBarHandler::onRangeChanged);
    connect(this, &QScrollBar::actionTriggered, handler, &QScrollBarHandler::onActionTriggered);
}

QScrollBarBind::~QScrollBarBind() {
    delete handler;
}

void QScrollBarBind::setValueChangedCallback(QScrollBar_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}

void QScrollBarBind::setSliderMovedCallback(QScrollBar_SliderMovedCallback callback) const {
    handler->setSliderMovedCallback(callback);
}

void QScrollBarBind::setSliderPressedCallback(QScrollBar_SliderPressedCallback callback) const {
    handler->setSliderPressedCallback(callback);
}

void QScrollBarBind::setSliderReleasedCallback(QScrollBar_SliderReleasedCallback callback) const {
    handler->setSliderReleasedCallback(callback);
}

void QScrollBarBind::setRangeChangedCallback(QScrollBar_RangeChangedCallback callback) const {
    handler->setRangeChangedCallback(callback);
}

void QScrollBarBind::setActionTriggeredCallback(QScrollBar_ActionTriggeredCallback callback) const {
    handler->setActionTriggeredCallback(callback);
}
