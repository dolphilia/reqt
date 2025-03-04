#ifndef DOUBLESPINBOX_HANDLER_H
#define DOUBLESPINBOX_HANDLER_H

#include <QObject>

class QDoubleSpinBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QDoubleSpinBox_ValueChangedCallback)(void*, double);
    typedef void (*QDoubleSpinBox_EditingFinishedCallback)(void*);
public:
    explicit QDoubleSpinBoxHandler(QObject* parent = nullptr);
    void setValueChangedCallback(QDoubleSpinBox_ValueChangedCallback callback);
    void setEditingFinishedCallback(QDoubleSpinBox_EditingFinishedCallback callback);
public slots:
    void onValueChanged(double value) const;
    void onEditingFinished() const;
private:
    QDoubleSpinBox_ValueChangedCallback valueCallback;
    QDoubleSpinBox_EditingFinishedCallback editingCallback;
};

#endif // DOUBLESPINBOX_HANDLER_H
