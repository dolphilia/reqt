#ifndef QINPUTDIALOG_BIND_H
#define QINPUTDIALOG_BIND_H

#include "QInputDialogHandler.h"
#include <QInputDialog>

class QInputDialogBind : public QInputDialog {
    Q_OBJECT
    typedef void (*QInputDialog_DoubleValueChangedCallback)(void*, double);
    typedef void (*QInputDialog_DoubleValueSelectedCallback)(void*, double);
    typedef void (*QInputDialog_IntValueChangedCallback)(void*, int);
    typedef void (*QInputDialog_IntValueSelectedCallback)(void*, int);
    typedef void (*QInputDialog_TextValueChangedCallback)(void*, const char*);
    typedef void (*QInputDialog_TextValueSelectedCallback)(void*, const char*);
public:
    explicit QInputDialogBind(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~QInputDialogBind() override;
    void setDoubleValueChangedCallback(QInputDialog_DoubleValueChangedCallback callback) const;
    void setDoubleValueSelectedCallback(QInputDialog_DoubleValueSelectedCallback callback) const;
    void setIntValueChangedCallback(QInputDialog_IntValueChangedCallback callback) const;
    void setIntValueSelectedCallback(QInputDialog_IntValueSelectedCallback callback) const;
    void setTextValueChangedCallback(QInputDialog_TextValueChangedCallback callback) const;
    void setTextValueSelectedCallback(QInputDialog_TextValueSelectedCallback callback) const;
private:
    QInputDialogHandler* handler;
};

#endif // QINPUTDIALOG_BIND_H
