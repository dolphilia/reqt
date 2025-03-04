#include "QHBoxLayoutBind.h"
#include "QHBoxLayoutHandler.h"

QHBoxLayoutBind::QHBoxLayoutBind(QWidget* parent)
    : QHBoxLayout(parent)
    , handler(new QHBoxLayoutHandler(this)) {
}

QHBoxLayoutBind::~QHBoxLayoutBind() {
    delete handler;
}
