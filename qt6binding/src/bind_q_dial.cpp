#include "bind_q_dial.h"
#include "handler_dial.h"

QDialBind::QDialBind(QWidget* parent)
    : QDial(parent), handler(nullptr)
{
}

QDialBind::~QDialBind()
{
    delete handler;
}

void QDialBind::setValueChangedCallback(QDial* dial, void (*callback)(void*, int))
{
    if (!handler) {
        handler = new DialHandler(this);
        handler->setDial(this);
    }
    handler->setValueChangedCallback(callback);
}

void QDialBind::setSliderMovedCallback(QDial* dial, void (*callback)(void*, int))
{
    if (!handler) {
        handler = new DialHandler(this);
        handler->setDial(this);
    }
    handler->setSliderMovedCallback(callback);
}

void QDialBind::setSliderPressedCallback(QDial* dial, void (*callback)(void*))
{
    if (!handler) {
        handler = new DialHandler(this);
        handler->setDial(this);
    }
    handler->setSliderPressedCallback(callback);
}

void QDialBind::setSliderReleasedCallback(QDial* dial, void (*callback)(void*))
{
    if (!handler) {
        handler = new DialHandler(this);
        handler->setDial(this);
    }
    handler->setSliderReleasedCallback(callback);
}

void QDialBind::setNotchesVisible(bool visible)
{
    QDial::setNotchesVisible(visible);
}

bool QDialBind::notchesVisible() const
{
    return QDial::notchesVisible();
}

void QDialBind::setNotchTarget(double target)
{
    QDial::setNotchTarget(target);
}

double QDialBind::notchTarget() const
{
    return QDial::notchTarget();
}


void QDialBind::setWrapping(bool on)
{
    QDial::setWrapping(on);
}

bool QDialBind::wrapping() const
{
    return QDial::wrapping();
}
