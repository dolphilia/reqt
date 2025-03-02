#ifndef QDATEEDIT_BIND_H
#define QDATEEDIT_BIND_H

#include <QDateEdit>
#include "QDateEditHandler.h"

class QDateEditBind : public QDateEdit {
    Q_OBJECT

public:
    explicit QDateEditBind(QWidget* parent = nullptr);
    QDateEditBind(const QDate& date, QWidget* parent = nullptr);
    ~QDateEditBind() override;

    void setDateChangedCallback(void (*callback)(void*, int, int, int));

private:
    DateEditHandler* handler;
};

#endif // QDATEEDIT_BIND_H
