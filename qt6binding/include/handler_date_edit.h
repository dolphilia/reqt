#ifndef DATEEDIT_HANDLER_H
#define DATEEDIT_HANDLER_H

#include <QObject>
#include <QDateEdit>

class DateEditHandler : public QObject {
    Q_OBJECT
public:
    explicit DateEditHandler(QObject* parent = nullptr);
    void setDateEdit(QDateEdit* dateEdit);
    void setDateChangedCallback(void (*callback)(void*, int, int, int));

public slots:
    void onDateChanged(const QDate& date);

private:
    QDateEdit* dateEdit;
    void (*callback)(void*, int, int, int);
};

#endif // DATEEDIT_HANDLER_H
