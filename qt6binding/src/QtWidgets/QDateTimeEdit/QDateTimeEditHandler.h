#ifndef DATETIMEEDIT_HANDLER_H
#define DATETIMEEDIT_HANDLER_H

#include <QObject>
#include <QDateTime>

class QDateTimeEditHandler : public QObject {
    Q_OBJECT
    typedef void (*QDateTimeEdit_DateChangedCallback)(void*, int, int, int);
    typedef void (*QDateTimeEdit_TimeChangedCallback)(void*, int, int, int);
public:
    explicit QDateTimeEditHandler(QObject* parent = nullptr);
    void setDateCallback(QDateTimeEdit_DateChangedCallback callback);
    void setTimeCallback(QDateTimeEdit_TimeChangedCallback callback);
public slots:
    void onDateTimeChanged(const QDateTime& datetime) const;
private:
    QDateTimeEdit_DateChangedCallback dateCallback;
    QDateTimeEdit_TimeChangedCallback timeCallback;
};

#endif // DATETIMEEDIT_HANDLER_H
