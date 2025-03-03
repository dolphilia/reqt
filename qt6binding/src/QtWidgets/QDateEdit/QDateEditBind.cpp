#include "QDateEditBind.h"
#include "QDateEditHandler.h"

QDateEditBind::QDateEditBind(QWidget* parent)
    : QDateEdit(parent)
    , handler(new DateEditHandler(this)) {
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
}

QDateEditBind::QDateEditBind(const QDate& date, QWidget* parent)
    : QDateEdit(date, parent)
    , handler(new DateEditHandler(this)) {
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
}

QDateEditBind::~QDateEditBind() {
    delete handler;
}

void QDateEditBind::setDateChangedCallback(DateChangedCallback callback) const {
    handler->setDateChangedCallback(callback);
}
