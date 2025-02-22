#ifndef DATETIMEEDIT_HANDLER_H
#define DATETIMEEDIT_HANDLER_H

#include <QObject>
#include <QDateTimeEdit>
#include <QDateTime>

class DateTimeEditHandler : public QObject {
    Q_OBJECT
public:
    explicit DateTimeEditHandler(QObject* parent = nullptr);
    void setDateTimeEdit(QDateTimeEdit* dateTimeEdit);
    void setDateTimeChangedCallback(void (*callback)(void*, int, int, int, int, int, int));

public slots:
    void onDateTimeChanged(const QDateTime& dateTime);

private:
    QDateTimeEdit* dateTimeEdit;
    void (*callback)(void*, int, int, int, int, int, int);
};

#endif // DATETIMEEDIT_HANDLER_H
