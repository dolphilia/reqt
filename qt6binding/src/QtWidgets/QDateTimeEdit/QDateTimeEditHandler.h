#ifndef DATETIMEEDIT_HANDLER_H
#define DATETIMEEDIT_HANDLER_H

#include <QObject>
#include <QDateTime>

class DateTimeEditHandler : public QObject {
    Q_OBJECT
    typedef void (*DateChangedCallback)(void*, int, int, int);
    typedef void (*TimeChangedCallback)(void*, int, int, int);
public:
    explicit DateTimeEditHandler(QObject* parent = nullptr);
    void setDateCallback(DateChangedCallback callback);
    void setTimeCallback(TimeChangedCallback callback);
public slots:
    void onDateTimeChanged(const QDateTime& datetime) const;
private:
    DateChangedCallback dateCallback;
    TimeChangedCallback timeCallback;
};

#endif // DATETIMEEDIT_HANDLER_H
