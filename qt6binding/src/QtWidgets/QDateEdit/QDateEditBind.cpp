#include "QDateEditBind.h"
#include "QDateEditHandler.h"

QDateEditBind::QDateEditBind(QWidget* parent)
    : QDateEdit(parent)
    , handler(new QDateEditHandler(this)) {
    connect(this, &QDateEdit::dateChanged, handler, &QDateEditHandler::onDateChanged);
}

QDateEditBind::QDateEditBind(const QDate& date, QWidget* parent)
    : QDateEdit(date, parent)
    , handler(new QDateEditHandler(this)) {
    connect(this, &QDateEdit::dateChanged, handler, &QDateEditHandler::onDateChanged);
}

QDateEditBind::~QDateEditBind() {
    delete handler;
}

void QDateEditBind::setDateChangedCallback(QDateEdit_DateChangedCallback callback) const {
    handler->setDateChangedCallback(callback);
}
