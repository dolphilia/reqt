#ifndef QINPUTDIALOG_BIND_H
#define QINPUTDIALOG_BIND_H

#include "QInputDialogHandler.h"
#include <QInputDialog>
#include <QLineEdit>

class QInputDialogBind : public QInputDialog {
    Q_OBJECT
    typedef void (*DoubleValueChangedCallback)(void*, double);
    typedef void (*DoubleValueSelectedCallback)(void*, double);
    typedef void (*IntValueChangedCallback)(void*, int);
    typedef void (*IntValueSelectedCallback)(void*, int);
    typedef void (*TextValueChangedCallback)(void*, const char*);
    typedef void (*TextValueSelectedCallback)(void*, const char*);
public:
    explicit QInputDialogBind(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~QInputDialogBind() override;
    
    void setDoubleValueChangedCallback(DoubleValueChangedCallback callback) const;
    void setDoubleValueSelectedCallback(DoubleValueSelectedCallback callback) const;
    void setIntValueChangedCallback(IntValueChangedCallback callback) const;
    void setIntValueSelectedCallback(IntValueSelectedCallback callback) const;
    void setTextValueChangedCallback(TextValueChangedCallback callback) const;
    void setTextValueSelectedCallback(TextValueSelectedCallback callback) const;
    
    // スタティック関数
    static double getDouble(QWidget* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags);
    static int getInt(QWidget* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags);
    static const char* getItem(QWidget* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags);
    static const char* getMultiLineText(QWidget* parent, const char* title, const char* label, const char* text, bool* ok, int flags);
    static const char* getText(QWidget* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags);
    
private:
    QInputDialogHandler* handler;
};

#endif // QINPUTDIALOG_BIND_H
