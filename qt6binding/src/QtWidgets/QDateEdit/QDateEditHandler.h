#ifndef DATEEDIT_HANDLER_H
#define DATEEDIT_HANDLER_H

#include <QObject>
#include <QDate>

class QDateEditHandler : public QObject {
    Q_OBJECT
    typedef void (*QDateEdit_DateChangedCallback)(void*, int, int, int);
public:
    explicit QDateEditHandler(QObject* parent = nullptr);
    void setDateChangedCallback(QDateEdit_DateChangedCallback callback);
public slots:
    void onDateChanged(const QDate& date) const;
private:
    QDateEdit_DateChangedCallback dateCallback;
};

#endif // DATEEDIT_HANDLER_H
