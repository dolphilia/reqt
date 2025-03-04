#ifndef QDATEEDIT_BIND_H
#define QDATEEDIT_BIND_H

#include "QDateEditHandler.h"
#include <QDateEdit>

class QDateEditBind : public QDateEdit {
    Q_OBJECT
    typedef void (*QDateEdit_DateChangedCallback)(void*, int, int, int);
public:
    explicit QDateEditBind(QWidget* parent = nullptr);
    explicit QDateEditBind(const QDate& date, QWidget* parent = nullptr);
    ~QDateEditBind() override;
    void setDateChangedCallback(QDateEdit_DateChangedCallback callback) const;
private:
    QDateEditHandler* handler;
};

#endif // QDATEEDIT_BIND_H
