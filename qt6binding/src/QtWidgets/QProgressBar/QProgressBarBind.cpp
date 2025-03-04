#include "QProgressBarBind.h"
#include "QProgressBarHandler.h"

QProgressBarBind::QProgressBarBind(QWidget* parent)
    : QProgressBar(parent)
    , handler(new QProgressBarHandler(this)) {
    connect(this, &QProgressBar::valueChanged, handler, &QProgressBarHandler::onValueChanged);
}

QProgressBarBind::~QProgressBarBind() {
    delete handler;
}

void QProgressBarBind::setValueChangedCallback(QProgressBar_ValueChangedCallback callback) const {
    handler->setValueChangedCallback(callback);
}
