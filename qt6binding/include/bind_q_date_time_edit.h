#ifndef QDATETIMEEDIT_BIND_H
#define QDATETIMEEDIT_BIND_H

#include <QDateTimeEdit>

class QDateTimeEditBind {
public:
    static QDateTimeEdit* create(QWidget* parent = nullptr);
    static QDateTimeEdit* createWithDateTime(int year, int month, int day, int hour, int minute, int second, QWidget* parent = nullptr);
    static void destroy(QDateTimeEdit* dateTimeEdit);
    static void setDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
    static void getDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
    static void setMinimumDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
    static void setMaximumDateTime(QDateTimeEdit* dateTimeEdit, int year, int month, int day, int hour, int minute, int second);
    static void getMinimumDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
    static void getMaximumDateTime(QDateTimeEdit* dateTimeEdit, int* year, int* month, int* day, int* hour, int* minute, int* second);
    static void setDisplayFormat(QDateTimeEdit* dateTimeEdit, const char* format);
    static const char* displayFormat(QDateTimeEdit* dateTimeEdit);
    static void setCalendarPopup(QDateTimeEdit* dateTimeEdit, bool enable);
    static bool calendarPopup(QDateTimeEdit* dateTimeEdit);
    static void setTimeZone(QDateTimeEdit* dateTimeEdit, const char* id);
    static const char* timeZone(QDateTimeEdit* dateTimeEdit);
    static void setEnabled(QDateTimeEdit* dateTimeEdit, bool enabled);
    static bool isEnabled(QDateTimeEdit* dateTimeEdit);
    static void setReadOnly(QDateTimeEdit* dateTimeEdit, bool readOnly);
    static bool isReadOnly(QDateTimeEdit* dateTimeEdit);
    static void setCurrentSectionIndex(QDateTimeEdit* dateTimeEdit, int index);
    static int currentSectionIndex(QDateTimeEdit* dateTimeEdit);
};

#endif // QDATETIMEEDIT_BIND_H
