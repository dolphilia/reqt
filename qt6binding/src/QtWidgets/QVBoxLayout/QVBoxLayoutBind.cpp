#include "QVBoxLayoutBind.h"
#include "QVBoxLayoutHandler.h"

QVBoxLayoutBind::QVBoxLayoutBind(QWidget* parent)
    : QVBoxLayout(parent)
    , handler(new QVBoxLayoutHandler(this)) {
}

QVBoxLayoutBind::~QVBoxLayoutBind() {
    delete handler;
}
