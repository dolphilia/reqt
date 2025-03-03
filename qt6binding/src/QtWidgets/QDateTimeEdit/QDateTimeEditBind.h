#ifndef QDATETIMEEDIT_BIND_H
#define QDATETIMEEDIT_BIND_H

#include "QDateTimeEditHandler.h"
#include <QDateTimeEdit>

class QDateTimeEditBind : public QDateTimeEdit {
    Q_OBJECT
    typedef void (*DateChangedCallback)(void*, int, int, int);
    typedef void (*TimeChangedCallback)(void*, int, int, int);
public:
    explicit QDateTimeEditBind(QWidget* parent = nullptr);
    ~QDateTimeEditBind() override;
    void setDateChangedCallback(DateChangedCallback callback) const;
    void setTimeChangedCallback(TimeChangedCallback callback) const;
private:
    DateTimeEditHandler* handler;
};

#endif // QDATETIMEEDIT_BIND_H
