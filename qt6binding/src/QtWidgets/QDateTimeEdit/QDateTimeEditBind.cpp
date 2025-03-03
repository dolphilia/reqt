#include "QDateTimeEditBind.h"

QDateTimeEditBind::QDateTimeEditBind(QWidget* parent)
    : QDateTimeEdit(parent)
    , handler(new DateTimeEditHandler(this))
{
    connect(this, &QDateTimeEdit::dateTimeChanged, handler, &DateTimeEditHandler::onDateTimeChanged);
}

QDateTimeEditBind::~QDateTimeEditBind() {
    delete handler;
}

void QDateTimeEditBind::setDateChangedCallback(DateChangedCallback callback) const {
    handler->setDateCallback(callback);
}

void QDateTimeEditBind::setTimeChangedCallback(TimeChangedCallback callback) const {
    handler->setTimeCallback(callback);
}
