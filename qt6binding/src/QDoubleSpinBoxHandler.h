#ifndef HANDLER_DOUBLE_SPIN_BOX_H
#define HANDLER_DOUBLE_SPIN_BOX_H

#include <QObject>

class DoubleSpinBoxHandler : public QObject {
    Q_OBJECT
public:
    explicit DoubleSpinBoxHandler(QObject *parent = nullptr);
    ~DoubleSpinBoxHandler();

    void setValueChangedCallback(void (*callback)(double value));
    void setEditingFinishedCallback(void (*callback)());

public slots:
    void onValueChanged(double value);
    void onEditingFinished();

private:
    void (*m_valueChangedCallback)(double value);
    void (*m_editingFinishedCallback)();
};

#endif // HANDLER_DOUBLE_SPIN_BOX_H
