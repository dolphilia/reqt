#include "QDateTimeEditBind.h"

QDateTimeEditBind::QDateTimeEditBind(QWidget* parent)
    : QDateTimeEdit(parent)
    , handler(new QDateTimeEditHandler(this)) {
    connect(this, &QDateTimeEdit::dateTimeChanged, handler, &QDateTimeEditHandler::onDateTimeChanged);
}

QDateTimeEditBind::~QDateTimeEditBind() {
    delete handler;
}

void QDateTimeEditBind::setDateChangedCallback(QDateTimeEdit_DateChangedCallback callback) const {
    handler->setDateCallback(callback);
}

void QDateTimeEditBind::setTimeChangedCallback(QDateTimeEdit_TimeChangedCallback callback) const {
    handler->setTimeCallback(callback);
}
