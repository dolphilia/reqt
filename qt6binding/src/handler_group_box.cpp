#include "../include/handler_group_box.h"

HandlerGroupBox::HandlerGroupBox(QObject *parent)
    : QObject(parent)
    , toggleCallback(nullptr)
    , widget(nullptr)
{
}

void HandlerGroupBox::setToggleCallback(void (*callback)(void*, bool)) {
    toggleCallback = callback;
}

void HandlerGroupBox::onToggled(bool checked) {
    if (toggleCallback && widget) {
        toggleCallback(widget, checked);
    }
}
