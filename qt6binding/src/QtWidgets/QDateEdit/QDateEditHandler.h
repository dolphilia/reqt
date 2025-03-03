#ifndef DATEEDIT_HANDLER_H
#define DATEEDIT_HANDLER_H

#include <QObject>
#include <QDate>

class DateEditHandler : public QObject {
    Q_OBJECT
    typedef void (*DateChangedCallback)(void*, int, int, int);
public:
    explicit DateEditHandler(QObject* parent = nullptr);
    void setDateChangedCallback(DateChangedCallback callback);
public slots:
    void onDateChanged(const QDate& date) const;
private:
    DateChangedCallback dateCallback;
};

#endif // DATEEDIT_HANDLER_H
