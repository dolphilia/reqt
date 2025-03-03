#include "QHBoxLayoutBind.h"
#include "QHBoxLayoutHandler.h"

QHBoxLayoutBind::QHBoxLayoutBind(QWidget* parent)
    : QHBoxLayout(parent)
    , handler(new HBoxLayoutHandler(this)) {
}

QHBoxLayoutBind::~QHBoxLayoutBind() {
    delete handler;
}
