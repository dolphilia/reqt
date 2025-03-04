#ifndef QDATETIMEEDIT_BIND_H
#define QDATETIMEEDIT_BIND_H

#include "QDateTimeEditHandler.h"
#include <QDateTimeEdit>

class QDateTimeEditBind : public QDateTimeEdit {
    Q_OBJECT
    typedef void (*QDateTimeEdit_DateChangedCallback)(void*, int, int, int);
    typedef void (*QDateTimeEdit_TimeChangedCallback)(void*, int, int, int);
public:
    explicit QDateTimeEditBind(QWidget* parent = nullptr);
    ~QDateTimeEditBind() override;
    void setDateChangedCallback(QDateTimeEdit_DateChangedCallback callback) const;
    void setTimeChangedCallback(QDateTimeEdit_TimeChangedCallback callback) const;
private:
    QDateTimeEditHandler* handler;
};

#endif // QDATETIMEEDIT_BIND_H
