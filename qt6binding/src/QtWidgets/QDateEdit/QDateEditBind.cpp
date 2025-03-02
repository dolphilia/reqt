#include "QDateEditBind.h"
#include "qdateedit.h"
#include <QDate>

QDateEditBind::QDateEditBind(QWidget* parent)
    : QDateEdit(parent)
    , handler(new DateEditHandler(this))
{
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
    handler->setDateEdit(this);
}

QDateEditBind::QDateEditBind(const QDate& date, QWidget* parent)
    : QDateEdit(date, parent)
    , handler(new DateEditHandler(this))
{
    connect(this, &QDateEdit::dateChanged, handler, &DateEditHandler::onDateChanged);
    handler->setDateEdit(this);
}

QDateEditBind::~QDateEditBind() {
    delete handler;
}

void QDateEditBind::setDateChangedCallback(void (*callback)(void*, int, int, int)) {
    handler->setDateChangedCallback(callback);
}
