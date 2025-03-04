#ifndef QSPINBOX_BIND_H
#define QSPINBOX_BIND_H

#include <QSpinBox>
#include "QSpinBoxHandler.h"

class QSpinBoxHandler;

class QSpinBoxBind : public QSpinBox {
    Q_OBJECT
    typedef void (*QSpinBox_ValueChangedCallback)(void*, int);
    typedef void (*QSpinBox_TextChangedCallback)(void*, const char*);
    typedef void (*QSpinBox_EditingFinishedCallback)(void*);
public:
    explicit QSpinBoxBind(QWidget* parent = nullptr);
    ~QSpinBoxBind() override;
    void setValueChangedCallback(QSpinBox_ValueChangedCallback callback) const;
    void setTextChangedCallback(QSpinBox_TextChangedCallback callback) const;
    void setEditingFinishedCallback(QSpinBox_EditingFinishedCallback callback) const;
private:
    QSpinBoxHandler* handler;
};

#endif // QSPINBOX_BIND_H
